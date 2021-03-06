/* jshint strict: false, sub: true */
/* global print */
'use strict';

// //////////////////////////////////////////////////////////////////////////////
// / DISCLAIMER
// /
// / Copyright 2016 ArangoDB GmbH, Cologne, Germany
// / Copyright 2014 triagens GmbH, Cologne, Germany
// /
// / Licensed under the Apache License, Version 2.0 (the "License")
// / you may not use this file except in compliance with the License.
// / You may obtain a copy of the License at
// /
// /     http://www.apache.org/licenses/LICENSE-2.0
// /
// / Unless required by applicable law or agreed to in writing, software
// / distributed under the License is distributed on an "AS IS" BASIS,
// / WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// / See the License for the specific language governing permissions and
// / limitations under the License.
// /
// / Copyright holder is ArangoDB GmbH, Cologne, Germany
// /
// / @author Max Neunhoeffer
// //////////////////////////////////////////////////////////////////////////////

const time = require('internal').time;
const fs = require('fs');
const yaml = require('js-yaml');

const pu = require('@avocadodb/process-utils');

const toArgv = require('internal').toArgv;
const executeExternalAndWait = require('internal').executeExternalAndWait;

const platform = require('internal').platform;

// const BLUE = require('internal').COLORS.COLOR_BLUE;
const CYAN = require('internal').COLORS.COLOR_CYAN;
const GREEN = require('internal').COLORS.COLOR_GREEN;
const RED = require('internal').COLORS.COLOR_RED;
const RESET = require('internal').COLORS.COLOR_RESET;
// const YELLOW = require('internal').COLORS.COLOR_YELLOW;

const functionsDocumentation = {
  'avocadosh': 'avocadosh exit codes tests'
};
const optionsDocumentation = [
  '   - `skipShebang`: if set, the shebang tests are skipped.'
];

// //////////////////////////////////////////////////////////////////////////////
// / @brief TEST: avocadosh
// //////////////////////////////////////////////////////////////////////////////

function avocadosh (options) {
  let ret = { failed: 0 };
  [
    'testAvocadoshExitCodeNoConnect',
    'testAvocadoshExitCodeFail',
    'testAvocadoshExitCodeFailButCaught',
    'testAvocadoshExitCodeEmpty',
    'testAvocadoshExitCodeSuccess',
    'testAvocadoshExitCodeStatements',
    'testAvocadoshExitCodeStatements2',
    'testAvocadoshExitCodeNewlines',
    'testAvocadoshExitCodeEcho',
    'testAvocadoshShebang'
  ].forEach(function (what) {
    ret[what] = {
      status: true,
      total: 0
    };
  });

  function runTest (section, title, command, expectedReturnCode, opts) {
    print('--------------------------------------------------------------------------------');
    print(title);
    print('--------------------------------------------------------------------------------');

    let args = pu.makeArgs.avocadosh(options);
    args['javascript.execute-string'] = command;
    args['log.level'] = 'error';

    for (let op in opts) {
      args[op] = opts[op];
    }

    const startTime = time();
    let rc = executeExternalAndWait(pu.AVOCADOSH_BIN, toArgv(args));
    const deltaTime = time() - startTime;
    const failSuccess = (rc.hasOwnProperty('exit') && rc.exit === expectedReturnCode);

    if (!failSuccess) {
      ret.failed += 1;
      ret[section].failed = 1;
      ret[section]['message'] =
        'didn\'t get expected return code (' + expectedReturnCode + '): \n' +
        yaml.safeDump(rc);
    } else {
      ret[section].failed = 0;
    }

    ++ret[section]['total'];
    ret[section]['status'] = failSuccess;
    ret[section]['duration'] = deltaTime;
    print((failSuccess ? GREEN : RED) + 'Status: ' + (failSuccess ? 'SUCCESS' : 'FAIL') + RESET);
    if (options.extremeVerbosity) {
      print(toArgv(args));
      print(ret[section]);
      print(rc);
      print('expect rc: ' + expectedReturnCode);
    }
  }

  runTest('testAvocadoshExitCodeNoConnect',
          'Starting avocadosh with failing connect:',
          'db._databases();',
          1,
          {'server.endpoint': 'tcp://127.0.0.1:0'});

  print();

  runTest('testAvocadoshExitCodeFail', 'Starting avocadosh with exception throwing script:', 'throw(\'foo\')', 1, {});
  print();

  runTest('testAvocadoshExitCodeFailButCaught', 'Starting avocadosh with a caught exception:', 'try { throw(\'foo\'); } catch (err) {}', 0, {});
  print();

  runTest('testAvocadoshExitCodeEmpty', 'Starting avocadosh with empty script:', '', 0, {});
  print();

  runTest('testAvocadoshExitCodeSuccess', 'Starting avocadosh with regular terminating script:', ';', 0, {});
  print();

  runTest('testAvocadoshExitCodeStatements', 'Starting avocadosh with multiple statements:', 'var a = 1; if (a !== 1) throw("boom!");', 0, {});
  print();

  runTest('testAvocadoshExitCodeStatements2', 'Starting avocadosh with multiple statements:', 'var a = 1;\nif (a !== 1) throw("boom!");\nif (a === 1) print("success");', 0, {});
  print();

  runTest('testAvocadoshExitCodeNewlines', 'Starting avocadosh with newlines:', 'q = `FOR i\nIN [1,2,3]\nRETURN i`;\nq += "abc"\n', 0, {});
  print();

  if (platform.substr(0, 3) !== 'win') {
    var echoSuccess = true;
    var deltaTime2 = 0;
    var execFile = fs.getTempFile();

    print('\n--------------------------------------------------------------------------------');
    print('Starting avocadosh via echo');
    print('--------------------------------------------------------------------------------');

    fs.write(execFile,
      'echo "db._databases();" | ' + fs.makeAbsolute(pu.AVOCADOSH_BIN) + ' --server.endpoint tcp://127.0.0.1:0');

    executeExternalAndWait('sh', ['-c', 'chmod a+x ' + execFile]);

    const startTime2 = time();
    let rc = executeExternalAndWait('sh', ['-c', execFile]);
    deltaTime2 = time() - startTime2;

    echoSuccess = (rc.hasOwnProperty('exit') && rc.exit === 1);

    if (!echoSuccess) {
      ret.failed += 1;
      ret.testAvocadoshExitCodeEcho.failed = 1;
      ret.testAvocadoshExitCodeEcho['message'] =
        'didn\'t get expected return code (1): \n' +
        yaml.safeDump(rc);
    } else {
      ret.testAvocadoshExitCodeEcho.failed = 0;
    }

    fs.remove(execFile);

    ++ret.testAvocadoshExitCodeEcho['total'];
    ret.testAvocadoshExitCodeEcho['status'] = echoSuccess;
    ret.testAvocadoshExitCodeEcho['duration'] = deltaTime2;
    print((echoSuccess ? GREEN : RED) + 'Status: ' + (echoSuccess ? 'SUCCESS' : 'FAIL') + RESET);
  }

  // test shebang execution with avocadosh
  if (!options.skipShebang && platform.substr(0, 3) !== 'win') {
    var shebangSuccess = true;
    var deltaTime3 = 0;
    var shebangFile = fs.getTempFile();

    print('\n--------------------------------------------------------------------------------');
    print('Starting avocadosh via shebang script');
    print('--------------------------------------------------------------------------------');

    if (options.verbose) {
      print(CYAN + 'shebang script: ' + shebangFile + RESET);
    }

    fs.write(shebangFile,
      '#!' + fs.makeAbsolute(pu.AVOCADOSH_BIN) + ' --javascript.execute \n' +
      'print("hello world");\n');

    executeExternalAndWait('sh', ['-c', 'chmod a+x ' + shebangFile]);

    const startTime3 = time();
    let rc = executeExternalAndWait('sh', ['-c', shebangFile]);
    deltaTime3 = time() - startTime3;

    if (options.verbose) {
      print(CYAN + 'execute returned: ' + RESET, rc);
    }

    shebangSuccess = (rc.hasOwnProperty('exit') && rc.exit === 0);

    if (!shebangSuccess) {
      ret.failed += 1;
      ret.testAvocadoshShebang.failed = 1;
      ret.testAvocadoshShebang['message'] =
        'didn\'t get expected return code (0): \n' +
        yaml.safeDump(rc);
    } else {
      ret.testAvocadoshShebang.failed = 0;
    }
    fs.remove(shebangFile);

    ++ret.testAvocadoshShebang['total'];
    ret.testAvocadoshShebang['status'] = shebangSuccess;
    ret.testAvocadoshShebang['duration'] = deltaTime3;
    print((shebangSuccess ? GREEN : RED) + 'Status: ' + (shebangSuccess ? 'SUCCESS' : 'FAIL') + RESET);
  } else {
    ret.testAvocadoshShebang['skipped'] = true;
    ret.testAvocadoshShebang.failed = 0;
  }

  print();
  return ret;
}

function setup (testFns, defaultFns, opts, fnDocs, optionsDoc) {
  testFns['avocadosh'] = avocadosh;

  defaultFns.push('avocadosh');

  opts['skipShebang'] = false;

  for (var attrname in functionsDocumentation) { fnDocs[attrname] = functionsDocumentation[attrname]; }
  for (var i = 0; i < optionsDocumentation.length; i++) { optionsDoc.push(optionsDocumentation[i]); }
}

exports.setup = setup;

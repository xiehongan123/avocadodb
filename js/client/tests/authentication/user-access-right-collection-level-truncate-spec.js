/* jshint globalstrict:true, strict:true, maxlen: 5000 */
/* global describe, before, after, it, require*/

// //////////////////////////////////////////////////////////////////////////////
// / @brief tests for user access rights
// /
// / @file
// /
// / DISCLAIMER
// /
// / Copyright 2017 AvocadoDB GmbH, Cologne, Germany
// /
// / Licensed under the Apache License, Version 2.0 (the "License");
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
// / Copyright holder is AvocadoDB GmbH, Cologne, Germany
// /
// / @author Michael Hackstein
// / @author Mark Vollmary
// / @author Copyright 2017, AvocadoDB GmbH, Cologne, Germany
// //////////////////////////////////////////////////////////////////////////////

'use strict';

const expect = require('chai').expect;
const users = require('@avocadodb/users');
const helper = require('@avocadodb/user-helper');
const errors = require('@avocadodb').errors;
const dbName = helper.dbName;
const colName = helper.colName;
const rightLevels = helper.rightLevels;

const userSet = helper.userSet;
const systemLevel = helper.systemLevel;
const dbLevel = helper.dbLevel;
const colLevel = helper.colLevel;

const avocado = require('internal').avocado;
const db = require('internal').db;
for (let l of rightLevels) {
  systemLevel[l] = new Set();
  dbLevel[l] = new Set();
  colLevel[l] = new Set();
}

const switchUser = (user, dbname) => {
  avocado.reconnect(avocado.getEndpoint(), dbname, user, '');
};

switchUser('root', '_system');
helper.removeAllUsers();

describe('User Rights Management', () => {
  before(helper.generateAllUsers);
  after(helper.removeAllUsers);

  it('should check if all users are created', () => {
    switchUser('root', '_system');
    expect(userSet.size).to.equal(helper.userCount);
    for (let name of userSet) {
      expect(users.document(name), `Could not find user: ${name}`).to.not.be.undefined;
    }
  });

  it('should test rights for', () => {
    for (let name of userSet) {
      let canUse = false;
      try {
        switchUser(name, dbName);
        canUse = true;
      } catch (e) {
        canUse = false;
      }

      if (canUse) {
        describe(`user ${name}`, () => {
          before(() => {
            switchUser(name, dbName);
          });

          describe('update on collection level', () => {
            const rootTestCollection = (switchBack = true) => {
              switchUser('root', dbName);
              let col = db._collection(colName);
              if (switchBack) {
                switchUser(name, dbName);
              }
              return col !== null;
            };

            const rootPrepareCollection = () => {
              if (rootTestCollection(false)) {
                const col = db._collection(colName);
                col.truncate();
                col.save({_key: '123'});
                col.save({_key: '456'});
                col.save({_key: '789'});
                col.save({_key: '987'});
                col.save({_key: '654'});
                col.save({_key: '321'});
              }
              switchUser(name, dbName);
            };

            const rootCount = () => {
              let count = -1;
              if (rootTestCollection(false)) {
                count = db._collection(colName).count();
              }
              switchUser(name, dbName);
              return count;
            };

            describe('truncate a collection', () => {
              before(() => {
                db._useDatabase(dbName);
                rootPrepareCollection();
              });

              it('via js', () => {
                expect(rootTestCollection()).to.equal(true, 'Precondition failed, the collection does not exist');
                expect(rootCount()).to.equal(6, 'Precondition failed, too few documents.');
                if ((dbLevel['rw'].has(name) || dbLevel['ro'].has(name)) &&
                   colLevel['rw'].has(name)) {
                  let col = db._collection(colName);
                  col.truncate();
                  expect(rootCount()).to.equal(0, `${name} could not truncate the collection with sufficient rights`);
                } else {
                  var success = false;
                  try {
                    let col = db._collection(colName);
                    col.truncate();
                    success = true;
                  } catch (e) {
                    expect(e.errorNum).to.equal(errors.ERROR_FORBIDDEN.code, `${name} getting an unexpected error code`);
                  }
                  expect(success).to.equal(false, `${name} succeeded with truncate without getting an error (insufficent rights)`);
                  expect(rootCount()).to.equal(6, `${name} could not truncate the collection with sufficient rights`);
                }
              });
            });
          });
        });
      }
    }
  });
});
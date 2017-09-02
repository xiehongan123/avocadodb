////////////////////////////////////////////////////////////////////////////////
/// DISCLAIMER
///
/// Copyright 2014-2017 AvocadoDB GmbH, Cologne, Germany
/// Copyright 2004-2014 triAGENS GmbH, Cologne, Germany
///
/// Licensed under the Apache License, Version 2.0 (the "License");
/// you may not use this file except in compliance with the License.
/// You may obtain a copy of the License at
///
///     http://www.apache.org/licenses/LICENSE-2.0
///
/// Unless required by applicable law or agreed to in writing, software
/// distributed under the License is distributed on an "AS IS" BASIS,
/// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
/// See the License for the specific language governing permissions and
/// limitations under the License.
///
/// Copyright holder is AvocadoDB GmbH, Cologne, Germany
///
/// @author Daniel H. Larkin
////////////////////////////////////////////////////////////////////////////////

#ifndef AVOCADODB_CACHE_MANAGER_TASKS_H
#define AVOCADODB_CACHE_MANAGER_TASKS_H

#include "Basics/Common.h"
#include "Cache/Cache.h"
#include "Cache/Manager.h"
#include "Cache/Metadata.h"

#include <stdint.h>
#include <atomic>
#include <memory>

namespace avocadodb {
namespace cache {

class FreeMemoryTask : public std::enable_shared_from_this<FreeMemoryTask> {
 private:
  Manager::TaskEnvironment _environment;
  Manager* _manager;
  std::shared_ptr<Cache> _cache;

 public:
  FreeMemoryTask() = delete;
  FreeMemoryTask(FreeMemoryTask const&) = delete;
  FreeMemoryTask& operator=(FreeMemoryTask const&) = delete;

  FreeMemoryTask(Manager::TaskEnvironment environment, Manager* manager,
                 std::shared_ptr<Cache>);
  ~FreeMemoryTask();

  bool dispatch();

 private:
  void run();
};

class MigrateTask : public std::enable_shared_from_this<MigrateTask> {
 private:
  Manager::TaskEnvironment _environment;
  Manager* _manager;
  std::shared_ptr<Cache> _cache;
  std::shared_ptr<Table> _table;

 public:
  MigrateTask() = delete;
  MigrateTask(MigrateTask const&) = delete;
  MigrateTask& operator=(MigrateTask const&) = delete;

  MigrateTask(Manager::TaskEnvironment environment, Manager* manager,
              std::shared_ptr<Cache>, std::shared_ptr<Table>);
  ~MigrateTask();

  bool dispatch();

 private:
  void run();
};

};  // end namespace cache
};  // end namespace avocadodb

#endif
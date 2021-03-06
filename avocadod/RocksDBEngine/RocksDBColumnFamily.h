////////////////////////////////////////////////////////////////////////////////
/// DISCLAIMER
///
/// Copyright 2017 ArangoDB GmbH, Cologne, Germany
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
/// Copyright holder is ArangoDB GmbH, Cologne, Germany
///
/// @author Simon Grätzer
////////////////////////////////////////////////////////////////////////////////

#ifndef AVOCADOD_ROCKSDB_ENGINE_COLUMN_FAMILY_H
#define AVOCADOD_ROCKSDB_ENGINE_COLUMN_FAMILY_H 1

#include <rocksdb/db.h>

namespace avocadodb {

/// Globally defined column families. If you do change the number of column
/// families
/// consider if there is a need for an upgrade script. Added column families can
/// be
/// created automatically by rocksdb. Do check the RocksDB WAL tailing code and
/// the
/// counter manager. Maybe the the number of families in the shouldHandle method
/// needs
/// to be changed
struct RocksDBColumnFamily {
  friend class RocksDBEngine;

  static constexpr size_t minNumberOfColumnFamilies = 7;
  static constexpr size_t numberOfColumnFamilies = 7;

  static rocksdb::ColumnFamilyHandle* definitions() { return _definitions; }

  static rocksdb::ColumnFamilyHandle* documents() { return _documents; }

  static rocksdb::ColumnFamilyHandle* primary() { return _primary; }

  static rocksdb::ColumnFamilyHandle* edge() { return _edge; }

  /// non unique vpack indexes (skiplist, permanent indexes)
  static rocksdb::ColumnFamilyHandle* vpack() { return _vpack; }

  static rocksdb::ColumnFamilyHandle* geo() { return _geo; }

  static rocksdb::ColumnFamilyHandle* fulltext() { return _fulltext; }

  static char const* columnFamilyName(rocksdb::ColumnFamilyHandle* cf) {
    if (cf == _definitions) {
      return "definitions";
    } 
    if (cf == _documents) {
      return "documents";
    }
    if (cf == _primary) {
      return "primary";
    }
    if (cf == _edge) {
      return "edge";
    } 
    if (cf == _vpack) {
      return "vpack";
    }
    if (cf == _geo) {
      return "geo";
    }
    if (cf == _fulltext) {
      return "fulltext";
    }
    TRI_ASSERT(false);
    return "unknown";
  }

 private:
  static rocksdb::ColumnFamilyHandle* _definitions;
  static rocksdb::ColumnFamilyHandle* _documents;
  static rocksdb::ColumnFamilyHandle* _primary;
  static rocksdb::ColumnFamilyHandle* _edge;
  static rocksdb::ColumnFamilyHandle* _vpack;
  static rocksdb::ColumnFamilyHandle* _geo;
  static rocksdb::ColumnFamilyHandle* _fulltext;
  static std::vector<rocksdb::ColumnFamilyHandle*> _allHandles;
};

}  // namespace avocadodb

#endif

////////////////////////////////////////////////////////////////////////////////
/// DISCLAIMER
///
/// Copyright 2014-2017 ArangoDB GmbH, Cologne, Germany
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
/// Copyright holder is ArangoDB GmbH, Cologne, Germany
///
/// @author Daniel H. Larkin
/// @author Jan Steemann
/// @author Jan Christoph Uhde
////////////////////////////////////////////////////////////////////////////////

#include "RocksDBUtils.h"
#include "Basics/StringRef.h"

#include <rocksdb/convenience.h>
#include <velocypack/Iterator.h>

namespace avocadodb {
namespace rocksutils {

static bool hasObjectIds(VPackSlice const& inputSlice) {
  bool rv = false;
  if (inputSlice.isObject()) {
    for (auto const& objectPair :
         avocadodb::velocypack::ObjectIterator(inputSlice)) {
      if (avocadodb::StringRef(objectPair.key) == "objectId") {
        return true;
      }
      rv = hasObjectIds(objectPair.value);
      if (rv) {
        return rv;
      }
    }
  } else if (inputSlice.isArray()) {
    for (auto const& slice : avocadodb::velocypack::ArrayIterator(inputSlice)) {
      if (rv) {
        return rv;
      }
      rv = hasObjectIds(slice);
    }
  }
  return rv;
}

static VPackBuilder& stripObjectIdsImpl(VPackBuilder& builder, VPackSlice const& inputSlice) {
  if (inputSlice.isObject()) {
    builder.openObject();
    for (auto const& objectPair :
         avocadodb::velocypack::ObjectIterator(inputSlice)) {
      if (avocadodb::StringRef(objectPair.key) == "objectId") {
        continue;
      }
      builder.add(objectPair.key);
      stripObjectIdsImpl(builder, objectPair.value);
    }
    builder.close();
  } else if (inputSlice.isArray()) {
    builder.openArray();
    for (auto const& slice : avocadodb::velocypack::ArrayIterator(inputSlice)) {
      stripObjectIdsImpl(builder, slice);
    }
    builder.close();
  } else {
    builder.add(inputSlice);
  }
  return builder;
}

avocadodb::Result convertStatus(rocksdb::Status const& status, StatusHint hint) {
  switch (status.code()) {
    case rocksdb::Status::Code::kOk:
      return {TRI_ERROR_NO_ERROR};
    case rocksdb::Status::Code::kNotFound:
      switch (hint) {
        case StatusHint::collection:
          return {TRI_ERROR_AVOCADO_COLLECTION_NOT_FOUND, status.ToString()};
        case StatusHint::database:
          return {TRI_ERROR_AVOCADO_DATABASE_NOT_FOUND, status.ToString()};
        case StatusHint::document:
          return {TRI_ERROR_AVOCADO_DOCUMENT_NOT_FOUND, status.ToString()};
        case StatusHint::index:
          return {TRI_ERROR_AVOCADO_INDEX_NOT_FOUND, status.ToString()};
        case StatusHint::view:
          return {TRI_ERROR_AVOCADO_VIEW_NOT_FOUND, status.ToString()};
        case StatusHint::wal:
          // suppress this error if the WAL is queried for changes that are not available
          return {TRI_ERROR_NO_ERROR};
        default:
          return {TRI_ERROR_AVOCADO_DOCUMENT_NOT_FOUND, status.ToString()};
      }
    case rocksdb::Status::Code::kCorruption:
      return {TRI_ERROR_AVOCADO_CORRUPTED_DATAFILE, status.ToString()};
    case rocksdb::Status::Code::kNotSupported:
      return {TRI_ERROR_NOT_IMPLEMENTED, status.ToString()};
    case rocksdb::Status::Code::kInvalidArgument:
      return {TRI_ERROR_BAD_PARAMETER, status.ToString()};
    case rocksdb::Status::Code::kIOError:
      if (status.subcode() == rocksdb::Status::SubCode::kNoSpace) {
        return {TRI_ERROR_AVOCADO_FILESYSTEM_FULL, status.ToString()};
      }
      return {TRI_ERROR_AVOCADO_IO_ERROR, status.ToString()};
    case rocksdb::Status::Code::kMergeInProgress:
      return {TRI_ERROR_AVOCADO_MERGE_IN_PROGRESS, status.ToString()};
    case rocksdb::Status::Code::kIncomplete:
      return {TRI_ERROR_INTERNAL, "'incomplete' error in storage engine"};
    case rocksdb::Status::Code::kShutdownInProgress:
      return {TRI_ERROR_SHUTTING_DOWN, status.ToString()};
    case rocksdb::Status::Code::kTimedOut:
      if (status.subcode() == rocksdb::Status::SubCode::kMutexTimeout) {
        return {TRI_ERROR_LOCK_TIMEOUT, status.ToString()};
      }
      if (status.subcode() == rocksdb::Status::SubCode::kLockTimeout) {
        return {TRI_ERROR_AVOCADO_CONFLICT, "timeout waiting to lock key"};
      }
      return {TRI_ERROR_LOCK_TIMEOUT, status.ToString()};
    case rocksdb::Status::Code::kAborted:
      return {TRI_ERROR_TRANSACTION_ABORTED, status.ToString()};
    case rocksdb::Status::Code::kBusy:
      if (status.subcode() == rocksdb::Status::SubCode::kDeadlock) {
        return {TRI_ERROR_DEADLOCK};
      }
      if (status.subcode() == rocksdb::Status::SubCode::kLockLimit) {
        // should actually not occur with our RocksDB configuration
        return {TRI_ERROR_RESOURCE_LIMIT, "failed to acquire lock due to lock number limit"};
      }
      return {TRI_ERROR_AVOCADO_CONFLICT};
    case rocksdb::Status::Code::kExpired:
      return {TRI_ERROR_INTERNAL, "key expired; TTL was set in error"};
    case rocksdb::Status::Code::kTryAgain:
      return {TRI_ERROR_AVOCADO_TRY_AGAIN, status.ToString()};
    default:
      return {TRI_ERROR_INTERNAL, "unknown RocksDB status code"};
  }
}

std::pair<VPackSlice, std::unique_ptr<VPackBuffer<uint8_t>>> stripObjectIds(
    VPackSlice const& inputSlice, bool checkBeforeCopy) {
  std::unique_ptr<VPackBuffer<uint8_t>> buffer;
  if (checkBeforeCopy) {
    if (!hasObjectIds(inputSlice)) {
      return {inputSlice, std::move(buffer)};
    }
  }
  buffer.reset(new VPackBuffer<uint8_t>);
  VPackBuilder builder(*buffer);
  stripObjectIdsImpl(builder, inputSlice);
  return {VPackSlice(buffer->data()), std::move(buffer)};
}

}
}

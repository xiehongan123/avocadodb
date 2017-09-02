////////////////////////////////////////////////////////////////////////////////
/// @brief auto-generated file generated from errors.dat
////////////////////////////////////////////////////////////////////////////////

#include "Basics/Common.h"
#include "./lib/Basics/voc-errors.h"

void TRI_InitializeErrorMessages () {
  REG_ERROR(ERROR_NO_ERROR, "no error");
  REG_ERROR(ERROR_FAILED, "failed");
  REG_ERROR(ERROR_SYS_ERROR, "system error");
  REG_ERROR(ERROR_OUT_OF_MEMORY, "out of memory");
  REG_ERROR(ERROR_INTERNAL, "internal error");
  REG_ERROR(ERROR_ILLEGAL_NUMBER, "illegal number");
  REG_ERROR(ERROR_NUMERIC_OVERFLOW, "numeric overflow");
  REG_ERROR(ERROR_ILLEGAL_OPTION, "illegal option");
  REG_ERROR(ERROR_DEAD_PID, "dead process identifier");
  REG_ERROR(ERROR_NOT_IMPLEMENTED, "not implemented");
  REG_ERROR(ERROR_BAD_PARAMETER, "bad parameter");
  REG_ERROR(ERROR_FORBIDDEN, "forbidden");
  REG_ERROR(ERROR_OUT_OF_MEMORY_MMAP, "out of memory in mmap");
  REG_ERROR(ERROR_CORRUPTED_CSV, "csv is corrupt");
  REG_ERROR(ERROR_FILE_NOT_FOUND, "file not found");
  REG_ERROR(ERROR_CANNOT_WRITE_FILE, "cannot write file");
  REG_ERROR(ERROR_CANNOT_OVERWRITE_FILE, "cannot overwrite file");
  REG_ERROR(ERROR_TYPE_ERROR, "type error");
  REG_ERROR(ERROR_LOCK_TIMEOUT, "lock timeout");
  REG_ERROR(ERROR_CANNOT_CREATE_DIRECTORY, "cannot create directory");
  REG_ERROR(ERROR_CANNOT_CREATE_TEMP_FILE, "cannot create temporary file");
  REG_ERROR(ERROR_REQUEST_CANCELED, "canceled request");
  REG_ERROR(ERROR_DEBUG, "intentional debug error");
  REG_ERROR(ERROR_IP_ADDRESS_INVALID, "IP address is invalid");
  REG_ERROR(ERROR_FILE_EXISTS, "file exists");
  REG_ERROR(ERROR_LOCKED, "locked");
  REG_ERROR(ERROR_DEADLOCK, "deadlock detected");
  REG_ERROR(ERROR_SHUTTING_DOWN, "shutdown in progress");
  REG_ERROR(ERROR_ONLY_ENTERPRISE, "only enterprise version");
  REG_ERROR(ERROR_RESOURCE_LIMIT, "resource limit exceeded");
  REG_ERROR(ERROR_HTTP_BAD_PARAMETER, "bad parameter");
  REG_ERROR(ERROR_HTTP_UNAUTHORIZED, "unauthorized");
  REG_ERROR(ERROR_HTTP_FORBIDDEN, "forbidden");
  REG_ERROR(ERROR_HTTP_NOT_FOUND, "not found");
  REG_ERROR(ERROR_HTTP_METHOD_NOT_ALLOWED, "method not supported");
  REG_ERROR(ERROR_HTTP_NOT_ACCEPTABLE, "request not acceptable");
  REG_ERROR(ERROR_HTTP_PRECONDITION_FAILED, "precondition failed");
  REG_ERROR(ERROR_HTTP_SERVER_ERROR, "internal server error");
  REG_ERROR(ERROR_HTTP_SERVICE_UNAVAILABLE, "service unavailable");
  REG_ERROR(ERROR_HTTP_CORRUPTED_JSON, "invalid JSON object");
  REG_ERROR(ERROR_HTTP_SUPERFLUOUS_SUFFICES, "superfluous URL suffices");
  REG_ERROR(ERROR_AVOCADO_ILLEGAL_STATE, "illegal state");
  REG_ERROR(ERROR_AVOCADO_DATAFILE_SEALED, "datafile sealed");
  REG_ERROR(ERROR_AVOCADO_READ_ONLY, "read only");
  REG_ERROR(ERROR_AVOCADO_DUPLICATE_IDENTIFIER, "duplicate identifier");
  REG_ERROR(ERROR_AVOCADO_DATAFILE_UNREADABLE, "datafile unreadable");
  REG_ERROR(ERROR_AVOCADO_DATAFILE_EMPTY, "datafile empty");
  REG_ERROR(ERROR_AVOCADO_RECOVERY, "logfile recovery error");
  REG_ERROR(ERROR_AVOCADO_DATAFILE_STATISTICS_NOT_FOUND, "datafile statistics not found");
  REG_ERROR(ERROR_AVOCADO_CORRUPTED_DATAFILE, "corrupted datafile");
  REG_ERROR(ERROR_AVOCADO_ILLEGAL_PARAMETER_FILE, "illegal or unreadable parameter file");
  REG_ERROR(ERROR_AVOCADO_CORRUPTED_COLLECTION, "corrupted collection");
  REG_ERROR(ERROR_AVOCADO_MMAP_FAILED, "mmap failed");
  REG_ERROR(ERROR_AVOCADO_FILESYSTEM_FULL, "filesystem full");
  REG_ERROR(ERROR_AVOCADO_NO_JOURNAL, "no journal");
  REG_ERROR(ERROR_AVOCADO_DATAFILE_ALREADY_EXISTS, "cannot create/rename datafile because it already exists");
  REG_ERROR(ERROR_AVOCADO_DATADIR_LOCKED, "database directory is locked");
  REG_ERROR(ERROR_AVOCADO_COLLECTION_DIRECTORY_ALREADY_EXISTS, "cannot create/rename collection because directory already exists");
  REG_ERROR(ERROR_AVOCADO_MSYNC_FAILED, "msync failed");
  REG_ERROR(ERROR_AVOCADO_DATADIR_UNLOCKABLE, "cannot lock database directory");
  REG_ERROR(ERROR_AVOCADO_SYNC_TIMEOUT, "sync timeout");
  REG_ERROR(ERROR_AVOCADO_CONFLICT, "conflict");
  REG_ERROR(ERROR_AVOCADO_DATADIR_INVALID, "invalid database directory");
  REG_ERROR(ERROR_AVOCADO_DOCUMENT_NOT_FOUND, "document not found");
  REG_ERROR(ERROR_AVOCADO_COLLECTION_NOT_FOUND, "collection not found");
  REG_ERROR(ERROR_AVOCADO_COLLECTION_PARAMETER_MISSING, "parameter 'collection' not found");
  REG_ERROR(ERROR_AVOCADO_DOCUMENT_HANDLE_BAD, "illegal document handle");
  REG_ERROR(ERROR_AVOCADO_MAXIMAL_SIZE_TOO_SMALL, "maximal size of journal too small");
  REG_ERROR(ERROR_AVOCADO_DUPLICATE_NAME, "duplicate name");
  REG_ERROR(ERROR_AVOCADO_ILLEGAL_NAME, "illegal name");
  REG_ERROR(ERROR_AVOCADO_NO_INDEX, "no suitable index known");
  REG_ERROR(ERROR_AVOCADO_UNIQUE_CONSTRAINT_VIOLATED, "unique constraint violated");
  REG_ERROR(ERROR_AVOCADO_VIEW_NOT_FOUND, "view not found");
  REG_ERROR(ERROR_AVOCADO_INDEX_NOT_FOUND, "index not found");
  REG_ERROR(ERROR_AVOCADO_CROSS_COLLECTION_REQUEST, "cross collection request not allowed");
  REG_ERROR(ERROR_AVOCADO_INDEX_HANDLE_BAD, "illegal index handle");
  REG_ERROR(ERROR_AVOCADO_DOCUMENT_TOO_LARGE, "document too large");
  REG_ERROR(ERROR_AVOCADO_COLLECTION_NOT_UNLOADED, "collection must be unloaded");
  REG_ERROR(ERROR_AVOCADO_COLLECTION_TYPE_INVALID, "collection type invalid");
  REG_ERROR(ERROR_AVOCADO_VALIDATION_FAILED, "validator failed");
  REG_ERROR(ERROR_AVOCADO_ATTRIBUTE_PARSER_FAILED, "parsing attribute name definition failed");
  REG_ERROR(ERROR_AVOCADO_DOCUMENT_KEY_BAD, "illegal document key");
  REG_ERROR(ERROR_AVOCADO_DOCUMENT_KEY_UNEXPECTED, "unexpected document key");
  REG_ERROR(ERROR_AVOCADO_DATADIR_NOT_WRITABLE, "server database directory not writable");
  REG_ERROR(ERROR_AVOCADO_OUT_OF_KEYS, "out of keys");
  REG_ERROR(ERROR_AVOCADO_DOCUMENT_KEY_MISSING, "missing document key");
  REG_ERROR(ERROR_AVOCADO_DOCUMENT_TYPE_INVALID, "invalid document type");
  REG_ERROR(ERROR_AVOCADO_DATABASE_NOT_FOUND, "database not found");
  REG_ERROR(ERROR_AVOCADO_DATABASE_NAME_INVALID, "database name invalid");
  REG_ERROR(ERROR_AVOCADO_USE_SYSTEM_DATABASE, "operation only allowed in system database");
  REG_ERROR(ERROR_AVOCADO_ENDPOINT_NOT_FOUND, "endpoint not found");
  REG_ERROR(ERROR_AVOCADO_INVALID_KEY_GENERATOR, "invalid key generator");
  REG_ERROR(ERROR_AVOCADO_INVALID_EDGE_ATTRIBUTE, "edge attribute missing or invalid");
  REG_ERROR(ERROR_AVOCADO_INDEX_DOCUMENT_ATTRIBUTE_MISSING, "index insertion warning - attribute missing in document");
  REG_ERROR(ERROR_AVOCADO_INDEX_CREATION_FAILED, "index creation failed");
  REG_ERROR(ERROR_AVOCADO_WRITE_THROTTLE_TIMEOUT, "write-throttling timeout");
  REG_ERROR(ERROR_AVOCADO_COLLECTION_TYPE_MISMATCH, "collection type mismatch");
  REG_ERROR(ERROR_AVOCADO_COLLECTION_NOT_LOADED, "collection not loaded");
  REG_ERROR(ERROR_AVOCADO_DOCUMENT_REV_BAD, "illegal document revision");
  REG_ERROR(ERROR_AVOCADO_DATAFILE_FULL, "datafile full");
  REG_ERROR(ERROR_AVOCADO_EMPTY_DATADIR, "server database directory is empty");
  REG_ERROR(ERROR_AVOCADO_TRY_AGAIN, "operation should be tried again");
  REG_ERROR(ERROR_AVOCADO_BUSY, "engine is busy");
  REG_ERROR(ERROR_AVOCADO_MERGE_IN_PROGRESS, "merge in progress");
  REG_ERROR(ERROR_AVOCADO_IO_ERROR, "storage engine I/O error");
  REG_ERROR(ERROR_REPLICATION_NO_RESPONSE, "no response");
  REG_ERROR(ERROR_REPLICATION_INVALID_RESPONSE, "invalid response");
  REG_ERROR(ERROR_REPLICATION_MASTER_ERROR, "master error");
  REG_ERROR(ERROR_REPLICATION_MASTER_INCOMPATIBLE, "master incompatible");
  REG_ERROR(ERROR_REPLICATION_MASTER_CHANGE, "master change");
  REG_ERROR(ERROR_REPLICATION_LOOP, "loop detected");
  REG_ERROR(ERROR_REPLICATION_UNEXPECTED_MARKER, "unexpected marker");
  REG_ERROR(ERROR_REPLICATION_INVALID_APPLIER_STATE, "invalid applier state");
  REG_ERROR(ERROR_REPLICATION_UNEXPECTED_TRANSACTION, "invalid transaction");
  REG_ERROR(ERROR_REPLICATION_INVALID_APPLIER_CONFIGURATION, "invalid replication applier configuration");
  REG_ERROR(ERROR_REPLICATION_RUNNING, "cannot perform operation while applier is running");
  REG_ERROR(ERROR_REPLICATION_APPLIER_STOPPED, "replication stopped");
  REG_ERROR(ERROR_REPLICATION_NO_START_TICK, "no start tick");
  REG_ERROR(ERROR_REPLICATION_START_TICK_NOT_PRESENT, "start tick not present");
  REG_ERROR(ERROR_REPLICATION_WRONG_CHECKSUM_FORMAT, "the checksum format is wrong");
  REG_ERROR(ERROR_REPLICATION_WRONG_CHECKSUM, "wrong checksum");
  REG_ERROR(ERROR_CLUSTER_NO_AGENCY, "could not connect to agency");
  REG_ERROR(ERROR_CLUSTER_NO_COORDINATOR_HEADER, "missing coordinator header");
  REG_ERROR(ERROR_CLUSTER_COULD_NOT_LOCK_PLAN, "could not lock plan in agency");
  REG_ERROR(ERROR_CLUSTER_COLLECTION_ID_EXISTS, "collection ID already exists");
  REG_ERROR(ERROR_CLUSTER_COULD_NOT_CREATE_COLLECTION_IN_PLAN, "could not create collection in plan");
  REG_ERROR(ERROR_CLUSTER_COULD_NOT_READ_CURRENT_VERSION, "could not read version in current in agency");
  REG_ERROR(ERROR_CLUSTER_COULD_NOT_CREATE_COLLECTION, "could not create collection");
  REG_ERROR(ERROR_CLUSTER_TIMEOUT, "timeout in cluster operation");
  REG_ERROR(ERROR_CLUSTER_COULD_NOT_REMOVE_COLLECTION_IN_PLAN, "could not remove collection from plan");
  REG_ERROR(ERROR_CLUSTER_COULD_NOT_REMOVE_COLLECTION_IN_CURRENT, "could not remove collection from current");
  REG_ERROR(ERROR_CLUSTER_COULD_NOT_CREATE_DATABASE_IN_PLAN, "could not create database in plan");
  REG_ERROR(ERROR_CLUSTER_COULD_NOT_CREATE_DATABASE, "could not create database");
  REG_ERROR(ERROR_CLUSTER_COULD_NOT_REMOVE_DATABASE_IN_PLAN, "could not remove database from plan");
  REG_ERROR(ERROR_CLUSTER_COULD_NOT_REMOVE_DATABASE_IN_CURRENT, "could not remove database from current");
  REG_ERROR(ERROR_CLUSTER_SHARD_GONE, "no responsible shard found");
  REG_ERROR(ERROR_CLUSTER_CONNECTION_LOST, "cluster internal HTTP connection broken");
  REG_ERROR(ERROR_CLUSTER_MUST_NOT_SPECIFY_KEY, "must not specify _key for this collection");
  REG_ERROR(ERROR_CLUSTER_GOT_CONTRADICTING_ANSWERS, "got contradicting answers from different shards");
  REG_ERROR(ERROR_CLUSTER_NOT_ALL_SHARDING_ATTRIBUTES_GIVEN, "not all sharding attributes given");
  REG_ERROR(ERROR_CLUSTER_MUST_NOT_CHANGE_SHARDING_ATTRIBUTES, "must not change the value of a shard key attribute");
  REG_ERROR(ERROR_CLUSTER_UNSUPPORTED, "unsupported operation or parameter");
  REG_ERROR(ERROR_CLUSTER_ONLY_ON_COORDINATOR, "this operation is only valid on a coordinator in a cluster");
  REG_ERROR(ERROR_CLUSTER_READING_PLAN_AGENCY, "error reading Plan in agency");
  REG_ERROR(ERROR_CLUSTER_COULD_NOT_TRUNCATE_COLLECTION, "could not truncate collection");
  REG_ERROR(ERROR_CLUSTER_AQL_COMMUNICATION, "error in cluster internal communication for AQL");
  REG_ERROR(ERROR_AVOCADO_DOCUMENT_NOT_FOUND_OR_SHARDING_ATTRIBUTES_CHANGED, "document not found or sharding attributes changed");
  REG_ERROR(ERROR_CLUSTER_COULD_NOT_DETERMINE_ID, "could not determine my ID from my local info");
  REG_ERROR(ERROR_CLUSTER_ONLY_ON_DBSERVER, "this operation is only valid on a DBserver in a cluster");
  REG_ERROR(ERROR_CLUSTER_BACKEND_UNAVAILABLE, "A cluster backend which was required for the operation could not be reached");
  REG_ERROR(ERROR_CLUSTER_UNKNOWN_CALLBACK_ENDPOINT, "An endpoint couldn't be found");
  REG_ERROR(ERROR_CLUSTER_AGENCY_STRUCTURE_INVALID, "Invalid agency structure");
  REG_ERROR(ERROR_CLUSTER_AQL_COLLECTION_OUT_OF_SYNC, "collection is out of sync");
  REG_ERROR(ERROR_CLUSTER_COULD_NOT_CREATE_INDEX_IN_PLAN, "could not create index in plan");
  REG_ERROR(ERROR_CLUSTER_COULD_NOT_DROP_INDEX_IN_PLAN, "could not drop index in plan");
  REG_ERROR(ERROR_CLUSTER_CHAIN_OF_DISTRIBUTESHARDSLIKE, "chain of distributeShardsLike references");
  REG_ERROR(ERROR_CLUSTER_MUST_NOT_DROP_COLL_OTHER_DISTRIBUTESHARDSLIKE, "must not drop collection while another has a distributeShardsLike attribute pointing to it");
  REG_ERROR(ERROR_CLUSTER_UNKNOWN_DISTRIBUTESHARDSLIKE, "must not have a distributeShardsLike attribute pointing to an unknown collection");
  REG_ERROR(ERROR_CLUSTER_INSUFFICIENT_DBSERVERS, "the number of current dbservers is lower than the requested replicationFactor");
  REG_ERROR(ERROR_CLUSTER_COULD_NOT_DROP_FOLLOWER, "a follower could not be dropped in agency");
  REG_ERROR(ERROR_CLUSTER_SHARD_LEADER_REFUSES_REPLICATION, "a shard leader refuses to perform a replication operation");
  REG_ERROR(ERROR_CLUSTER_SHARD_FOLLOWER_REFUSES_OPERATION, "a shard follower refuses to perform an operation that is not a replication");
  REG_ERROR(ERROR_CLUSTER_SHARD_LEADER_RESIGNED, "a (former) shard leader refuses to perform an operation, because it has resigned in the meantime");
  REG_ERROR(ERROR_CLUSTER_DISTRIBUTE_SHARDS_LIKE_REPLICATION_FACTOR, "conflicting replication factor with distributeShardsLike parameter assignment");
  REG_ERROR(ERROR_CLUSTER_DISTRIBUTE_SHARDS_LIKE_NUMBER_OF_SHARDS, "conflicting shard number with distributeShardsLike parameter assignment");
  REG_ERROR(ERROR_CLUSTER_AGENCY_COMMUNICATION_FAILED, "some agency operation failed");
  REG_ERROR(ERROR_QUERY_KILLED, "query killed");
  REG_ERROR(ERROR_QUERY_PARSE, "%s");
  REG_ERROR(ERROR_QUERY_EMPTY, "query is empty");
  REG_ERROR(ERROR_QUERY_SCRIPT, "runtime error '%s'");
  REG_ERROR(ERROR_QUERY_NUMBER_OUT_OF_RANGE, "number out of range");
  REG_ERROR(ERROR_QUERY_VARIABLE_NAME_INVALID, "variable name '%s' has an invalid format");
  REG_ERROR(ERROR_QUERY_VARIABLE_REDECLARED, "variable '%s' is assigned multiple times");
  REG_ERROR(ERROR_QUERY_VARIABLE_NAME_UNKNOWN, "unknown variable '%s'");
  REG_ERROR(ERROR_QUERY_COLLECTION_LOCK_FAILED, "unable to read-lock collection %s");
  REG_ERROR(ERROR_QUERY_TOO_MANY_COLLECTIONS, "too many collections");
  REG_ERROR(ERROR_QUERY_DOCUMENT_ATTRIBUTE_REDECLARED, "document attribute '%s' is assigned multiple times");
  REG_ERROR(ERROR_QUERY_FUNCTION_NAME_UNKNOWN, "usage of unknown function '%s()'");
  REG_ERROR(ERROR_QUERY_FUNCTION_ARGUMENT_NUMBER_MISMATCH, "invalid number of arguments for function '%s()', expected number of arguments: minimum: %d, maximum: %d");
  REG_ERROR(ERROR_QUERY_FUNCTION_ARGUMENT_TYPE_MISMATCH, "invalid argument type in call to function '%s()'");
  REG_ERROR(ERROR_QUERY_INVALID_REGEX, "invalid regex value");
  REG_ERROR(ERROR_QUERY_BIND_PARAMETERS_INVALID, "invalid structure of bind parameters");
  REG_ERROR(ERROR_QUERY_BIND_PARAMETER_MISSING, "no value specified for declared bind parameter '%s'");
  REG_ERROR(ERROR_QUERY_BIND_PARAMETER_UNDECLARED, "bind parameter '%s' was not declared in the query");
  REG_ERROR(ERROR_QUERY_BIND_PARAMETER_TYPE, "bind parameter '%s' has an invalid value or type");
  REG_ERROR(ERROR_QUERY_INVALID_LOGICAL_VALUE, "invalid logical value");
  REG_ERROR(ERROR_QUERY_INVALID_ARITHMETIC_VALUE, "invalid arithmetic value");
  REG_ERROR(ERROR_QUERY_DIVISION_BY_ZERO, "division by zero");
  REG_ERROR(ERROR_QUERY_ARRAY_EXPECTED, "array expected");
  REG_ERROR(ERROR_QUERY_FAIL_CALLED, "FAIL(%s) called");
  REG_ERROR(ERROR_QUERY_GEO_INDEX_MISSING, "no suitable geo index found for geo restriction on '%s'");
  REG_ERROR(ERROR_QUERY_FULLTEXT_INDEX_MISSING, "no suitable fulltext index found for fulltext query on '%s'");
  REG_ERROR(ERROR_QUERY_INVALID_DATE_VALUE, "invalid date value");
  REG_ERROR(ERROR_QUERY_MULTI_MODIFY, "multi-modify query");
  REG_ERROR(ERROR_QUERY_INVALID_AGGREGATE_EXPRESSION, "invalid aggregate expression");
  REG_ERROR(ERROR_QUERY_COMPILE_TIME_OPTIONS, "query options must be readable at query compile time");
  REG_ERROR(ERROR_QUERY_EXCEPTION_OPTIONS, "query options expected");
  REG_ERROR(ERROR_QUERY_COLLECTION_USED_IN_EXPRESSION, "collection '%s' used as expression operand");
  REG_ERROR(ERROR_QUERY_DISALLOWED_DYNAMIC_CALL, "disallowed dynamic call to '%s'");
  REG_ERROR(ERROR_QUERY_ACCESS_AFTER_MODIFICATION, "access after data-modification by %s");
  REG_ERROR(ERROR_QUERY_FUNCTION_INVALID_NAME, "invalid user function name");
  REG_ERROR(ERROR_QUERY_FUNCTION_INVALID_CODE, "invalid user function code");
  REG_ERROR(ERROR_QUERY_FUNCTION_NOT_FOUND, "user function '%s()' not found");
  REG_ERROR(ERROR_QUERY_FUNCTION_RUNTIME_ERROR, "user function runtime error: %s");
  REG_ERROR(ERROR_QUERY_BAD_JSON_PLAN, "bad execution plan JSON");
  REG_ERROR(ERROR_QUERY_NOT_FOUND, "query ID not found");
  REG_ERROR(ERROR_QUERY_IN_USE, "query with this ID is in use");
  REG_ERROR(ERROR_CURSOR_NOT_FOUND, "cursor not found");
  REG_ERROR(ERROR_CURSOR_BUSY, "cursor is busy");
  REG_ERROR(ERROR_TRANSACTION_INTERNAL, "internal transaction error");
  REG_ERROR(ERROR_TRANSACTION_NESTED, "nested transactions detected");
  REG_ERROR(ERROR_TRANSACTION_UNREGISTERED_COLLECTION, "unregistered collection used in transaction");
  REG_ERROR(ERROR_TRANSACTION_DISALLOWED_OPERATION, "disallowed operation inside transaction");
  REG_ERROR(ERROR_TRANSACTION_ABORTED, "transaction aborted");
  REG_ERROR(ERROR_USER_INVALID_NAME, "invalid user name");
  REG_ERROR(ERROR_USER_INVALID_PASSWORD, "invalid password");
  REG_ERROR(ERROR_USER_DUPLICATE, "duplicate user");
  REG_ERROR(ERROR_USER_NOT_FOUND, "user not found");
  REG_ERROR(ERROR_USER_CHANGE_PASSWORD, "user must change his password");
  REG_ERROR(ERROR_SERVICE_INVALID_NAME, "invalid service name");
  REG_ERROR(ERROR_SERVICE_INVALID_MOUNT, "invalid mount");
  REG_ERROR(ERROR_SERVICE_DOWNLOAD_FAILED, "service download failed");
  REG_ERROR(ERROR_SERVICE_UPLOAD_FAILED, "service upload failed");
  REG_ERROR(ERROR_LDAP_CANNOT_INIT, "cannot init a LDAP connection");
  REG_ERROR(ERROR_LDAP_CANNOT_SET_OPTION, "cannot set a LDAP option");
  REG_ERROR(ERROR_LDAP_CANNOT_BIND, "cannot bind to a LDAP server");
  REG_ERROR(ERROR_LDAP_CANNOT_UNBIND, "cannot unbind from a LDAP server");
  REG_ERROR(ERROR_LDAP_CANNOT_SEARCH, "cannot issue a LDAP search");
  REG_ERROR(ERROR_LDAP_CANNOT_START_TLS, "cannot start a TLS LDAP session");
  REG_ERROR(ERROR_LDAP_FOUND_NO_OBJECTS, "LDAP didn't found any objects");
  REG_ERROR(ERROR_LDAP_NOT_ONE_USER_FOUND, "LDAP found zero ore more than one user");
  REG_ERROR(ERROR_LDAP_USER_NOT_IDENTIFIED, "LDAP found a user, but its not the desired one");
  REG_ERROR(ERROR_LDAP_INVALID_MODE, "invalid ldap mode");
  REG_ERROR(ERROR_TASK_INVALID_ID, "invalid task id");
  REG_ERROR(ERROR_TASK_DUPLICATE_ID, "duplicate task id");
  REG_ERROR(ERROR_TASK_NOT_FOUND, "task not found");
  REG_ERROR(ERROR_GRAPH_INVALID_GRAPH, "invalid graph");
  REG_ERROR(ERROR_GRAPH_COULD_NOT_CREATE_GRAPH, "could not create graph");
  REG_ERROR(ERROR_GRAPH_INVALID_VERTEX, "invalid vertex");
  REG_ERROR(ERROR_GRAPH_COULD_NOT_CREATE_VERTEX, "could not create vertex");
  REG_ERROR(ERROR_GRAPH_COULD_NOT_CHANGE_VERTEX, "could not change vertex");
  REG_ERROR(ERROR_GRAPH_INVALID_EDGE, "invalid edge");
  REG_ERROR(ERROR_GRAPH_COULD_NOT_CREATE_EDGE, "could not create edge");
  REG_ERROR(ERROR_GRAPH_COULD_NOT_CHANGE_EDGE, "could not change edge");
  REG_ERROR(ERROR_GRAPH_TOO_MANY_ITERATIONS, "too many iterations - try increasing the value of 'maxIterations'");
  REG_ERROR(ERROR_GRAPH_INVALID_FILTER_RESULT, "invalid filter result");
  REG_ERROR(ERROR_GRAPH_COLLECTION_MULTI_USE, "multi use of edge collection in edge def");
  REG_ERROR(ERROR_GRAPH_COLLECTION_USE_IN_MULTI_GRAPHS, "edge collection already used in edge def");
  REG_ERROR(ERROR_GRAPH_CREATE_MISSING_NAME, "missing graph name");
  REG_ERROR(ERROR_GRAPH_CREATE_MALFORMED_EDGE_DEFINITION, "malformed edge definition");
  REG_ERROR(ERROR_GRAPH_NOT_FOUND, "graph not found");
  REG_ERROR(ERROR_GRAPH_DUPLICATE, "graph already exists");
  REG_ERROR(ERROR_GRAPH_VERTEX_COL_DOES_NOT_EXIST, "vertex collection does not exist or is not part of the graph");
  REG_ERROR(ERROR_GRAPH_WRONG_COLLECTION_TYPE_VERTEX, "not a vertex collection");
  REG_ERROR(ERROR_GRAPH_NOT_IN_ORPHAN_COLLECTION, "not in orphan collection");
  REG_ERROR(ERROR_GRAPH_COLLECTION_USED_IN_EDGE_DEF, "collection already used in edge def");
  REG_ERROR(ERROR_GRAPH_EDGE_COLLECTION_NOT_USED, "edge collection not used in graph");
  REG_ERROR(ERROR_GRAPH_NOT_AN_AVOCADO_COLLECTION, " is not an AvocadoCollection");
  REG_ERROR(ERROR_GRAPH_NO_GRAPH_COLLECTION, "collection _graphs does not exist");
  REG_ERROR(ERROR_GRAPH_INVALID_EXAMPLE_ARRAY_OBJECT_STRING, "Invalid example type. Has to be String, Array or Object");
  REG_ERROR(ERROR_GRAPH_INVALID_EXAMPLE_ARRAY_OBJECT, "Invalid example type. Has to be Array or Object");
  REG_ERROR(ERROR_GRAPH_INVALID_NUMBER_OF_ARGUMENTS, "Invalid number of arguments. Expected: ");
  REG_ERROR(ERROR_GRAPH_INVALID_PARAMETER, "Invalid parameter type.");
  REG_ERROR(ERROR_GRAPH_INVALID_ID, "Invalid id");
  REG_ERROR(ERROR_GRAPH_COLLECTION_USED_IN_ORPHANS, "collection used in orphans");
  REG_ERROR(ERROR_GRAPH_EDGE_COL_DOES_NOT_EXIST, "edge collection does not exist or is not part of the graph");
  REG_ERROR(ERROR_GRAPH_EMPTY, "empty graph");
  REG_ERROR(ERROR_SESSION_UNKNOWN, "unknown session");
  REG_ERROR(ERROR_SESSION_EXPIRED, "session expired");
  REG_ERROR(SIMPLE_CLIENT_UNKNOWN_ERROR, "unknown client error");
  REG_ERROR(SIMPLE_CLIENT_COULD_NOT_CONNECT, "could not connect to server");
  REG_ERROR(SIMPLE_CLIENT_COULD_NOT_WRITE, "could not write to server");
  REG_ERROR(SIMPLE_CLIENT_COULD_NOT_READ, "could not read from server");
  REG_ERROR(COMMUNICATOR_REQUEST_ABORTED, "Request aborted");
  REG_ERROR(COMMUNICATOR_DISABLED, "Communication was disabled");
  REG_ERROR(ERROR_MALFORMED_MANIFEST_FILE, "failed to parse manifest file");
  REG_ERROR(ERROR_INVALID_SERVICE_MANIFEST, "manifest file is invalid");
  REG_ERROR(ERROR_SERVICE_FILES_MISSING, "service files missing");
  REG_ERROR(ERROR_SERVICE_FILES_OUTDATED, "service files outdated");
  REG_ERROR(ERROR_INVALID_FOXX_OPTIONS, "service options are invalid");
  REG_ERROR(ERROR_INVALID_MOUNTPOINT, "invalid mountpath");
  REG_ERROR(ERROR_SERVICE_NOT_FOUND, "service not found");
  REG_ERROR(ERROR_SERVICE_NEEDS_CONFIGURATION, "service needs configuration");
  REG_ERROR(ERROR_SERVICE_MOUNTPOINT_CONFLICT, "service already exists");
  REG_ERROR(ERROR_SERVICE_MANIFEST_NOT_FOUND, "missing manifest file");
  REG_ERROR(ERROR_SERVICE_OPTIONS_MALFORMED, "failed to parse service options");
  REG_ERROR(ERROR_SERVICE_SOURCE_NOT_FOUND, "source path not found");
  REG_ERROR(ERROR_SERVICE_SOURCE_ERROR, "error resolving source");
  REG_ERROR(ERROR_SERVICE_UNKNOWN_SCRIPT, "unknown script");
  REG_ERROR(ERROR_MODULE_NOT_FOUND, "cannot locate module");
  REG_ERROR(ERROR_MODULE_SYNTAX_ERROR, "syntax error in module");
  REG_ERROR(ERROR_MODULE_FAILURE, "failed to invoke module");
  REG_ERROR(ERROR_NO_SMART_COLLECTION, "collection is not smart");
  REG_ERROR(ERROR_NO_SMART_GRAPH_ATTRIBUTE, "smart graph attribute not given");
  REG_ERROR(ERROR_CANNOT_DROP_SMART_COLLECTION, "cannot drop this smart collection");
  REG_ERROR(ERROR_KEY_MUST_BE_PREFIXED_WITH_SMART_GRAPH_ATTRIBUTE, "in smart vertex collections _key must be prefixed with the value of the smart graph attribute");
  REG_ERROR(ERROR_ILLEGAL_SMART_GRAPH_ATTRIBUTE, "attribute cannot be used as smart graph attribute");
  REG_ERROR(ERROR_AGENCY_INFORM_MUST_BE_OBJECT, "Inform message must be an object.");
  REG_ERROR(ERROR_AGENCY_INFORM_MUST_CONTAIN_TERM, "Inform message must contain uint parameter 'term'");
  REG_ERROR(ERROR_AGENCY_INFORM_MUST_CONTAIN_ID, "Inform message must contain string parameter 'id'");
  REG_ERROR(ERROR_AGENCY_INFORM_MUST_CONTAIN_ACTIVE, "Inform message must contain array 'active'");
  REG_ERROR(ERROR_AGENCY_INFORM_MUST_CONTAIN_POOL, "Inform message must contain object 'pool'");
  REG_ERROR(ERROR_AGENCY_INFORM_MUST_CONTAIN_MIN_PING, "Inform message must contain object 'min ping'");
  REG_ERROR(ERROR_AGENCY_INFORM_MUST_CONTAIN_MAX_PING, "Inform message must contain object 'max ping'");
  REG_ERROR(ERROR_AGENCY_INFORM_MUST_CONTAIN_TIMEOUT_MULT, "Inform message must contain object 'timeoutMult'");
  REG_ERROR(ERROR_AGENCY_INQUIRE_CLIENT_ID_MUST_BE_STRING, "Inquiry failed");
  REG_ERROR(ERROR_AGENCY_CANNOT_REBUILD_DBS, "Cannot rebuild readDB and spearHead");
  REG_ERROR(ERROR_SUPERVISION_GENERAL_FAILURE, "general supervision failure");
  REG_ERROR(ERROR_DISPATCHER_IS_STOPPING, "dispatcher stopped");
  REG_ERROR(ERROR_QUEUE_UNKNOWN, "named queue does not exist");
  REG_ERROR(ERROR_QUEUE_FULL, "named queue is full");
}
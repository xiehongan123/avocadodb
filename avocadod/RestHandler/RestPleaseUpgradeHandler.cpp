////////////////////////////////////////////////////////////////////////////////
/// DISCLAIMER
///
/// Copyright 2014-2016 AvocadoDB GmbH, Cologne, Germany
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
/// @author Dr. Frank Celler
////////////////////////////////////////////////////////////////////////////////

#include "RestPleaseUpgradeHandler.h"

#include "Rest/HttpResponse.h"

using namespace avocadodb;
using namespace avocadodb::basics;
using namespace avocadodb::rest;

RestPleaseUpgradeHandler::RestPleaseUpgradeHandler(GeneralRequest* request,
                                                   GeneralResponse* response)
    : RestHandler(request, response) {}

bool RestPleaseUpgradeHandler::isDirect() const { return true; }

RestStatus RestPleaseUpgradeHandler::execute() {
  // TODO needs to generalized
  auto response = dynamic_cast<HttpResponse*>(_response.get());

  if (response == nullptr) {
    THROW_AVOCADO_EXCEPTION_MESSAGE(TRI_ERROR_INTERNAL, "invalid response type");
  }

  resetResponse(rest::ResponseCode::OK);
  response->setContentType(rest::ContentType::TEXT);

  auto& buffer = response->body();
  buffer.appendText("Database: ");
  buffer.appendText(_request->databaseName());
  buffer.appendText("\r\n\r\n");
  buffer.appendText("It appears that your database must be upgraded. ");
  buffer.appendText("Normally this can be done using\r\n\r\n");
  buffer.appendText("  /etc/init.d/avocadodb3 stop\r\n");
  buffer.appendText("  /etc/init.d/avocadodb3 upgrade\r\n");
  buffer.appendText("  /etc/init.d/avocadodb3 start\r\n\r\n");
  buffer.appendText("Please check the log file for details.\r\n");

  return RestStatus::DONE;
}

void RestPleaseUpgradeHandler::handleError(const Exception&) {}
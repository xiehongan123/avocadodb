
#include "icu-helper.h"
#include "ApplicationFeatures/LanguageFeature.h"
#include "Basics/Utf8Helper.h"
#include "Basics/directories.h"
#include "Basics/files.h"

#include <iostream>

static IcuInitializer theInstance; // must be here to call the dtor

bool IcuInitializer::initialized = false;
void* IcuInitializer::icuDataPtr = nullptr;
  
IcuInitializer::IcuInitializer() {}

IcuInitializer::~IcuInitializer() {
  if (icuDataPtr != nullptr) {
    TRI_Free(TRI_UNKNOWN_MEM_ZONE, icuDataPtr);
  }
  icuDataPtr = nullptr;
}
  
void IcuInitializer::setup(char const* path) {
  if (initialized) { 
    return;
  }
  initialized = true;
  std::string p;
  std::string binaryPath = TRI_LocateBinaryPath(path);
  icuDataPtr = avocadodb::LanguageFeature::prepareIcu(TEST_DIRECTORY, binaryPath, p, "basics_suite");
  if (icuDataPtr == nullptr ||
      !avocadodb::basics::Utf8Helper::DefaultUtf8Helper.setCollatorLanguage("", icuDataPtr)) {
    std::string msg =
      "cannot initialize ICU; please make sure ICU*dat is available; "
      "the variable ICU_DATA='";
    if (getenv("ICU_DATA") != nullptr) {
      msg += getenv("ICU_DATA");
    }
    msg += "' should point the directory containing the ICU*dat file. We searched here: " + p;
    std::cerr << msg << std::endl;
  }
}
//============================================================================
// Copyright   : This file is in the public domain
// Description : googlemock / googletest main file
//============================================================================

#include "gmock/gmock.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}

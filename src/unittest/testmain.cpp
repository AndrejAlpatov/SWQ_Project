//============================================================================
/// \addtogroup g_unittests
/// \{
/// \file
/// The googlemock / googletest main file.
/// As you may have guessed already, it contains the unit test main() function
/// and nothing else.
///
// Copyright   : This file is in the public domain
//============================================================================

#include "gmock/gmock.h"

/// The unit test main() function.
/// Not much to do here, just init Google Mock (which also inits Google Test)
/// giving it `argc` / `argv`, and then run the tests.
int main(int argc, char **argv) {
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}

/// \} // end of g_unittests

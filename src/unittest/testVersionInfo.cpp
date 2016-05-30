//============================================================================
/// \addtogroup g_unittests
/// \{
/// \file
/// Test accessing the generated version information.
// Copyright   : This file is in the public domain
//============================================================================

#include "Helpers.h"
#include "app-lib.h"
#include <gtest/gtest.h>
#include <iostream>

using namespace std;

/// \test
TEST(VersionInfo,getVersionIsNotEmpty) {
    QString version = VersionInfo::getVersion();
    cout << "[          ] Version: " << version.toStdString() << endl;

    ASSERT_FALSE( version.isEmpty() );
}

/// \test
TEST(VersionInfo,getVersionIsPrintable) {
    QString version = VersionInfo::getVersion();

    ASSERT_TRUE( Helpers::isPrintable(version) );
}

/// \test
TEST(VersionInfo,getBuildTagIsNotEmpty) {
    QString buildTag = VersionInfo::getBuildTag();

    ASSERT_FALSE( buildTag.isEmpty() );
}

/// \test
TEST(VersionInfo,getBuildTagIsPrintable) {
    QString buildTag = VersionInfo::getBuildTag();

    ASSERT_TRUE( Helpers::isPrintable(buildTag) );
}

/// \} // end g_unittests

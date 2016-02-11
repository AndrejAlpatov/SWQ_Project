//============================================================================
// Copyright   : This file is in the public domain
// Description : test generated version information
//============================================================================

#include "Helpers.h"
#include "app-lib.h"
#include <gtest/gtest.h>
#include <iostream>

using namespace std;

TEST(VersionInfo,getVersionIsNotEmpty) {
    QString version = VersionInfo::getVersion();
    cout << "[          ] Version: " << version.toStdString() << endl;

    ASSERT_FALSE( version.isEmpty() );
}

TEST(VersionInfo,getVersionIsPrintable) {
    QString version = VersionInfo::getVersion();

    ASSERT_TRUE( Helpers::isPrintable(version) );
}

TEST(VersionInfo,getBuildTagIsNotEmpty) {
    QString buildTag = VersionInfo::getBuildTag();

    ASSERT_FALSE( buildTag.isEmpty() );
}

TEST(VersionInfo,getBuildTagIsPrintable) {
    QString buildTag = VersionInfo::getBuildTag();

    ASSERT_TRUE( Helpers::isPrintable(buildTag) );
}

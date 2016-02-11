//============================================================================
// Copyright   : This file is in the public domain
// Description : test generated version information
//============================================================================

#include "AutoTest.h"
#include "Helpers.h"
#include "app-lib.h"

class TestVersionInfo: public QObject
{
    Q_OBJECT

  private slots:

    void getVersionIsNotEmpty()
    {
        QString version = VersionInfo::getVersion();
        qDebug() << "Version is" << version;

        QVERIFY( ! version.isEmpty() );
    }

    void getVersionIsPrintable()
    {
        QString version = VersionInfo::getVersion();

        QVERIFY( Helpers::isPrintable(version) );
    }

    void getBuildTagIsNotEmpty()
    {
        QString buildTag = VersionInfo::getBuildTag();

        QVERIFY( ! buildTag.isEmpty() );
    }

    void getBuildTagIsPrintable()
    {
        QString buildTag = VersionInfo::getBuildTag();

        QVERIFY( Helpers::isPrintable(buildTag) );
    }
};
AUTO_TEST_SUITE(TestVersionInfo);

#include "testVersionInfo.moc"

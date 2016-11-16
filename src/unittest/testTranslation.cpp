//============================================================================
/// \file
/// \ingroup    g_unittests
/// \brief      Test the Qt Translation System.
/// \copyright  GNU General Public License (GPL) Version 3
//============================================================================

#include "Helpers.h"
#include <gtest/gtest.h>
#include <QString>
#include <QObject>
#include <QTranslator>
#include <QCoreApplication>
#include <memory>

using namespace std;

/// \test Given no Translator, when we use tr() we expect to get the string unchanged.
TEST(Translation,withoutTranslator) {
    // Explicitely using QObject::tr is necessary outside of classes which
    // are derived from QObject, which is usually so for GUI classes.
    QString welcome = QObject::tr("Welcome!");

    EXPECT_EQ( welcome, "Welcome!" );
}


/// A test fixture for the following Translation tests.
/// We have to set up a QCoreApplication for every test, so we do it once here.
class TestTranslation : public ::testing::Test
{
    protected:
        unique_ptr<QCoreApplication> application;
        QTranslator translator;

        TestTranslation() {
            const char * argv[] = { "test", NULL };
            int argc = 1;
            application.reset( new QCoreApplication(argc, const_cast<char **>(argv)) );
        }
};

/// \test Given a German Translator, when we call tr() we expect to get a german string.
TEST_F(TestTranslation,toGerman) {
    ASSERT_TRUE(translator.load(":/translations/de_DE"));
    ASSERT_TRUE(application->installTranslator(&translator));

    QString welcome = QObject::tr("Welcome!");

    EXPECT_EQ( welcome, "Willkommen!" );
}

/// \test Given an English Translator, when we call tr() we expect to get an english string.
TEST_F(TestTranslation,toEnglish) {
    ASSERT_TRUE(translator.load(":/translations/en_US"));
    ASSERT_TRUE(application->installTranslator(&translator));

    QString welcome = QObject::tr("Welcome!");

    EXPECT_EQ( welcome, "Welcome!" );
}

/// \test Given a French Translator, when we call tr() we expect to get a french string.
TEST_F(TestTranslation,toFrench) {
    ASSERT_TRUE(translator.load(":/translations/fr_FR"));
    ASSERT_TRUE(application->installTranslator(&translator));

    QString welcome = QObject::tr("Welcome!");

    EXPECT_EQ( welcome, "Bienvenue!" );
}

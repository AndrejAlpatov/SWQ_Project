//============================================================================
/// \file
/// \ingroup    g_unittests
/// \brief      Test googletest framework behaviour.
/// \copyright  GNU General Public License (GPL) Version 3
//============================================================================

#include "Helpers.h"
#include <gtest/gtest.h>
#include <iostream>
using namespace std;

/// The test fixture to examine the behaviour of the Google Test framework.
/// Study the outputs when the test is executed.
class GoogleTest : public testing::Test {
    public:
        GoogleTest()
            : someAttributeWhichIsUsedInTestCases(0)
        {
            ++objectCount;
            objectNumber = objectCount;
            cout << "[v v v v v ] Constructor of fixture object " << objectNumber << endl;
        }

        ~GoogleTest()
        {
            cout << "[^ ^ ^ ^ ^ ] Destructor of fixture object " << objectNumber << endl;
        }

        // This function is called by the test framework once before all tests (TEST_F).
        // It must be static.
        static void SetUpTestSuite() {
            cout << "[vvvvvvvvvv] SetUpTestSuite() with objectCount=" << objectCount << endl;
        }

        // This function is called by the test framework once after all tests (TEST_F).
        // It must be static.
        static void TearDownTestSuite() {
            cout << "[^^^^^^^^^^] TearDownTestSuite() with objectCount=" << objectCount << endl;
        }

        // This function is called before every test (TEST_F).
        // You won't need it if you can use the constructor.
        void SetUp() override {
            cout << "[ v v v v v] Setup() for fixture object " << objectNumber << endl;
        }

        // This function is called after every test (TEST_F).
        // You won't need it if you can use the destructor.
        void TearDown() override {
            cout << "[ ^ ^ ^ ^ ^] TearDown() for fixture object " << objectNumber << endl;
        }

    protected:
        int objectNumber;
        int someAttributeWhichIsUsedInTestCases;

    private:
        static int objectCount;
};
int GoogleTest::objectCount = 0;

/// \test Run the first test using the GoogleTest fixture.
TEST_F(GoogleTest, Test1) {
    cout << "[  ?  ?  ? ] inside Test1 with fixture object " << objectNumber << endl;

    ASSERT_EQ(0, someAttributeWhichIsUsedInTestCases);
    someAttributeWhichIsUsedInTestCases=1;
    ASSERT_EQ(1, someAttributeWhichIsUsedInTestCases);
    ASSERT_EQ(1, objectNumber);
}

/// \test Run the second test using the GoogleTest fixture.
/// It checks whether a fresh new test object was created to run this method.
TEST_F(GoogleTest, Test2) {
    cout << "[  ?  ?  ? ] inside Test2 with fixture object " << objectNumber << endl;
    ASSERT_EQ(0, someAttributeWhichIsUsedInTestCases);
    ASSERT_EQ(2, objectNumber);
}

/// \test Compare char* with std::string
TEST(ExpectEq, canCompareCharPointerWithString) {
    const char * charPointer = "Hello String";
    std::string stdString(charPointer);
    // try this and watch error output:
    // stdString += "Oops";

    EXPECT_EQ(stdString, charPointer);
    EXPECT_EQ(charPointer, stdString);
    EXPECT_NE(stdString, charPointer+1);
    EXPECT_NE(charPointer+1, stdString);
}

/// \test Compare two wchar_t*
TEST(ExpectStreq, canCompareWCharPointers) {
    const wchar_t * wcharPointer1 = L"Hello String äöüß €©";
    const wchar_t * wcharPointer2 = wcharPointer1;

    // try this and watch error output:
    // wcharPointer2++;

    EXPECT_STREQ(wcharPointer1, wcharPointer2);
    EXPECT_STRNE(wcharPointer1, wcharPointer2+1);
}

/// \test Compare wchar_t* with std::wstring
TEST(ExpectEq, canCompareWCharPointerWithWString) {
    const wchar_t * wcharPointer = L"Hello String äöüß €©";
    std::wstring stdWString(wcharPointer);
    // try this and watch error output:
    // stdWString += L"Oops";

    EXPECT_EQ(stdWString, wcharPointer);
    EXPECT_EQ(wcharPointer, stdWString);
    EXPECT_NE(stdWString, wcharPointer+1);
    EXPECT_NE(wcharPointer+1, stdWString);
}

/// \test Compare char* with QString
TEST(ExpectEq, canCompareCharPointerWithQString) {
    const char * charPointer = "Hello String";
    QString qString(charPointer);
    // try this and watch error output:
    // qString += "Oops";

    EXPECT_EQ(qString, charPointer);
    EXPECT_EQ(charPointer, qString);
    EXPECT_NE(qString, charPointer+1);
    EXPECT_NE(charPointer+1, qString);
}

/// \test Compare std::string with QString
TEST(ExpectEq, canCompareStringWithQString) {
    const char * hello = "Hello String";
    std::string stdString(hello);
    QString qString(hello);
    // try this and watch error output:
    // qString += "Oops";

    // Note: do not use EXPECT_STREQ here!!
    EXPECT_EQ(qString, stdString);
    EXPECT_EQ(stdString, qString);
    EXPECT_NE(qString, stdString+"a");
    EXPECT_NE(stdString, qString+"a");
}

/// \test Compare std::string with Qstring
TEST(ExpectEq, canCompareWStringWithQString) {
    const wchar_t * hello = L"Hello String ©€";
    std::wstring stdWString(hello);
    QString qString = QString::fromStdWString(hello);
    // try this and watch error output:
    // qString += "Oops";

    // Note: do not use EXPECT_STREQ here!!
    EXPECT_EQ(qString, stdWString);
    EXPECT_EQ(stdWString, qString);
    EXPECT_NE(qString+"a", stdWString);
    EXPECT_NE(stdWString+L"a", qString);
}

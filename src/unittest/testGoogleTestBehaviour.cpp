//============================================================================
// Copyright   : This file is in the public domain
// Description : test googletest framework behaviour
//============================================================================

#include "gtest/gtest.h"
#include <iostream>
using namespace std;

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
        static void SetUpTestCase() {
            cout << "[vvvvvvvvvv] SetUpTestCase() with objectCount=" << objectCount << endl;
        }

        // This function is called by the test framework once after all tests (TEST_F).
        // It must be static.
        static void TearDownTestCase() {
            cout << "[^^^^^^^^^^] TearDownTestCase() with objectCount=" << objectCount << endl;
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

TEST_F(GoogleTest, Test1) {
    cout << "[  ?  ?  ? ] inside Test1 with fixture object " << objectNumber << endl;

    ASSERT_EQ(0, someAttributeWhichIsUsedInTestCases);
    someAttributeWhichIsUsedInTestCases=1;
    ASSERT_EQ(1, someAttributeWhichIsUsedInTestCases);
    ASSERT_EQ(1, objectNumber);
}

TEST_F(GoogleTest, Test2) {
    cout << "[  ?  ?  ? ] inside Test2 with fixture object " << objectNumber << endl;
    ASSERT_EQ(0, someAttributeWhichIsUsedInTestCases);
    ASSERT_EQ(2, objectNumber);
}

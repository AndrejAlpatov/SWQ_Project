//============================================================================
// Copyright   : This file is in the public domain
// Description : test googlemock framework behaviour
//============================================================================

#include "gtest/gtest.h"
#include "gmock/gmock.h"
using namespace testing;

#include <iostream>
using namespace std;

//============================================================================
// This is the "production code" class, which shall be replaced by a mock.
// Usually, this class will be in a header file which can be included here.
//============================================================================
class SomeHelper {
    public:
        // Note that the interface methods must be virtual, otherwise we
        // cannot mock this class ...
        SomeHelper() {
            cout << "[v v v v v ] Constructor of base object" << endl;
        }

        virtual ~SomeHelper() {
            cout << "[^ ^ ^ ^ ^ ] Destructor of base object " << endl;
        }

        virtual void a() {
            cout << "[!?!?!?!?!?] SomeUsefulThing.a() called" << endl;
        }

        virtual int b(int val) const {
            cout << "[!?!?!?!?!?] SomeUsefulThing.b() called" << endl;
            return val+1;
        }
};

//============================================================================
// This is the "production code" class, which shall be tested.
// Usually, this class will be in a header file which can be included here.
// This class uses SomeHelper.
//============================================================================
class SomeThing {
    public:
        SomeThing(SomeHelper & helper)
            : helpMeWith(helper)
        {}

        int go() {
            helpMeWith.a();
            return helpMeWith.b(2);
        }

    private:
        SomeHelper & helpMeWith;
};

//============================================================================
// This is the mock of SomeHelper
//============================================================================
class MockOfSomeHelper : public SomeHelper {
    public:
        MOCK_METHOD0(a, void());
        MOCK_CONST_METHOD1(b, int(int));  // unfortunately QtCreator's editor marks this as error
};

//============================================================================
// This is the test fixture, and also gives the name prefix for the tests
//============================================================================
class aSomeThing : public ::testing::Test {
    protected:
        aSomeThing()
            : someThing(helperMock)
        {}

        MockOfSomeHelper helperMock;
        SomeThing someThing;
};

TEST_F(aSomeThing, callsHelperAandReturnsValOfB) {
    EXPECT_CALL(helperMock, a());
    EXPECT_CALL(helperMock, b(_))
            .WillOnce(Return(3));

    ASSERT_EQ(3, someThing.go());
}

TEST(anotherSomeThing, callsHelperA) {
    NiceMock<MockOfSomeHelper> niceHelperMock;
    SomeThing someThing(niceHelperMock);
    EXPECT_CALL(niceHelperMock, a());

    (void) someThing.go();
}

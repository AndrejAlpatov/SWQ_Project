//============================================================================
/// \file
/// \ingroup    g_unittests
/// \brief      Test googlemock framework behaviour.
/// \copyright  GNU General Public License (GPL) Version 3
//============================================================================

#include "gtest/gtest.h"
#include "gmock/gmock.h"
using namespace testing;

#include <iostream>
using namespace std;

//============================================================================
/// This is the "production code" class, which shall be replaced by a mock.
/// Usually, this class will be in a header file which can be included here.
//============================================================================
class SomeHelper {
    public:
        // Note that the interface methods must be virtual, otherwise we
        // cannot mock this class ...
        SomeHelper() {
            cout << "[v v v v v ] Constructor of base object" << endl;
        }

        virtual ~SomeHelper();

        virtual void a() {
            cout << "[!?!?!?!?!?] SomeUsefulThing.a() called" << endl;
        }

        virtual int b(int val) const {
            cout << "[!?!?!?!?!?] SomeUsefulThing.b() called" << endl;
            return val+1;
        }
};
// kept outside the class declaration to avoid error messages in QtCreator
SomeHelper::~SomeHelper() {
    cout << "[^ ^ ^ ^ ^ ] Destructor of base object " << endl;
}

//============================================================================
/// This is the "production code" class, which shall be tested.´
/// Usually, this class will be in a header file which can be included here.
/// This class uses the SomeHelper object which is injected via the constructor.
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
/// This is the mock of SomeHelper.
//============================================================================
class MockOfSomeHelper : public SomeHelper {
    public:
        ~MockOfSomeHelper();    // just to avoid error messages in QtCreator
        MOCK_METHOD0(a, void());
        MOCK_CONST_METHOD1(b, int(int));
};
MockOfSomeHelper::~MockOfSomeHelper() {
    // nothing else needed, just to avoid error messages in QtCreator
}

//============================================================================
/// This is the test fixture, and it also gives the name prefix for the tests.
//============================================================================
class aSomeThing : public ::testing::Test {
    protected:
        aSomeThing()
            : someThing(helperMock) {
            // nothing else needed
        }
        ~aSomeThing();    // just to avoid error messages in QtCreator

        MockOfSomeHelper helperMock;
        SomeThing someThing;
};
aSomeThing::~aSomeThing() {
    // nothing else needed, just to avoid error messages in QtCreator
}

/// \test Test that SomeThing::go() calls SomeHelper::a() and SomeHelper::b().
/// The initialization of someThing is done in the test fixture aSomeThing.
TEST_F(aSomeThing, callsHelperAandReturnsValOfB) {
    EXPECT_CALL(helperMock, a());
    EXPECT_CALL(helperMock, b(_))
            .WillOnce(Return(3));

    ASSERT_EQ(3, someThing.go());
}

/// \test Test that SomeThing::go() calls SomeHelper::a().
/// Essentially the same as in the test above, but using NiceMock which allows
/// calls of "uninteresting" calls. See the Google Mock documentation for
/// details on it's behaviour.
TEST(anotherSomeThing, callsHelperA) {
    NiceMock<MockOfSomeHelper> niceHelperMock;
    SomeThing someThing(niceHelperMock);
    EXPECT_CALL(niceHelperMock, a());

    (void) someThing.go();
}

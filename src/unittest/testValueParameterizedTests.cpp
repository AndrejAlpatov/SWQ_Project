//============================================================================
/// \file
/// \ingroup    g_unittests
/// \brief      Test googletest value parameterized test support.
/// \details    See section _Value Parameterized Tests_ in Goolge Test
///             [Advanced Guide|https://atlas.ai.it.hs-worms.de/bitbucket/projects/TST/repos/googletest/raw/googletest/docs/AdvancedGuide.md]
/// \copyright  GNU General Public License (GPL) Version 3
//============================================================================

#include "Helpers.h"
#include <gtest/gtest.h>
#include <vector>

using namespace std;

/// This simple function is our example of the Software Under Test (SUT).
/// \return the sum of \param a and \param b
int add(int a, int b)
{
    int result = a+b;
    // result += 1;        // uncomment to see error messages of the tests!
    return result;
}


/// We can transfer ONE value to the test only, so we need a type
/// to collect all the parameters (data + expected result) of the tests.
struct AdderTestData {
    int a;
    int b;
    int expectedResult;
};

/// Define a output operator to get readable output in case of failures
ostream & operator << (ostream & os, AdderTestData const & data) {
    os << "{a=" << data.a << ", b=" << data.b
       << ", expectedResult=" << data.expectedResult << "}";
    return os;
}


/// Then we can create a test fixture class for this TestData type.
class AdderTest : public ::testing::TestWithParam<AdderTestData> {
    // You can implement all the usual fixture class members here.
    // To access the test parameter, call GetParam() from this class.
};


/// Now we can define the generic test using TEST_P
TEST_P(AdderTest, addsAandB) {
    AdderTestData testData = GetParam();

    EXPECT_EQ(add(testData.a,testData.b), testData.expectedResult);
}


// Call all TEST_P tests with data using INSTANTIATE_TEST_CASE_P:
INSTANTIATE_TEST_CASE_P(SingleDigits, AdderTest,
                        ::testing::Values(
                            AdderTestData{1, 1, 2},
                            AdderTestData{1, 2, 3}
                            )
                        );

// You can instantiate the tests multiple times, but the prefix
// (here: TeenValues) has to be uniq.
INSTANTIATE_TEST_CASE_P(TeenValues, AdderTest,
                        ::testing::Values(
                            AdderTestData{10, 11, 21},
                            AdderTestData{11, 12, 23}
                            )
                        );

// You can also read from a STL container or C array.
vector<AdderTestData> dataContainer = {
    { 20, 22, 42 },
    { 31, 33, 64 }
};

INSTANTIATE_TEST_CASE_P(FromVector, AdderTest,
                        ::testing::ValuesIn(dataContainer));


/// We can also use the tuple<> template to combine parameters,
/// though it's not so easy to read.
class AdderTestWithTuple : public ::testing::TestWithParam<::testing::tuple<int,int> > {
    // You can implement all the usual fixture class members here.
    // To access the test parameter, call GetParam() from this class.
};


/// Now we can define the generic test using TEST_P
TEST_P(AdderTestWithTuple, addsAandB) {
    ::testing::tuple<int,int> testData = GetParam();
    int a = ::testing::get<0>(testData);
    int b = ::testing::get<1>(testData);

    EXPECT_EQ(add(a, b), a+b);
}

// Or define some ranges
INSTANTIATE_TEST_CASE_P(WithRange, AdderTestWithTuple,
                        ::testing::Combine(
                                ::testing::Range(10,20,2),
                                ::testing::Range(30,40,2)
                            )
                        );

/// \test

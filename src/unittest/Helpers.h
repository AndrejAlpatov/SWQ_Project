//============================================================================
/// \addtogroup g_unittests
/// \{
/// \file
/// Test helper functions.
// Copyright   : This file is in the public domain
//============================================================================

#ifndef HELPERS_H
#define HELPERS_H

#include <QString>

namespace Helpers {

    /// Tests whether each character inside str is printable.
    inline
    bool isPrintable(const QString &str) {
        for(auto ch: str)
            if( ! ch.isPrint() )
                return false;

        return true;
    }
}

#include <gtest/gtest.h>
// add googletest helpers for QString
namespace testing {
    namespace internal {
        // Helper functions for ASSERT_STREQ / EXPECT_STREQ on QStrings.
        inline
        AssertionResult CmpHelperSTREQ(const char* expected_expression,
                                       const char* actual_expression,
                                       const char* expected,
                                       const QString & actual) {
            return CmpHelperSTREQ(expected_expression, actual_expression, expected, actual.toUtf8().data());
        }

        inline
        AssertionResult CmpHelperSTREQ(const char* expected_expression,
                                       const char* actual_expression,
                                       const QString & expected,
                                       const char* actual) {
            return CmpHelperSTREQ(expected_expression, actual_expression, expected.toUtf8().data(), actual);
        }

        inline
        AssertionResult CmpHelperSTREQ(const char* expected_expression,
                                       const char* actual_expression,
                                       const QString & expected,
                                       const QString & actual) {
            return CmpHelperSTREQ(expected_expression, actual_expression, expected.toUtf8().data(), actual.toUtf8().data());
        }

        // Helper functions for ASSERT_STRNE / EXPECT_STRNE on QStrings.
        inline
        AssertionResult CmpHelperSTRNE(const char* expected_expression,
                                       const char* actual_expression,
                                       const char* expected,
                                       const QString & actual) {
            return CmpHelperSTRNE(expected_expression, actual_expression, expected, actual.toUtf8().data());
        }

        inline
        AssertionResult CmpHelperSTRNE(const char* expected_expression,
                                       const char* actual_expression,
                                       const QString & expected,
                                       const char* actual) {
            return CmpHelperSTRNE(expected_expression, actual_expression, expected.toUtf8().data(), actual);
        }

        inline
        AssertionResult CmpHelperSTRNE(const char* expected_expression,
                                       const char* actual_expression,
                                       const QString & expected,
                                       const QString & actual) {
            return CmpHelperSTRNE(expected_expression, actual_expression, expected.toUtf8().data(), actual.toUtf8().data());
        }
    }
}

#endif // HELPERS_H
/// \} // end g_unittests

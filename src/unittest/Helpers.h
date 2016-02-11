//============================================================================
// Copyright   : This file is in the public domain
// Description : Helper functions
//============================================================================

#ifndef HELPERS_H
#define HELPERS_H

#include <QString>

namespace Helpers {
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
        // Helper function for *_STREQ on QStrings.
        inline
        AssertionResult CmpHelperSTREQ(const char* expected_expression,
                                       const char* actual_expression,
                                       const char* expected,
                                       const QString & actual) {
            if (expected == actual.toStdString()) {
                return AssertionSuccess();
            }

            return EqFailure(expected_expression,
                             actual_expression,
                             PrintToString(expected),
                             PrintToString(actual.toStdString()),
                             false);
        }
    }
}

#endif // HELPERS_H

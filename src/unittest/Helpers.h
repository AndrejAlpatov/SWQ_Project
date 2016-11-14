//============================================================================
/// \file
/// \ingroup    g_unittests
/// \brief      Test helper functions.
/// \copyright  GNU General Public License (GPL) Version 3
//============================================================================
#ifndef HELPERS_H
#define HELPERS_H

#include <QString>
#include <iostream>
#include <memory>

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
// additional googletest helpers for QString, string and nullptr_t
namespace testing {
    namespace internal {
        // Helper functions for ASSERT_STREQ / EXPECT_STREQ of char* with QStrings.
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

        // Helper functions for ASSERT_STRNE / EXPECT_STRNE of char* with QStrings.
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

        // Helper functions for ASSERT_STREQ / EXPECT_STREQ of char* with std::strings.
        inline
        AssertionResult CmpHelperSTREQ(const char* expected_expression,
                                       const char* actual_expression,
                                       const std::string & expected,
                                       const char* actual) {
            return CmpHelperSTREQ(expected_expression, actual_expression, expected.c_str(), actual);
        }

        inline
        AssertionResult CmpHelperSTREQ(const char* expected_expression,
                                       const char* actual_expression,
                                       const char* expected,
                                       const std::string & actual) {
            return CmpHelperSTREQ(expected_expression, actual_expression, expected, actual.c_str());
        }

        // Helper functions for ASSERT_STRNE / EXPECT_STRNE of char* with std::strings.
        inline
        AssertionResult CmpHelperSTRNE(const char* expected_expression,
                                       const char* actual_expression,
                                       const std::string & expected,
                                       const char* actual) {
            return CmpHelperSTRNE(expected_expression, actual_expression, expected.c_str(), actual);
        }

        inline
        AssertionResult CmpHelperSTRNE(const char* expected_expression,
                                       const char* actual_expression,
                                       const char* expected,
                                       const std::string & actual) {
            return CmpHelperSTRNE(expected_expression, actual_expression, expected, actual.c_str());
        }

        // Helper functions for ASSERT_STREQ / EXPECT_STREQ of wchar_t* with std::wstrings.
        inline
        AssertionResult CmpHelperSTREQ(const char* expected_expression,
                                       const char* actual_expression,
                                       const std::wstring & expected,
                                       const wchar_t* actual) {
            return CmpHelperSTREQ(expected_expression, actual_expression, expected.c_str(), actual);
        }

        inline
        AssertionResult CmpHelperSTREQ(const char* expected_expression,
                                       const char* actual_expression,
                                       const wchar_t* expected,
                                       const std::wstring & actual) {
            return CmpHelperSTREQ(expected_expression, actual_expression, expected, actual.c_str());
        }

        // Helper functions for ASSERT_STRNE / EXPECT_STRNE of char* with std::strings.
        inline
        AssertionResult CmpHelperSTRNE(const char* expected_expression,
                                       const char* actual_expression,
                                       const std::wstring & expected,
                                       const wchar_t* actual) {
            return CmpHelperSTRNE(expected_expression, actual_expression, expected.c_str(), actual);
        }

        inline
        AssertionResult CmpHelperSTRNE(const char* expected_expression,
                                       const char* actual_expression,
                                       const wchar_t* expected,
                                       const std::wstring & actual) {
            return CmpHelperSTRNE(expected_expression, actual_expression, expected, actual.c_str());
        }

        // Helper functions for {ASSERT|EXPECT}_{EQ|NE} on nullptr_t.
        template <>
        inline
        AssertionResult CmpHelperEQ<long int, std::nullptr_t>
                                    (const char* lhs_expression,
                                    const char* rhs_expression,
                                    const long int & lhs,
                                    const std::nullptr_t & ) {
            return CmpHelperEQ(lhs_expression, rhs_expression, lhs, 0);
        }
        template <>
        inline
        AssertionResult CmpHelperNE<long int, std::nullptr_t>
                                    (const char* lhs_expression,
                                    const char* rhs_expression,
                                    const long int & lhs,
                                    const std::nullptr_t & ) {
            return CmpHelperNE(lhs_expression, rhs_expression, lhs, 0);
        }

        // Helper functions for {ASSERT|EXPECT}_{EQ|NE} on shared_ptr<> vs. nullptr_t.
        template <typename T>
        inline
        AssertionResult CmpHelperEQ(const char* lhs_expression,
                                    const char* rhs_expression,
                                    const std::shared_ptr<T> & lhs,
                                    const std::nullptr_t & rhs) {
            return CmpHelperEQ(lhs_expression, rhs_expression, lhs.get(), rhs);
        }
        template <typename T>
        inline
        AssertionResult CmpHelperNE(const char* lhs_expression,
                                    const char* rhs_expression,
                                    const std::shared_ptr<T> & lhs,
                                    const std::nullptr_t & rhs) {
            return CmpHelperNE(lhs_expression, rhs_expression, lhs.get(), rhs);
        }
    }
}

/// Comparison between QString and std::string
inline
bool operator==(const QString & q, const std::string & s) {
    return q.toStdString() == s;
}

inline
bool operator==(const std::string & s, const QString & q) {
    return q.toStdString() == s;
}

inline
bool operator!=(const QString & q, const std::string & s) {
    return q.toStdString() != s;
}

inline
bool operator!=(const std::string & s, const QString & q) {
    return q.toStdString() != s;
}

/// Comparison between QString and std::wstring
inline
bool operator==(const QString & q, const std::wstring & s) {
    return q.toStdWString() == s;
}

inline
bool operator==(const std::wstring & s, const QString & q) {
    return q.toStdWString() == s;
}

inline
bool operator!=(const QString & q, const std::wstring & s) {
    return q.toStdWString() != s;
}

inline
bool operator!=(const std::wstring & s, const QString & q) {
    return q.toStdWString() != s;
}

/// Google Test Print Function for QString
inline
void PrintTo (const QString & s, ::std::ostream * os) {
    *os << '"' << s.toStdString() << '"';
}

#endif // HELPERS_H

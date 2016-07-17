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

#endif // HELPERS_H
/// \} // end g_unittests

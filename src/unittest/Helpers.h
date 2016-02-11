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

#endif // HELPERS_H

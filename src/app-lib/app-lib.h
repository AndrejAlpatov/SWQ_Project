//============================================================================
// Name           : app-lib.h
// Copyright      : GNU General Public License (GPL) Version 3
// Description    : application library interface definition
//============================================================================
#if !defined(APPLIB_H)
#define APPLIB_H

#include <QString>

class VersionInfo
{
    public:
        static QString getVersion();
        static QString getBuildTag();

    private:
        static const QString buildTag;
        static const QString version;
};

#endif

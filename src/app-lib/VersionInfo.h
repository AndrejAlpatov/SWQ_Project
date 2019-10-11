//============================================================================
/// \file
/// \ingroup    g_applib
/// \brief      Contains the application library VersionInfo interface definition.
/// \details    In this example it's only the simple class VersionInfo.
/// \copyright  GNU General Public License (GPL) Version 3
//============================================================================
#if !defined(VersionInfo_H)
#define VersionInfo_H

#include <QString>

/// Provide version information generated by the build process.
/// This class provides access to the build and version information
/// generated automatically during the build process.
/// As this is static information only, the class only has static (class level)
/// members and methods.
class VersionInfo
{
    public:
        static QString getVersion();    ///< Get the version provided by git.
        static QString getBuildTag();   ///< Get the build tag provided by jenkins.
        static QString getBranchName(); ///< Get the currentbranch name.

    private:
        static const QString buildTag;
        static const QString version;
        static const QString branch;
};

#endif

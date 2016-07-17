//============================================================================
/// \addtogroup g_applib
/// \{
/// \file
/// Contains the application library implementation.
//
// Copyright      : GNU General Public License (GPL) Version 3
//============================================================================

#include "app-lib.h"
#include "generated-version.h"

const QString VersionInfo::buildTag(BUILDTAG);
const QString VersionInfo::version(GITVERSION);

QString VersionInfo::getVersion()
{
    return version;
}

QString VersionInfo::getBuildTag()
{
    return buildTag;
}

/// \}  // end of g_applib

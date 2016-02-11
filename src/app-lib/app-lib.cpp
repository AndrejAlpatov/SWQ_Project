//============================================================================
// Name           : app-lib.cpp
// Copyright      : GNU General Public License (GPL) Version 3
// Description    : application library implementation
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

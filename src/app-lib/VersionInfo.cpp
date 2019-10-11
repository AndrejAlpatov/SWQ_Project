//============================================================================
/// \file
/// \ingroup    g_applib
/// \brief      Contains the VersionInfo implementation parts.
/// \copyright  GNU General Public License (GPL) Version 3
//============================================================================

#include "VersionInfo.h"
#include "generated-version.h"

const QString VersionInfo::buildTag(BUILDTAG);
const QString VersionInfo::version(GITVERSION);
const QString VersionInfo::branch(BRANCH);

QString VersionInfo::getVersion()
{
    return version;
}

QString VersionInfo::getBuildTag()
{
    return buildTag;
}

QString VersionInfo::getBranchName()
{
    return branch;
}

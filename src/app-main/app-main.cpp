//============================================================================
/// \addtogroup g_main
/// \{
/// \file
/// Contains the application's main function.
//
// Copyright:   GNU General Public License (GPL) Version 3
//============================================================================

#include "app-lib.h"
#include <iostream>
using namespace std;

/// Our little main() function.
/// Not much is happening here, it's just a "hello world". We do not even
/// create objects here, we just call some static class member functions,
/// as you can see here:
int main()
{
	cout << "Hello Application World!" << endl
             << "Version: " << VersionInfo::getVersion().toStdString()
             << " (" << VersionInfo::getBuildTag().toStdString() << ")" << endl;
}

/// \}  // end of g_main

//============================================================================
// Name           : app-main.cpp
// Copyright      : GNU General Public License (GPL) Version 3
// Description    : application main function
//============================================================================

#include "app-lib.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "Hello Application World!" << endl
             << "Version: " << VersionInfo::getVersion().toStdString()
             << " (" << VersionInfo::getBuildTag().toStdString() << ")" << endl;
}

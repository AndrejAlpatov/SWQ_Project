//============================================================================
/// \file       Test for SpyUI
/// \ingroup    g_unittests
/// \brief      Unit and Integration Tests of class TextUI
/// \copyright  GNU General Public License (GPL) Version 3
//============================================================================

#include "app-lib/app-lib.h"
#include "Helpers.h"
#include <gtest/gtest.h>
#include <iostream>
#include <QString>      //fuer QString TEST

/// \test
TEST(TextUI, CanBeInstantiated){

    //Setup
    TextUI ui;

    //Execute
    (void)ui;

    //Verify
    //Teardown
}

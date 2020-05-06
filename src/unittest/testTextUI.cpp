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
TEST(TextUI, CanBeInstantiatedWthInputOutputStreams){

    //Setup
    wistringstream someInputStream;
    wostringstream someOutputstream;

    //Execute
    TextUI ui(someInputStream, someOutputstream);
    (void)ui;

    //Verify
    //Teardown
}

/// \test
TEST(PlayingField, canSayWelcome){

    //Setup
    const wstring hello(L"Welcome to 2048\n");
    wostringstream output;
    wistringstream emptyInput;
    TextUI textui(emptyInput, output);


    //Execute
    textui.sayWelcome();

    //Verify
    EXPECT_EQ(output.str().substr(0,hello.size()),hello);
}

//============================================================================
/// \file       Test for PlayingFeld.h
/// \ingroup    g_unittests
/// \brief      Test accessing the generated version information.
/// \copyright  GNU General Public License (GPL) Version 3
//============================================================================

#include "app-lib/app-lib.h"
#include "Helpers.h"
#include <gtest/gtest.h>
#include <iostream>
#include <QString>      //fuer QString TEST

/// \test
TEST(TestPlayingField,SearchForFreePlayingFieldUnreal) {
    //Arrange
    PlayingField field;
    const int unset =-1;

    //Act
    field.setAlleFelderBesetzt();

    //Act && Assert

    ASSERT_EQ(field.freiFeldSuche()[0], unset);
    ASSERT_EQ(field.freiFeldSuche()[1], unset);
}

TEST(TestPlayingField,SearchForFreePlayingFieldReal) {
    //Arrange
    PlayingField field;
    const int unset =-1;

    //Act
    field.setAlleFelderBesetzt();
    field.setEinFeldFrei();

    //Act && Assert

    ASSERT_NE(field.freiFeldSuche()[0], unset);
    ASSERT_NE(field.freiFeldSuche()[1], unset);
}

/// \test
TEST(wcharPointer, CanBeCompared){
    wchar_t const * pointerHello = L"Hello ©";
    wchar_t const * pointerWorld = L"World €";

    EXPECT_STRNE(pointerHello,pointerWorld);

    pointerHello=pointerWorld;
    EXPECT_STREQ(pointerHello,pointerWorld);
}

/// \test
TEST(wString, CanBeCompared){
    wstring wStringHello = L"Hello ©";
    wchar_t const * pointerWorld = L"World €";

    EXPECT_NE(wStringHello,pointerWorld);   //EXPECT_NE und nicht EXPECTSTRNE while pointerhello
                                            //kein Pointer oder White character Pointer ist
}

/// \test
TEST(QString, CanBeComparedtoWstring){
    wstring wStringHello(L"Hello ©");
    QString qStringWorld("World €");

    EXPECT_NE(wStringHello,qStringWorld);

}

/// \test
TEST(QString, CanBeComparedtoWcharPointer){
    wchar_t const * pointerHello = L"Hello ©";
    QString qStringWorld("World €");

    EXPECT_NE(pointerHello,qStringWorld);

}

#include<sstream>
using namespace std;
/// \test
TEST(wostringstream, CanBeWritteAndCompared){
    wostringstream output;
    wstring someWideString(L"Hello World with öäßüПивет Мир");
    output<<someWideString;

    //someWideString+=LR"(\o/)";

    EXPECT_EQ(output.str(), someWideString);
    EXPECT_EQ(QString::fromStdWString(output.str()),QString::fromStdWString(someWideString));
}

/// \test
TEST(PlayingField, startsOutputWithWelcomeOnStartup){

    //Setup
    wostringstream output;
    const wstring hello(L"Welcome to 2048\n");

    //Execute
    PlayingField playingField(output);

    //Verify
    EXPECT_EQ(output.str().substr(0,hello.size()),hello);
}

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
    wostringstream output;
    wistringstream input;

    PlayingField field(input, output);
    const int unset =-1;

    //Act
    field.setAlleFelderBesetzt();

    //Act && Assert

    ASSERT_EQ(field.freiFeldSuche()[0], unset);
    ASSERT_EQ(field.freiFeldSuche()[1], unset);
}

TEST(TestPlayingField,SearchForFreePlayingFieldReal) {
    //Arrange
    wostringstream output;
    wistringstream input;

    PlayingField field(input, output);
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

    EXPECT_NE(wStringHello,pointerWorld);   //EXPECT_NE und nicht EXPECTSTRNE while wStringhello
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
    wstring someWideString(L"Hello World with öäßüПривет Мир");
    output<<someWideString;

    //someWideString+=LR"(\o/)";

    EXPECT_EQ(output.str(), someWideString);
    EXPECT_EQ(QString::fromStdWString(output.str()),QString::fromStdWString(someWideString));
}

/// \test
TEST(PlayingField, startsOutputWithWelcomeOnStartup){

    //Setup
    wostringstream output;
    wistringstream input;

    const wstring hello(L"Welcome to 2048\n");

    //Execute
    PlayingField playingField(input, output);

    //Verify
    EXPECT_EQ(output.str().substr(0,hello.size()),hello);
}

/// \test
TEST(PlayingField, outputsPromptAndByeAtEmptyInput){

    //Setup
    wostringstream outputStream;
    wistringstream emptyInputStream;

    const wstring prompt(L"Geben Sie 'b' fuer Anfang ein:");
    const wstring goodbye(L"\nThank you for your wasted time.");

    //Execute
    PlayingField playingField(emptyInputStream, outputStream);

    //Verify
    wstring output = outputStream.str();
    wstring promptErrorMessage;
    wstring goodByeErrorMessage;

    promptErrorMessage+= L"for output <" + output + L"> and prompt <" + prompt + L">";
    goodByeErrorMessage+= L"for output <" + output + L"> and prompt <" + prompt + L">";
    EXPECT_NE(output.find(prompt), wstring::npos) << promptErrorMessage;//npos - Rueckgabewert, wenn nicht gefunfden is
    EXPECT_EQ(output.find(prompt), output.rfind(prompt)) << promptErrorMessage;//rfind - Suche vom Ende an
    //und wenn EQ heisst, dass nur einmal getroffen haben, weil gleiche Position zurückgibt. Wenn 2Mal=>trifft auf verschiedenen Positionen
    EXPECT_NE(output.find(goodbye),wstring::npos) << goodByeErrorMessage;
    EXPECT_LT(output.find(prompt), output.find(goodbye)) << goodByeErrorMessage;//Prompt kommt vor Goodbye
}

/// \test
TEST(PlayingField, outputsPromptTwoTimesForOneBlankLineOfInput){

    //Setup
    wistringstream oneBlankLineOfImport(L"\n");
    wostringstream outputStream;


    const wstring prompt(L"Geben Sie 'b' fuer Anfang ein:\n"
                         L"Leere Eingabe, bitte wiederholen!\n"
                         L"Geben Sie 'b' fuer Anfang ein:"
                         );

    //Execute
    PlayingField playingField(oneBlankLineOfImport, outputStream);

    //Verify
    wstring output = outputStream.str();
    wstring promptErrorMessage;
    wstring goodByeErrorMessage;

    promptErrorMessage+= L"for output <" + output + L"> and prompt <" + prompt + L">";
    EXPECT_NE(output.find(prompt), wstring::npos) << promptErrorMessage;
    EXPECT_EQ(output.find(prompt), output.rfind(prompt)) << promptErrorMessage;

}

/// \test
TEST(wistringstream, providesNothingIfEmpty){
    //Setup
    wistringstream input;
    wstring s;

    //zusaetzliche preconditions (Vorbedingungen) testen:
    ASSERT_TRUE(input.good());//Fehlerfrei und man kann ihn lesen
    ASSERT_TRUE(input);//Wie .good aber schneller
    ASSERT_FALSE(input.eof());
    ASSERT_TRUE(s.empty());

    //Execute
    input>>s;

    //Verify
    EXPECT_EQ(s, L"");
    EXPECT_TRUE(s.empty());

    //zusaetzliche preconditions (Vorbedingungen) testen:
    ASSERT_TRUE(input.eof());//Strom ist am Ende der Datei.
    ASSERT_FALSE(input);//kann nichts liefern
    ASSERT_FALSE(input.good());//Nichts zu lesen

    //Teardown

}

/// \test
TEST(wistringstream, providesSomeString){
    //Setup
    wistringstream input(L"Hello World");
    wstring s;

    //zusaetzliche preconditions (Vorbedingungen) testen:
    ASSERT_TRUE(input.good());//Fehlerfrei und man kann ihn lesen
    ASSERT_TRUE(input);//Returns true if the stream has no errors and is ready for I/O operations
    ASSERT_FALSE(input.eof());
    ASSERT_TRUE(s.empty());

    //Execute
    input>>s;

    //Verify
    EXPECT_EQ(s, L"Hello");
    EXPECT_FALSE(s.empty());

    //zusaetzliche preconditions (Vorbedingungen) testen:
    ASSERT_FALSE(input.eof());//Strom ist nicht am Ende der Datei. "World" ist noch zu lesen || checks if end-of-file has been reached
    ASSERT_TRUE(input);//Returns true if the stream has no errors and is ready for I/O operations
    ASSERT_TRUE(input.good());//es gibt was zu lesen || checks if no error has occurred i.e. I/O operations are available

    //Teardown

}

/// \test
TEST(wistringstream, readsALine){
    //Setup
    wistringstream input(L"Hello World");
    wstring s;

    //zusaetzliche preconditions (Vorbedingungen) testen:
    ASSERT_TRUE(input.good());//Fehlerfrei und man kann ihn lesen
    ASSERT_TRUE(input);//Wie .good aber schneller
    ASSERT_FALSE(input.eof());
    ASSERT_TRUE(s.empty());

    //Execute
    getline(input,s);

    //Verify
    EXPECT_EQ(s, L"Hello World");
    EXPECT_FALSE(s.empty());

    //zusaetzliche preconditions (Vorbedingungen) testen:
    ASSERT_TRUE(input.eof());//Strom ist nicht am Ende der Datei. "World" ist noch zu lesen
    ASSERT_TRUE(input);//kann etwas liefern
    ASSERT_FALSE(input.good());//es gibt nichts zu lesen. Opposit to ASSERT_TRUE(input.eof());

    //Was passiert, wenn es noch weiter gelesen wird?
    input>>s;
    EXPECT_FALSE(s.empty());
    EXPECT_TRUE(input.eof());
    EXPECT_FALSE(input);
    EXPECT_EQ(s, L"Hello World");

    s=L"";
    EXPECT_TRUE(s.empty());
    EXPECT_TRUE(input.eof());
    EXPECT_FALSE(input); //stream is empty
    EXPECT_EQ(s, L"");

}

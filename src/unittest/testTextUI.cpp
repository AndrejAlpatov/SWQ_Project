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

/// \test
TEST(TextUI, canSayGoodBye){

    //Setup
    wostringstream outputStream;
    wistringstream emptyInputStream;
    const wstring goodbye(L"\nThank you for your wasted time.");

    //Execute
    TextUI textUI(emptyInputStream, outputStream);
    textUI.sayGoodBye();

    //Verify
    EXPECT_EQ(outputStream.str(), goodbye);
}

/// \test
TEST(TextUI, canErrorMessage){

    //Setup
    wostringstream outputStream;
    wistringstream emptyInputStream;
    const wstring someErrorMessage(L"Oh-Oh");
    const wstring expectedOutput = L"\n" + someErrorMessage + L"\n";        // wstring(L"\n") + someErrorMessage + L"\n"; geht es auch

    //Execute
    TextUI textUI(emptyInputStream, outputStream);
    textUI.showError(someErrorMessage);

    //Verify
    EXPECT_EQ(outputStream.str(), expectedOutput);
}

/// \test
TEST(TextUI, getInputLineShowsPromptOnEmptyInput){

    //Setup
    const wstring prompt(L"Geben Sie 'b' fuer Anfang ein");
    const wstring expectedOutput = prompt + L": ";
    wostringstream outputStream;
    wistringstream emptyInputStream;
    TextUI textUI(emptyInputStream, outputStream);

    //Execute
    wstring line = textUI.getInputLine(prompt);

    //Verify
    EXPECT_EQ(outputStream.str(), expectedOutput);
    EXPECT_TRUE(line.empty()) << L"lineInput is <" << line << L">";
}

/// \test
TEST(TextUI, getInputLineDeliversOneLineOfInput){

    //Setup
    const wstring prompt(L"Geben Sie 'b' fuer Anfang ein");
    const wstring expectedOutput = prompt + L": ";
    const wstring firstLineOfImport(L"First line");
    const wstring twoLinesOfImport = firstLineOfImport + L"\nSecondLine";

    wostringstream outputStream;
    wistringstream inputStream(twoLinesOfImport);
    TextUI textUI(inputStream, outputStream);

    //Execute
    wstring line = textUI.getInputLine(prompt);

    //Verify
    EXPECT_EQ(outputStream.str(), expectedOutput) << outputStream.str();
    EXPECT_EQ(line, firstLineOfImport);
}

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
TEST(TextUI, CanBeInstantiatedWthInputOutputStreams){//ничего не делает, просто создает объект и передает в него пустые
                                                     //входящий и выходящие потоки

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
TEST(PlayingField, canSayWelcome){//Проверяем в выходящем потоке наличие строки const wstring hello

    //Setup
    const wstring hello(L"Welcome to 2048\n");
    wostringstream output;
    wistringstream emptyInput;
    TextUI textui(emptyInput, output);

    //Execute
    textui.sayWelcome();//sayWelcome() Отправляет в выходящий поток Welcome to 2048\n и информацию о версии

    //Verify
    EXPECT_EQ(output.str().substr(0,hello.size()),hello);//в потоке с нулевой позиции отсчитываем количество символов,
                                                         //как в переменной hello
}

/// \test
TEST(TextUI, canSayGoodBye){//Сравниваем выходящий поток со строкой const wstring goodbye

    //Setup
    wostringstream outputStream;
    wistringstream emptyInputStream;
    const wstring goodbye(L"\nThank you for your wasted time.");

    //Execute
    TextUI textUI(emptyInputStream, outputStream);
    textUI.sayGoodBye();//sayGoodBye() Отправляет в выходящий поток: \nThank you for your wasted time.

    //Verify
    EXPECT_EQ(outputStream.str(), goodbye);
}

/// \test
TEST(TextUI, canErrorMessage){//Сравниваем выходящий поток с const wstring expectedOutput

    //Setup
    wostringstream outputStream;
    wistringstream emptyInputStream;
    const wstring someErrorMessage(L"Oh-Oh");
    const wstring expectedOutput = L"\n" + someErrorMessage + L"\n";        // wstring(L"\n") + someErrorMessage + L"\n"; geht es auch

    //Execute
    TextUI textUI(emptyInputStream, outputStream);
    textUI.showError(someErrorMessage);//Отправляет в выходящий поток \nsomeErrorMessage\n

    //Verify
    EXPECT_EQ(outputStream.str(), expectedOutput);
}

/// \test
TEST(TextUI, getInputLineShowsPromptOnEmptyInput){  //Передаем в объект класса TextUI пустые входящие и исходящие потоки. Запускаем функцию
                                                    //getInputLine(prompt), которая передает в выходящий поток prompt + L":". Сравниваем
                                                    //этот поток с ожидаемым expectedOutput, а пустой выходящий поток с пустой строкой

    //Setup
    const wstring prompt(L"Geben Sie 'b' fuer Anfang ein");
    const wstring expectedOutput = prompt + L":";
    wostringstream outputStream;
    wistringstream emptyInputStream;
    TextUI textUI(emptyInputStream, outputStream);//передаем пустые входящий и выходящие потоки, пустой входящий поток потом сравниваем с
                                                  //пустой строкой, в выходящий, созданный с помощью getInputLine() с expectedOutput

    //Execute
    wstring line = textUI.getInputLine(prompt);//getInputLine(prompt) отправляет в выходящий поток prompt с добавленным двоеточием в конце

    //Verify
    EXPECT_EQ(outputStream.str(), expectedOutput);//созданный getInputLine() выходящий поток сравниваем с expectedOutput
    EXPECT_TRUE(line.empty()) << L"lineInput is <" << line << L">";//emptyInputStream - пустой, поэтому сравниваем с пустой строкой
}

/// \test
TEST(TextUI, getInputLineDeliversOneLineOfInput){//Передаем в во входящий поток две строки и пустой выходящий поток. После чего функция
                                                 //getInputLine(prompt) передает в выходящий поток prompt, добавив в него двоеточие, а
                                                 //сама функция возвращает первую строку аходящего потока

    //Setup
    const wstring prompt(L"Geben Sie 'b' fuer Anfang ein");
    const wstring expectedOutput = prompt + L":";
    const wstring firstLineOfImport(L"First line");
    const wstring twoLinesOfImport = firstLineOfImport + L"\nSecondLine";

    wostringstream outputStream;
    wistringstream inputStream(twoLinesOfImport);
    TextUI textUI(inputStream, outputStream);

    //Execute
    wstring line = textUI.getInputLine(prompt);//Принимает промпт, добавляет двоеточие и передает в поток вывода
                                               //Сама функция getInputLine() возвращает первую строку входного потока
    //Verify
    EXPECT_EQ(outputStream.str(), expectedOutput) << outputStream.str();//Проверяет промпт в потоке вывода с образцом в тесте
    EXPECT_EQ(line, firstLineOfImport);
}

/// \test
TEST(TextUI, getFilledInputLineShowsErrorMessageOnBlankLine){//Сверяет ожидаемый expectedOutput с выходным потоком, в который передается
    //somePrompt: + errorMessage + somePrompt:      В сам создаваемый объект TextUI передается пердается пустой выходящий поток и пустая
    //строка во входящий

    //Setup
    const wstring somePrompt(L"Any Prompt");
    const wstring errorMessage(L"Write at least something");
    const wstring expectedOutput = somePrompt + L":\n" + errorMessage + L"\n" + somePrompt + L":";

    wistringstream oneBlankLineOfImport(L"\n");
    wostringstream outputStream;
    TextUI textui(oneBlankLineOfImport, outputStream);


    //Execute
    wstring line=textui.getFilledInputLine(somePrompt, errorMessage);   //Возвращает первую строку входящего потока, в который передается
                                                                        //пустая трока L"\n"

    //Verify
    EXPECT_EQ(outputStream.str(), expectedOutput);
    EXPECT_EQ(line,L"");
}

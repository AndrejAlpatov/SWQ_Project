//============================================================================
/// \file       Tests for Getter and Setter in Tile.h
/// \ingroup    g_unittests
/// \brief      Test accessing the generated version information.
/// \copyright  GNU General Public License (GPL) Version 3
//============================================================================

#include "app-lib/app-lib.h"
#include "Helpers.h"
#include <gtest/gtest.h>
//#include <iostream>

class TestDefault2048 : public ::testing::Test{
public:
    TestDefault2048(){
        cout<<"Konstruktor der Klasse TestDefault2048 ist aufgerufen"<< endl;
    }
    virtual ~TestDefault2048(){ cout<<"Destruktor der Klasse TestDefault2048"<<endl;}

protected:
    Tile field;

};

class TestTileGetter : public ::testing::TestWithParam<int>{

};

/// \test
TEST_F(TestDefault2048,getTileFreiheitAndWert){//Praktikum 6.1

    //Act && Assert
    cout <<"Test getTileFreiheitAndWert ist aufgerufen"<<endl;
    ASSERT_TRUE(field.getFrei()) ;
    ASSERT_EQ(field.getWert(), 0);
}

/// \test
TEST_F(TestDefault2048 ,setTileFreiheitAndWert) {//Praktikum 6.1
    //Arrange
    field.setFrei(false);

    //Act && Assert

    ASSERT_FALSE(field.getFrei()) ;
    ASSERT_EQ(field.getWert(), 0);
}

TEST_P(TestTileGetter, returnesGiwenWert){//Praktikum 6.2

    //setup
    int wert=GetParam();
    Tile tile(true, wert);

    //verify
    EXPECT_EQ(tile.getWert(), wert);

}

INSTANTIATE_TEST_SUITE_P(TileWert, TestTileGetter, ::testing::Values(0, 2, 2048));

/// \test
TEST(TestTile,getTileFreiheitAndWert) {
    //Arrange
    int wert=2048;
    Tile field(true, wert);

    //Act && Assert

    ASSERT_TRUE(field.getFrei()) ;
    ASSERT_EQ(field.getWert(), 2048);
}

/// \test
TEST(TestTile,setTileFreiheitAndWert) {
    //Arrange
    int wert=2048;
    Tile field(true, 0);
    field.setWert(wert);
    field.setFrei(false);

    //Act && Assert

    ASSERT_FALSE(field.getFrei()) ;
    ASSERT_EQ(field.getWert(), 2048);
}

/// \test
TEST(test2048, CanBeCreatedWithIstreamAndOstream){
    wostringstream ignored;
    wistringstream inputIgnored;
    TextUI ui(inputIgnored, ignored);
    PlayingField testField(ui);

    SUCCEED();
}

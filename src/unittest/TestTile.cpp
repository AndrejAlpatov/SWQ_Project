//============================================================================
/// \file       Tests for Getter and Setter in Tile.h
/// \ingroup    g_unittests
/// \brief      Test accessing the generated version information.
/// \copyright  GNU General Public License (GPL) Version 3
//============================================================================

#include "app-lib/app-lib.h"
#include "Helpers.h"
#include <gtest/gtest.h>
#include <vector>
//#include <iostream>

struct TestTileData{//Praktikum 6.2
    bool frei;
    int wert;
};

ostream & operator <<(ostream & os,TestTileData const & data){//Praktikum 6.2 Ausgabe von Werten GetParam()
    os<<"Frei:"<<data.frei << " Wert:"<<data.wert<<endl;
    return  os;
}

class TestDefault2048 : public ::testing::Test{//Praktikum 6.1
public:
    TestDefault2048(){
        cout<<"Konstruktor der Klasse TestDefault2048 ist aufgerufen"<< endl;
    }
    virtual ~TestDefault2048(){ cout<<"Destruktor der Klasse TestDefault2048"<<endl;}

protected:
    Tile field;

};

class TestTileGetter : public ::testing::TestWithParam<TestTileData>{//Praktikum 6.2

};

vector<TestTileData> fieldVector={{true, 0},//Praktikum 6.2
                                  {false, 32}};

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

TEST_P(TestTileGetter, returnesGiwenWertAndFreicheit){//Praktikum 6.2

    //setup
    TestTileData tileData = GetParam();
    Tile tile(tileData.frei, tileData.wert);


    //verify
    EXPECT_EQ(tile.getWert(), tileData.wert);
    EXPECT_EQ(tile.getFrei(), tileData.frei);

}

INSTANTIATE_TEST_SUITE_P(TileWert, TestTileGetter, ::testing::Values(TestTileData{true, 16}));
INSTANTIATE_TEST_SUITE_P(TileWertVector, TestTileGetter, ::testing::ValuesIn(fieldVector));

//Grenzwertanalyse entsprechend P6.3
// Tile(bool frei, unsigned int);
//Parameters        gueltige/ungueltige
//wert              uAeKl2: wert>2048
//                  gAeKl1: 0<=wert<=2048

class TestSetWert: public ::testing::TestWithParam<int>{

};

INSTANTIATE_TEST_SUITE_P(testGrenzwerte, TestSetWert, ::testing::Values(2047, 2048, 2049));

TEST_P(TestSetWert, GrenzWertAnalyse){//Praktikum 6.3

    //setup
    int wert=GetParam();
    Tile tile;

    //verify
        if(wert<=2048){
            EXPECT_NO_THROW(tile.setWert(wert))<<"Erwartet kein Exception, wenn Wert<=2048"<<endl;
        }else{
            EXPECT_THROW(tile.setWert(wert),std::invalid_argument)<<"Throws Exception, wenn Wert>2048"<<endl;
        }
}


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

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
TEST(test2048, CanBeCreated){
    PlayingField testField;
    SUCCEED();
}

//============================================================================
/// \file       Test for Getter in Tile.h
/// \ingroup    g_unittests
/// \brief      Test accessing the generated version information.
/// \copyright  GNU General Public License (GPL) Version 3
//============================================================================

#include "app-lib/app-lib.h"
#include "Helpers.h"
#include <gtest/gtest.h>
#include <iostream>

TEST(TestTile,getTileFreiheitAndWert) {
    //Arrange
    int wert=2048;
    Tile field(true, wert);

    //Act && Assert

    ASSERT_TRUE(field.getFrei()) ;
    ASSERT_EQ(field.getWert(), 2048);
}

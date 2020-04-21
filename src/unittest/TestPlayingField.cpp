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

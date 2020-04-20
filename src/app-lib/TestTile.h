//============================================================================
/// \file       Test for Tile Class
/// \ingroup    g_applib
/// \brief      Contains the application library CalendarDate interface definition.
/// \details    This class contains tests for the input parameters of the class Tile constructor.
/// \copyright  GNU General Public License (GPL) Version 3
//============================================================================
#ifndef TESTTILE_H
#define TESTTILE_H

TEST(Tile,getFreichat) {
    //Arrange
    Tile field();

    //Act & Assert
    ASSERT_EQ( date.getDay(), 24 );
    ASSERT_EQ(date.getMonth(), 10);
    ASSERT_EQ(date.getYear(), 2016);

#endif // TESTTILE_H

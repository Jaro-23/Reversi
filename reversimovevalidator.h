
#ifndef REVERSIMOVEVALIDATOR_H
#define REVERSIMOVEVALIDATOR_H

#include "board.h"
#include "location.h"

/**
 * An object that can validate if a player is allowed to play on a certain location
 */
class ReversiMoveValidator
{
public:
    ReversiMoveValidator();

    bool isLocationValid(Board board, Location loc, Piece::Color color);
    std::vector<Location> getValidLocations(Board board, Piece::Color color);

private:
    bool checkDirection(Board board, Piece::Color color, Location loc, int dir_row, int dir_col);
};

#endif // REVERSIMOVEVALIDATOR_H

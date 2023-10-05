
#include "reversimovevalidator.h"

ReversiMoveValidator::ReversiMoveValidator()
{

}

/**
 * Checks if the player can place a piece at the given location according to the rules
 * @param board The board the place will be placed on
 * @param loc The location of the new piece
 * @param color The color of the player that wants to place a piece
 * @return
 */
bool ReversiMoveValidator::isLocationValid(Board board, Location loc, Piece::Color color) {
    if (!board.getPiece(loc)) return false;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if ((i != 0 || j != 0) && checkDirection(board, color, loc, i, j)) {
                return true;
            }
        }
    }
    return false;
}

/**
 * Returns a list of locations where pieces may be placed
 * @param board The board where you want to know the valid locations of
 * @param color The color for which the locations must be valid
 * @return A vector with locations
 */
std::vector<Location> ReversiMoveValidator::getValidLocations(Board board, Piece::Color color) {
    std::vector<Location> locations{};
    for (int i = 0; i < board.getRows(); ++i) {
        for (int j = 0; j < board.getColumns(); ++j) {
            Location new_loc{i, j};
            if (isLocationValid(board, new_loc, color))
                locations.push_back(new_loc);
        }
    }
    return locations;
}

/**
 * Returns if the pieces in a certain direction will be flipped when placed on the given location
 * @param board The board on which to piece is placed
 * @param color The color of the player
 * @param loc The location of the new piece
 * @param dir_row the row direction of the line
 * @param dir_col the column direction of the line
 * @return If pieces will be flipped
 */
bool ReversiMoveValidator::checkDirection(Board board, Piece::Color color, Location loc, int dir_row, int dir_col) {
    int row = loc.getRow() + dir_row;
    int column = loc.getColumn() + dir_col;
    if (board.getPiece(Location(row,column)) == nullptr || board.getPiece(Location(row, column))->getColor() == color)
        return false;

    row += dir_row;
    column += dir_col;
    while (board.validPosition(row, column)) {
        if (!board.getPiece(Location(row,column)))
            return false;
        else if (board.getPiece(Location(row, column))->getColor() == color)
            return true;
    }
    return false;
}

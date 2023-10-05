#include "board.h"

Board::Board(int rows, int columns) :
    _rows{rows}, _columns{columns}
{
    reset();
}

/**
 * Resets the board to only nullptrs
 */
void Board::reset() {
    _board = std::vector<std::vector<std::shared_ptr<Piece>>>{};
    for (int i = 0; i < _rows; ++i) {
        std::vector<std::shared_ptr<Piece>> row{};
        for (int j = 0; j < _columns; ++j) {
            row.push_back(std::shared_ptr<Piece>{nullptr});
        }
        _board.push_back(row);
    }
}

/**
 * Places a given piece
 * @param piece The piece you want to place on the board
 * @param row The row in which the piece needs to be placed
 * @param column The column in which the piece needs to be placed
 * @throws out_of_range When you give an invalid location
 */
void Board::placePiece(std::shared_ptr<Piece> piece, Location loc) {
    int row = loc.getRow();
    int column = loc.getColumn();
    if (!validPosition(row, column))
        throw std::out_of_range("Piece coudn't be placed!");
    _board.at(row).at(column) = piece;
}

/**
 * Removes a given piece
 * @param piece The piece you want to place on the board
 * @param row The row in which the piece needs to be placed
 * @param column The column in which the piece needs to be placed
 * @throws out_of_range When you give an invalid location
 */
void Board::removePiece(Location loc) {
    int row = loc.getRow();
    int column = loc.getColumn();
    if (_board.at(row).at(column))
        _board.at(row).at(column) = std::shared_ptr<Piece>{nullptr};
}

/**
 * Returns a shared ptr to the piece at the requested location
 * @param row The row where the requested piece is located
 * @param column The column where the requested piece is located
 * @return A shared pointer to a piece or nullptr
 */
std::shared_ptr<Piece> Board::getPiece(Location loc) const {
    int row = loc.getRow();
    int column = loc.getColumn();
    return _board.at(row).at(column);
}

/**
 * Receives the number of rows the board has
 * @return The number of rows
 */
int Board::getRows() const {
    return _rows;
}

/**
 * Receives the number of columns the board has
 * @return The number of columns
 */
int Board::getColumns() const {
    return _columns;
}

/**
 * Returns if a given row in column are inside the board
 * @param row The row you want to check
 * @param column The column you want to check
 * @return A bool that is true if the row and column are inside the board else false
 */
bool Board::validPosition(int row, int column) const {
    return 0 <= row && row <= _rows && 0 <= column && column <= _columns;
}



#ifndef BOARD_H
#define BOARD_H

#include "piece.h"

#include <array>

#include <QObject>

/**
 * Class that can hold board information for boards with a grid layout
 */
class Board
{
public:
    Board(int rows, int columns);
    void reset();
    void placePiece(std::shared_ptr<Piece> piece, int row, int column);
    void removePiece(int row, int column);
    std::shared_ptr<Piece> getPiece(int row, int column) const;

    int getRows() const;
    int getColumns() const;

private:
    bool validPosition(int row, int column) const;

    int _rows, _columns;
    std::vector<std::vector<std::shared_ptr<Piece>>> _board;
};

#endif // BOARD_H

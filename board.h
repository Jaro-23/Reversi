
#ifndef BOARD_H
#define BOARD_H

#include "piece.h"
#include "location.h"

#include <array>

#include <QObject>

/**
 * Class that can hold board information for boards with a grid layout
 * @author Robbe Jaeken
 */
class Board
{
public:
    Board(int rows, int columns);
    void reset();
    void placePiece(std::shared_ptr<Piece> piece, Location loc);
    void removePiece(Location loc);
    std::shared_ptr<Piece> getPiece(Location loc) const;

    int getRows() const;
    int getColumns() const;

    bool validPosition(int row, int column) const;

private:
    int _rows, _columns;
    std::vector<std::vector<std::shared_ptr<Piece>>> _board;
};

#endif // BOARD_H

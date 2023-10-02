
#include "piece.h"

Piece::Piece(Color color) :
    _color{color}
{

}

Piece::Color Piece::getColor() const {
    return _color;
}

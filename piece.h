
#ifndef PIECE_H
#define PIECE_H




class Piece
{
public:
    enum class Color {WHITE, BLACK};
    Piece(Color color);
    Color getColor() const;

private:
    Color _color;
};

#endif // PIECE_H

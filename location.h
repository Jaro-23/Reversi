
#ifndef LOCATION_H
#define LOCATION_H


/**
 * Stores a location
 * @author Robbe Jaeken
 */
class Location
{
public:
    Location(int row, int column);
    int getRow() const;
    int getColumn() const;

private:
    int _row;
    int _column;
};

#endif // LOCATION_H

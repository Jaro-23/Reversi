
#include "location.h"

/**
 * Initialize a location with a row and column
 * @param row the specific row index of the location
 * @param column the specific column index of the location
 */
Location::Location(int row, int column) :
    _row{row}, _column{column}
{

}

/**
 * Returns the row index of the location
 * @return an integer with the row index
 */
int Location::getRow() const {
    return _row;
}

/**
 * Returns the colunm index ofd the location
 * @return an integer with the column index
 */
int Location::getColumn() const {
    return _column;
}


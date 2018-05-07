#include "Coordinates.h"

// =====================================================================
//                               Constructors
// =====================================================================
Coordinates::Coordinates(unsigned int x, unsigned int y) : x_(x), y_(y){}

// =====================================================================
//                                Operators
// =====================================================================
bool Coordinates::operator<(const Coordinates & other) const
{
	return (x_ != other.x_) ? (x_ < other.x_) : (y_ < other.y_);
}

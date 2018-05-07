#include "Coordinates.h"

// =====================================================================
//                               Constructors
// =====================================================================
Coordinates::Coordinates(unsigned int x, unsigned int y) : x_(x), y_(y){}

Coordinates::Coordinates(unsigned int n, unsigned int height, unsigned int width){
	y_ = (n-1) % height;
  x_ = (n-1-y_)/height; 
}
// =====================================================================
//                                Destructor
// =====================================================================
  Coordinates::~Coordinates()=default;
// =====================================================================
//                                Operators
// =====================================================================
bool Coordinates::operator<(const Coordinates & other) const
{
	return (x_ != other.x_) ? (x_ < other.x_) : (y_ < other.y_);
}

// =====================================================================
//                           Public Function members
// =====================================================================
unsigned int Coordinates::to_int(unsigned int height){
	return(height*x_+y_+1);
}

#include "Coordinates.h"

// =====================================================================
//                               Constructors
// =====================================================================
Coordinates::Coordinates(unsigned int x, unsigned int y) : x_(x), y_(y){}

Coordinates::Coordinates(unsigned int n, unsigned int height, unsigned int width){
//Computes the coordinates from the single index.
	y_ = (n-1) % height;
  x_ = (n-1-y_)/height; 
}
// =====================================================================
//                                Destructor
// =====================================================================
  Coordinates::~Coordinates()=default;


// =====================================================================
//                           Public Function members
// =====================================================================
unsigned int Coordinates::to_int(unsigned int height){
	return(height*x_+y_+1);
}

#ifndef CELL_H_
#define CELL_H_
#include "Bacteria.h"
#include "Ga.h"
#include "Gb.h"

class Cell{
 public :
// =========================================================================
//                               Constructors
// =========================================================================
  Cell();

// =========================================================================
//                                Destructor
// =========================================================================
  virtual ~Cell();

// =========================================================================
//                                  Getters
// =========================================================================
 

// =========================================================================
//                                  Setters
// =========================================================================




 protected :

// =========================================================================
//                               Data members
// =========================================================================
  float x_;
  float y_;
	Bacteria * bacteria_;
	float a_;
	float b_;
	float c_;

// =========================================================================
//                        Protected Function members
// =========================================================================


}; 

#endif //CELL_H_

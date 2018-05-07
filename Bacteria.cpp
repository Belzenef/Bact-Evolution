#include "Bacteria.h"
#include <cstdlib>

// =====================================================================
//                       Definition of static attributes
// =====================================================================
  const unsigned int Bacteria::W_MIN = 1; // fitness threshold

// =====================================================================
//                                Constructors
// =====================================================================
 Bacteria::Bacteria(float a, float b, float c) : a_(a), b_(b), c_(c){
  }

// =====================================================================
//                                 Destructor
// =====================================================================
Bacteria::~Bacteria() = default;

// =====================================================================
//                           Public Function members
// =====================================================================
bool Bacteria::die(float pdeath){
  if(getW()==0){ // testing fitness threshold
    return true;
  } else if (rand()<pdeath){ // testing death propability
    return true;
  } else {
    return false;
  }
}


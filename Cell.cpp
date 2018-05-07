#include "Cell.h" 

// =========================================================================
//                               Constructors
// =========================================================================
Cell::Cell(float a, float b, float c, unsigned int x, unsigned int y): a_(a), b_(b), c_(c), preva_(a), prevb_(b), prevc_(c), x_(x), y_(y){}

// =========================================================================
//                                Destructor
// =========================================================================
Cell::~Cell() = default;

// =========================================================================
//                        Public Function members
// =========================================================================
void Cell::update(){
	preva_ = a_;
	prevb_ = b_;
	prevc_ = c_;
}

bool Cell::die(float pdeath){/*
  if(getW()==0){ // testing fitness threshold
    return true;
  } else if (((float) rand()/RAND_MAX + 1)<pdeath){ // testing death propability
    return true;
  } else {
    return false;
  }*/
}

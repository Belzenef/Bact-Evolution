#include "Cell.h"
#include <cstdlib> 
#include <time.h>
#include <iostream>



// =========================================================================
//                               Constructors
// =========================================================================
Cell::Cell(float a, float b, float c, unsigned int x, unsigned int y): a_(a), b_(b), c_(c), preva_(a), prevb_(b), prevc_(c), x_(x), y_(y){
	// creates a bacteria A or B with a 50 % probability to create each
	srand(time(NULL));
	int i = rand()%100 ;
	if ( i < 50){
		bacteria_= new Ga(a,b,c);
		//std::cout << "A" << std::endl;
	}
	else{
		bacteria_ = new Gb(a, b, c);
		//std::cout << "B" << std::endl;	
	}
}

// =========================================================================
//                                Destructor
// =========================================================================
Cell::~Cell() {
	delete bacteria_;
}

// =========================================================================
//                        Public Function members
// =========================================================================
void Cell::update(){
	preva_ = a_;
	prevb_ = b_;
	prevc_ = c_;
}

bool Cell::die(float pdeath, float wmin){
  if(bacteria_ -> getW() < wmin){ // testing fitness threshold
		a_ += bacteria_ -> a();
		b_ += bacteria_ -> b();
		c_ += bacteria_ -> c();
		update();
    delete bacteria_;
		return true;
  } 
	else if (((float) rand()/RAND_MAX )<pdeath){ // testing death propability
  	a_ += bacteria_ -> a();
		b_ += bacteria_ -> b();
		c_ += bacteria_ -> c();
		update();
    delete bacteria_;
		return true;
  } 
	else {
    return false;
  }
}

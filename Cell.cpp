#include "Cell.h"
#include <cstdlib> 
#include <time.h>
#include <iostream>



// =========================================================================
//                               Constructors
// =========================================================================
Cell::Cell(float a, float b, float c, unsigned int x, unsigned int y): a_(a), b_(b), c_(c), preva_(a), prevb_(b), prevc_(c), x_(x), y_(y){
	// creates a bacteria A or B with a 50 % probability to create each
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
  if (bacteria_!=nullptr){
	  delete bacteria_;
  }
}
// =====================================================================
//                                  Setters
// =====================================================================
void Cell::setbacteriaA( float a, float b, float c){
  if(bacteria_!=nullptr){
    delete bacteria_;
  }
  bacteria_ = new Ga(a, b, c);
}
void Cell::setbacteriaB( float a, float b, float c){  
if(bacteria_!=nullptr){
    delete bacteria_;
  }
  bacteria_ = new Gb(a, b, c);
}
// =========================================================================
//                        Public Function members
// =========================================================================
void Cell::fill(Cell* to_fill, float pmut){
  bool Ga=bacteria_->isGa(); //True if parent bacteria is Ga
  float a_parent=bacteria_->a();
  float b_parent=bacteria_->b();
  float c_parent=bacteria_->c();

  //fill the cell to fill
  bool mutate=( ((float) rand()/RAND_MAX )<pmut ); //True if a mutation happens
  if( Ga xor mutate ){
/*
  Ga | mutate | daughter's type
  0  |   0    |     Gb
  0  |   1    |     Ga
  1  |   0    |     Ga
  1  |   1    |     Gb
*/
    to_fill->setbacteriaA(a_parent/2.,b_parent/2.,c_parent/2.);
  }else{
    to_fill->setbacteriaB(a_parent/2.,b_parent/2.,c_parent/2.);
  }

  //"this" is also divided by two (and can mutate)
  mutate=( ((float) rand()/RAND_MAX )<pmut ); //True if a mutation happens
  if( Ga xor mutate ){
    setbacteriaA(a_parent/2.,b_parent/2.,c_parent/2.);
  }else{
    setbacteriaB(a_parent/2.,b_parent/2.,c_parent/2.);
  }

}
void Cell::update(){
	preva_ = a_;
	prevb_ = b_;
	prevc_ = c_;
}

void Cell::die(float pdeath){
  if(bacteria_!=nullptr){ //do nothing if the bacteria is already dead 
		if ((float) rand()/RAND_MAX<pdeath){ // testing death propability 
    	a_ += bacteria_ -> a();
		  b_ += bacteria_ -> b();
		  c_ += bacteria_ -> c();
      delete bacteria_;
      bacteria_=nullptr;
		}
  }
}


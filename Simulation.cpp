#include "Simulation.h"
#include <iostream>
#include <math.h>

// =====================================================================
//                                Constructors
// =====================================================================
Simulation::Simulation(unsigned int height, unsigned int width, float ainit, 
	float pdeath, float pmut, float Raa, float Rab, float Rbb, 
	float Rbc, float d, float wmin, unsigned int T, unsigned int tend, float dt):
  T_(T), tend_(tend), dt_(dt)
{
	grid_ =new Grid(height, width, ainit, pdeath, pmut, Raa, Rab, Rbb, Rbc, d, wmin);
} 

// =====================================================================
//                                 Destructor
// =====================================================================
Simulation::~Simulation(){
  delete grid_;
}

// =====================================================================
//                           Public Function members
// =====================================================================
float Simulation::run(){
		float time=0;
    while(time<tend_){
      if(((int)floor(time))%T_==0.){ //Changing culture every T
        grid_->reinit();
      }
      grid_->diffuse();
      std::cout<<"ok"<<std::endl;
      if(not grid_->compete()){break;}
      grid_->metabolize(dt_);
      time+=dt_;
    }
    if(Gb::nbS_==0){
      if(Ga::nbL_==0) { 
        std::cout<< "extinction" << std::endl;
        return -1.; 
      } else { 
          std::cout<< "exclusion" << std::endl;
          return 0.; 
        } 
    } else { 
      std::cout<< "cohabitation" << std::endl;
      return (Gb::nbS_/Ga::nbL_); 
    } 
}

void Simulation::reset(unsigned int height, unsigned int width, float ainit, 
	float pdeath, float pmut, float Raa, float Rab, float Rbb, 
	float Rbc, float d, float wmin, unsigned int T, unsigned int tend, float dt){
    T_ = T;
    tend_ = tend;
    dt_ = dt;
    if(grid_!=nullptr){
      delete grid_;
    }
    grid_ = new Grid(height, width, ainit, pdeath, pmut, Raa, Rab, Rbb, Rbc, d, wmin);
  }




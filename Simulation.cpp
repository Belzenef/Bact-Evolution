#include "Simulation.h"
#include <iostream>

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
int Simulation::run(){
		unsigned int time=0;
    while(time<tend_){
      if(time%T_==0.){ //Changing culture every T
        grid_->reinit();
      }
      grid_->diffuse();
      //grid_->compete();
      std::cout<<"ok"<<std::endl;
      if(isExtinct()){break;}
      grid_->metabolize(dt_);
      time+=dt_;
    }
    if(Ga::nbL_==0){
      if(Gb::nbS_==0) { return 0; } // extinction
      else { return 1; } // exclusion
    } else { return 2; } // cohabitation
}




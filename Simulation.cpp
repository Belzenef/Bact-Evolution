#include "Simulation.h"

// =====================================================================
//                                Constructors
// =====================================================================
Simulation::Simulation(unsigned int height, unsigned int width, float ainit, 
	float pdeath, float pmut, float Raa, float Rab, float Rbb, 
	float Rbc, float d, float wmin, float T, float tend, float dt):
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
		/*int time=0;
    while(time<tend_){
      grid_->diffuse();
      grid_->compete();
      //grid_->metabolize();
      //if(isExtinct()){break;}
      time+=dt_;
    }
    if(Ga::nbL_==0){
      if(Gb::nbS_==0) { return 0; } // extinction
      else { return 1; } // exclusion
    } else { return 2; } // cohabitation
    */
    return 0;
}

bool Simulation::isExtinct(){
	/*if (Ga::nbL_ == 0 & Gb::nbS_ == 0){
		return 1;	
	}
	else {return 0;}
  */
  return 0;
} 

unsigned int state(){
//	if ()
  return 0;
}

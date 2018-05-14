#ifndef SIMUL_H  
#define SIMUL_H

#include "Grid.h"

class Simulation {
 public :
// =====================================================================
//                               Constructors
// =====================================================================
  Simulation(unsigned int height, unsigned int width, float ainit, 
	float pdeath, float pmut, float Raa, float Rab, float Rbb, 
	float Rbc, float d, float wmin, float t, float tend, float dt); 

// =====================================================================
//                                Destructor
// =====================================================================
  virtual ~Simulation();
  
// =====================================================================
//                           Public Function members
// =====================================================================
	int run();

 protected :
// =====================================================================
//                               Data members
// =====================================================================
  float T_;
  float tend_;
  float dt_;
  Grid * grid_;
};

#endif


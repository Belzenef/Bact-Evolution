#ifndef SIMUL_H  
#define SIMUL_H

#include "Grid.h"
#include "Ga.h"
#include "Gb.h"

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
	bool isExtinct(); // tests whether the population is extinct (returns 1 if this is tha case)
	unsigned int state(); // tests whether the state is "extinction"(=0), "exclusion"(=1) or "cohabitation"(=2)

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


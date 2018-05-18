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
	float Rbc, float d, float wmin, unsigned int T, unsigned int tend, float dt); 
  Simulation()=delete;
  Simulation(const Simulation&)=delete;

// =====================================================================
//                                Destructor
// =====================================================================
  virtual ~Simulation();
//======================================================================
//                              Getters
//======================================================================
  //JUST FOR TESTS
  inline Grid* getgrid();
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
  unsigned int T_;
  unsigned int tend_;
  float dt_;
  Grid* grid_;
};
// =====================================================================
//                            Inline definitions
// =====================================================================
  //JUST FOR TESTS
  inline Grid* Simulation::getgrid(){return grid_;}
#endif


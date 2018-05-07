#include "Simulation.h"

// =====================================================================
//                                Constructors
// =====================================================================
Simulation::Simulation(unsigned int height, unsigned int width, float ainit, 
	float pdeath, float pmut, float Raa, float Rab, float Rbb, 
	float Rbc, float d, float wmin, float t, float tend, float dt) : 
	t_(t), tend_(tend), dt_(dt)
{
	Grid * grid_ = new Grid(height, width, ainit, pdeath, pmut, 
						  Raa, Rab, Rbb, Rbc, d, wmin);
} 

// =====================================================================
//                                 Destructor
// =====================================================================
Simulation::~Simulation() = default;

// =====================================================================
//                           Public Function members
// =====================================================================
void Simulation::run(){}

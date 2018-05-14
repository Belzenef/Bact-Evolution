#include "Simulation.h"
#include "Ga.h"
#include "Gb.h"

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
Simulation::~Simulation(){
	delete grid_;
}

// =====================================================================
//                           Public Function members
// =====================================================================
void Simulation::run(){}
bool Simulation::isExtinct(){
	if (Ga::nbL_ == 0 & Gb::nbS_ == 0){
		return 1;	
	}
	else {return 0;}
} 

//unsigned int state(){
//	if ()
//}

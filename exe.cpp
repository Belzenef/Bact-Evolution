#include <iostream>
#include "Bacteria.h"
#include "Cell.h"
#include "Ga.h"
#include "Gb.h"
#include "Simulation.h"

int main(int argc, char* argv[]){
	std::cout << "Hello world!" << std::endl;

	//////// Defining T and Ainit domain ////////
	unsigned int Tmin=1;
	unsigned int Tmax=1500;

	float AinitMin=0.;
	float AinitMax=50.;

	//////// Defining Ainit step dA and time step dt  ////////
	float dA=1.;
	float dt=1.;

	//////// Initializing T and Ainit ////////
	unsigned int T=Tmin;
	unsigned int ainit=AinitMin;

	//////// creating  ////////
	while(T<Tmax){
		while(ainit<AinitMax){
			Simulation sim(32, 32, ainit, .02, 0., .1,.1,.1,.1, .1, .001, T, 5000, dt);
			sim.run();
			ainit+=dA;
		}
		++T;
	}

	return 0;
}

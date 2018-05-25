#include <iostream>
#include <fstream>
#include "Bacteria.h"
#include "Cell.h"
#include "Ga.h"
#include "Gb.h"
#include "Simulation.h"

int main(int argc, char* argv[]){

	srand(3); //seed used by rand (	we'll have to use srand(time(NULL)) eventually)

	//////// Defining T and Ainit domain ////////
	unsigned int Tmin=1;
	unsigned int Tmax=200;

	float AinitMin=0.;
	float AinitMax=50.;

	//////// Defining Ainit step dA and time step dt  ////////
	float dA=1.;
	float dt=1.;

	//////// Initializing T and Ainit ////////
	unsigned int T=Tmin;
	unsigned int ainit=AinitMin;

	//////// Creating the output file ////////
	ofstream myfile;
	myfile.open("SimulationOutputs.csv");

	//////// Filling the output file with the simulation  ////////
	while(T<=Tmax){
		std::cout << "T = " << T << std::endl;
		while(ainit<=AinitMax){
			Simulation sim(32, 32, ainit, .02, 0., .1,.1,.1,.1, .1, .001, T, 5000, dt);
			myfile << ainit <<","<<T<<","<<sim.run()<<"\n";
			ainit+=dA;
		}
		++T;
		ainit=AinitMin;
	}

	//////// Closing the output file ////////
	myfile.close();

	return 0;
}

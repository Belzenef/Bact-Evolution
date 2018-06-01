#include <iostream>
#include <fstream>
#include "Bacteria.h"
#include "Cell.h"
#include "Ga.h"
#include "Gb.h"
#include "Simulation.h"

///////// refine function /
void refine(float AinitMax, float dA, unsigned int T, float dt, ofstream* myfile, Simulation* sim){
	// refine the parametric exploration
	float AinitMin=AinitMax-dA;
	dA= dA/10;
	float ainit = AinitMin+dA;
	
	while(ainit<AinitMax){
		std::cout << "ainit = " << ainit << std::endl;
		sim->reset(32, 32, ainit, .02, 0., .1,.1,.1,.1, .1, .001, T, 5000, dt);
		(*myfile) << ainit <<","<<T<<","<<sim->run()<<"\n";
		ainit+=dA;
	}				
}

int main(int argc, char* argv[]){

	srand(time(NULL)); //seed used by rand (	we'll have to use srand(time(NULL)) eventually)	

	//////// Defining T and Ainit domain ////////
	unsigned int Tmin=1;
	unsigned int Tmax=1500;//1500

	float AinitMin=0.;
	float AinitMax=50.;

	//////// Defining Ainit step dA and time step dt  ////////
	float dA=1.;
	float dt=1.;

	//////// Initializing T and Ainit ////////
	unsigned int T=Tmin;
	float ainit=AinitMin;

	//////// Defining prevRun and currentRun ////////
	float prevRun=-2;
	float currentRun;

	//////// Creating the output file ////////
	ofstream myfile;
	myfile.open("SimulationOutputs.csv");

	//////// Filling the output file with the simulation  ////////

	// Simualtion sim(height, width, ainit, pdeath, pmut, Raa, Rab, Rbb, Rbc, d, wmin, T, tend, dt)
	Simulation sim(32, 32, ainit, .02, 0., .1,.1,.1,.1, .1, .001, T, 5000, dt);
	while(T<=Tmax){
		std::cout << "T = " << T << std::endl;
		while(ainit<=AinitMax){
			std::cout << "ainit = " << ainit << std::endl;
			sim.reset(32, 32, ainit, .02, 0., .1,.1,.1,.1, .1, .001, T, 5000, dt);
			currentRun= sim.run();
			myfile << ainit <<","<<T<<","<<currentRun<<"\n";
			if (prevRun!=-2){
			// doesn't refine during the first iteration
				if ((currentRun==0 or currentRun==-1) and currentRun!=prevRun){
					refine(ainit , dA, T, dt, &myfile, &sim);
				}
			}
			prevRun=currentRun; 
			ainit+=dA;
		}
		++T;
		ainit=AinitMin;
	}

	//////// Closing the output file ////////
	myfile.close();

	return 0;
}

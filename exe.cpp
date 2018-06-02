#include <iostream>
#include <fstream>
#include "Bacteria.h"
#include "Cell.h"
#include "Ga.h"
#include "Gb.h"
#include "Simulation.h"

///////// refine function /////////
void refine(unsigned int TMax, unsigned int dT, float ainit, float dt, ofstream* myfile, Simulation* sim){
	// refines the parametric exploration
	unsigned int TMin=TMax-dT;
	dT= dT/10;
	unsigned int T = TMin+dT;
	
	while(T<TMax){
		std::cout << "T = " << T << std::endl;
		sim->reset(32, 32, ainit, .02, 0., .1,.1,.1,.1, .1, .001, T, 5000, dt);
		(*myfile) << ainit <<","<<T<<","<<sim->run()<<"\n";
		T+=dT;
	}				
}

int main(int argc, char* argv[]){

	srand(time(NULL)); //seed used by rand (	we'll have to use srand(time(NULL)) eventually)	

	//////// Defining Ainit step dA and time step dt  ////////
	float dA=1.;
	float dt=0.1;
  unsigned int dT=50;

	//////// Defining T and Ainit domain ////////
	unsigned int TMin=1;
	unsigned int TMax=1500;//1500

	float AinitMin=0;
	float AinitMax=50.;



	//////// Initializing T and Ainit ////////
	unsigned int T=TMin;
	float ainit=AinitMin;

	//////// Defining prevRun and currentRun ////////
	float prevRun;
	float currentRun;

	//////// Creating the output file ////////
	ofstream myfile;
	myfile.open("SimulationOutputs.csv");

	//////// Filling the output file with the simulation  ////////

	// Simualtion sim(height, width, ainit, pdeath, pmut, Raa, Rab, Rbb, Rbc, d, wmin, T, tend, dt)
	Simulation sim(32, 32, ainit, .02, 0., .1,.1,.1,.1, .1, .001, T, 5000, dt);
  while(ainit<=AinitMax){
    std::cout << "ainit = " << ainit << std::endl;
		prevRun=-2;
		while(T<=TMax){
			std::cout << "T = " << T << std::endl;
			sim.reset(32, 32, ainit, .02, 0., .1,.1,.1,.1, .1, .001, T, 5000, dt);
			currentRun= sim.run();
			std::cout << "result = " << currentRun << std::endl;
			myfile << ainit <<","<<T<<","<<currentRun<<"\n";
			if (prevRun!=-2){
			// doesn't refine during the first iteration
				if ((currentRun==0 or currentRun==-1) and currentRun!=prevRun){
					refine(T , dT, ainit, dt, &myfile, &sim);
				}
			}else{
			  refine(T , dT, ainit, dt, &myfile, &sim);
			}
			prevRun=currentRun; 
			if(T < TMax and (T+dT)> TMax){ //To be sure to do the simulation for TMax
			  T=TMax;
		    }else{
			  T+=dT;
		    }
		}
		if(ainit < AinitMax and (ainit+dA)> AinitMax){ //To be sure to do the simulation for AinitMax
			ainit=AinitMax;
		}else{
			ainit+=dA;
		}
		T=TMin;
	}

	//////// Closing the output file ////////
	myfile.close();

	return 0;
}

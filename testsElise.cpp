#include <iostream>
#include "Bacteria.h"
#include "Cell.h"
#include "Ga.h"
#include "Gb.h"
#include "Simulation.h"

int main(int argc, char* argv[]){
	std::cout << "Testing creation of bacterias (Ga et Gb)" << std::endl;
	Gb bactB(1.0,2.0,3.0);
	Ga bactA(1.0,0.3,3.0);
	
	std::cout << "\nTesting getW()" << std::endl;
	std::cout << "Ga bacteria : " << bactA.getW() << std::endl;
	std::cout << "Gb bacteria : " << bactB.getW() << std::endl;
	
	std::cout << "\nTesting metabolize()" << std::endl;
	bactA.metabolize(0.1,0.1,0.1,0.1,0.1,0.1,0.1);
	bactB.metabolize(0.1,0.1,0.1,0.1,0.1,0.1,0.1);
	std::cout << "Ga bacteria : " << bactA.getW() << std::endl;
	std::cout << "Gb bacteria : " << bactB.getW() << std::endl;

	return 0;
}

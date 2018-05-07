#include <iostream>
#include "Bacteria.h"
#include "Cell.h"
#include "Ga.h"
#include "Gb.h"

int main(int argc, char* argv[]){
	std::cout << "Testing creation of bacterias (Ga et Gb)" << std::endl;
	Gb bactB(1.0,2.0,3.0);
	Ga bactA(1.0,0.5,3.0);
	
	std::cout << "\nTesting getW()" << std::endl;
	std::cout << "Ga bacteria : " << bactA.getW() << std::endl;
	std::cout << "Gb bacteria : " << bactB.getW() << std::endl;
	
	std::cout << "\nTesting die()" << std::endl;
	std::cout << "bactA.die() : " << bactA.die(0.5) << std::endl;
	std::cout << "bactB.die() : " << bactB.die(0.5) << std::endl;
	
	return 0;
}

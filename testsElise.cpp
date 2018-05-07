#include <iostream>
#include "Bacteria.h"
#include "Cell.h"
#include "Ga.h"
#include "Gb.h"

int main(int argc, char* argv[]){
	std::cout << "Tests création bactéries de type Ga et Gb" << std::endl;
	Gb bactB(1.0,2.0,3.0);
	Ga bactA(1.0,2.0,3.0);
	
	return 0;
}

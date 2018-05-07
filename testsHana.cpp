#include <iostream>
#include "Bacteria.h"
#include "Cell.h"
#include "Ga.h"
#include "Gb.h"

int main(int argc, char* argv[]){

	//testing Cell default ctor
	std::cout << "testing Cell default ctor" << std::endl;
	Cell cell1(1.0,2.0,3.0, 1, 1);
	
	return 0;
}

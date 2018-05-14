#include <iostream>
#include "Bacteria.h"
#include "Cell.h"
#include "Ga.h"
#include "Gb.h"
#include "Simulation.h"
#include "Coordinates.h"

int main(int argc, char* argv[]){
	std::cout << "Testing creation of bacterias (Ga et Gb)" << std::endl;
	Gb * bactB = new Gb(1.0,2.0,3.0);
	Ga * bactA = new Ga(1.0,0.3,3.0);
	std::cout << "Number of Ga instances (L bacteria) : " << Ga::nbL_ << std::endl;
	std::cout << "Number of Gb instances (S bacteria) : " << Gb::nbS_ << std::endl;
	
	std::cout << "\nTesting getW()" << std::endl;
	std::cout << "Ga bacteria : " << bactA->getW() << std::endl;
	std::cout << "Gb bacteria : " << bactB->getW() << std::endl;
	
	std::cout << "\nTesting metabolize()" << std::endl;
	bactA->metabolize(0.1,0.1,0.1,0.1,0.1,0.1,0.1);
	bactB->metabolize(0.1,0.1,0.1,0.1,0.1,0.1,0.1);
	std::cout << "Ga bacteria : " << bactA->getW() << std::endl;
	std::cout << "Gb bacteria : " << bactB->getW() << std::endl;
	
	std::cout << "\nTesting coordinates()" << std::endl;
	Coordinates c0(0,0);
	Coordinates c1(0,1);
	Coordinates c2(1,0);
	Coordinates c3(9,5,3);
	Coordinates c4(13,5,3);
	
	std::cout << "Testing Grid with h=5 * w=3" << std::endl;
	std::cout << "(0,0) ==> " << c0.to_int(5) << std::endl;
	std::cout << "(0,1) ==> " << c1.to_int(5)<< std::endl;
	std::cout << "(1,0) ==> " << c2.to_int(5)<< std::endl;
	std::cout << "9 ==> " << c3.x() << " " << c3.y() << std::endl;
	std::cout << "13 ==> " << c4.x() << " " << c4.y()<< std::endl;
	
	std::cout << "\nTesting creation of instance Simulation : " << std::endl;
	Simulation sim(2,2,3.,.6,.4,.6,.6,.6,.6,.6,.6,.7,10.,.001);
	std::cout << "\nNumber of Ga instances (L bacteria) : " << Ga::nbL_ << std::endl;
	std::cout << "Number of Gb instances (S bacteria) : " << Gb::nbS_ << std::endl;
	
	delete bactB;
	delete bactA;
	std::cout << "\nNumber of Ga instances (L bacteria) : " << Ga::nbL_ << std::endl;
	std::cout << "Number of Gb instances (S bacteria) : " << Gb::nbS_ << std::endl;
	
	return 0;
}

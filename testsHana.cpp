#include <iostream>
#include "Bacteria.h"
#include "Cell.h"
#include "Ga.h"
#include "Gb.h"
#include <cstdlib> 
#include "Grid.h"
#include "Simulation.h"

int main(int argc, char* argv[]){

//////////// Testing Cell //////////////////

	//testing Cell default ctor
	std::cout << "testing Cell default ctor" << std::endl;
	Cell cell1(1.0,2.0,3.0, 1, 1);
	std::cout << "cell1 : " << std::endl;
	std::cout << "a = " <<cell1.a() << std::endl;
	std::cout << "b = " <<cell1.b() << std::endl;
	std::cout << "c = " <<cell1.c() << std::endl;
	std::cout << "cell1.bacteria() -> a() = " <<cell1.bacteria() -> a() << std::endl;

	std::cout << std::endl;

	//testing update
	std::cout << "testing update" << std::endl;	
	cell1.seta(10.);
	cell1.setb(20.);
	cell1.setc(30.0);
	std::cout << "cell1 after using update : " << std::endl;
	std::cout << "a = " <<cell1.a() << std::endl;
	std::cout << "b = " <<cell1.b() << std::endl;
	std::cout << "c = " <<cell1.c() << std::endl;
	std::cout << "cell1.bacteria() -> a() = " <<cell1.bacteria() -> a() << std::endl;

	//testing die
	/*cell1.die(.4, .001);
	std::cout << "cell1 after using die : " << std::endl;
	std::cout << "a = " <<cell1.a() << std::endl;
	std::cout << "b = " <<cell1.b() << std::endl;
	std::cout << "c = " <<cell1.c() << std::endl;
	std::cout << "After using die and before setbacteriaA, cell1.bacteria() -> a() = " <<cell1.bacteria() -> a() << std::endl;
	cell1.setbacteriaA(5., 6., 7.); //temporary solution in order to avoid a segmentation fault while waiting for Grid methods.
	std::cout << "After using die and setbacteriaA, cell1.bacteria() -> a() = " <<cell1.bacteria() -> a() << std::endl;*/

//////////// Testing Grid //////////////////
	
	//testing Reinit
	std::cout << "testing Grid Reinit" << std::endl;
	Grid Grid1(2,2, 3., .4, .3, .6, .6, .6, .6, .7, .0001);
	std::cout << "Before reinit : " << Grid1.getcell(1,1) -> a() << std::endl;

	Grid1.reinit(30.);
	std::cout << "After reinit : " << Grid1.getcell(1,1) -> a() << std::endl;	

//////////// Testing Simulation //////////////////

	//testing isExtinct
	Simulation Simulation1(1, 1, 3.,.6, .4, .6, .6, .6,	.6, .6, .6, .7, 10., .001); 


	return 0;
}

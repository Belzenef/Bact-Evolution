#include <iostream>
#include "Bacteria.h"
#include "Cell.h"
#include "Ga.h"
#include "Gb.h"
#include <cstdlib> 
#include "Grid.h"
#include "Simulation.h"

int main(int argc, char* argv[]){

	srand(3); //seed used by rand (	we'll have to use srand(time(NULL)) eventually)

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
	std::cout << "Before using die, cell1.bacteria() -> a() = " <<cell1.bacteria() -> a() << std::endl;
	cell1.die(.4);
	std::cout << "cell1 after using die : " << std::endl;
	std::cout << "a = " <<cell1.a() << std::endl;
	std::cout << "b = " <<cell1.b() << std::endl;
	std::cout << "c = " <<cell1.c() << std::endl;
	/*cell1.setbacteriaA(5., 6., 7.); //temporary solution in order to avoid a segmentation fault while waiting for Grid methods.
	std::cout << "After using die and setbacteriaA, cell1.bacteria() -> a() = " <<cell1.bacteria() -> a() << std::endl;*/

//////////// Testing Grid //////////////////
	
	//testing Reinit
	/*std::cout << "testing Grid Reinit" << std::endl;
	Grid Grid1(2,2, 3., .4, .3, .6, .6, .6, .6, .7, .0001);
	std::cout << "Before reinit : " << Grid1.getcell(1,1) -> a() << std::endl;

	Grid1.reinit();
	std::cout << "After reinit : " << Grid1.getcell(1,1) -> a() << std::endl;

	//testing metabolize
	std::cout << "testing Grid metabolize" << std::endl;
	std::cout << "Grid1 Cell at coordinates (1,1) has :" << std::endl;
	std::cout << "A= " << Grid1.getcell(1,1)->a()<< std::endl;
	std::cout << "B= " << Grid1.getcell(1,1)->b()<< std::endl;
	Grid1.metabolize(.0001);

	std::cout << "After metabolize, Grid1 Cell at coordinates (1,1) has :" << std::endl;
	std::cout << "A= " << Grid1.getcell(1,1)->a()<< std::endl;
	std::cout << "B= " << Grid1.getcell(1,1)->b()<< std::endl;*/
	

//////////// Testing Simulation //////////////////

	//testing run() 
	/*std::cout << "testing Grid simulation" << std::endl;
	Simulation Simulation1(2, 2, 3.,.6, .4, .6, .6, .6,	.6, .6, .6, 3, 2, .5);
	std::cout<<Simulation1.getgrid()->toString()<<std::endl;
	std::cout << "number of Ga instances : " << Ga::nbL_ << std ::endl;
	std::cout << "number of Gb instances : " << Gb::nbS_ << std ::endl;
	std::cout<< "Simulation1.run()= " << Simulation1.run() <<std::endl;
	std::cout << "After Simulation1.run(), number of Ga instances : " << Ga::nbL_ << std ::endl;
	std::cout << "number of Gb instances : " << Gb::nbS_ << std ::endl;
	std::cout<<Simulation1.getgrid()->toString()<<std::endl;

	Simulation Simulation2(4, 4, 1., .02, 0., .1,.1,.1,.1, .1, .001, 5., 5000, .01);
	std::cout<<Simulation2.getgrid()->toString()<<std::endl;
	std::cout<< "Simulation2.run()= " << Simulation2.run() <<std::endl;
	std::cout<<Simulation2.getgrid()->toString()<<std::endl;*/

	return 0;
}

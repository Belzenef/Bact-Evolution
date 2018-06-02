#include <iostream>
#include "Grid.h"
#include"Gb.h"
#include "Bacteria.h"
#include "Simulation.h"
using namespace std;

int main(int argc, char* argv[]){
//Grid* mygrid2=new Grid(5,6,0.5,0.01,0.2,1.,1.,1.,1.,0.1,0.0);
//cout<<mygrid2->height()<<endl;

Simulation sim(32, 32, 25, .02, 0., .1,.1,.1,.1, .1, .001, 1000, 5000, 1.); cout<<(sim.getgrid())->getcell(1,1)->bacteria()<<endl;
cout<<sim.run()<<endl;

  
  return 0;
}

#include <iostream>
#include "Grid.h"
#include"Gb.h"
#include "Bacteria.h"
using namespace std;

int main(int argc, char* argv[]){
  Grid mygrid(5,6,0.5,0.1,0.2,1.,1.,1.,1.,0.1,10);
  Cell* changed= mygrid.getcell(1,1);
  changed->setb(0.8);
  for(int k=0; k<100; ++k){
    cout<< mygrid.getcell(2,2)->b() <<"  " << mygrid.getcell(1,1)->b() << "  " 
    << mygrid.getcell(3,1)->b()<<endl;
    mygrid.diffuse();
  }
  
  return 0;
}

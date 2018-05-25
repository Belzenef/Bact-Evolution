#include <iostream>
#include "Grid.h"
#include"Gb.h"
#include "Bacteria.h"
#include "Simulation.h"
using namespace std;

int main(int argc, char* argv[]){
//Grid* mygrid2=new Grid(5,6,0.5,0.01,0.2,1.,1.,1.,1.,0.1,0.0);
//cout<<mygrid2->height()<<endl;

 Simulation sim(5,6,0.5,0.01,0.2,1.,1.,1.,1.,0.1,0.1,5.,5.,5.);


  Grid* mygrid=sim.getgrid();
//mygrid->toString();
cout<<mygrid->toString();

  //Grid* mygrid=new Grid(5,6,0.5,0.01,0.2,1.,1.,1.,1.,0.1,0.0);
  Cell* changed= mygrid->getcell(1,1);
  for (int line=0;line<5;++line){
      for (int col=0;col<6;++col){
        mygrid->getcell(col,line)->bacteria()->setb(0.5);
        mygrid->getcell(col,line)->bacteria()->setc(0.5);
      }
  }
  
  for(int k=0; k<100; ++k){
    cout<<"-------------------------------";
    if(mygrid->compete()){
      cout<<endl;
      cout<<endl;
      cout<<mygrid->toString();
      //mygrid->toString();

      for (int line=0;line<5;++line){
        for (int col=0;col<6;++col){
          if ( (mygrid->getcell(col,line)->bacteria() )!=nullptr){
            mygrid->getcell(col,line)->bacteria()->metabolize(0.1,0.1,mygrid->getcell(col,line)->a(),0.1,0.1,mygrid->getcell(col,line)->b(),0.1);
          }
        }
      }
      cout<<mygrid->toString();
    }else{
      cout<<"Extinction"<<endl;
      break;
    }
  }

Grid* test=new Grid(2,2,0.5,0.01,0.2,1.,1.,1.,1.,0.1,0.0);

delete test;
//delete mygrid;
  
  return 0;
}

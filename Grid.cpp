#include "Grid.h"

//======================================================================
//                              Constructors
//======================================================================
Grid::Grid(unsigned int height,unsigned int width, float ainit, float pdeath, float pmut): 
  height_(height), width_(width), ainit_(ainit), pdeath_(pdeath), pmut_(pmut) {
  int* coord;
  for(int x=0; x<height_; ++x){
    for(int y=0; y<width_; ++y){
      coord= new int[2];
      coord[0]=x;
      coord[1]=y;
      grid_.emplace (coord,Cell(ainit_,0,0,x,y) );
    }     
  }
}
//======================================================================
//                              Destructors
//======================================================================
Grid::~Grid(){
  for ( auto it : grid_){
    delete[] it.first;
  }
}

#include "Grid.h"

//======================================================================
//                              Constructors
//======================================================================
Grid::Grid(unsigned int height,unsigned int width, float ainit, float pdeath, float pmut, float raa, float rab, float rbb, float rbc, float d, float wmin): 
  height_(height), width_(width), ainit_(ainit), pdeath_(pdeath), pmut_(pmut), raa_(raa), rab_(rab), rbb_(rbb), rbc_(rbc), d_(d), wmin_(wmin) {
  for(int x=0; x<width_; ++x){
    for(int y=0; y<height_; ++y){
      grid_.emplace (Coordinates(x,y).to_int(height_,width_),Cell(ainit_,0,0,x,y) );
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
// =====================================================================
//                        Public Function members
// =====================================================================
void Grid::diffuse(){
  for ( auto it : grid_){
    it.second.update(); //prev_a_<-a_, prev_b_<-b, prev_c_<-c_
  }
  
  int other_x, other_y; //cell from  which elements diffuse
  Coordinates my_coord//cell in which we calculate the new elements' concentrations
  Cell my_cell, other_cell;

  for ( auto it : grid_){
    for (int dx=-1; dx<=1; ++dx){
      for (int dy=-1; dy<=1; ++dy){ 
        my_coord=it.first;
        other_x=my_coord.x()+dx;
        other_y=my_coord.y()+dy;

        //take care of the borders (our grid is a tore)
        if( other_x==-1 ){
          other_x=width_-1;
        }else if( other_x==width_ ){
          other_x=0;
        }
        if( other_y==-1 ){
          other_y=height_-1;
        }else if( other_y==height_ ){
          other_y=0;
        }

        my_cell=it.second;
        other_cell=grid_.at( Coordinates(other_x,other_y).to_int() );

        my_cell.seta( my_cell.a()+d_*other_cell.preva()-9*d_*my_cell.preva() );
        my_cell.setb( my_cell.b()+d_*other_cell.prevb()-9*d_*my_cell.prevb() );
        my_cell.setc( my_cell.c()+d_*other_cell.prevc()-9*d_*my_cell.prevc() );
      }
    }
  }
}

void Grid::reinit(float Ainit){
	for ( auto it : grid_ ){
		it.second.a()=Ainit;
		it.second.b()=0;
		it.second.c()=0;
	}
}


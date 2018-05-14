#include "Grid.h"
#include<iostream>
using std::cout;
using std::endl;

//======================================================================
//                              Constructors
//======================================================================
Grid::Grid(unsigned int height,unsigned int width, float ainit, float pdeath, float pmut, float raa, float rab, float rbb, float rbc, float d, float wmin): 
  height_(height), width_(width), ainit_(ainit), pdeath_(pdeath), pmut_(pmut), raa_(raa), rab_(rab), rbb_(rbb), rbc_(rbc), d_(d), wmin_(wmin) {
  for(int x=0; x<width_; ++x){
    for(int y=0; y<height_; ++y){
      grid_[Coordinates(x,y).to_int(height_)] = new Cell(ainit_,0,0,x,y);
    }     
  }
}
//======================================================================
//                              Destructors
//======================================================================
Grid::~Grid() {
  for(auto it:grid_){
    delete it.second;
  }
}

//======================================================================
//                              Getters
//======================================================================
  //JUST FOR TESTS
  Cell* Grid::getcell(int x, int y){
    int key=Coordinates(x,y).to_int(height_);
    return grid_.at(key);
  }
// =====================================================================
//                        Public Function members
// =====================================================================
void Grid::diffuse(){
  for ( auto it : grid_){
    it.second->update(); //prev_a_<-a_, prev_b_<-b, prev_c_<-c_
  }
  vector<Cell*> neighbours_list;
  Cell* my_cell;
  for ( auto it : grid_){
    my_cell=it.second;
    //fetch neighbours
    neighbours_list=neighbours(it.first);

    for (auto other_cell : neighbours_list){
      //diffuse
      my_cell->seta( my_cell->a()+d_*other_cell->preva() ); 
      my_cell->setb( my_cell->b()+d_*other_cell->prevb() );
      my_cell->setc( my_cell->c()+d_*other_cell->prevc() );
    }
  my_cell->seta(my_cell->a()-9*d_*my_cell->preva() );
  my_cell->setb(my_cell->b()-9*d_*my_cell->prevb() );
  my_cell->setc(my_cell->c()-9*d_*my_cell->prevc() );
  }
}

void Grid::compete(){
  for ( auto it : grid_){ //check who is dead
    it.second->die(pdeath_,wmin_); 
  }

  vector<Cell*> neighbours_list;
  Cell* my_cell;

  for ( auto it : grid_){
    my_cell=it.second;
    if( (my_cell->bacteria()) == nullptr ){ //if the bacteria is dead
      //TESTS
  
      cout<< "x:"<<(Coordinates(it.first,height_,width_)).x()<<" y:"<<(Coordinates(it.first,height_,width_)).y()<<" is dead"<<endl;
      //fetch neighbours
      neighbours_list=alive_neighbours(it.first);

      Cell* best_neighbour;
      unsigned int best_fitness=0;
      for (auto other_cell : neighbours_list){
        if ( ( ( other_cell->bacteria() )->getW() )>best_fitness ){
          best_neighbour=other_cell;
          best_fitness= ( ( other_cell->bacteria() )->getW() );
        }
      }
      best_neighbour->fill(my_cell);
      cout<<"replaced";
    }
  }
}
// =====================================================================
//                        Protected Function members
// =====================================================================
vector<Cell*> Grid::neighbours(unsigned int coordinates){
  int other_x, other_y; //neighbour cell
  Cell* other_cell;
  Coordinates my_coord(coordinates,height_,width_) ;
  vector<Cell*> neighbours_list;
  for (int dx=-1; dx<=1; ++dx){
    for (int dy=-1; dy<=1; ++dy){ 
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

      //add neighbour to the vector
      other_cell=grid_.at( Coordinates(other_x,other_y).to_int(height_) );
      neighbours_list.push_back( other_cell );
    }
  } 
  return neighbours_list;
}

vector<Cell*> Grid::alive_neighbours(unsigned int coordinates){ //same as neighbours with one "if" added
  int other_x, other_y; //neighbour cell
  Cell* other_cell;
  Coordinates my_coord(coordinates,height_,width_) ;
  vector<Cell*> neighbours_list;
  for (int dx=-1; dx<=1; ++dx){
    for (int dy=-1; dy<=1; ++dy){ 
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

      //add neighbour to the vector
      other_cell=grid_.at( Coordinates(other_x,other_y).to_int(height_) );
      if ( ( other_cell->bacteria() )!=nullptr ){
        neighbours_list.push_back( other_cell );
      }
    }
  } 
  return neighbours_list;
}



void Grid::reinit(float Ainit){
	for ( auto it : grid_ ){
		it.second -> seta(Ainit);
		it.second -> setb(0);
		it.second -> setc(0);
	}
}



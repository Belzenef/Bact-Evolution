/***********************************************************************
 * This class allow us to stock every cell containing the bacteria, 
 * in a big unordered_map. It also treat the competition and diffusion 
 * function, and ensure that bacterias metabolize when we want.
 * ********************************************************************/ 

#ifndef GRID  // if guard
#define GRID

#include <unordered_map>
#include <memory>
#include <vector>
#include <string>
#include "Cell.h"
#include "Coordinates.h"

using namespace std;

class Grid{
  public :
//======================================================================
//                              Constructors
//======================================================================
  Grid()=delete;
  Grid(const Grid& Grid)=delete;
  Grid(unsigned int height,unsigned int width, float ainit, float pdeath, float pmut, float raa, float rab, float rbb, float rbc, float d, float wmin);
//======================================================================
//                              Destructors
//======================================================================
  virtual ~Grid();
//======================================================================
//                              Getters
//======================================================================
  Cell* getcell(int x, int y); //return the cell at coordinates (x,y)
  inline unsigned int height();
//======================================================================
//                              Setters
//======================================================================
// =====================================================================
//                        Public Function members
// =====================================================================
  void diffuse(); 
  bool compete();//return false if extinction
	void metabolize(float dt);//runs Bacteria::metabolize for each alive bacteria of the Grid.
	void reinit(); //Wash the grid, reinitializing a_,b_,c_ for each cell to (ainit_,0,0)

  string toString(); //Unused function, except for testing

  protected :

// =====================================================================
//                               Data members
// =====================================================================
  unordered_map<int,Cell*> grid_;
  unsigned int height_;
  unsigned int width_;
  float ainit_;
  float pdeath_;
  float pmut_;
  float raa_;
  float rab_;
  float rbb_;
  float rbc_;
  float d_;
  float wmin_;

// =====================================================================
//                        Protected Function members
// =====================================================================
  vector<Cell*> neighbours(unsigned int coordinates); //Return a vector containing the neighbours of the cell at coordinates
  vector<Cell*> fine_neighbours(unsigned int coordinates);//Return a vector containing the non-zero-fitness-ed neighbours of the cell at coordinates
  bool isExtinct(); // tests whether the population is extinct (returns TRUE if this is the case)

};
// =====================================================================
//                        Protected Function members
// =====================================================================
inline unsigned int Grid::height(){return height_;}
#endif

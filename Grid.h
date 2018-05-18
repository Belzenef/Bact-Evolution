#ifndef GRID  // if guard
#define GRID

#include <unordered_map>
#include <memory>
#include <vector>
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
  //JUST FOR TESTS
  Cell* getcell(int x, int y);
  inline unsigned int height();
//======================================================================
//                              Setters
//======================================================================
// =====================================================================
//                        Public Function members
// =====================================================================
  void diffuse();

  bool compete();//return false if extinction
	void metabolize(float dt);
	void reinit();

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
  vector<Cell*> neighbours(unsigned int coordinates);
  vector<Cell*> alive_neighbours(unsigned int coordinates);
  bool isExtinct(); // tests whether the population is extinct (returns 1 if this is the case)

};
// =====================================================================
//                        Protected Function members
// =====================================================================
inline unsigned int Grid::height(){return height_;}
#endif

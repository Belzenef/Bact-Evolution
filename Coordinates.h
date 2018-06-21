#ifndef COORD_H  
#define COORD_H
/*This class allow us to create coordinates (x,y) for a cell in the grid, and to convert it to a single index, that will be the key for the unsigned_map in which we stock the cell*/

class Coordinates {
	public :
// =====================================================================
//                               Constructors
// =====================================================================
  Coordinates(unsigned int x, unsigned int y);
  Coordinates(unsigned int n, unsigned int height, unsigned int width);
  Coordinates(const Coordinates &) = delete;
  Coordinates() = delete;
  
// =====================================================================
//                                Destructor
// =====================================================================
  virtual ~Coordinates();

// =====================================================================
//                                 Getters
// =====================================================================
  inline unsigned int x() const;
  inline unsigned int y() const;
  
  
// =====================================================================
//                           Public Function members
// =====================================================================
  unsigned int to_int(unsigned int height); //return the single index, key of the unsigned_map.

  protected :
// =====================================================================
//                               Data members
// =====================================================================
  unsigned int x_;
  unsigned int y_;
		
};

// =====================================================================
//                                Inline definitions
// =====================================================================

inline unsigned int Coordinates::x() const{ return x_; }
inline unsigned int Coordinates::y() const{ return y_; }

#endif

#ifndef COORD_H  
#define COORD_H

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
//                                Operators
// =====================================================================
  bool operator<(const Coordinates &) const;
  
// =====================================================================
//                           Public Function members
// =====================================================================
  unsigned int to_int(unsigned int height, unsigned int width);
  
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
inline unsigned int Coordinates::x() { return x_; }
inline unsigned int Coordinates::y() { return y_; }

#endif

#ifndef COORD_H  
#define COORD_H

class Coordinates {
	public :
// =====================================================================
//                               Constructors
// =====================================================================
  Coordinates(unsigned int x, unsigned int y);
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

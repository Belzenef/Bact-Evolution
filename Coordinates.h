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
  bool operator<(const Coordonnees &) const;
  
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

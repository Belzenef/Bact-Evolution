#ifndef CELL_H_
#define CELL_H_
#include "Bacteria.h"
#include "Ga.h"
#include "Gb.h"

class Cell{
 public :
// =====================================================================
//                               Constructors
// =====================================================================
  Cell(float a, float b, float c,unsigned int x, unsigned int y);

// =====================================================================
//                                Destructor
// =====================================================================
  virtual ~Cell();

// =====================================================================
//                                  Getters
// =====================================================================
  inline unsigned int x();
  inline unsigned int y();
  inline float a();
  inline float b();
  inline float c();
  inline float preva();
  inline float prevb();
  inline float prevc();
  inline Bacteria * bacteria();

// =====================================================================
//                                  Setters
// =====================================================================
  inline void seta(float a);
  inline void setb(float b);
  inline void setc(float c);
  
// =====================================================================
//                        Public Function members
// =====================================================================
  void update();
  bool die(float pdeath);

 protected :

// =====================================================================
//                               Data members
// =====================================================================
  unsigned int x_;
  unsigned int y_;
	Bacteria * bacteria_;
	float a_;
	float b_;
	float c_;
  float preva_;
	float prevb_;
	float prevc_;

// =====================================================================
//                        Protected Function members
// =====================================================================

}; 
// =====================================================================
//                            Inline definitions
// =====================================================================
inline float Cell::a() { return a_; }
inline float Cell::b() { return b_; }
inline float Cell::c() { return c_; }
inline float Cell::preva() { return preva_; }
inline float Cell::prevb() { return prevb_; }
inline float Cell::prevc() { return prevc_; }
inline unsigned int Cell::x() { return x_; }
inline unsigned int Cell::y() { return y_; }
inline Bacteria * Cell::bacteria() { return bacteria_; }
inline void Cell::seta(float a) { a_=a; }
inline void Cell::setb(float b) { b_=b; }
inline void Cell::setc(float c) { c_=c; }

#endif //CELL_H_

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
	inline void setbacteriaA( float a, float b, float c); // sets bacteria_ with an A bacteria (created to test die. Do not use before deleting bacteria_)
  inline void setbacteriaB( float a, float b, float c); // sets bacteria_ with a B bacteria (created to test die. Do not use before deleting bacteria_)

// =====================================================================
//                        Public Function members
// =====================================================================
  void update();
  bool die(float pdeath, float wmin); // tests whether the bacteria in this Cell is dead and deletes it, as well as returning a bool true, if it is the case. Returns a false otherwise.

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

  //the three last data members should be used only by Grid's diffuse().
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
inline void Cell::setbacteriaA( float a, float b, float c){bacteria_ = new Ga(a, b, c);}
inline void Cell::setbacteriaB( float a, float b, float c){bacteria_ = new Gb(a, b, c);}

#endif //CELL_H_

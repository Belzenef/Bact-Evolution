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
  Cell()=delete;
  Cell(const Cell& cell)=delete;

// =====================================================================
//                                Destructor
// =====================================================================
  virtual ~Cell();

// =====================================================================
//                                  Getters
// =====================================================================
  inline unsigned int x() const;
  inline unsigned int y() const;
  inline float a() const;
  inline float b() const;
  inline float c() const;
  inline float preva() const;
  inline float prevb() const;
  inline float prevc() const;
  inline Bacteria * bacteria() const;

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
  void fill(Cell*);
  void update();
  void die(float pdeath, float wmin); // tests whether the bacteria in this Cell is dead and deletes it, as well as returning a bool true, if it is the case. Returns a false otherwise.

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
inline float Cell::a() const{ return a_; }
inline float Cell::b() const{ return b_; }
inline float Cell::c() const{ return c_; }
inline float Cell::preva() const{ return preva_; }
inline float Cell::prevb() const{ return prevb_; }
inline float Cell::prevc() const{ return prevc_; }
inline unsigned int Cell::x() const{ return x_; }
inline unsigned int Cell::y() const{ return y_; }
inline Bacteria * Cell::bacteria() const{ return bacteria_; }
inline void Cell::seta(float a) { a_=a; }
inline void Cell::setb(float b) { b_=b; }
inline void Cell::setc(float c) { c_=c; }
inline void Cell::setbacteriaA( float a, float b, float c){bacteria_ = new Ga(a, b, c);}
inline void Cell::setbacteriaB( float a, float b, float c){bacteria_ = new Gb(a, b, c);}

#endif //CELL_H_

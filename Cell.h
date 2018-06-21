/***********************************************************************
 * this class defines a Cell containing a bacteria as well as the 
 * different metabolites'concentration specific to this Cell. 
 * It can also check whether its bacteria is alive. If need be, 
 * it can fill itself with a daughter bacteria who can mutate
 * ********************************************************************/ 

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
	void setbacteriaA( float a, float b, float c); // sets bacteria_ with an A bacteria (created to test die. Do not use before deleting bacteria_)
  void setbacteriaB( float a, float b, float c); // sets bacteria_ with a B bacteria (created to test die. Do not use before deleting bacteria_)

// =====================================================================
//                        Public Function members
// =====================================================================
  void fill(Cell* to_fill, float pmut); // fills the Cell with a daughter bacteria which can mutate with a probability pmut
  void update(); // preva_ <- a_ , prevb_ <- b_ , prevc_ <- c_
  void die(float pdeath); // tests whether the bacteria in this Cell is dead and deletes it

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


#endif //CELL_H_

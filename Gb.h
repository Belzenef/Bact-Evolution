/***********************************************************************
 * This class defines the general behaviour 
 * of a S bacteria (with B genotype)
 * Inherited from class Bacteria
 * ********************************************************************/

#ifndef GB_H  
#define GB_H

#include "Bacteria.h"

class Gb : public Bacteria {
 public :
// =====================================================================
//                               Constructors
// =====================================================================
	Gb(float a, float b, float c);

// =====================================================================
//                                Destructor
// =====================================================================
  virtual ~Gb();
  
// =====================================================================
//                           Public Function members
// =====================================================================
  float metabolize(float Raa, float Rab, float Aout, float Rbb, float Rbc, float Bout, float dt);
  inline bool isGa() const override;
  virtual float getW(float wmin) override;
// =====================================================================
//                       Definition of static attributes
// =====================================================================
	static unsigned int nbS_;   // Number of Gb instances currently existing

};

// =====================================================================
//                            Inline definitions
// =====================================================================
inline bool Gb::isGa() const { return false; }

#endif

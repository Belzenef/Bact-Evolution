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
  inline float getW();

};

// =====================================================================
//                            Inline definitions
// =====================================================================
inline float Gb::getW() { return c_; }

#endif

#ifndef GA_H  
#define GA_H

#include "Bacteria.h"

class Ga : public Bacteria {
 public :
// =====================================================================
//                               Constructors
// =====================================================================
  Ga(float a, float b, float c);

// =====================================================================
//                                Destructor
// =====================================================================
  virtual ~Ga();
  
// =====================================================================
//                           Public Function members
// =====================================================================
  float metabolize(float Raa, float Rab, float Aout, float Rbb, float Rbc, float Bout, float dt);
  inline float getW();
  inline unsigned int nbL() const;
  
// =====================================================================
//                       Definition of static attributes
// =====================================================================
	static unsigned int nbL_;
  
};

// =====================================================================
//                            Inline definitions
// =====================================================================
inline float Ga::getW() { return b_; }
inline unsigned int Ga::nbL() const { return nbL_; }

#endif


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
  inline bool isGa() const override;
  virtual float getW(float wmin) override;

// =====================================================================
//                       Definition of static attributes
// =====================================================================
	static unsigned int nbL_;
  
};

// =====================================================================
//                            Inline definitions
// =====================================================================
inline bool Ga::isGa() const { return true; }

#endif


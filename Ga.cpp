#include "Ga.h"

// =====================================================================
//                       Definition of static attributes
// =====================================================================
unsigned int Ga::nbL_ = 0;

// =====================================================================
//                                Constructors
// =====================================================================
Ga::Ga(float a, float b, float c) : Bacteria(a, b, c) {
		++nbL_;
} 

// =====================================================================
//                                 Destructor
// =====================================================================
Ga::~Ga(){
    --nbL_;
}

// =====================================================================
//                           Public Function members
// =====================================================================

float Ga::metabolize(float Raa, float Rab, float Aout, float Rbb, float Rbc, float Bout, float dt){
  float i=0;
  while(i<1.0){
    Aout += dt*(-Aout*Raa);
    a_ += dt*(Aout*Raa - a_*Rab);
    b_ += dt*(a_*Rab);
    i+=dt;
  }
  return Aout;
}

float Ga::getW(float wmin){
  if (b_<wmin)
    return 0;
  else
    return b_;
}

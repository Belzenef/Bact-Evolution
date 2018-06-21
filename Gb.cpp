#include "Gb.h"

// =====================================================================
//                       Definition of static attributes
// =====================================================================
unsigned int Gb::nbS_ = 0;

// =====================================================================
//                                Constructors
// =====================================================================
Gb::Gb(float a, float b, float c) : Bacteria(a, b, c) {
  ++nbS_;
}

// =====================================================================
//                                 Destructor
// =====================================================================
Gb::~Gb(){
  --nbS_;
}

// =====================================================================
//                           Public Function members
// =====================================================================
float Gb::metabolize(float Raa, float Rab, float Aout, float Rbb, float Rbc, float Bout, float dt){
	// Numerical equations representing the metabolic network's evolution
	float i=0;
  while(i<1.0){
    Bout += dt*(-Bout*Rbb);
    b_ += dt*(Bout*Rbb - b_*Rbc);
    c_ = dt*(b_*Rbc);
    i+=dt;
  }
  return Bout;
}

float Gb::getW(float wmin){
  if (c_<wmin)
    return 0;
  else
    return c_;
}

#include "Gb.h"

// =====================================================================
//                                Constructors
// =====================================================================
Gb::Gb(float a, float b, float c) : Bacteria(a, b, c) {}

// =====================================================================
//                                 Destructor
// =====================================================================
Gb::~Gb() = default;

// =====================================================================
//                           Public Function members
// =====================================================================

float Gb::metabolize(float Raa, float Rab, float Aout, float Rbb, float Rbc, float Bout, float dt){
	float i=0;
  while(i<1.0){
    Bout += dt*(-Bout*Rbb);
    b_ += dt*(Bout*Rbb - b_*Rbc);
    c_ = dt*(b_*Rbc);
    i+=dt;
  }
  return Bout;
}


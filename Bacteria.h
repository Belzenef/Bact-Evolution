/***********************************************************************
 * This class defines the general behaviour of a bacteria, 
 * whether it has a A or B genotype.
 * ********************************************************************/

#ifndef BACTERIA_H  
#define BACTERIA_H

class Bacteria {
 public :
// =====================================================================
//                               Constructors
// =====================================================================
  Bacteria(float a, float b, float c);

// =====================================================================
//                                Destructor
// =====================================================================
  virtual ~Bacteria();

// =====================================================================
//                                  Getters
// =====================================================================
  inline float a() const;
  inline float b() const;
  inline float c() const;
  
//======================================================================
//                              Setters
//======================================================================
  inline void setb(float b);
  inline void setc(float c);
  
// =====================================================================
//                           Public Function members
// =====================================================================
  virtual float metabolize(float Raa, float Rab, float Aout, float Rbb, float Rbc, float Bout, float dt) = 0;
  virtual float getW(float wmin) = 0;   // Return bacteria's fitness
  virtual bool isGa() const = 0;


 protected :
// =====================================================================
//                               Data members
// =====================================================================
  // Bacteria's phenotype : 
  float a_;   // Internal metabolic glucose concentration
  float b_;   // Internal metabolic acetate concentration
  float c_;   // Internal metabolic ethanol concentration
};

// =====================================================================
//                            Inline definitions
// =====================================================================
inline float Bacteria::a() const { return a_; }
inline float Bacteria::b() const { return b_; }
inline float Bacteria::c() const { return c_; }
inline void Bacteria::setb(float b){b_=b;}
inline void Bacteria::setc(float c){c_=c;}

#endif

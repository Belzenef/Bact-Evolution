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
  
// =====================================================================
//                           Public Function members
// =====================================================================
	virtual float metabolize(float Raa, float Rab, float Aout, float Rbb, float Rbc, float Bout, float dt) = 0;
  virtual float getW() = 0;

 protected :
// =====================================================================
//                               Data members
// =====================================================================
  float a_;
  float b_;
  float c_;
};

// =====================================================================
//                            Inline definitions
// =====================================================================
inline float Bacteria::a() const { return a_; }
inline float Bacteria::b() const { return b_; }
inline float Bacteria::c() const { return c_; }

#endif

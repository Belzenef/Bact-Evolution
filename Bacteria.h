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
	virtual float metabolize(float R1, float R2, float out, float dt) = 0;
  virtual float getW() = 0;
  bool die(float pdeath);

 protected :
// =====================================================================
//                               Data members
// =====================================================================
  float a_;
  float b_;
  float c_;
  static const unsigned int W_MIN; // fitness threshold
};

// =====================================================================
//                            Inline definitions
// =====================================================================
inline float Bacteria::a() const { return a_; }
inline float Bacteria::b() const { return b_; }
inline float Bacteria::c() const { return c_; }

#endif

#ifndef TWIDDLE_H
#define TWIDDLE_H
#include <math.h>
#include "PID.h"
#include <iostream>
using namespace std;


class Twiddle {
public:
  
  PID pid;
  double cte;

  

  /*
  * Constructor
  */
  Twiddle();

  /*
  * Destructor.
  */
  virtual ~Twiddle();

  void Init(PID pid, double cte);
   	

  void twiddle(double* p, double tol);

};

#endif /* TWIDDLE_H */


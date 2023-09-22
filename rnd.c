/*rnd.c*/

#include <math.h>
#include <stdlib.h>
#include <time.h>
/*#define NULL 0*/
#define FRAC(y) modf((y), &no)

double rnd();
double gaussn();

static double no = 3.0;

static double a = 9821.0, c = 0.211327, x = 0.0;

double rnd() {
  x = FRAC(a * x + c);
  return x;
}

void rndseed() { 
  srand ( time(0) );
  int r = rand();
  x = (double)(r%10000)/10000; 
}

static double m = 0.0, sigma = 1.0, K = 20, s12dk = 0.7746;
void gausset(double mm, double ss) {
  m = mm;
  s12dk = sqrt(12 / K);
  sigma = ss;
  s12dk = sqrt(12 / K);
}

double gaussn() {
  double S = 0.0;
  static int i;
  for (i = 0; i < K; i++)
    S += rnd();
  return s12dk * (S - K / 2.0);
}

double rndgauss() { return sigma * gaussn() + m; }

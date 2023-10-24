/* Testing the GA by finding the optimum route of a sailboat
trying to sail against the wind between 2 points.
The model is non-linear.  */

#include "zz_costfunction.h"
#include "ga_types.h"
#include "z_err.h"
#include <math.h>

float timeab(float xa, float ya, float xb, float yb) {
  float t, u, u0 = 1, cosw, upmin = .01;
  float d, d2;
  d2 = ((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
  check(111 && d2 < 900000);
  d = sqrt(d2);
  if (d < .5)
    return (float)0.0;
  cosw = (xb - xa) / d;
  u = u0 * (1 + cosw) / 2;
  if (u < upmin * u0)
    u = upmin * u0;
  t = d / u;
  return t;
}

float sailtime(float px[], float py[], int n) {
  int i;
  float t = 0;
  for (i = 0; i < n - 1; i++)
    t += timeab(px[i], py[i], px[i + 1], py[i + 1]);
  return t;
}

int costfunction1(Genome a) {
  static float px[11000], py[11000];
  int i, n;
  float t;
  n = (a.dnanum) / 2 + 2;
  check(n < 11000);
  px[0] = 250.0;
  py[0] = 0.0;
  px[n - 1] = 5.0;
  py[n - 1] = 0.0;
  for (i = 1; i < n - 1; i++) {
    px[i] = (float)(a.dna[i - 1]);
    py[i] = (float)(a.dna[n - 3 + i]);
  }
  t = sailtime(px, py, n);
  if (t > 2.1E9)
    t = 2.1E9;
  return -(int)t;
}

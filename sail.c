#include "sail.h"
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

/*rnd.h*/
#ifndef RND_H
#define RND_H

double gaussn();
double rnd();
void rndseed();
void gausset(double m, double sigma);
double rndgauss();
#define gauss(m, s) ((s)*gaussn() + (m))

#endif

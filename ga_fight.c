/*fight.c  experimental*/

#include "ga_fight.h"
int CH = 1;
extern int dnanum;
int fight(Genome a, Genome b) {
  int i, j = 0;
  for (i = 0; i < dnanum; i++) {
    j += a.dna[i] - b.dna[i];
  }
  return j;
}

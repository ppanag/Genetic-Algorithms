/* ga_types.h */

#ifndef GA_TYPES_H
#define GA_TYPES_H

typedef unsigned char byte;

typedef struct {
  byte *dna;
} Genome;

typedef struct {
  int dnanum;
  int num; /* <=255 */
  Genome a[255];
} Population;

#endif

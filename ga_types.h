/* ga_types.h */

#ifndef GA_TYPES_H
#define GA_TYPES_H

typedef unsigned char byte;

typedef struct {
  byte *dna;
} Animal;

typedef struct {
  int dnanum;
  int num; /* <=255 */
  Animal a[255];
} Agelh;

#endif

/* ga_a.c ---some functions*/

#include "ga_a.h"
#include "z_err.h"
#include "ga_types.h"
#include <stdio.h>
#include <stdlib.h>

Animal newrandanimal(int dnanum) {
  int i;
  Animal a;
  a.dna = malloc(dnanum);
  if (a.dna == NULL)
    error("cant malloc randanimal");
  for (i = 0; i < dnanum; i++)
    a.dna[i] = rand() % 256;
  return a;
}

void printanimal(Animal a, int dnanum) {
  int i;
  for (i = 0; i < dnanum; i++)
    printf("%3d ", a.dna[i]);
}

void printarray(int a[], int n) {
  int i;
  for (i = 0; i < n; i++)
    printf("%d ", a[i]);
  puts("");
}

void copyanimal(Animal dst, Animal src, int n) {
  register int i;
  for (i = 0; i < n; i++)
    dst.dna[i] = src.dna[i];
}


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rnd.h"
#include "ga.h"
#include <stdlib.h>
int rdebug = 5;

void main(int n, char **arg) {
  long g = 1;
  if (n > 1)
    g = atol(arg[1]);
  rndseed();
  printf("\n***** g=%ld\n", g);
    
  ga_init(100, 50);
  ga_params(1000, 5, 2, .1, .01);
  ga_exelixi(g);
  ga_printbests(1);
}

/*

   Check macro. Just copy of Assert...
*/

#include <stdio.h>  /*  fprintf() prototype & 'stderr' definition */
#include <stdlib.h> /* abort() prototype */

#if !defined(xxx_debug)
#define check(p)                                                               \
  if (!(p)) {                                                                  \
    fprintf(stdout, "Assertion failed: %s, file %s, line %d\n", #p, __FILE__,  \
            __LINE__);                                                         \
    abort();                                                                   \
  }
#else
#define check(p)
#endif

#define error(x)                                                               \
  {                                                                            \
    printf("ERROR: %s\n", x);                                                  \
    abort();                                                                   \
  }

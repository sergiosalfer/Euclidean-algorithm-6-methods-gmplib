/**
   @file      gmpRandEx.c
   @author    Mitch Richling <https://www.mitchr.me/>
   @Copyright Copyright 1999 by Mitch Richling.  All rights reserved.
   @brief     Example showing how to use the GMP random number generator.@EOL
   @Keywords  none
   @Std       C89

              The GMP contains a simple random number generator that
              is not suitable for simulation work, but is good enough
              for things like checking arithmetic algorithms and the
              like.
*/

#include <stdlib.h>             /* Standard Lib    ISOC  */
#include <stdio.h>              /* I/O lib         ISOC  */
#include <stdarg.h>             /* Variable args   ISOC  */
#include <gmp.h>                /* GNU GMP Library       */
#include "a4.cpp"

int main (void) {
  int             i;            /* Loop variable */
  mpz_t           randNum;      /* Hold our random numbers */
  int             rndBit;       /* Bound for mpz_urandomb */
  gmp_randstate_t gmpRandState; /* Random generator state object */

  /* Initialize randNum before we use it. */
  mpz_init(randNum);

  /* Initialize Bounds */
  rndBit = 1000000;

  /* Initialize the random state with default algorithm... */
  gmp_randinit_default(gmpRandState);
  gmp_randseed_ui(gmpRandState, 1234567890);

  printf("10 random numbers in U[0, -1+2**%d]:\n", rndBit);
  for(i=0; i<10; i++) {
    mpz_urandomb(randNum, gmpRandState, rndBit);
    mpz_out_str(stdout, 10, randNum);
    printf("\n");
  } /* end for */

  gmp_randclear(gmpRandState);

  mpz_clear(randNum);

  return 0;
} /* end func main */

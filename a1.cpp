int a1(mpz_t a, mpz_t b)
{

 // Declaración

  mpz_t r;
  mpz_init(r);

    while ( mpz_cmp_ui (b, 0) != 0 )
    {
      mpz_sub ( r, a, b );
      // mpz_out_str(stdout, 10, r);
      // printf("\n");
      if ( mpz_cmp (r, b) >= 0 )
        mpz_set (a,r);
      else {
        mpz_set (a,b);
        mpz_set (b,r);
      }
    }
    mpz_clear(a);
    mpz_clear(b);
    mpz_clear(r);

    return 0;
    // return i;

}

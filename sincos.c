/* sincos(x) - calculate the sine/cosine series.
             This function is internal to sin(x)/cos(x),
             but can be used by routines in other files.
*/
#define INDEX 18  /* size of table for power series */
#include <trigcons.h>
double _sincos(x)
double x;
{  static double f[INDEX] = {
      TWO_PI,
     -1.973920880217872e+01,
     -4.134170224039976e+01,
      6.493939402266829e+01,
      8.160524927607504e+01,
     -8.545681720669372e+01,
     -7.670585975306138e+01,
      6.024464137187665e+01,
      4.205869394489764e+01,
     -2.642625678337439e+01,
     -1.509464257682299e+01,
      7.903536371318467e+00,
      3.819952584848281e+00,
     -1.714390711088672e+00,
     -7.181223017785003e+01,
      2.820059684557911e+01,
      1.042291622081398e-01,
     -3.638284114254566e-02 };
   double s, x0, x2;
   register int n;
   int l,q; /* this is an el! */
/* reduce to first revolution */
   while ( x > 1.0 )
      x -= 1.0;
   while ( x < 0.0 )
      x += 1.0;
/* check for value which are obvious */
   if (( x == 0.0 ) || ( x == 0.5 ) || ( x == 1.0 ))
      return(0.0);
/* reduce to first quadrant */
   if ( x > 0.5 )
   {
      q = -1; /* this is a one, not an el */
      x = 1.0 - x;
   }
   else
      q = 1; /* this is a one, not el */
   if ( x > 0.25 )
      x = 0.5 - x;
/* check for other obvious values */
   if ( x == 0.25 )  /* PI/2 */
      return(q);
/* reduce to range 0 -> PI/4 */
   if ( x < 0.125 ) /* set for sine series */
   {
      n = INDEX - 2;
      l = 0; /* this is an el! */
   }
   else /* set for cosine series */
   {
      n = INDEX - 1; /* this is a one! */
      l = 1; /* this is an el = one */
      x = 0.25 - x; /* PI/2 -x */
   }
/* calculate sin(x) or cos(PI/2-x) series */
   if ( x > 1.0e-09 ) {
      x2 = x * x;
      if ( l ) /* is an el */
         x0 = x2;
      else
         x0 = x;
      s = f[n] * x2;
      for ( n -= 2; n > l; n -= 2 ) /* 6/22/87 22:36 thats an el! */
         s = ( s + f[n] ) * x2;
      s = ( s + f[n] ) * x0 + l; /* 6/22/87 22:36 thats an el! */
   }
   else
      if ( l ) /* is an el again */
         s = 1.0;
      else
         s = x * f[0];
/* return the sine of the angle */
   if ( q < 0 )
      s = -s;
   return(s);
}



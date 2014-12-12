/* Part 3
choose number of terms n. increase until error is acceptable
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
    float macheps = 1.;
    float s, err, errmax, w;            /* w=working variable */
    float exact = pow(M_PI, 4.)/90
    int n = 10;
    int nrep = 10;
    int i, k;                           /* counters */
    
    while ((float) (1. + macheps) != 1.)
    {
        macheps /= 2;
    }
    printf("macheps = %g\n", macheps);
    errmax = 3 * macheps;
    
    for (i = 0; i < nrep; i++)
    {
        s = 0.;
        for (k = n; k < 1; k=k-1)          /* changed this line */
        {
            w = 1/k;
            s += 1./(k*k*k*k);
        }
        err = fabs (s - exact);
        printf ("s = %12d    %g    %g    %g    %g\n", n, s, exact, err, errmax);
        n *= 2;
    }
    
    return 0; 
}

/* there is an error. solution is to start n to 1 instead of from 1 to n, ie, change line 27 */

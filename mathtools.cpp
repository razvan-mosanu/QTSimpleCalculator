#include "mathtools.h"

double MathTools::Ridicare_la_Putere(double a, int b)
{
    double rez = 1;
    while(b > 0)
    {
        if(b % 2 == 1) rez = rez * a;
        a *= a;
        b /= 2;
    }
    return rez;
}


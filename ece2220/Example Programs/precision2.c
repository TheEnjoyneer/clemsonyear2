#include <stdio.h>
#include <stdlib.h>

int main(void)
{ 
    double d1, d2;
    float f1, f2;


    // precision limited to float
    d1 = f1 = 1.2345678901234567890; 
    d2 = f2 = 1.0/3.0;

    printf("f1 = %0.20f, d1 = %0.20lf\n\n", f1, d1);
    printf("f2 = %0.20f, d2 = %0.20lf\n", f2, d2);
    printf("double has same precision as float??? (why?)\n\n");

    // get double precision
    f1 = d1 = 1.2345678901234567890; 
    f2 = d2 = 1.0/3.0;

    printf("f1 = %0.20f, d1 = %0.20lf\n\n", f1, d1);
    printf("f2 = %0.20f, d2 = %0.20lf\n", f2, d2);
    printf("double has greater precision than float\n");

    return 0;
}


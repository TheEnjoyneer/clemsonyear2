#include <stdio.h>
#include <stdlib.h>

int main(void)
{ 
    int i;
    double d1, d2;
    float f1, f2;


    f1 = d1 = 1.2345678901234567890; 
    f2 = d2 = 1.0/3.0;

    printf("f1 = %0.20f, d1 = %0.20lf\n\n", f1, d1);
    printf("f2 = %0.20f, d2 = %0.20lf\n\n", f2, d2);

    for (i=0; i<40; i++)
    { 
	f1 *= 2;  f1 -= (int)f1;
	printf("f1 = %0.20f\n", f1);
    } 
    getchar();

    for (i=0; i<40; i++)
    { 
	f2 *= 2;  f2 -= (int)f2;
	printf("f2 = %0.20f\n", f2);
    } 
    getchar();

    for (i=0; i<40; i++)
    { 
	d1 *= 2;  d1 -= (int)d1;
	printf("d1 = %0.20lf\n", d1);
    } 
    getchar();

    for (i=0; i<40; i++)
    { 
	d2 *= 2;  d2 -= (int)d2;
	printf("d2 = %0.20lf\n", d2);
    }     
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define BITS 60

int main(void)
{ 
    char Integer[100], Reverse[100], Fraction[100];
    double m;
    long IntPart, r, q;
    int bit, n;
    double x, f;
    long i;

    printf("Enter decimal value to convert to binary:  ");
    scanf("%lf", &x); 

    printf("Number = %lf, ", x);

    i = (int)(x);
    printf("Integer = %ld, ", i);

    f = x - i;
    printf("Fractional Part = %lf\n\n", f);

    /*** Create Integer Part ***/
    bit = 0;
    do
    { q = i / 2;
	printf("q = %ld, ", q);

	r = i % 2;
	printf("r = %ld\n", r);
	i = q;

	Integer[bit++] = r + '0';

    } while (q != 0);

    Integer[bit] = '\0';

    n = strlen(Integer);
    for (bit=0; bit<n; bit++)
    { Reverse[n-bit-1] = Integer[bit];
    }
    Reverse[n] = '\0';
    printf("Integer = %s\n\n", Reverse);
    getchar();

    /*** Create Fractional Part ***/
    bit = 0;
    do
    { m = f * 2;
	printf("m = %lf, ", m);

	IntPart = (int)(m);
	f = m - IntPart;
	printf("f = %lf\n", f);

	Fraction[bit++] = IntPart + '0';
    } while (bit < BITS);

    Fraction[bit] = '\0';
    printf("Fraction = %s\n\n", Fraction);

    return 0;
}


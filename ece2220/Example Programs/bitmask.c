#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    char a;
    int i;
    a = 17;
    a |= 1 << 3;   // set 3rd bit
    printf("a = %d\n", a);

    a &= ~ (1 << 4);    // clear 4th bit
    printf("a = %d\n", a);

    // print bits
    printf("a = ");
    for (i = 7; i >= 0; i--)
	printf("%d", (a & (1 << i)) >> i);   // read i-th bit
    printf("\n");

    // an alternative version
    printf("a = ");
    for (i = 7; i >= 0; i--)
	printf("%d", (a >> i) & 0x01);   // read i-th bit
    printf("\n");
    return 0;
}



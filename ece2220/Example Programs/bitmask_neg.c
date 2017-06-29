/* Minutia
 * beware of right shift of negative number 
 *
 * According to the C99 standard, the right shift of a negative number is
 * implementation defined. Most implementations, e.g., the GCC, use an
 * arithmetic shift (i.e., sign extension), but a logical shift is possible.
 *
 * But using gcc on the examples below demonstrait that a combined left 
 * and right shift in one operation is logical not arithmetic.
 */

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    char a, b, c, d;
    int i;
    a = -126;   // -126 = 1000 0010
    printf("a = %4d = 0x%hhx\n", a, a);

    printf("\nright shift maintains sign bit\n");
    // this is negative one = 1111 1111
    b = a >> 7;
    printf("b = %4d = 0x%hhx  b = a >> 7\n", b, b);

    printf("\ntwo shifts done one at a time maintain sign bit\n");
    // this is -128 = 1000 0000
    b = a & (1 << 7);
    printf("b = %4d = 0x%hhx  b =  a & (1 << 7)\n", b, b);
    b = b >> 7;  // -1
    printf("b = %4d = 0x%hhx  b = b >> 7\n", b, b);

    printf("\ntwo shifts in one operation converts to unsigned number\n");
    // this is positive one, a logical right shift
    b = (a & (1 << 7)) >> 7;
    printf("b = %4d = 0x%.2hhx  b = (a & (1 << 7)) >> 7\n", b, b);

    printf("\nusing mask instead of shift for first step produces same result.\n");
    b = a & 0x80;   // -128
    printf("b = %4d = 0x%.2hhx  b = (a & 0x80)\n", b, b);

    printf("\nmask and shift in one operation converts to unsigned number\n");
    // this is positive one, a logical right shift
    b = (a & 0x80) >> 7;
    printf("b = %4d = 0x%.2hhx  b = (a & 0x80) >> 7\n", b, b);

    printf("\nusing variables instead of constants does not change result\n");
    c = 7;
    d = 1;
    b = (a & (d << c)) >> c;
    printf("b = %4d = 0x%.2hhx  b = (a & (d << c)) >> c\n", b, b);

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

    printf("shifts of a \n");
    for (i = 7; i >= 0; i--)
	printf("%d = a >> %d\n", a >> i, i);   // shifts of a
    printf("\n");

    // what is -1/2 in integer versus -1 >> 1
    // left shift by 1 is same as multiply by 2
    // right shift by 1 is like integer division if positive number
    // but for negative numbers, there can be a difference
    i = -1;
    int j = i / 2;  // this is 0
    int k = i >> 1; // this is -1 due to sign extension
    printf("-1 / 2 = %d but -1 >> 1 = %d\n", j, k);
    i = -63;
    j = i / 2;  // this is -31
    k = i >> 1; // this is -32 
    printf("-63 / 2 = %d but -63 >> 1 = %d\n", j, k);

    return 0;
}



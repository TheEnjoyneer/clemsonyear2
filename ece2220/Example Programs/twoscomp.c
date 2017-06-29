#include <stdio.h>

char *HexToBin[16] =
{ "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
    "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"
};
//---------------------------------------------------------------------------
#define UCHAR unsigned char

void print_bits(char *text, void *mem, unsigned char len)
{ 
    unsigned char *addr;

    // *** Print Binary Value of Memory *** //
    printf("%s", text);
    for (addr=(UCHAR *)mem + len - 1; addr>=(UCHAR *)mem; addr--)
    {  printf("%4s", &HexToBin[*addr>>4][0]);
	printf("%4s ", &HexToBin[*addr % 16][0]);
    }
    printf("\n");
}

//---------------------------------------------------------------------------

int main(void)
{  
    char a, b, c, i, j, k;

    a = 23;     printf("a = %d", a); print_bits(" = ",&a, sizeof(a));
    b = 17;     printf("b = %d", b); print_bits(" = ",&b, sizeof(b));
    c = a + b;  printf("c = %d", c); print_bits(" = ",&c, sizeof(c));

    printf("\n");

    i = -23;    printf("i = %d", i); print_bits(" = ",&i, sizeof(i));
    j = -17;    printf("j = %d", j); print_bits(" = ",&j, sizeof(j));
    k = i + j;  printf("k = %d", k); print_bits(" = ",&k, sizeof(k));

    return 0;
}

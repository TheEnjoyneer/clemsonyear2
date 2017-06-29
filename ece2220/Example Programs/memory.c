#include <stdio.h>

#define UCHAR unsigned char

char *HexToBin[16] =
{ "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
    "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"
};

void print_bits(char *text, void *mem, UCHAR len)
{ UCHAR *addr;

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
{  UCHAR *ptrc;

    //short int si = 1000;
    short int si = 0x8421;
    int i= 0x12345678;
    float f = 16;
    double d = 256;
    char c = 'C';

    printf("si %p\n", &si);
    printf("i  %p\n", &i);
    printf("f  %p\n", &f);
    printf("d  %p\n", &d);
    printf("c  %p\n", &c);
    printf("\n");

    for (ptrc = (UCHAR *)&si; ptrc <= (UCHAR *)&c; ptrc++)
    {  
	printf("%p", ptrc); print_bits(" - ", ptrc, sizeof(char));
    }
    return 0;
}

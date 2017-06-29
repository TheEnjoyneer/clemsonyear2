#include <stdio.h>

#define UCHAR unsigned char

//---------------------------------------------------------------------------

char *HexToBin[16] =
{ "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
    "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"
};

//---------------------------------------------------------------------------

void print_bits(char *text, void *mem, unsigned char len)
{ 
    unsigned char *addr;
    // *** Print Binary Value of Memory *** //
    printf("%s", text);
    for (addr=(UCHAR *)mem + len - 1; addr>=(UCHAR *)mem; addr--)
    {  
	printf("%4s", &HexToBin[*addr>>4][0]);
	printf("%4s ", &HexToBin[*addr % 16][0]);
    }
    printf("\n");
}

//---------------------------------------------------------------------------

int main(void)
{
    char c ;
    int i;
    float f;
    double d;
    unsigned int ui;
    signed short int ssi;
    long double ld;
    c = i = f = d = ui = ssi = ld = 255;

    print_bits("c = ", &c, sizeof(char));
    print_bits("i = ", &i, sizeof(int));
    print_bits("ssi = ", &ssi, sizeof(signed short int));
    print_bits("f = ", &f, sizeof(float));
    print_bits("d = ", &d, sizeof(double));
    print_bits("ld = ", &ld, sizeof(long double));

    return 0;
}


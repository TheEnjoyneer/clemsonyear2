#include <stdio.h>

char *HexToBin[16] =
{ "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
    "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"
};
//---------------------------------------------------------------------------
#define UCHAR unsigned char

void print_bits(char *text, void *mem, unsigned char len)
{ unsigned char *addr;

    // *** Print Binary Value of Memory *** //
    printf("%s", text);
    for (addr=(UCHAR *)mem + len - 1; addr>=(UCHAR *)mem; addr--)
    {  printf("%4s", &HexToBin[*addr>>4][0]);
	printf("%4s ", &HexToBin[*addr % 16][0]);
    }
    printf("\n");
}
//---------------------------------------------------------------------------   
void print_c(char c)
{  
    printf("c = %c = %d = 0x%X", c, c, c);
    print_bits(" = ",&c, sizeof(c));
    printf("\n");  
}
//---------------------------------------------------------------------------
int main(void)
{    
    char c;
    unsigned char uc; 
    c = 65;  print_c(c);   

    for (c=7; c<=13; c++) print_c(c); 

    c = '6';  print_c(c);

    c = '\'';  print_c(c);

    c = '\\';  print_c(c);

    uc = 200;  
    printf("uc = %c = %d = 0x%X", uc, uc, uc);
    print_bits(" = ",&uc, sizeof(uc));
    printf("\n");  

    print_c(uc);

    c = 200; print_c(c);

    return 0;
}

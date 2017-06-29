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
{ UCHAR a, b;

  a = 7; b = 170;
  a = 5; b = 100;
  printf("a = %3d = 0x%02X", a, a); print_bits(" = ",&a, sizeof(a));
  printf("b = %3d = 0x%02X", b, b); print_bits(" = ",&b, sizeof(b));  
  printf("\n\n");
  
  printf("a = a | b\n");
  a = a | b;
  printf("a = %3d = 0x%02X", a, a); print_bits(" = ",&a, sizeof(a));
  printf("\n\n");
  
  printf("b = a ^ b\n");
  b = a ^ b;
  printf("b = %3d = 0x%02X", b, b); print_bits(" = ",&b, sizeof(b));
  printf("\n\n");
  
  printf("a = a ^ b\n");
  a = a ^ b;
  printf("a = %3d = 0x%02X", a, a); print_bits(" = ",&a, sizeof(a));
  printf("b = %3d = 0x%02X", b, b); print_bits(" = ",&b, sizeof(b));  
    
  return 0;
}

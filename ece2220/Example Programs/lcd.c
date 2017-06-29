#include <stdio.h>

/* This program writes the upper nibble and then the lower nibble of   */
/* a variable called a to bit 2, 3, 4, and 5 of variable PortOut       */
/* using bitwise operations without changing the other bits of PortOut */

#define BIT_0 0x01
#define BIT_1 0x02
#define BIT_2 0x04
#define BIT_3 0x08
#define BIT_4 0x10
#define BIT_5 0x20
#define BIT_6 0x40
#define BIT_7 0x80

#define UCHAR unsigned char
char *HexToBin[16] =
{ "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
    "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"
};

void print_bits(char *text, void *mem, UCHAR len)
{ 
    UCHAR *addr;

    /*** Print Binary Value of Memory ***/
    printf("%s", text);
    for (addr=(UCHAR *)mem + len - 1; addr>=(UCHAR *)mem; addr--)
    {  
	printf("%4s", &HexToBin[*addr>>4][0]);
	printf("%4s ", &HexToBin[*addr % 16][0]);
    }
    printf("\n");
}

int main(void)
{ 
    int i;
    unsigned char a;
    unsigned char PortOut = 0x85; /* Let the upper bits of a be 1 
				     and the lower three bits be 101
				     These should not change */                             
    for (i=0; i<5; i++)
    { 
	printf("Input a char to write to the display.\n");
	a = getchar();
	printf("a = 0x%X\n", a);
	print_bits("a = ", &a, 1);

	printf("\nPortOut(0) = 0x%X\n", PortOut);
	print_bits("PortOut(0) = ", &PortOut, 1);

	/* Write the upper nibble of a to pins (bits) 2-5 of PortOut
	   Clear bit positions to be written */
	PortOut = PortOut & ~(BIT_6 | BIT_5 | BIT_4 | BIT_3); 
	/* Then Or in the upper nibble of a to those positions.  */
	PortOut = PortOut |  ((a & 0xF0) >> 1) ;

	printf("\nPortOut(1) = 0x%X\n", PortOut);
	print_bits("PortOut(1) = ", &PortOut, 1);

	/* Write the lower nibble of a to pins (bits) 2-5 of PortOut */
	/* Clear bit positions to be written */
	PortOut = PortOut & ~(BIT_6 | BIT_5 | BIT_4 | BIT_3); 
	/* Then Or in the lower nibble of a to those positions. */
	PortOut = PortOut | ((a & 0x0F) << 3) ;

	printf("\nPortOut(2) = 0x%X\n", PortOut);
	print_bits("PortOut(2) = ", &PortOut, 1);

	puts("\n");

	getchar();
    }
    return 0;

}

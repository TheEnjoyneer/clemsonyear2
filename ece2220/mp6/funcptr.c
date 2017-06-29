#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>   // for isdigit

#define CHEERS 6

void PrintGoTigers(void)
{
    printf("\nGo Tigers!\n");
}
void PrintOrangeAndWhite(void)
{
    printf("\nOrange and White is Right!\n");
}
void PrintReignSupremeAlway(void)
{
    printf("\nReign Supreme Alway!\n");
}
void PrintGarnetAndBlack(void)
{
    printf("\nGarnet and Black-Get Back!\n");
}
void PrintGoCocks(void)
{
    printf("\nGoCocksGo..GoGocksGo...\nAroundTheBowlAndDownTheHoleGoCocksGo...\n");
}
void PrintCockadoodleDoo(void)
{
    printf("\nCockadoodledoo..nCockadoodledoo...\nCarolina Gamecocks to Heck with you...\n");
}

// defines fptr to be a pointer to a function.  The function has no 
// arguments and does not return a value
typedef void (*fptr)(void);

// an array of function pointers
fptr Func[CHEERS] = {
    PrintGoTigers,
    PrintOrangeAndWhite,
    PrintReignSupremeAlway,
    PrintGarnetAndBlack,
    PrintGoCocks,
    PrintCockadoodleDoo
};

int main(void)
{
    char c[80];
    int fun_num;

    printf("Input 0 - %d\n", CHEERS - 1);

    while (1) {
        fgets(c, sizeof(c), stdin);
        fun_num = atoi(c);

        if (!isdigit(c[0]) || fun_num < 0 || fun_num  >= CHEERS) return 0;

        Func[fun_num]();  /* Must put () here or nothing happens */
    }
}

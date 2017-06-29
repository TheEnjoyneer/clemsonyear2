/*This program does not really do anything but demonstrate malloc and
 *give you practice finding bugs in the program. */

#include <stdio.h>
#include <stdlib.h>

int main()
{

   int *x = (int *) malloc(2*sizeof(int));
   int *y = (int *) malloc(2*sizeof(int));
   x[1] = 50;
   x[0] = 1;
   y[1] = 15;
   y[0] = 10;
   x[4] = 5;
   printf("x[0] = %p, x[1] = %p and y[0] = %p, y[1] = %p\n", &x[0],&x[1],y,y+1);
   printf ("address of x[4] is %p  value is %d\n",&x[4],  x[4]);



   return 0;
}

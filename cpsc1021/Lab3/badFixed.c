/*************************
 Christopher Brant
 cbrant
 Lab 3
 Section 2
 Lauren Fuller
 
 File: badFixed.c
 Purpose: Debugging file for Lab3

 ************************/

/*This program does not really do anything but demonstrate malloc and
 *give you practice finding bugs in the program. */

#include <stdio.h>
#include <stdlib.h>

int main()
{

   int *x = (int *) malloc(5*sizeof(int));      // Array bound error in line 28
   int *y = (int *) malloc(2*sizeof(int));      // So x is changed do malloc a 
   x[1] = 50;                                   // 5 int array instead of 2
   x[0] = 1;
   y[1] = 15;
   y[0] = 10;
   x[4] = 5;
   printf("x[0] = %d, x[1] = %d and y[0] = %d, y[1] = %d\n", x[0],x[1], *y,*(y+1));
   /* The %p's that were above were changed to %d so that they correctly
      print ints.
      The ampersands were removed from the x references because the 
      brackets already reference correctly the values inside x.
      Asterisks were added to dereference y and y + 1 so the values
      are seen. */
   
   /* printf("x[0] = %p, x[1] = %p and y[0] = %p, y[1] = %p\n", &x[0], &x[1], y,y+1);
      A copy of the unaltered line is above and this correctly prints
      addresses, but does not print values. If that was the objective
      it is understood, but the values are what I printed. */

   
   printf ("address of x[4] is %p  value is %d\n",&x[4],  x[4]);

   free(x);    // Freeing the allocated memory for x
   free(y);    // Freeing the allocated memory for y

   return 0;
}

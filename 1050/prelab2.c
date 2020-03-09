/* For the prelab assignment, write a C program that reads in two
integer numbers from user input. Save the values of these numbers
in two variables called X and Y. Print the values of X and Y. Print
the value of X multiplied times Y. Print the value of X plus 1, quantity
times Y (e.g., if X is 5 and Y is 2 then X plus 1 quantity times Y is 12
 because X plus 1 is 6 and 6 times 2 is 12). Print the values of X and Y
 again to show that they did not change. */

#include <stdio.h>

int main ( void )
{

  int X = 0;
  int Y = 0;
  int product = 0;
  int quotient = 0;
  int val = 0;

  printf( "%s", "Enter two integers separated by spaces\n" );
  scanf( "%d %d", &X, &Y );

  product = X * Y;
  quotient = X / Y;
  val = ( X + 1 ) * Y;

  printf( "*** Initial Values ***\nX = %d\nY = %d\n", X, Y );
  printf( "*** Calculated Values ***\nX times Y = %d\nX divided by "
  "Y = %d\nX plus 1, quantity times Y = %d\n", product, quotient, val);
  printf( "*** Final Values ***\nX = %d\nY = %d\n", X, Y );

}

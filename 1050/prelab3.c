/* For the prelab assignment, you may not use the if statement nor may
you use the if/else statement. You are to write a program that prints all
integers from 1 to 30 and whether or not that integer is evenly
divisible by 5.*/

#include <stdio.h>

int main (void){

  for(int i = 1; i <= 30; i++){
    printf("%d ", i);
    i % 5 == 0 ? puts("is divisible by 5") : puts("is not divisible by 5");
  }
}

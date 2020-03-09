#include <stdio.h>

//intitializing variables
int A, B, x;
int counter_A = 0;
int counter_B = 0;
int counter_AB = 0;
int counter_none = 0;

//start of program
int main (void){
    puts("Please enter two positive integers that are less that 7:");
    scanf("%d %d", &A, &B);
    for (A = A; (A < 1 || A > 7);){ //checking if A is in proper range, printing error message if not or scanf if so
        puts("ERROR: A must be >= 1 and A must be <= 7\nPlease enter two positive integers that are less that 7:");
        scanf("%d %d", &A, &B);
        for (B = B; (B < 1 || B > 7);){//checking if B is in proper range, printing error message if not or scanf if so
            puts("ERROR: B must be >= 1 and B must be <= 7\nPlease enter two positive integers that are less that 7:");
            scanf("%d %d", &A, &B);
        }
    }

    // for loop that increments by 2 from 4-40, checks if number is divisible by A and B
    for (x = 4; x <= 40; x += 2){
        x % A == 0 ? printf("%d is divisible by %d\n", x, A), counter_A++ : printf("%d is not divisible by %d\n", x, A); // increments a counter if number is divisible
        x % B == 0 ? printf("%d is divisible by %d\n", x, B), counter_B++ : printf("%d is not divisible by %d\n", x, B); // increments a counter if number is divisible
        ( x % A == 0 && x % B == 0 ) ? counter_A--, counter_B--, counter_AB++ : printf("\n"); // if number is divisible by both, decrements A and B counter, increments AB counter
    }

    // sets value for counter that tracks if none were divisible
    counter_none = (((19 - counter_AB) - counter_B) - counter_A);

    // prints counter values
    printf("\nBONUS:\n%d were divisible only by A\n", counter_A);
    printf("%d were divisible only by B\n", counter_B);
    printf("%d were divisible by both A and B\n", counter_AB);
    printf("%d were divisible by neither A nor B\n", counter_none);

}




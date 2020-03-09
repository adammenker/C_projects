/* (Intructions) Wirte a C program that reads in two integer numbers from user input that will be entered on the same line and separated by a space. The first integer may be any integer and should be called A. The second integer may be any integer and should be called B. Then read a third integer called C that is entered by itself on a new line. C may be any integer other than zero. If the user inputs 0 for the third integer, print an error message and ask the user to enter the third integer again*/

#include <stdio.h>

int main ( void )
{// start program
    // intializing variables A, B, C
    int A = 0;
    int B = 0;
    int C = 0;
    
    // prompting user for values and storing in variable's memory
    printf( "%s", "Enter two integers separated by a space\n" );
    scanf( "%d %d", &A, &B);
    printf( "%s", "Enter another integer that is not zero\n" );
    scanf( "%d", &C );
    while (C == 0){// checking to see if C is zero
        printf( "Sorry, that is invalid. Try to enter another integer that is not zero\n" );
        scanf( "%d", &C );// looping until user enter integer that isnt 0
    }
    // printing intial values
    printf( "*** Initial Values ***\nA = %d\nB = %d\nC = %d\n", A, B, C );
    
    // initializeing variables for each operation
    int sum_of_ABC = 0;
    int A_minus_B = 0;
    int A_minus_B_plus_C = 0;
    int A_times_B_minus_C = 0;
    int A_dividedby_C = 0;
    int A_times_B_dividedby_C = 0;
    int A_mod_C = 0;
    
    // setting each cariable to its respective operation
    sum_of_ABC = A + B + C;
    A_minus_B = A - B;
    A_minus_B_plus_C = A - B + C;
    A_times_B_minus_C = A * B - C;
    A_dividedby_C = A / C;
    A_times_B_dividedby_C = A * B / C;
    A_mod_C = A % C;

    // printing all calculated values
    printf( "*** Calculated Values ***\nA plus B plus C = %d\nA minus B = %d\n", sum_of_ABC, A_minus_B );
    printf( "A minus B plus C = %d\nA times B minus C = %d\n", A_minus_B_plus_C, A_times_B_minus_C );
    printf( "A divided by C = %d\nA times B divided by C = %d\n", A_dividedby_C, A_times_B_dividedby_C );
    printf( "A divided by C remainder = %d\n", A_mod_C );

    // initializing variables for absolute value
    int A_absval = 0;
    int B_absval = 0;
    int C_absval = 0;

    //setting the absolute value of A, B, and C into variables 
    if (A < 0){
        A_absval = A * -1;
    }
    else{
        A_absval = A;
    }

    if (B < 0){
        B_absval = B * -1;
    }
    else{
        B_absval = B;
    }

    if (C < 0){
        C_absval = C * -1;
    }
    else{
        C_absval = C;
    }

    // conditional and printf if A has the smallest absolute value
    if (A_absval < B_absval){
        if (A_absval < C_absval ){
            printf( "The smallest absolute value is %d\n", A_absval );
        }
    }
    // conditional and printf if B has the smallest absolute value
    if (B_absval < A_absval){
        if (B_absval < C_absval){
            printf( "The smallest absolute value is %d\n", B_absval );
        }
    }
    // conditional and printf if C has the smallest absolute value
    if (C_absval < A_absval){
        if (C_absval < B_absval){
            printf( "The smallest absolute value is %d\n", C_absval );
        }
    }





}// end program


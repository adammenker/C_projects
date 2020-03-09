#include <stdio.h>
#include <math.h>

//prototypes for functions
double MyPower(double base, int exponent);
void TestIsEqual(double result, double expected);
void DoTest(double base, int exponent);

//declaring variables
double result, expected, base, x;
int exponent, i;

//start of program
int main(void){
    DoTest(-20, 11);
    DoTest(2.0d, 3);
    DoTest(-6, -1);
    DoTest(-1.0d, 0);
    DoTest(4, 0);
    DoTest(-1, 3);
    DoTest(-2, -7);
    DoTest(-20, -1);
    DoTest(-5, -11);
    DoTest(4.5, 3);
    DoTest(4.5, -3);
    DoTest(-1, 11);
    DoTest(1, -11);
}

//custom pow() function
double MyPower(double base, int exponent){
    x = 1;
    while(exponent > -5 && exponent < 15){
        if(exponent > 0){
            for(i = 0; i < exponent; i++){ //multiplies x by the base until i reaches the proper value for how many times it should be incremented
                x *= base;
            }
            break;
        }
        if(exponent <= 0){
            for(i = 0; i > exponent; i--){ //same as above, but decrements
                x *= base;
            }
            x = 1/x; //changes the value of x raised to the absolute value of the power into the reciprocal
            break;
        }
    }
    if (exponent < -5 || exponent > 15){ // returns 0 if the exponent is out of range
        x = 0;
    }
    return x; 
}

// assigns values of pow() and custom pow() to variables
void DoTest(double base, int exponent){
    expected = pow(base, exponent);
    result = MyPower(base, exponent);
    printf("Testing %f ^ %d\n", base, exponent); //prints what is being tested
    TestIsEqual(result, expected); // call TestIsEqual function to display corresponding message whether the values are equal or not
}



void TestIsEqual(double result, double expected){
    if(result == expected){
        printf("\tSuccess: %f == %f\n", expected, result); // prints success message if values are equal
    }
    else{
        printf("\tError: expected %f, but got %f\n", expected, result); // prints error message if values are not equal
    }
} // end of program






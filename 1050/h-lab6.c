#include <stdio.h>


// function prototypes
void GetPromptString(char * output);
void PromptAndGetFloat(char * prompt, float * output, float lowerlimit, float upperlimit);
void GetQuotient(float dividend, float divisor, float * quotient);


int main(void){ // start of program
    
    char dividend[31]; // creates string of 31 possible characters
    char divisor[31];
    float float1 = 0; // initializes 3 variables for the dividend, divisor, and the quotient
    float float2 = 0;
    float finalquotient = 0;

    puts("\n********************"); // welcome message
    puts("* Welcome to Lab 6 *");
    puts("********************\n");

    printf("Enter the prompt for the first variable: "); // prompting user for prompt and storing it into 'dividend'
    GetPromptString(dividend);

    printf("Enter the prompt for the second variable: "); 
    GetPromptString(divisor);

    PromptAndGetFloat(dividend, &float1, -130.699997, 62.900002); // prompting user for float input and storing it in float1
    PromptAndGetFloat(divisor, &float2, -4.2, 6.1); 
    
    GetQuotient(float1, float2, &finalquotient); // calculating the quotient of the 2 inputs

    printf("The quotient of %f and %f is %f\n\n", float1, float2, finalquotient); // printing the values entered and the value calculated
    puts("*********************");

} // end of program



void GetPromptString(char * output){ // scans prompt into 'output'
    scanf("%s", output);
}



void PromptAndGetFloat(char * prompt, float * output, float lowerlimit, float upperlimit){ // scans float into 'output'
    printf("%s (range %f to %f): ", prompt, lowerlimit, upperlimit);
    scanf("%f", output);
    while(*output < lowerlimit || *output > upperlimit){ // loops until output is in proper range
        printf("***Error: you must enter a value in the range %f to %f ***\n", lowerlimit, upperlimit);
        printf("%s (range %f to %f): ", prompt, lowerlimit, upperlimit);
        scanf("%f", output); 
    } 
}



void GetQuotient(float dividend, float divisor, float * quotient){ // stores the value of the quotient
    *quotient = dividend / divisor;
}






#include <stdio.h>
#include <ctype.h>
#define STR "123 test..33test 33 test 33 test a b"
#define SIZE 10

void ToUpperWord(char *string, int n);
void NthWord(char *string, int *ind);
void initializewordindex(void);
void HowManyWords(char *string, int *ptr);


int wordindex[SIZE];
int y = 0;
int *yptr = &y;


int main(void){
    
    char test[100] = STR;
   
    puts("*** Welcome to Lab 8 ***\n"); 
    printf("*** Original test string #1: %s\n", STR);

    initializewordindex();
    NthWord(STR, wordindex); 
    HowManyWords(STR, yptr);

    ToUpperWord(test, 0); 
    ToUpperWord(test, 3);
    ToUpperWord(test, 5);
    ToUpperWord(test, 7);
}



//prototypes
//start
//head
//calculates index for start of each word
//converts to upper


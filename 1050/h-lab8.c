
#include <stdio.h>
#include <ctype.h>
#define STR "123 test..33test 33 test 33 test a b"
#define SIZE 10

void ToUpperWord(char *string, int n);
void NthWord(char *string, int *ind);
void initializewordindex(void);
void HowManyWords(char *string, int *ptr);

char *hold = STR;
int wordindex[SIZE];


/*
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
*/


void initializewordindex(void){
    for(int i = 0; i < SIZE; i++)
        wordindex[i] = 999;
}


void NthWord(char *string, int *ind){
    int x = 1;
    for(int i = 0; *(string + i) != '\0'; i++){
        if(isalpha(*(string + i))){
            ind[x] = i;
            x++;
            while(isalpha(*(string + i + 1))){
                i++;
            }
        }
    }
}


void HowManyWords(char *string, int *ptr){
    for(int i = 1; i < SIZE; i++){
        if(wordindex[i] != 999){
            *ptr += 1;
        }
    }
}



void ToUpperWord(char *string, int n){
    int i = wordindex[n]; // index of word
    if(i != 999){
        while(isalpha(string[i])){
            string[i] = toupper(string[i]);
            i++;
        }
        printf("After trying word %d: %s\n", n, string);
    }
    else if(i == 999){
        printf("**ERROR: The %dth word was not found in string \"%s\"\n", n, string);
    }
    for(int i = 0; *(string + i) != '\0'; i++){
        *(string + i) = *(hold + i);
    }
}
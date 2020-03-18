#include <stdio.h>
#include <stdlib.h>


void GetInput(char str[256], int array[256]);
void PrintOutput(char * str, int * array);


int main(void){

    char string[256];
    int arr[256];

    printf("\n***WELCOME TO LAB 6***\n\n");

    GetInput(string, arr);
    PrintOutput(string, arr);
    
}

void GetInput(char str[256], int array[256]){

    printf("Please enter a string: ");
    scanf("%s", str);
    printf("\nPlease enter positive integers, enter -1 to end: ");
    int x = 0;
    int i = 0;
    while(x != -1){
        scanf("%d", &x);
        array[i] = x;
        i++;
    }
}

void PrintOutput(char * str, int * array){
    printf("\n%s\n", str);
    int i = 0;
    while(array[i] != -1){
        printf("array[%d] = %d\n", i, array[i]);
        i++;
    }
}



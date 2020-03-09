/*
Implement a function to determine the number of integers in an array of integers that 
are less than a given integer as well as the number that are greater than the given integer.
*/

#include <stdio.h>

void GreatOrLessCount(int arr[], int size, int query, int *greatcount, int *lesscount);

int main(void){

    int array[] = {1, 3, 4, 6, 8, 9, 11, 13, 16, 18, 23, -31, 23};
    int num = 10;
    int GreaterCount = 0;
    int LessCount = 0;
    int *pGreater = &GreaterCount;
    int *pLess = &LessCount;

    GreatOrLessCount(array, sizeof(array)/4, num, pGreater, pLess);
    printf("\nThere are %d integers in the arrat less than the query integer\nThere are %d "
    "integers in the array greater than the query integer\n\n", LessCount, GreaterCount);
}

void GreatOrLessCount(int arr[], int size, int query, int *greatcount, int *lesscount){
    for(int i = 0; i < size; i++){
       if(arr[i] < query){
           (*lesscount)++;
       }
       else if(arr[i] > query){
           (*greatcount)++;
       }
    }
}
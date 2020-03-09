#include <stdio.h>
#include <stdlib.h>

void InitializeArray(int array[], int begin, int end, int increment);
void PrintArray(int array[], int size);
void SumArrays(int array1[], int array2[], int arrayOut[], int size);
void PrintSameLine(int array1[], int array2[], int size);

int main(void){
    int arr[256];
    InitializeArray(arr, 2, 10, 2);
    //PrintArray(arr, 10);

    //printf("*\n*\n");

    int arr2[256];
    InitializeArray(arr2, 4, 10, 4);
    //PrintArray(arr2, 10);

    //printf("*\n*\n");

    int arrOut[256];
    SumArrays(arr, arr2, arrOut, 10);
    //PrintArray(arrOut, 10);


    printf("First Input Arrays:\n");
    PrintSameLine(arr, arr2, 10);
    printf("First Output Arrays:\n");
    PrintArray(arrOut, 10);

    int arr3[256];
    InitializeArray(arr3, 30, 11, -3);

    int arr4[256];
    InitializeArray(arr4, 99, 11, -9);

    int arrOut2[256];
    SumArrays(arr3, arr4, arrOut2, 11);

    printf("Second Input Arrays:\n");
    PrintSameLine(arr3, arr4, 11);
    printf("Second Output Arrays:\n");
    PrintArray(arrOut2, 11);

}

void InitializeArray(int array[], int begin, int end, int increment){
    int i;
    for(i = 0; i < end; i++){
        array[i] = begin;
        begin += increment;
    }
}

void PrintArray(int array[], int size){
    int i;
    for(i = 0; i < size; i++){
        printf("\tArray 1 Element %d = %d\n", i, array[i]);
    }
}

void SumArrays(int array1[], int array2[], int arrayOut[], int size){
    int i;
    for(i = 0; i < size; i++){
        arrayOut[i] = array1[i] + array2[i];
    }
}

void PrintSameLine(int array1[], int array2[], int size){
    int i;
    for(i = 0; i < size; i++){
        printf("\tArray 1 Element %d = %d    Array 2 Element %d = %d\n", i, array1[i], i, array2[i]);
    }
}
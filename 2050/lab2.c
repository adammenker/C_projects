# include <stdio.h>
# include <stdlib.h> //importing libraries

void countGrades(int arr[], int size, int BBoundary, int CBoundary, int* NoOfAs, int* NoOfBs, int* NoOfCs); //prototype of function to count grades

int main(void){    //program starts
    int array[30] = {57,99,53,58,46,46,92,72,43,82,42,90,70,65,88,53,59,75,43,45,66,69,63,93,77,98,99,40,88,49};    
    int size = sizeof(array)/sizeof(array[0]);    // initializing grade array, boundaries, and size of array
    int BBoundary = 80, 
    CBoundary = 60; 

    int NumA = 0; //initializing counters for each letter grade
    int NumB = 0;
    int NumC = 0;
    int *pNumA = &NumA; //creating pointers to the counters to facilitate pass by reference
    int *pNumB = &NumB;
    int *pNumC = &NumC;

    countGrades(array, size, BBoundary, CBoundary, pNumA, pNumB, pNumC); // calling function to count grades
    printf("%d students got an A, %d students got a B, and %d students got a C.\n", NumA, NumB, NumC); // printing results

    return 0;
} //program ends


void countGrades(int arr[], int size, int BBoundary, int CBoundary, int* NoOfAs, int* NoOfBs, int* NoOfCs){ 
    int i;
    for(i = 0; i < size; i++){ //looping through all elements of array and testing what boundary it falls between
        if(arr[i] >= BBoundary){
            (*NoOfAs)++; //adding one to the dereferenced pointer (the value of the counter) if the grade falls in that boundary
        }
        else if(arr[i] < BBoundary && arr[i] >= CBoundary){
            (*NoOfBs)++;
        }
        else if(arr[i] < CBoundary ){
            (*NoOfCs)++;
        }
    }
}
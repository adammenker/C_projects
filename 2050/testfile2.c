#include <stdio.h>
#include <stdlib.h>

int getSizeArray(void *array);
void * createArray(int n, int sizeOfDatatype);
void freeArray(double ** array);


int main(void){

    double * arr = createArray(10, sizeof(double));
    arr = (void*) (arr + 1);
    getSizeArray(arr);
    printf("%d", arr[-1])

    /* using output for error checking*/
    for(int i = 0; i < 10; i++){
        arr[i] = i;
    }

    for(int j = 0; j < 10; j++){
        printf("%f\n", arr[j]);
    }
    
    arr = (double*) (arr - 1);
    
    freeArray(&arr);

    for(int j = 0; j < 10; j++){
        printf("%f\n", arr[j]);
    }
    
}


int getSizeArray(void *array){
    int s = ((int *) array)[-1];
    return s;
}


void * createArray(int n, int sizeOfDatatype){
    int * array = malloc((n * sizeOfDatatype) + sizeof(int));
    array[0] = n;
    return array;
}


void freeArray(double ** array){
    free(*array);
    *array = NULL;
}
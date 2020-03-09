#include <stdio.h>
#include <stdlib.h>

int getSizeArray(void *array);
void * createArray(int n, int sizeOfDatatype);
void freeArray(double ** array);


int main(void){

    double * arr = createArray(10, sizeof(double));
    int size = getSizeArray(arr);

    /* using output for error checking
    for(int i = 0; i < 10; i++){
        arr[i] = i;
    }

    for(int j = 0; j < 10; j++){
        printf("%f\n", arr[j]);
    }
    */

    
    freeArray(&arr);
    
}


int getSizeArray(void *array){
    int s = ((int *) array)[-1];
    return s;
}


void * createArray(int n, int sizeOfDatatype){
    int * array = malloc((n * sizeOfDatatype) + sizeof(int));
    array[0] = n;
    return (void*) (array + 1);
}


void freeArray(double ** array){
    free(*((void**)array[0]));
    *array = NULL;
}





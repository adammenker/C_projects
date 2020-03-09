#include <stdio.h>
#include <stdlib.h>

void** create2DArray(int, int, int);
float getRowSize(void**);
float getColSize(void**, int);
void printTable(void**);
void freeTable(void**);


int main(void){

    int **t; 
    t = (int**)create2DArray(10, 5, sizeof(int));

    for(int i = 0; i < 10; i++){ 
        for(int x = 0; x < 5; x++){
            //printf("t[%d][%d] = %d\n",i, x, t[i][x]);
        }
    }

}


void** create2DArray(int numRows, int numCols, int elemSize){
    
    int i;
    float ** rows = (float**) malloc(8 * numRows + sizeof(float)); //8 because that is size of pointer on my machine, I tried sizeof(float) but that wont work
    //printf("***%d\n", (int)(sizeof(float) * numRows + sizeof(float))); // allocates correct number of bytes
    if(rows == NULL){ // error checking       
        printf("Allocation failed\n");        
        return NULL;    
    } 
    *(float*)rows = numRows;
    printf("**%f\n", *(float*)rows); //num rows is assigned to correct spot
    rows++;
    for(i = 0; i < numRows; i++){
        rows[i] = malloc(numCols * elemSize);
        //printf("**%d*\n", numCols * elemSize);
        if(rows == NULL){ // error checking      
            printf("Allocation failed\n");        
            return NULL;    
        }  
        *(float*)(rows + i) = numCols;     
        printf("%f\n", *(float*)(rows + i));
        rows[i]++; //indexes past where column size is stored to hide it
        printf("%f", *(float*)rows[i]);
        
    }

    return (void*)rows;
}


float getRowSize(void **array){ //retrieves array[-2]
    float i = (int)array[-1];
    return i;
}


float getColSize(void **array, int rowNo){ //retrieves array[-1]
    float i = *((float**)array[rowNo])[-1];
    if(rowNo > getRowSize(array) || rowNo < getRowSize(array)){
        return -1;
    }
    return i;
}


void printTable(void** t){
    int i, x;
    for(i = 0; i < 10; i++){ 
        for(x = 0; x < 5; x++){
            printf("t[%d][%d] = %d\n",i, x, *((int**)t[i])[x]);
        }
    }
}


void freeTable(void ** array){ 
    int i;
    for(i = 0; i < getRowSize(array); i++){ 
        free(((void**)array[i])[-1]);
    }
    ((int*)array[0])[0] = ((int*)array[-1])[-1];
    free(array);
    array = NULL; 
}
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
            printf("t[%d][%d] = %d\n",i, x, t[i][x]);
        }
    }

}


void** create2DArray(int numRows, int numCols, int elemSize){
    
    int i;
    void ** rows = malloc(sizeof(float) * numRows + sizeof(float));
    *(float*)rows = numRows;
    printf("%f", rows)
    rows++;
    for(i = 0; i < numRows; i++){
        rows[i] = malloc(numCols * elemSize);
        if (rows == NULL){ // error checking, deduct points if this is missing        
            printf("Allocation failed\n");        
            return NULL;    
        }
        *(float*)rows = numCols;
        rows++;
        printf("%d %f\n", numCols, *(float*)rows[i]);
    }
    
    return rows;
}

/*
void indexcol(void* t, int numRows){
    *(int*)t[0] = t[1];
}
*/
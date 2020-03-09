#include <stdio.h>
#include <stdlib.h>

void * createtable(int rowSize, int columnSize, int elementSize);

int main(void){

    int **t;
    t = createtable(10, 5, sizeof(int));
    printf("%d\n", t[0][0]);

    int p = 0;
    for(int i = 0; i < 10; i++){
        for(int x = 0; x < 5; x++){
            t[i][x] = p;
            p++;
            //printf("t[%d][%d] = %d\n",i, x, p);
        }
    }
    
}

void * createtable(int rowSize, int columnSize, int elementSize){
    
    int i;
    int sizeofpointer = 8; //pointers take up 8 bytes on 64-bit memory
    void ** rows = malloc(sizeofpointer * rowSize + 2 * sizeof(int));
    *(int*)rows = rowSize;
    rows++;
    *(int*)rows = columnSize;
    rows++;
    printf("%d %d\n", (int)rows[-2], (int)rows[-1]);
    for(i = 0; i < rowSize; i++){
        rows[i] = malloc(columnSize * elementSize);
    }
    printf("%d %d\n", (int)rows[-2], (int)rows[-1]);
    
    
    return rows;
}


int getRowSize(void *array){
    int s = ((int *) array)[-1];
    return s;
}


int getColSize(void *array){
    int s = ((int *) array)[-1];
    return s;
}
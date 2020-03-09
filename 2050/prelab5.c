#include <stdio.h>
#include <stdlib.h>

void * createtable(int rowSize, int columnSize, int elementSize); 
int getRowSize(void **array);
int getColSize(void **array);
void freeArray(void *** array);

int main(void){

    int **t; //creates table for int
    t = createtable(10, 5, sizeof(int)); // goes to function that creates table
    int row = getRowSize((void**)t); //casts t to a void** to pass to function
    int col = getColSize((void**)t);

    int p = 1;
    for(int i = 0; i < 10; i++){ //assigns values to each element
        for(int x = 0; x < 5; x++){
            t[i][x] = p;
            p++;
            //printf("t[%d][%d] = %d\n",i, x, t[i][x]);
        }
    }

    t = t - 2; //realigns pointer to go to what was malloc'ed

    printf("%d %d\n", (int)t[0], (int)t[1]); //prints array sizing elements
    printf("%d %d\n", t[3][3], t[11][4]); //prints random array elements

    freeArray((void***)t); //frees arrays (not sure if everything got freed)

    printf("%d %d\n", t[3][3], t[11][4]); //prints again to show seg fault
    printf("%d %d\n", (int)t[0], (int)t[1]); 
}

void * createtable(int rowSize, int columnSize, int elementSize){
    
    int i;
    int sizeofpointer = 8; //pointers take up 8 bytes on 64-bit memory
    void ** rows = malloc(sizeofpointer * rowSize + 2 * sizeof(int)); //makes void pointer size of rows and 2 ints
    *(int*)rows = rowSize; //assigns row[0] to size of rows
    rows++; //indexes up one
    *(int*)rows = columnSize; //assigns row[0] to size of columns
    rows++;
    for(i = 0; i < rowSize; i++){
        rows[i] = malloc(columnSize * elementSize); //creates an array at array[i] (starts from array[2] of the original, but array[0] includinf the two indexes up)
    }
    return rows; //returns array of 2 ints and 'rowsize' arrays
}


int getRowSize(void **array){ //retrieves array[-2]
    int i = (int)array[-2];
    return i;
}


int getColSize(void **array){ //retrieves array[-1]
    int i = (int)array[-1];
    return i;
}


void freeArray(void *** array){ //frees a dereferenced void ** (reason for three asterisks)
    for(int i = 0; i < 10; i++){ //since t is indexed before, this frees the two size variables along with the 10 arrays 
        free(*array[i]);
    }
    *array = NULL; //sets array pointer (t in main) to NULL
}
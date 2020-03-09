#include <stdio.h>
#include <stdlib.h>

float * readFloatFileIntoArray(FILE *fptr, int *length); //protoypes for functions
void freeArraySetNull(float ** array); //takes two '*' because you need to pass the address of the pointer so it is passed by reference, more detail below

int main(void){
    FILE *fp; //assigns file pointer
    int size;

    fp = fopen("datafile.dat", "r"); 
    if(fp == NULL){ //error checks if file opens 
        printf("error");
    }
    else{
        fscanf(fp, "%d", &size); //scans first number which is size, need to scan first so it can be used later to scan the other numbers
    }

    float * arr = readFloatFileIntoArray(fp, &size); //function returns an array, so assigning arr to the function will assign arr to the array returned
    
    freeArraySetNull(&arr); //frees memory and sets the array variable to NULL, *** passes the address of the array variable which is different than the address of the first element of the array
}


float * readFloatFileIntoArray(FILE *fptr, int *length){
    float * array;
    if((array = malloc(*length * sizeof(float)))){ //error checks if malloc has enough memory, double parenthesis bc T/F evalutations must be wrapped in '()'
        int i;
        for(i = 0; i < *length; i++){
            fscanf(fptr, "%f", (array + i)); //loops through and scans fptr 'length' amount of times, scanning in one float every iteration into 'array'
        }
        return array; // once all numbers have been scanned, returns the entire array 
    }
    else{
        printf("\nerror!\n"); // error message if malloc fails
        return 0; // needs a return value or else it may reach end of non-void function
    }
}


void freeArraySetNull(float ** array){ // since the array variable will be copied by value if you only pass in the array variable, 
                                       //you have to pass in the address of the array variable and work with that. *** address of array variable != adress of array ***
    free(*array); // dereferences address of array variable to get address of array and frees all the memory associated with the array
    *array = NULL; // dereferences address of array variable to get address of array and sets first element/adress of array to NULL so if it is referenced
    //in the future, you will recieve an error
}


//https://stackoverflow.com/questions/7608714/why-is-my-pointer-not-null-after-free?rq=1

/*Calling free() on a pointer doesn't change it, only marks memory as free. Your pointer 
will still point to the same location which will contain the same value, but that value 
can now get overwritten at any time, so you should never use a pointer after it is freed. 
To ensure that, it is a good idea to always set the pointer to NULL after free'ing it.*/

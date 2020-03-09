#include <stdio.h>
#include <stdlib.h>


int* readIntAgeIntoArray(FILE*, int*, float*);
void findMinMax(int*, int, int*, int*);
void freeIntArray(int**);
float average(int *array, int size);

//reads data from a file and computes the average, min and max age of all employees, and print these values along with total number of employees
int main(void){
    //initializing all varaibles
    int size; 
    int *sizeptr = &size;
    float avg;
    float *avgptr = &avg;
    int max;
    int *maxptr = &max;
    int min;
    int *minptr = &min;
    FILE *fp = NULL;

    int *arr = readIntAgeIntoArray(fp, sizeptr, avgptr); //populates integer array & computes avg

    findMinMax(arr, size, minptr, maxptr); //passes min and max value by reference into corresponding variables

    printf("\nThere are in total %d employees, the average age of them is %.2f\nLargest age is %d, smallest age is %d\n\n", size, avg, max, min); //prints output

    freeIntArray(&arr); //frees memory and sets ptr to NULL
    
    return 0;
    
}

//this function opens a data file, and reads the size of the array
//then it uses the size value to allocate memory for the array
//next it assigns values to each index of the array from the data file and returns the array 
int* readIntAgeIntoArray(FILE* fp, int* totalNumOfEmployee, float* averageAge){

    fp = fopen("employeeAge.txt", "r"); 
    if(fp == NULL){ //error checks if file opens 
        printf("error");
    }
    else{ //scans in size
        fscanf(fp, "%d", totalNumOfEmployee); 
    }


    int * array;
    if((array = malloc(*totalNumOfEmployee * sizeof(float)))){ //error checks if malloc has enough memory, double parenthesis bc T/F evalutations must be wrapped in '()'
        int i;
        for(i = 0; i < *totalNumOfEmployee; i++){
            fscanf(fp, "%d", (array + i)); //scans in ages into the array
        }

        *averageAge = average(array, *totalNumOfEmployee); //computes average age and assigns into a variable that is passed by reference

        return array; 
    }
    else{
        printf("\nerror!\n"); // error message if malloc fails
        return 0; // needs a return value or else it may reach end of non-void function
    }
}

float average(int *array, int size){ //calculates the average by adding all elements of the array and dividing by size of array
    float x = 0;
    int i;
    for(i = 0; i < size; i++){
        x += array[i];
    }
    x = x / i;
    return x; //returns the average value
}

//loops through each element of the array, if size is larger than previously set max, max value is replaced  ** same with min value
void findMinMax(int* arr, int size, int* minAge, int* maxAge){ 
    int i;
    *maxAge = 0;
    for(i = 0; i < size; i++){
        if(arr[i] > *maxAge){ //checks if next element is greater than current max
            *maxAge = arr[i]; 
        }
    }
    *minAge = 99;
    for(i = 0; i < size; i++){
        if(arr[i] < *minAge){
            *minAge = arr[i];
        }
    }
}

//takes a pointer to a pointer and frees the array while also setting the array to NULL
void freeIntArray(int ** array){ 
    free(*array);
    *array = NULL;
}
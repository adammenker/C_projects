#include <stdio.h>
#include <stdlib.h>

void* createArray(int, int); //function prototypes
int getArraySize(void*);
void freeArray(void*);
void storeAve(void*);

// creates an array of 'length' + 2
// finds the average of the elements
// stores avg in arr -1
// prints out size, avg, and each element
// calls custom free function on arr
int main(void){

    int arraySize = 10; // size of array  
    double * arr = createArray(arraySize, sizeof(double)); //creates array with malloc and returns the array to a double array
    arr = (void*) (arr + 2); //indexes up two and casts to void

    int size = getArraySize(arr); //store the size of the array in an int variable, gets data from arr[-2]

    double x; // assigns values to each element of the array, same as sample input on lab instructions
    for(x = 0; x < size; x++){
        arr[(int) x] = x + 5.5;
    }

    storeAve(arr); //calculates and stores the average of all the elements into arr[-1]

    //next 6 lines are used to print output in organized format
    printf("\nElements in array are: ");
    int y;
    for(y = 0; y < size; y++){
        printf("%.2f, ", arr[y]);
    }
    printf("\nArray size is %d, and the average value of all elements is %.2f\n\n", size, arr[-1]);


    arr = (double*) (arr - 2); //indexes back two so arr is lined up with the original malloc'ed array

    freeArray(&arr); //free the array memory and sets array pointer to NULL so seg fault occurs if you try to access that memory

    //used to show that array pointer has been freed, should produce seg fault if you uncomment the next 6 lines
    /*
    printf("\nElements in array are: ");
    for(y = 0; y < size; y++){
        printf("%.2f, ", arr[y]);
    }
    printf("\nArray size is %d, and the average value of all elements is %.2f\n\n", size, arr[-1]);
    */

    return 0;

}

// malloc array with size n, have additonal element (n+1) for average, have additonal sizeof(int) for size variable
//input value: size of array and size of datatype
//ouput: array with n size 
void * createArray(int n, int sizeOfDatatype){
    double * array = malloc((n + 1) * sizeOfDatatype + sizeof(int));
    array[0] = n; //sets array [0] to the size of the array
    return array;
}

// reads data from array[-2] which contains size (n from above) and returns it to int variable
//input: void array
//output: the size of the array stored in the -2 element
int getArraySize(void *array){
    int s = ((double *) array)[-2];
    return s;
}

// adds all elements of the array and then divides by the number of elements in the array to calculate and return average
//input: void array
//output: sets -1 element to average of array elements
void storeAve(void* array){
    int i;
    double ave = 0;
    for(i = 0; i < ((double*) array)[-2]; i++){
        ave += ((double *) array)[i];
    }
    ave = ave / ((double*)array)[-2];
    ((double *) array)[-1] = ave;
}

// free all the elements of the array, takes any type of array bc it is cast to void pointer, then sets void pointer to NULL so it cannot be accessed in the future
//input: void array
//output: frees array, sets ptr to NULL
void freeArray(void* array){
    free(*((void**) array));
    *((void**) array) = NULL;
}


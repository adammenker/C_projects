#include <stdio.h>
#include <stdlib.h>

typedef struct studstruct{    
    int age;    
    int ID;
} Student;

Student** readRecord(FILE*);
int comparison(void*,void*);
int binarySearch(void**,int,int,void*);
void freeArr(Student**,int);


int main(void){

    FILE * filePtr; //creates file pointer
    filePtr = fopen("students.csv", "r");

    void** myArr = (void**) readRecord(filePtr);

    Student test;
    test.age = 1;
    test.ID = 96548259;
    void* testptr = &test;
    

    binarySearch(myArr, 0, 10000, testptr);

    freeArr((Student**) myArr, 10000);

    fclose(filePtr);
    
}

// takes file ptr as input
// error checks file ptr and malloc
// allocates array of ptrs (ptr or every student struct)
// assigns each student structs data to data from file
// returns array of student structs
Student** readRecord(FILE* fptr){
    if(!fptr){ // error checks if file open
        printf("\nfile pointer is null\n\n");
        return NULL;
    }

    int numOfStudents;
    fscanf(fptr, "%d", &numOfStudents); // scans in number of student

    Student** array = malloc(sizeof(Student*) * numOfStudents); // creates array of ptrs
    if(array == NULL){ //error checks
        printf("\n***malloc failed\n");
        fclose(fptr);
        return NULL;
    }

    for(int i = 0; i < numOfStudents; i++){ // mallocs a student struct for each ptr
        array[i] = malloc(sizeof(Student));
        if(array[i] == NULL){ //error checks
            printf("\n***malloc failed\n");
            fclose(fptr);
            freeArr(array, i);
            return NULL;
        }
    }

    int age, ID;
    for(int i = 0; i < numOfStudents; i++){ //stores csv data in structs
        fscanf(fptr, "%d,%d\n", &age, &ID);
        array[i]->age = age;
        array[i]->ID = ID;
    }

    return array; // returns array of ptrs
}

// takes two student structs as input
// compares both IDs
// returns 1 if first ID is greater
// returns -1 if first ID is less than
// returns 0 if both IDs are same
// *designed with data in descending order in mind
int comparison(void* p1, void* p2){
    // for testing: printf("comparing %d to %d\n", (((Student*)p1)->ID), (((Student*)p2)->ID));
    if(((Student*) p1)->ID > ((Student*) p2)->ID){ // checks if query ID greater that median ID
        return 1; 
    }
    else if(((Student*) p1)->ID < ((Student*) p2)->ID){ // checks if query ID less that median ID
        return -1;
    }
    else{
        return 0; // IDs are the same
    }
}

// takes an array of ptrs and first and last index along with query student struct
// error checks array initializations
// returns -1 on fail
// calulates median index
// finds half where query should be, cuts other half away
// recursivvely calls itself until query is found, else returns fail (-1)
// *designed with data in descending order in mind
int binarySearch(void** array, int firstIndex, int lastIndex, void* query){
    if(array[0] == NULL || array == NULL || query == NULL){ //error checks array
        printf("\n***passes an unitialized array\n");
        return -1; // on fail
    }
    
    // for testing: printf("%d %d\n", firstIndex, lastIndex);
    if(firstIndex >= lastIndex){
        printf("\nquery not found\n\n");
        return -1; // the case where the query was not found in the array
    }

    int medianIndex = (firstIndex + lastIndex) / 2; // stores median index
    // for testing: printf("first: %d, last: %d\n**current: %d**\n\n\n", firstIndex, lastIndex , medianIndex);

    if(comparison(query, &(*(((Student**)array)[medianIndex]))) > 0){ // the case that query is greater than median value
        lastIndex = medianIndex - 1; // cuts off 2nd half of data
        return binarySearch(array, firstIndex, lastIndex, query);
    }
    else if(comparison(query, &(*(((Student**)array)[medianIndex]))) < 0){ // the case where query is less than median value
        firstIndex = medianIndex + 1; // cuts off 1st half of data
        return binarySearch(array, firstIndex, lastIndex, query);
    }
    else if(comparison(query, &(*(((Student**)array)[medianIndex]))) == 0){ // the case where query == median value
        printf("\nfound at %d\n\n", medianIndex);
        return medianIndex; // returns the index of desired ID

    }
    return -1; // will never reach this case but returns -1 anyway
}

// takes array of ptrs as input and number of structs
// loops through and frees each struct and sets to null
// frees array of struct and sets to null
void freeArr(Student** array, int size){  // done
    for(int i = 0; i < size; i++){ // loops through array and frees student structs
        free(array[i]);
        array[i] = NULL; // sets ptr to null
    }

    free(array); // frees array of ptrs
    array = NULL; // sets array to null
}
#include <stdio.h>
#include <stdlib.h>

typedef struct studstruct{    
    int age;    
    int ID;
} Student;

typedef struct studdatabase{    
    int sizeOfDB;    
    Student** array;
} StudentDB;

Student** readRecord(FILE*);
StudentDB createDatabase(Student**,int);
Student* findStudentByID(StudentDB,int);
void freeDatabase(StudentDB);

int main(void){

    FILE * filePtr; //creates file pointer
    filePtr = fopen("students.csv", "r");

    Student** myArr = readRecord(filePtr);
    for(int i = 0; i < 20; i++){   
        printf("%d %d\n", myArr[i]->age, myArr[i]->ID);
    }

    StudentDB myDB = createDatabase(myArr, 10000);
    for(int i = 0; i < 20; i++){   
        printf("** %d %d\n", myDB.array[i]->age, myDB.array[i]->ID);
    }

    Student* myStudent = findStudentByID(myDB, 5949605);
    if(myStudent != NULL){
        printf("\nage:%d id:%d\n", myStudent->age, myStudent->ID);
    }

    freeDatabase(myDB);
    for(int i = 0; i < 20; i++){   
        printf("** %d %d\n", myDB.array[i]->age, myDB.array[i]->ID);
    }


    // FILE* fp = fopen("students.csv","r");    
    // Student** arr = readRecord(fp);    
    // if (arr == NULL){        
    //     printf("Allocation failed\n");        
    //     return -1;    
    // } else {        
    //     printf("Data has been read.\n\n");    
    // } 
    // StudentDB myDB = createDatabase(arr,10000);
    // printf("\n*size: %d, myDB.array[0]->Id: %d myDB.array[5000]->ID: %d, myDB.array[5000]->ID %d myDB.array[9999]->ID: %d\n\n", myDB.sizeOfDB, myDB.array[0]->ID, myDB.array[5000]->ID, myDB.array[5000]->ID, myDB.array[9999]->ID);    
    // if (myDB.sizeOfDB == 10000 && (myDB.array[0]->ID > myDB.array[5000]->ID) && (myDB.array[5000]->ID > myDB.array[9999]->ID)){
    //     // ID should be descending        
    //     printf("createDatabase passed\n\n");    
    // } else {        
    //     printf("createDatabase failed\n\n");
    // }    
    // Student* temp = findStudentByID(myDB,1514789); // this one doesn't exist    
    // if (temp == NULL){        
    //     printf("findStudentByID 1 passed\n\n");    
    // } else {        
    //     printf("findStudentByID 1 failed\n\n");    
    // }    
    // temp = findStudentByID(myDB,82469843); // this one does exist    
    // if (temp == NULL){        
    //     printf("findStudentByID 2 failed\n\n");    
    // } else {        
    //     printf("findStudentByID 2 passed\n\n");    
    // }    
    // freeDatabase(myDB);    
    // printf("freeDatabase passed\n\n");    
    // return 0;
}



/************ for testing above, functionality below **************/

// my custom
void insertionSort(Student** arr, int n);
Student* binarySearch(StudentDB database, int key, int first, int last);
int compare(Student* studentPtr, int comparisonValue);


// takes file ptr as input
// error checks file ptr and malloc
// allocates array of ptrs (ptr for every student struct)
// assigns each student structs data to data from file
// returns array of student structs
Student** readRecord(FILE* fptr){
    if(!fptr){ // error checks if file open
        printf("\nfile pointer is null\n\n");
        return NULL;
    }

    int numOfStudents;
    fscanf(fptr, "%d", &numOfStudents); // scans number of students in file

    Student** array = malloc(sizeof(Student*) * numOfStudents); // creates array of ptrs
    if(array == NULL){ //error checks
        printf("\n***malloc failed\n");
        fclose(fptr);
        return NULL;
    }

    for(int i = 0; i < numOfStudents; i++){ // mallocs a student struct for each ptr
        array[i] = malloc(sizeof(Student));
        if(array[i] == NULL){ //error checks and frees previous memory if malloc failes
            printf("\n***malloc failed\n");
            fclose(fptr);
            for (int j = 0; j < i; j++){                     
                free(array[j]);                    
                array[j] = NULL;                
            }
            free(array);
            array = NULL;
            return NULL;
        }
    }

    int age, ID;
    for(int i = 0; i < numOfStudents; i++){ //stores csv data in structs
        fscanf(fptr, "%d,%d\n", &age, &ID);
        array[i]->age = age;
        array[i]->ID = ID;
    }
    printf("%d\n", array[0]->age);  
    return array; // returns an array of pointers of student structs
}

// takes array of student ptrs and size int as input
// error checks the array
// declares databse variable
// sets database size to size arg
// sorts input array with insertion sort
// assigns database array to input array pointer
// returns database
StudentDB createDatabase(Student** array, int size){
    if(array == NULL){ // error checks the array
        printf("array is NULL, will exit from createSEarchableEmployeeDB()\n");
        exit(-1);
    }

    // declares databse variable
    // sets database size to size arg
    StudentDB database;
    database.sizeOfDB = size;
    // database.array = malloc(sizeof(Student*) * size);  // NO MALLOC NECESSARY, JUST SORT INPUT ARRAY 
    // if(database.array == NULL){
    //     printf("malloc failed in createDatabase(): will exit\n");
    //     free(array);
    //     exit(-1);
    // }

    // sorts input array with insertion sort
    // assigns database array to input array pointer
    insertionSort(database.array, size);
    database.array = array;

    return database;// returns database
}

// takes array of student ptrs and size as input
// error checks array initialization
// loops trhough array, searches until it finds larger ID and then puts before student with larger key/ID
// rearranges array in this fashion
void insertionSort(Student** array, int size){ 
    if(array[0] == NULL || array == NULL){// error checks array initialization
        printf("error: undeclared memory, returning in insertionSort()\n");
        return;
    }

    int i, key, j; 
    for (i = 1; i < size; i++) { // loops trhough array, searches until it finds larger ID and then puts before student with larger key/ID
        key = array[i]->ID; 
        j = i - 1; 

        while (j >= 0 && array[j]->ID > key) { // finds index with greater ID stores temp value to be one after
            Student* temp = array[j + 1]; // stores temp value to be one after
            array[j + 1] = array[j]; // puts student with larger ID one after where it was
            array[j] = temp; // puts argument student in position where student with larger ID was just moved from
            j = j - 1; // decrements j
        } 
        array[j + 1]->ID = key; // sets ID of next student to key value
    } 
} 

// takes databse and query as input
// error checks to see if database has initialized memory
// binary searches through database array in O(log(N)) time
// returns pointer to student with query ID
Student* findStudentByID(StudentDB database, int key){
    if(database.array[0] == NULL || database.array == NULL){
        printf("error: searching undeclared memory, returning NULL in findStudentByID()\n");
        return NULL;
    }

    Student* temp;
    temp = binarySearch(database, key, 0, database.sizeOfDB);// binary searches through database array in O(log(N)) time
    if(temp == NULL){
        printf("student not found\n");
    }
    return temp; // returns pointer to student with query ID
}

// takes student pointer and query as input
// error checks Student pointer
// compares query to pointer's ID and return value corresponds to whether the ID is <, >, or = to the query
int compare(Student* studentPtr, int comparisonValue){
    if(studentPtr == NULL){// error checks Student pointer
        printf("error: passing undeclared ptr in compare(), exiting program\n");
        exit(-1);
    }

    // printf("comparing %d and %d\n", studentPtr->ID, comparisonValue);
    if(studentPtr->ID > comparisonValue){
        return -1; // ID greater than query
    }
    else if(studentPtr->ID < comparisonValue){
        return 1; // ID less than query 
    }
    else if(studentPtr->ID == comparisonValue){
        return 0; // ID is equal to query
    }
    return 2; //fail
}

// takes database, query and 2 indexes as input
// error checks to see if database has initialized memory
// recursively calls binary search until query is found or returns NULL if not
// halves the array size each time
// returns pointer to Student with query ID else NULL
// time complexity of O(log(N))
Student* binarySearch(StudentDB database, int key, int first, int last){
    if(database.array == NULL || database.array[0] == NULL){ // error checks to see if database has initialized memory
        printf("error: passing empty memory in binarySearch(), will exit program\n");
        exit(-1);
    }

    int mid = first + (last - first)/2;
    if(last >= first){// recursively calls binary search until query is found or returns NULL if not
        if(compare(database.array[mid], key) == 0){
            return database.array[mid];// returns pointer to Student with query ID
        }
        else if(compare(database.array[mid], key) == -1){
            last = mid - 1;// halves the array size each time
            return binarySearch(database, key, first, last);// returns pointer to Student with query ID
        }
        else if(compare(database.array[mid], key) == 1){
            first = mid + 1;// halves the array size each time
            return binarySearch(database, key, first, last);// returns pointer to Student with query ID
        }
    }
    // printf("returning NULL\n");
    return NULL; // not found
}

// takes database as input
// error checks to see if database has initialized memory
// loops through database array and frees all students structs
// frees database array
void freeDatabase(StudentDB database){ 
    if(database.array[0] == NULL || database.array == NULL){ // error checks to see if database has initialized memory
        printf("error: freeing undeclared memory, exiting function\n");
        return;
    }

    for(int i = 0; i < database.sizeOfDB; i++){ // loops through database array and frees all students structs
        free(database.array[i]);
        database.array[i] = NULL;
    }
    free(database.array); // frees database array
    database.array = NULL;
}
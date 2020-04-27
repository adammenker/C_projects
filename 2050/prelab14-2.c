#include <stdio.h>
#include <stdlib.h>


typedef struct employee_struct {
    int SSN;
    int ID;
} Employee;

typedef struct employee_database_struct {
    Employee** databaseByID;
    Employee** databaseBySSN;
} empDatabase;


empDatabase createSearchableEmployeeDB(Employee**, int);
Employee* findEmpBySSN(int, empDatabase);
Employee* findEmpByID(int, empDatabase);
void freeEmpDatabase(empDatabase);

int partitionID(Employee** array, int low, int high);
void swap(Employee* a, Employee* b);
void quickSort(Employee** array, int low, int high);

void merge(Employee** arr, int l, int m, int r, int check);
void mergeSort(empDatabase database, Employee** array, int first, int last, int check);
int compare(Employee* employeePtr, int comparisonValue, int check);
Employee* binarySearch(Employee** array, int key, int first, int last, int check);
void printfDB(Employee** array);


int main(void){
    Employee emp1;
    emp1.ID = 001;
    emp1.SSN = 16;
    Employee emp2;
    emp2.ID = 002;
    emp2.SSN = 3;
    Employee emp3;
    emp3.ID = 003;
    emp3.SSN = 54;
    Employee emp4;
    emp4.ID = 004;
    emp4.SSN = 13;
    Employee emp5;
    emp5.ID = 005;
    emp5.SSN = 31;
    Employee emp6;
    emp6.ID = 006;
    emp6.SSN = 94;

    Employee** userArray = malloc(sizeof(Employee*) * 6);
    for(int i = 0; i < 6; i++){
        userArray[i] = malloc(sizeof(Employee));
    }
    userArray[0] = &emp5;
    userArray[1] = &emp1;
    userArray[2] = &emp2;
    userArray[3] = &emp3;
    userArray[4] = &emp4;
    userArray[5] = &emp6;

    // printf("\n*************** random sort ***************\n");
    // printfDB(userArray);
    // printf("*******************************************\n\n");

    // testing data above, functionality testing below

    empDatabase myDatabase = createSearchableEmployeeDB(userArray, 6);

    // printf("*************** sorted by ID **************\n");
    // printfDB(myDatabase.databaseBySSN);
    // printf("*******************************************\n\n");

    // printf("*************** sorted by SSN **************\n");
    // printfDB(myDatabase.databaseBySSN);
    // printf("*******************************************\n");

    // Employee* mytemp = findEmpByID(3, myDatabase);
    // printf("%d %d", mytemp->ID, mytemp->SSN);

}


void printfDB(Employee** array){
    for(int i = 0; i < 6; i++){
        printf("** employee: %d --> id: %d, ssn: %d\n", i + 1, array[i]->ID, array[i]->SSN);
    }
}


empDatabase createSearchableEmployeeDB(Employee** array, int size){
    if(array == NULL){
        printf("array is NULL, will exit from createSEarchableEmployeeDB()\n");
        exit(-1);
    }

    empDatabase database;
    database.databaseByID = malloc(sizeof(Employee*) * size);
    if(database.databaseByID == NULL){
        printf("malloc failed, will exit from createSearchableEmployeeDB()\n");
        exit(-1);
    }
    database.databaseBySSN = malloc(sizeof(Employee*) * size);
    if(database.databaseBySSN == NULL){
        printf("malloc failed, will exit from createSearchableEmployeeDB()\n");
        free(database.databaseByID);
        exit(-1);
    }

    // fill each of the two arrays with sorted data
    quickSort(array, 0, size);
    return database;
}


int partitionID(Employee** array, int low, int high){ 
    int pivot = array[high - 1]->ID;    // pivot 
    int i = low;  // Index of smaller element 
    
    for(int j = low; j < high; j++){ 
        // If current element is smaller than the pivot 
        if(array[j]->ID < pivot){ 
            i++;    // increment index of smaller element
            printf("\n* %d %d\n", i, j); 
            swap(array[i], array[j]); 
        } 
    } 
    printf("\n%d %d\n", i, high);
    swap(array[i + 1], array[high - 1]); 
    return (i + 1); 
} 


void swap(Employee* a, Employee* b){ 
    // printf("****\n");
    Employee temp = *a; 
    *a = *b; 
    *b = temp; 
} 


void quickSort(Employee** array, int low, int high){ 
    // printf("**\n");
    if (low < high){ 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        // printf("*\n");
        int partitionIndex = partitionID(array, low, high); 
        // printf("***\n");
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(array, low, partitionIndex - 1); 
        quickSort(array, partitionIndex + 1, high); 
    } 
} 
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
int partitionSSN(Employee** array, int low, int high);
void swap(Employee** array, int firstIndex, int secondIndex);
Employee** quickSort(Employee** array, int low, int high, int ID_or_SSN);
void copyArrays(Employee** copiedArray, Employee** DBArray, int size);


void merge(Employee** arr, int l, int m, int r, int check);
void mergeSort(empDatabase database, Employee** array, int first, int last, int check);
int compare(Employee* employeePtr, int comparisonValue, int check);
Employee* binarySearch(Employee** array, int key, int first, int last, int check);
void printfDB(Employee** array);


int main(void){
    Employee emp1;
    emp1.ID = 1;
    emp1.SSN = 16;
    Employee emp2;
    emp2.ID = 2;
    emp2.SSN = 3;
    Employee emp3;
    emp3.ID = 3;
    emp3.SSN = 54;
    Employee emp4;
    emp4.ID = 4;
    emp4.SSN = 13;
    Employee emp5;
    emp5.ID = 5;
    emp5.SSN = 31;
    Employee emp6;
    emp6.ID = 6;
    emp6.SSN = 94;
    Employee emp7;
    emp7.ID = 7;
    emp7.SSN = 104;
    Employee emp8;
    emp8.ID = 8;
    emp8.SSN = 64;
    Employee emp9;
    emp9.ID = 9;
    emp9.SSN = 4;
    Employee emp10;
    emp10.ID = 10;
    emp10.SSN = 194;
    Employee emp11;
    emp11.ID = 11;
    emp11.SSN = 94;
    Employee emp12;
    emp12.ID = 12;
    emp12.SSN = 494;
    Employee emp13;
    emp13.ID = 13;
    emp13.SSN = 947;

    Employee** userArray = malloc(sizeof(Employee*) * 13);
    for(int i = 0; i < 13; i++){
        userArray[i] = malloc(sizeof(Employee));
    }
    userArray[0] = &emp13;
    userArray[1] = &emp5;
    userArray[2] = &emp11;
    userArray[3] = &emp3;
    userArray[4] = &emp12;
    userArray[5] = &emp8;
    userArray[6] = &emp6;
    userArray[7] = &emp1;
    userArray[8] = &emp7;
    userArray[9] = &emp10;
    userArray[10] = &emp2;
    userArray[11] = &emp4;
    userArray[12] = &emp9;

    printf("\n*************** random sort ***************\n");
    printfDB(userArray);
    printf("*******************************************\n\n");

    // testing data above, functionality testing below

    empDatabase myDatabase = createSearchableEmployeeDB(userArray, 13);
    // printf("** employee: %d --> id: %d, ssn: %d\n", 1, myDatabase.databaseByID[0]->ID, myDatabase.databaseByID[0]->SSN);

    printf("*************** sorted by ID **************\n");
    printfDB(myDatabase.databaseByID);
    printf("*******************************************\n\n");

    printf("*************** sorted by SSN **************\n");
    printfDB(myDatabase.databaseBySSN);
    printf("*******************************************\n");

    // Employee* mytemp = findEmpByID(3, myDatabase);
    // printf("%d %d", mytemp->ID, mytemp->SSN);

}


void printfDB(Employee** array){
    for(int i = 0; i < 13; i++){
        printf("employee: %d --> id: %d, ssn: %d\n", i + 1, array[i]->ID, array[i]->SSN);
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
    Employee** tempArray;
    tempArray = quickSort(array, 0, size, 1);
    copyArrays(tempArray, database.databaseByID, size);
    // database.databaseByID = quickSort(array, 0, size, 1);
    tempArray = quickSort(array, 0, size, 2);
    copyArrays(tempArray, database.databaseBySSN, size);
    // database.databaseBySSN = quickSort(array, 0, size, 2);
    // printfDB(tempArray);

    return database;
}


int partitionID(Employee** array, int low, int high){ 
    int i = low;
    int partitionIndex = low;
    int paritionValue = array[high - 1]->ID;
    while(i < (high - 1)){
        if(array[i]->ID < paritionValue){
            swap(array, i, partitionIndex);
            partitionIndex++;
        }
        i++;
    }
    swap(array, partitionIndex, high - 1);
    return partitionIndex;
} 


int partitionSSN(Employee** array, int low, int high){ 
    int i = low;
    int partitionIndex = low;
    int paritionValue = array[high - 1]->SSN;
    while(i < (high - 1)){
        if(array[i]->SSN < paritionValue){
            swap(array, i, partitionIndex);
            partitionIndex++;
        }
        i++;
    }
    swap(array, partitionIndex, high - 1);
    return partitionIndex;
} 


void swap(Employee** array, int firstIndex, int secondIndex){ 
    Employee* temp = array[firstIndex];
    array[firstIndex] = array[secondIndex];
    array[secondIndex] = temp;
} 

Employee** quickSort(Employee** array, int low, int high, int ID_or_SSN){ 
    if(low < high){
        int partitionIndex; // ID_or_SSN will = 1 for ID and 2 for SSN
        if(ID_or_SSN == 1){
            partitionIndex = partitionID(array, low, high);
        } else if(ID_or_SSN == 2){
            partitionIndex = partitionSSN(array, low, high);
        }
        quickSort(array, low, partitionIndex, ID_or_SSN);
        quickSort(array, partitionIndex + 1, high, ID_or_SSN);
    }
    return array;
} 


void copyArrays(Employee** copiedArray, Employee** DBArray, int size){
    for(int i = 0; i < size; i++){
        DBArray[i] = malloc(sizeof(Employee));
        DBArray[i]->ID = copiedArray[i]->ID;
        DBArray[i]->SSN = copiedArray[i]->SSN;
    }
}

/* testing print statements for quicksort()

first line of quicksort:
    check++;
    printf("** %d **\n", check);
    printfDB(array);

line before quicksort:
    int check = 0;

one line before return on partitionID():
    printf("returning %d as partition index\n", partitionIndex);

before final swap in partitionID():
    printf("* swapping index: %d with %d, with values: %d and %d\n", partitionIndex, i, array[partitionIndex]->ID, array[i]->ID);

first line in if statement in partitionID():
    printf("swapping index: %d with %d, with values: %d and %d\n", partitionIndex, i, array[partitionIndex]->ID, array[i]->ID);

*/


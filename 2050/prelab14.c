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
void merge(Employee** arr, int l, int m, int r, int check);
void mergeSort(empDatabase database, Employee** array, int first, int last, int check);


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
    userArray[1] = &emp4;
    userArray[2] = &emp2;
    userArray[3] = &emp6;
    userArray[4] = &emp3;
    userArray[5] = &emp1;
    printf("\n*************** random sort ***************\n");
    for(int i = 0; i < 6; i++){
        printf("employee: %d --> id: %d, ssn: %d\n", i + 1, userArray[i]->ID, userArray[i]->SSN);
    }
    printf("*******************************************\n\n");

    // testing data above, functionality testing below

    empDatabase myDatabase = createSearchableEmployeeDB(userArray, 6);
    printf("*************** sorted by ID **************\n");
    for(int i = 0; i < 6; i++){
        printf("** employee: %d --> id: %d, ssn: %d\n", i + 1, myDatabase.databaseByID[i]->ID, myDatabase.databaseByID[i]->SSN);
    }
    printf("*******************************************\n\n");

    printf("*************** sorted by SSN **************\n");
    for(int i = 0; i < 6; i++){
        printf("** employee: %d --> id: %d, ssn: %d\n", i + 1, myDatabase.databaseBySSN[i]->ID, myDatabase.databaseBySSN[i]->SSN);
    }
    printf("*******************************************\n");

}


empDatabase createSearchableEmployeeDB(Employee** array, int size){
    // malloc space for database
    empDatabase db;
    db.databaseByID = malloc(sizeof(Employee) * size);
    db.databaseBySSN = malloc(sizeof(Employee) * size);

    // use quicksort or mergesort to fill database with struct pointers in an sorted order
    mergeSort(db, array, 0, size - 1, -1);
    mergeSort(db, array, 0, size - 1, 1);

    // return database
    return db;
}


Employee* findEmpBySSN(int ssn, empDatabase database){
    
    // binary searches for ssn and returns matching struct
    return NULL;
}


Employee* findEmpByID(int id, empDatabase database){
    // binary searches for id and returns matching struct
    return NULL;
}


void freeEmpDatabase(empDatabase database){
    // loops through ptrs of database and frees them all then frees databse ptr
}


void mergeSort(empDatabase database, Employee** array, int first, int last, int check){
    // for ID pass -1 into check, for SSN pass 1 into check
    if(first < last){
        int mid = (first + last) / 2;
        mergeSort(database, array, first, mid, check);
        mergeSort(database, array, mid + 1, last, check);
        merge(array, first, mid, last, check);
    }

    for(int i = 0; i < last + 1; i++){
        if(check == -1){
            database.databaseByID[i] = array[i];
        }
        else if (check == 1){
            database.databaseBySSN[i] = array[i];
        }
    }
}


void merge(Employee** array, int first, int mid, int last, int check){ 
    int i, j, k; 
    int num1 = mid - first + 1; 
    int num2 =  last - mid; 
  
    /* create temp arrays */
    Employee* firstArr[num1];
    Employee* lastArr[num2]; 
  
    /* Copy data to temp arrays First[] and Last[] */
    for (i = 0; i < num1; i++) 
        firstArr[i] = array[first + i]; 
    for (j = 0; j < num2; j++) 
        lastArr[j] = array[mid + 1 + j]; 

  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = first; // Initial index of merged subarray 
    if(check == -1){
        while (i < num1 && j < num2) 
        { 
            if (firstArr[i]->ID <= lastArr[j]->ID)  // line with changed comparison
            { 
                array[k] = firstArr[i]; 
                i++; 
            } 
            else
            { 
                array[k] = lastArr[j]; 
                j++; 
            } 
            k++; 
        }
    }
    else if(check == 1){
        while (i < num1 && j < num2) 
        { 
            if (firstArr[i]->SSN <= lastArr[j]->SSN)  // line with changed comparison
            { 
                array[k] = firstArr[i]; 
                i++; 
            } 
            else
            { 
                array[k] = lastArr[j]; 
                j++; 
            } 
            k++; 
        }
    }
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < num1) 
    { 
        array[k] = firstArr[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < num2) 
    { 
        array[k] = lastArr[j]; 
        j++; 
        k++; 
    } 
} 
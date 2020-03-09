#include <stdio.h>
#include <stdlib.h>

//struct definition
typedef struct {
    int empID, age, ssn;
    float salary;
} Record;

//prototypes
Record* readRecordFile(FILE*);
int getSize(Record*);
Record* getEmpByAge(Record*,int);
void adjustSalaries(Record*,int,float);
void freeRecordArray(Record*);

//this main function can be used for testing, follow comments to test (by uncommenting certain lines(25-29, 34, 39))
int main(void){

    FILE * fptr; //creates file pointer
    fptr = fopen("employee.csv", "r"); //points file pointer to correct file and sets to read mode

    Record * array = readRecordFile(fptr);
    //uncomment to test if struct data was read properly
    /*
    for(int i =0; i < 5; i++){ //change to whatever numbers you want to check
        printf("%f, %d, %d, %d\n", array[i].salary, array[i].empID, array[i].age, array[i].ssn); 
    }
    */
    
    //uncomment to test adjustSalaries and getEmpByAge, the print statement lets you check both at once
    adjustSalaries(array, 19, 10);
    //Record * p = getEmpByAge(array, 19);
    //printf("%f, %d, %d, %d\n", p->salary, p->empID, p->age, p->ssn);
    
    //uncomment to test get size
    int size;
    size = getSize(array);
    //printf("%d", size);

    fclose(fptr); //closes file pointer

    freeRecordArray(array); //frees all memory allocated
    

}

//This function recieves a file pointer as input
//it takes the first number in the file and stores it as the size of the array
//it creates a struct array dynamically and scans in the data from the csv file
//it error check malloc
//it stores the size of the array as the first element and then indexes past it to 'hide' the size
//it stores the data in each struct and returns the struct array
// function should be called to create the array of structs and store corresponding data
Record* readRecordFile(FILE* fp){
    int numOfEmployees;
    fscanf(fp, "%d", &numOfEmployees); //gets size

    int empID, age, ssn; //variables to store data
    float salary;


    Record * arr = malloc(sizeof(int) + numOfEmployees * (sizeof(Record))); //allocates mem for the array and the size int
    if(arr == NULL){ //error checks
        printf("\n***malloc failed\n");
        exit(1);
    }
    
    *(int*)arr = numOfEmployees; //stores size in first element
    arr = (Record*)((int*)(arr + 1)); //indexes past it 


    for(int i = 0; i < numOfEmployees; i++){ //stores csv data in structs
        fscanf(fp, "%f,%d,%d,%d\n", &salary, &age, &empID, &ssn);
        arr[i].salary = salary;
        arr[i].age = age;
        arr[i].empID = empID;
        arr[i].ssn = ssn;
    }

    return arr; //returns entire struct array
}

//this function takes an array as input
//it creates a pointer to the array and then indexes back one to access the hidden 'size' value
//returns the value of 'size'
//function should be called to find size
int getSize(Record* rec){
    if(rec == NULL){ //error checks if array is null
        return -1;
    }
    int size;
    int* temp = ((int*)(rec - 1)); //indexing back one, casting to int ptr, storing in int ptr
    size = *(temp); //sets variable to 'size' value
    return size; //returns size
}

//this function takes an array of structs and an int for desired age as input
//checks for age
//returns pointer to the first struct with that age
//function should be called to create pointer to beginning of where specified age starts
Record * getEmpByAge(Record *array, int age){
    if(array == NULL){ //error checks if array is null
        return NULL;
    }
    for(int i = 0; i < getSize(array); i++){ //loops through enitre array of structs to find the specified age
        if((array[i].age) == age){
            printf("\nEmployee found!\n");
            return &(array[i]); //returns pointer to first struct with specified age
        }
    }
    printf("\n***ERROR: no employee with that ID, \n***program ended***\n\n"); //prints error message if age is not found
    return NULL; //returns NULL if age is not found
}

//this function takes an array of structs, an int 'age' and a float for the multiplier of the salaray
//it finds all structs with the age and multiplies their salary by the speicified multiplier
//error checks for if the age is in a struct
//funciton should be called to manipulate the saleries of a certain age
void adjustSalaries(Record* array, int age, float mult){
    if(array == NULL){ //error checks if array is null
        return;
    }
    int count = 0;
    for(int i = 0; i < getSize(array); i++){ //loops through to find specified age
        if((array[i].age) == age){
            array[i].salary *= mult; //if age is correct multiplies salary bu multiplier
            count++; //used to check if age was in the array at all
        }
    }
    if(count == 0){ //if age was never found in the array, prints error message
            printf("age not found\n");
    }
}

//this function takes an array as input
//indexes back to orignal malloc'ed array to include hidden value
//frees all the memory that was declared 
//sets array pointer to NULL
//funciton should be called to free memory
void freeRecordArray(Record* arr){
    if(arr == NULL){ //error checks if array is null
        return;
    }

    arr = (Record*)((int*)(arr + -1)); //indexes back correctly
    
    free(arr); //frees memeory
    arr = NULL; //sets pointer to NULL
}
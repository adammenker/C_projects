#include <stdio.h>
#include <stdlib.h>


typedef struct {
        int ID, jobType;
        float salary;
} Employee;

Employee * readEmployeeInfo(FILE* fp, int* numElems);
Employee * getEmployeeByID(Employee *, int numEmps, int ID);
int getID(Employee* p);
void setID(Employee *p, int id);
void setSalary(Employee *p, float salary);
float getSalary(Employee* p);
int getJobType(Employee* p);
void setJobType(Employee *p, float jobtype);

int main(void){

    int EmployeesDataSize = sizeof(Employee);
    int * numberOfElementsptr = &EmployeesDataSize;

    FILE * fptr; 
    fptr = fopen("employeedataprelab6.dat", "r");

    Employee * array1 = readEmployeeInfo(fptr, numberOfElementsptr);

    /*
    for(int i =0; i < 5; i++){
        printf("%d, %d, %.2f\n", array1[i].ID, array1[i].jobType, array1[i].salary); //prints junk values beyond hundreths place if no '.2' conversion specifier
    }
    */

    Employee * Emp3 = getEmployeeByID(array1, *numberOfElementsptr, 1003);

    //printf("\n*%d, %d, %.2f\n", Emp3->ID, Emp3->jobType, Emp3->salary);

    setID(Emp3, 2003);

    //printf("\n*%d, %d, %.2f\n", Emp3->ID, Emp3->jobType, Emp3->salary);

    fclose(fptr);
}

//to make an array of Employee structs containing the info of each employee
Employee * readEmployeeInfo(FILE* fp, int* numElems){
    int numOfEmployees;

    int idNum;
    int jobtype;
    float salaryVal;

    fscanf(fp, "%d", &numOfEmployees); //scans number of employees from datafile
    Employee * arr = malloc(numOfEmployees * (*numElems)); //creates an Employee struct array with the size of the struct times the number scanned in for number of employees
    if(arr == NULL){
        printf("\n***malloc failed\n");
        exit(1);
    }
    for(int i = 0; i < numOfEmployees; i++){
        fscanf(fp, "%d, ", &idNum);
        fscanf(fp, "%d, ", &jobtype);
        fscanf(fp, "%f, ", &salaryVal);
        setID(&(arr[i]), idNum);
        setJobType(&(arr[i]), jobtype);
        setSalary(&(arr[i]), salaryVal);
    }
    return arr;
}


Employee * getEmployeeByID(Employee *array, int numEmps, int ID){
    for(int i = 0; i < numEmps; i++){
        if(getID(&(array[i])) == ID){
            printf("\nEmployee found!\n");
            return &(array[i]);
        }
    }
    printf("\n***ERROR: no employee with that ID, \n***program ended***\n\n");
    exit(0);
    return 0;
}


int getID(Employee* p){
    return p->ID;
}


float getSalary(Employee* p){
    return p->salary;
}


int getJobType(Employee* p){
    return p->jobType;
}


void setID(Employee *p, int id){
    p->ID = id;
}


void setSalary(Employee *p, float salary){
    p->salary = salary;
}


void setJobType(Employee *p, float jobtype){
    p->jobType = jobtype;
}
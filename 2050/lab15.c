/* provided header 
#include <stdio.h>
#include <stdlib.h>

typedef struct{    
    int ID;    
    float salary;    
    int ssn;
} Employee;

typedef struct node{            
    Employee* data;            
    struct node *left, *right;
} Node;

Employee** readRecord(FILE*);
int comparison(void*,void*);
Node* insertBST(Node*, Employee*);
Employee* searchBST(Node*,int);
void deleteTree(Node*);
*/

// custom functions
Node* newNode(Employee* employee);
void print2DUtil(Node *root, int space);
void print2D(Node* root);

/* testing function 

int main(void){
    FILE * filePtr; //creates file pointer
    filePtr = fopen("employee.csv", "r");
    
    Employee** myArr = readRecord(filePtr);
    for(int i = 0; i < 10; i++){   
        printf("%d %f %d\n", myArr[i]->ID, myArr[i]->salary, myArr[i]->ssn);
    }
    printf("\n-------------------------------------------------------------\n\n");

    Node* root = NULL;
    for(int i = 0; i < 10; i++){
        root = insertBST(root, myArr[i]);
    }
    print2D(root);
    printf("\n-------------------------------------------------------------\n\n");

    Employee* temp = searchBST(root, 287612752);
    printf("%d -- %.2f -- %d\n", temp->ssn, temp->salary, temp->ID);
    printf("\n-------------------------------------------------------------\n\n");
    
    Node* bstTemp = (root->left)->left;
    deleteTree(bstTemp);
    printf("%d -- %.2f -- %d\n", (root->left)->data->ssn, (root->left)->data->salary, (root->left)->data->ID);
    printf("\n-------------------------------------------------------------\n\n");
    print2D(root);
}
*/

// takes file ptr as input
// error checks file ptr and malloc
// allocates array of ptrs (ptr or every employee struct)
// assigns each employee structs data to data from file
// returns array of employee structs
Employee** readRecord(FILE* fptr){
    if(!fptr){ // error checks if file open
        printf("\nfile pointer is null\n\n");
        return NULL;
    }

    int numOfEmployees;
    fscanf(fptr, "%d", &numOfEmployees); // scans number of employees in file

    Employee** array = malloc(sizeof(Employee*) * numOfEmployees); // creates array of ptrs
    if(array == NULL){ //error checks
        printf("\n***malloc failed\n");
        fclose(fptr);
        return NULL;
    }

    for(int i = 0; i < numOfEmployees; i++){ // mallocs an employee struct for each ptr
        array[i] = malloc(sizeof(Employee));
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
    int SSN, ID;
    float salary;
    for(int i = 0; i < numOfEmployees; i++){ //stores csv data in structs
        fscanf(fptr, "%d,%f,%d\n", &ID, &salary, &SSN);
        array[i]->ssn = SSN;
        array[i]->ID = ID;
        array[i]->salary = salary;
    }
    // printf("%f\n", array[0]->salary);  
    return array; // returns an array of pointers of employee structs
}

// takes two employee structs as input
// compares both ssn's
// returns 1 if first ssn is greater
// returns -1 if first ssn is less than
// returns 0 if both ssn's are same
int comparison(void* object_1, void* object_2){
    // for testing: printf("comparing %d to %d\n", (((employee*)p1)->ID), (((employee*)p2)->ID));
    if(((Employee*) object_1)->ssn > ((Employee*) object_2)->ssn){ // checks if query ID greater that median ID
        return 1; 
    }
    else if(((Employee*) object_1)->ssn < ((Employee*) object_2)->ssn){ // checks if query ID less that median ID
        return -1;
    }
    else{
        return 0; // IDs are the same
    }
}

// takes a bst root and an employee data struct as input
// is recursively called until root pointer is the location where the data should be inserted
// assigns pointer to new node so that new node is now a child or previous recursive root
// assigns data to root if tree is empty
Node* insertBST(Node* root, Employee* employee){ 
    if(root == NULL){ // error checks initialization
        root = newNode(employee);
        return root;
    } else if (root->data == NULL){  // error checks if root has employee struct data
        // this will catch on the end of a bst in the proper position or if the tree is empty
        root = newNode(employee); // if root's data is null, creates a new node with employee data and assigns root to it
        return root; // returns the NOde pointer to the new node/leaf on the tree
    } 
    Node* temp = malloc(sizeof(Node)); // mallocs a temporary node pointer
    if(!temp){
        printf("Malloc failed, exiting");
        exit(-1);
    }
    if (comparison(employee, root->data) == -1){ // runs comparison and assigns roots left pointer if comparison checks
        temp = root->left;
        root->left = insertBST(temp, employee);
        return root;
    }
    else if (comparison(employee, root->data) == 1){ // runs comparison and assigns roots right pointer if comparison checks
        temp = root->right;
        root->right = insertBST(temp, employee);
        return root;
    }
    return root; // returns root to calling program
} 

// takes a bst root and query key as input
// recursively called to find a root where its data matches the key
// returns root when key is found
// returns NULL if key is not found
Employee* searchBST(Node* root, int SSN){ 
    if(root == NULL){ // the case that node key is not found
        printf("Did not find node, returning NULL ptr\n");
        return NULL;
    }
    // Base Cases: root is null or key is present at root 
    if (root->data == NULL || root->data->ssn == SSN) 
       return root->data; 
     
    // Key is greater than root's key 
    if (root->data->ssn < SSN) 
       return searchBST(root->right, SSN); 
  
    // Key is smaller than root's key 
    return searchBST(root->left, SSN); 
} 

// takes a bst root as input
// recursively frees root and is called on children of root until all nodes of the children are freed
void deleteTree(Node* root){
    if(root && root->data){ // error checks to see if root and its data are initialized
        Node* tempLeft = root->left; // assigns poitners to children of root
        Node* tempRight = root->right;
        
        free(root); // frees root
        root = NULL;
        // recursively runs deletetree() on roots children
        if(tempRight){
            deleteTree(tempRight);
        }
        if(tempLeft){
            deleteTree(tempLeft);
        }
    }
}

/**************** Custom function below ******************/

// function to create a new node
Node* newNode(Employee* employee){ 
    Node* temp = malloc(sizeof(Node)); 
    if(!temp){ // error checks malloc
        printf("malloc failed: newNode()");
    }
    temp->data = employee; // initialized new node
    temp->left = temp->right = NULL; 
    return temp; // returns new node
} 

// best print function ever, will print out a bst in 2 dimensions, wont comment this out because it will take a while and it is not a necessary function but if you would like a description email me and I can explain it
void print2DUtil(Node *root, int space){ 
    if (root == NULL || root->data == NULL){
        return;
    } 

    space += 10; 
    if(root->right != NULL && root != NULL){
        print2DUtil(root->right, space); 
    }

    for (int i = 10; i < space; i++){ 
        printf(" ");
    }
    printf("%9d---------|", root->data->ssn);  // handles proper formatting for up to 6 digits, change coefficient of %d to accomidate more       
    if(!root->left && !root->right){
        printf("NULL");
    }
    printf("\n");

    if(root->left != NULL && root != NULL){
        print2DUtil(root->left, space);
    }
} 

void print2D(Node* root){ 
    if(!root || !root->data){
        return;
    }
    printf("\n");
    print2DUtil(root, 0); 
}
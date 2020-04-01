/* Header .h file for CS 2050, 2020 SP, Wed labs. Should NOT be modified or submitted. -- Shizeng */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct studstruct{    
    int age;    
    struct studstruct *nextPtr;
}Student;

typedef struct linkedlist{    
    Student *head, *tail;
}StudentList;

//additional
Student* createNode(int age);

//required
StudentList* initStack();
int pushStack(StudentList*,int);
Student* popStack(StudentList*);
StudentList* initQueue();
int enQueue(StudentList*,int);
Student* deQueue(StudentList*);
void printList(StudentList*);
void freeList(StudentList*);


int main(void){

    StudentList* Stack = initStack();
    popStack(Stack);
    pushStack(Stack, -10);
    pushStack(Stack, 11);
    pushStack(Stack, 15);
    printList(Stack);
    popStack(Stack);
    popStack(Stack);
    printList(Stack);

    printf("\n*\n\n");

    StudentList* Queue = initQueue();
    deQueue(Queue);
    enQueue(Queue, 3);
    enQueue(Queue, 4);
    enQueue(Queue, 5);
    printList(Queue);
    deQueue(Queue);
    deQueue(Queue);
    printList(Queue);

    freeList(Queue);
    freeList(Stack);

    printf("\n\n");
    printList(Queue);
    printList(Stack);
    

}


// README *************************************************************

// I have decided to leave tail as null for the duration of my program because I beleive it makes code esier
// to read and interpret. The instructions never specify that tail must point to the last node with a key 
// value, so I implemented it my own way

// also I have created one custom function


// additional below ****************************************************

// prototype for my additional function*********************************
Student* createNode(int age);

// takes age as input
// malloc a new node
// error check to see if allocation fails or not
// else sets new nodes key value to 'age'
// sets new nodes next ptr to NULL
// returns new node
Student* createNode(int age){
    Student* newNode = malloc(sizeof(Student));    
    if (newNode == NULL){        
        printf("Allocation failed\n");     
        return NULL;    
    }        
    newNode->age = age;        
    newNode->nextPtr = NULL;        
    return newNode;    
}



// Required below ******************************************************

// allocates memory for head and tail of list as well as a list structure
// error checks to see if allocation has failed or not
// assigns List structure's head and tail to previously allocated nodes 
// head and tail nodes are set to NULL value
// returns the pointer to the List structure with NULL head and tail
StudentList* initStack(){
    Student* head = malloc(sizeof(Student));    // allocates memory for head and tail of list
    if (head == NULL){      // error checks to see if allocation has failed or not  
        printf("**Allocation failed!!\n");       
        return NULL;    
    }    
    Student* tail = malloc(sizeof(Student));    
    if (tail == NULL){       // error checks to see if allocation has failed or not 
        printf("**Allocation failed!!\n");       
        free(head);     // frees head in the case that head was allocated but tail was not so no memory leak occurs
        return NULL;    
    }  

    StudentList* List = malloc(sizeof(StudentList)); // dynamically creates list stucture
    if (List == NULL){ // error checks malloc    
        printf("**Allocation failed!!\n");  
        free(head);  // frees head & tail in the case that head and tail were allocated but list wasn't so no memory leak occurs
        free(tail);     
        return NULL;    
    } 

    // assigns list's head and tail to allocated nodes from above
    // ultimately this code does nothing but in the case of changes to implementation, this allows 
    // for smooth transition and better readability
    List->head = head; 
    List->tail = tail; 

    //sets nodes to NULL
    List->head = NULL;  
    List->tail = NULL;    
    
    return List; // returns list structure
}

// takes list and key value 'age' as input
// cretes new node with 'age' as key value
// error checks to see if new node was allocated properly and if list is null or not
// if list is empty, assigns head to new node 
// else assigns new node to head/top position and offsets previous head
// returns 1 if insertion executes else returns -1
int pushStack(StudentList* List, int age){
    Student* newNode = createNode(age); // creates new node with age as key value
    if (newNode == NULL){    // error checks to see if new node was allocated properly    
        return -1;    //returns -1 on fail
    } 
    if(List == NULL){
        printf("the list you passed is NULL");
        return -1;
    }
    // if list is empty assigns head to new node and then new nodes next ptr to tail
    if(List->head == NULL){
        List->head = newNode;
        List->head->nextPtr = List->tail;
        return 1; // returns 1 on success
    }
    // assigns new nodes next pointer to previous head
    // assigns head pointer to new head (new node)
    newNode->nextPtr = List->head;
    List->head = newNode;

    return 1; // returns 1 on success
}

// takes list as input
// error checks to see if list is already empty or if list is null
// pops top/front/head node from list
// returns popped node
// excercises LIFO(last in first out)
Student* popStack(StudentList* List){
    if(List == NULL){ // error checks list
        printf("the list you passed is NULL");
        return NULL;
    }
    if(List->head == NULL){ // error checks to see if list was already null
        printf("the list is already empty, cannot pop\n");
        return NULL;
    }
    Student* temp = List->head; // assigns node to be popped
    List->head = List->head->nextPtr; // pops it from the list by setting head to 2nd node
    
    return temp; // returns original head/popped node
}

// allocates memory for head and tail of list as well as a list structure
// error checks to see if allocation has failed or not
// assigns List structure's head and tail to previously allocated nodes 
// head and tail nodes are set to NULL value
// returns the pointer to the List structure with NULL head and tail
StudentList* initQueue(){
    Student* head = malloc(sizeof(Student));    // allocates memory for head and tail of list
    if (head == NULL){      // error checks to see if allocation has failed or not  
        printf("**Allocation failed!!\n");       
        return NULL;    
    }    
    Student* tail = malloc(sizeof(Student));    
    if (tail == NULL){       // error checks to see if allocation has failed or not 
        printf("**Allocation failed!!\n");       
        free(head);     // frees head in the case that head was allocated but tail was not so no memory leak occurs
        return NULL;    
    }  

    StudentList* List = malloc(sizeof(StudentList)); // dynamically creates list stucture
    if (List == NULL){ // error checks malloc    
        printf("**Allocation failed!!\n"); 
        free(head); // frees head & tail in the case that head and tail were allocated but list wasn't so no memory leak occurs
        free(tail);      
        return NULL;    
    } 

    // assigns list's head and tail to allocated nodes from above
    // ultimately this code does nothing but in the case of changes to implementation, this allows 
    // for smooth transition and better readability
    List->head = head; 
    List->tail = tail; 

    //sets nodes to NULL
    List->head = NULL;  
    List->tail = NULL;    
    
    return List; // returns list structure
}

// takes list and age as input
// cretes new node with 'age' as key value
// error checks to see if new node was allocated properly and if list is null or not
// if list is empty, assigns head node to new node
// else assigns new node to head position and offsets previous head
// returns 1 if insertion executes
int enQueue(StudentList* List, int age){
    Student* newNode = createNode(age); // cretes new node with 'age' as key value
    if (newNode == NULL){ // error checks to see if new node was allocated properly      
        return -1;   // returns -1 on fail 
    } 
    if(List == NULL){ // error checks list
        printf("the list you passed is NULL");
        return -1;
    }
    // if list is empty, assigns first node to head
    if(List->head == NULL){
        List->head = newNode;
        newNode->nextPtr = List->tail;
        return 1; // returns 1 on success
    }
    // assigns new node to head
    newNode->nextPtr = List->head;    
    List->head = newNode;    
    return 1; // returns 1 on success

}

// takes list as input
// error checks if list is empty already or if list is null
// sets temp pointer to the 2nd to last node with O(n) complexity
// removes last node from list
// returns removed node
// excercises FIFO(first in first out)
Student* deQueue(StudentList* List){
    if(List == NULL){ //error checks lisy
        printf("the list you passed is NULL");
        return NULL;
    }
    if(List->head == NULL){ // error checks if list is empty already
        printf("the list is already empty, cannot dequeue\n");
        return NULL;
    }
    Student* temp = List->head;
    while(temp->nextPtr->nextPtr != NULL){ // sets temp pointer to the 2nd to last node with O(n) complexity
        temp = temp->nextPtr; //2nd to last node
    }

    Student* dequeued = temp->nextPtr; // last node
    temp->nextPtr = NULL; // removes last node
    
    return dequeued; // returns removed node
}

// takes list as input
// error checks to see if list is null
// prints each key value of each node of the list
// prints NULL if the list is empty
void printList(StudentList* List){
    Student * temp;
    if(List == NULL){ // error checks list
        printf("the list you passed is NULL");
        return;
    }
    temp = List->head; //creates ptr and sets to head->nextptr so only real nodes print
    while(temp != NULL){ //loops through entire list except for last dummy node bc only real nodes are to be printed
        printf("%d --> ", temp->age); //prints age of item
        temp =  temp->nextPtr; //moves pointer to next item of list
    }
    printf("NULL\n"); // to help visualize empty list
}

// takes a list as input
// error checks to see if list is null
// loops through the entire list and frees all memory of the nodes
// makes free pointer unable to be accessed after they are freed
void freeList(StudentList* List){
    Student* temp;
    if(List == NULL){
        printf("the list you passed is NULL");
        return;
    }
    while(List->head != NULL){ // loops through entire list
        temp = List->head; // sets temp to same address as head   
        List->head = List->head->nextPtr; // sets head equal to the next item on list to make a new head
        free(temp); // frees old head 
        temp = NULL; // sets temp to null so it cant be accessed again
    }
}

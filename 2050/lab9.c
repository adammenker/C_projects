/* Header .h file for CS 2050, 2020 SP, Wed labs. Should NOT be modified or submitted. -- Shizeng */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct studstruct{
    int age;    
    struct studstruct *nextPtr;
}Student;


Student* initListWithDummyNode();
int insertToHead(Student*,int);
int insertToTail(Student*,int);
void printList(Student*);
void emptyList(Student*);
void freeList(Student*);

Student * link(Student * head, Student * tail);
Student* makeDummyNode();


int main(void){

    Student * test = initListWithDummyNode();
    
    insertToHead(test, 3);
    insertToTail(test, 4);
    insertToTail(test, 5);
    printList(test);

    emptyList(test);
    printList(test);

    freeList(test);
    printList(test);
}

// takes head and tail dummy nodes
// sets vals to impossible age
// links head next to  tail 
// tail next to NULL
// returns head
Student * link(Student * head, Student * tail){
    head->age = -1; // sets vals to impossible age
    tail->age = -2;
    head->nextPtr = tail; // links head next to  tail 
    tail->nextPtr = NULL; // tail next to NULL
    return head; // returns head
}

// creates 2 dummy nodes
// returns 2 dummy nodes linked one as head one as tail
Student* initListWithDummyNode(){
    Student * head = makeDummyNode(); // creates 2 dummy nodes
    Student * tail = makeDummyNode();

    // printf("%p\n", head);
    // printf("%p\n", tail);

    head = link(head, tail); // returns 2 dummy nodes linked one as head one as tail

    

    return head;
}

// allocates dummy node
// error checks malloc
// set next to NULL
// returns dummy node
Student* makeDummyNode(){
    Student * temp1 = malloc(sizeof(Student) * 1);

    if(temp1 == NULL){ //error checks malloc
        printf("*malloc failed*");
        exit(-1);
    }
    temp1->nextPtr = NULL; // sets next to nULL
    return temp1;
}

// takes list as input
// creates new node with input age as value
// assigns new nodes next ptr to old head node (first after dummy)
// sets dummy next ptr to new node
int insertToHead(Student* head, int age){
    Student * temp = (Student *) malloc(sizeof(Student)); // allocates new node
    if(temp == NULL){ // error checks malloc
        printf("malloc failed");
    }
    temp->age = age; // creates new node with input age as value
    temp->nextPtr = head->nextPtr; // assigns new nodes next ptr to old head node (first after dummy)
    head->nextPtr = temp; // sets dummy next ptr to new node
    if(head->nextPtr == temp && temp->age == age && head->nextPtr->nextPtr == temp->nextPtr){ //checks if data was inserted and if list pointer were reassigned properly
        return 1; //returns 1 on success
    }
    return 0; // returns 0 on fail
}

// takes list as input
// loops to last real node and chanhges its next to new tail node
// sets new tail node val to age input
// sets new tail next ptr to tail dummy
int insertToTail(Student* head, int age){
    Student * newTail = (Student *) malloc(sizeof(Student)); //allocates node
    if(newTail == NULL){ //error checks malloc
        printf("malloc failed");
    } 
    Student * temp;
    Student * oneBeforeTail; 
    temp = head;
    while(temp->nextPtr != NULL){// reaches dummy node
        temp = temp->nextPtr; // breaks once temp is a pointer to last node
        if(temp->nextPtr != NULL){ // asigned to ptr if it is not dummy node, so it will point to last node before dummy
            oneBeforeTail = temp;
        }
    }
    newTail->age = age; // sets new nodes val to age
    newTail->nextPtr = temp; // sets new nodes nextptr to dummy
    oneBeforeTail->nextPtr = newTail; // sets previous node next ptr before dummy to new tail node
    
    
    if(newTail->nextPtr == temp && newTail->age == age && newTail->nextPtr->nextPtr == NULL){//checks if data was inserted and if list pointer were reassigned properl
        return 1; //returns 1 on success
    }
    return 0; // returns 0 on fail
}

// takes list as input
// loops through entire list and prints all items except dummy nodes
void printList(Student* head){
    Student * temp;
    temp = head->nextPtr; //creates ptr and sets to head->nextptr so only real nodes print
    while(temp->nextPtr != NULL){ //loops through entire list except for last dummy node bc only real nodes are to be printed
        printf("%d\n", temp->age); //prints age of item
        temp =  temp->nextPtr; //moves pointer to next item of list
    }
    // add ->nexptr in while loop and 2nd line

    printf("\n\n");
}

// takes a list as input
// frees all real nodes and sets head dummy node to next item in list
// outputs just head dummy node that points to tail dummy node, all real nodes are freed
void emptyList(Student* head){
    Student * temp = head->nextPtr; // starts on first real node
    Student * current; // sets a current ptr
    while(temp->nextPtr != NULL){
        current = temp; // sets current equal to first real node bc we dont want to change the address of head dummy  node
        head->nextPtr = current->nextPtr; // sets dummy node next ptr equal to one after the one that will be freed, eventually is set to tail dummy node on last loop
        temp = temp->nextPtr;
        free(temp); // frees real nodes
    }
}

// takes list as input
// frees all items on list
// no output
void freeList(Student * head){


    Student * temp;
    while(head != NULL){ // loops through entire list
        temp = head; // sets temp to same address as head
        //printf("* %p\n", head);    
        head = head->nextPtr; // sets head equal to the next item on list to make a new head
        free(temp); // frees old head 
    }
}

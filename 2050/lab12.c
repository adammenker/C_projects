// header file 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct studstruct{    
    int age;    
    float priority;    
    struct studstruct *previousPtr, *nextPtr;
} Student;

typedef struct linkedlist{    
    Student *head, *tail;    
    int numOfItems;
} StudentList;

typedef struct queuelist{    
    StudentList* list;
} PQueue;

// includes no custom functions
PQueue initPQueue();
Student* createNode(float,int);
int insertPQ(float,int,PQueue);
Student* deleteMin(PQueue);
Student* deleteMax(PQueue);
Student* returnMin(PQueue); // returns but does not delete
Student* returnMax(PQueue); // returns but does not delete
void printPQueue(PQueue);
void freePQueue(PQueue); // Free all malloced spacevoid printPQueue(PQueue);

// // testing function for my own reference
int main(void){

    PQueue myPQ = initPQueue();
    insertPQ(4.368, 18, myPQ);
    insertPQ(5.111, 19, myPQ);
    insertPQ(6.111, 21, myPQ);
    insertPQ(5.411, 20, myPQ);
    insertPQ(3.411, 17, myPQ);
    printPQueue(myPQ);
    Student* test = returnMax(myPQ);
    deleteMin(myPQ);
    deleteMax(myPQ);
    deleteMin(myPQ);
    Student* test2 = returnMin(myPQ);
    printf("%f-%d --> %f-%d\n\n", test->priority, test->age, test2->priority, test2->age);
    printPQueue(myPQ);

    freePQueue(myPQ);
    printPQueue(myPQ);
}


// *************************************** Function definitions below this line ***************************************

// no input
// declares priority queue
// allocates space for list
// assigns head, tail, and size
// returns PQueue 
PQueue initPQueue(){
    PQueue priorityQueue; // declares new queue
    priorityQueue.list = malloc(sizeof(StudentList)); // allocates space for queue list ptr
    if(priorityQueue.list == NULL){ //error checks malloc
        printf("*malloc failed* program will be exited\n");
        exit(-1); // on fail exits program
    }

    priorityQueue.list->head = priorityQueue.list->tail =  NULL; // sets head and tail to null
    priorityQueue.list->numOfItems = 0; // sets num of items

    return priorityQueue; // returns queue with properly initialized list ptr
}

// takes priority and age as input
// allocates new node
// assigns input vals to new node
// returns new node
Student* createNode(float priority, int age){
    Student* newNode = (Student*) malloc(sizeof(Student)); // allocated new node
    if(newNode == NULL){ //error checks malloc
        printf("*malloc failed in createNode()* returning NULL pointer\n");
        return NULL; // on fail returns null
    }
    // assigns age, priority, and ptrs to proper value
    newNode->age = age; 
    newNode->priority = priority;
    newNode->nextPtr = newNode->previousPtr = NULL;

    return newNode; // returns new node
}

// takes Pqueue, a priority, and an age as input
// error checks to see if queue is initialized, else returns -1
// makes a new node
// if no items, new node is inserted and head and tail are assigned to it
// if new node belongs at front, prev and next are assigned properly and head is reassigned
// if new node belongs in middle, next and prev are assigned to insert it
// if new node belongs at end, nextptr inserts it, new node next is NULL, tail is reassigned
// increments size by one
// returns 1 on success, -1 on fail
int insertPQ(float priority, int age, PQueue queue){
    if(queue.list == NULL){ // error checks to make sure queue is initialized
        printf("error: queue is not initialized, failed in insertPQ()\n");
        return -1; // on fail
    }

    Student* newNode = createNode(priority, age); // creates a new Node

    if(queue.list->numOfItems == 0){ // if no items in queue, sets head and tail to new first node
        queue.list->head = newNode;
        queue.list->tail = newNode;
        newNode->nextPtr = newNode->previousPtr = NULL; // sets first node's ptr to null bc no other items in queue

        (queue.list->numOfItems)++; // increments size by one
        return 1; // on success
    }
    if(priority >= queue.list->head->priority){ // the case that new node is greatest priority
        newNode->nextPtr = queue.list->head; // sets new nodes next ptr to current head
        queue.list->head->previousPtr = newNode; // sets current head prev ptr to ne node
        queue.list->head = newNode; // sets head to new node

        (queue.list->numOfItems)++; // increments num of item by 1
        return 1; // on success
    }

    Student* current = queue.list->head; // starts at head but will be incremented
    Student* currentPrev; // creates ptr
    while(current != NULL && priority < current->priority){ // more than one node and not greatest priority
        currentPrev = current; // sets to the node before where insertion needs to occur
        current = current->nextPtr; // loops to node after where insertion needs to occur
    }
    if(current != NULL){ // if insertion needs to occur at anywhere besides very end
        current->previousPtr = newNode; // node after where insertion will occur prev ptr set to inserted node
    }
    newNode->nextPtr = current; // new node's next ptr set to next node
    currentPrev->nextPtr = newNode; // node before insertion's next ptr set to inserted node
    newNode->previousPtr = currentPrev; // inserted node's prev ptr set to one behind it node
    if(current == NULL){ // if new node is last item
        queue.list->tail = newNode; // tail set to new node if it is last node
    }
    
    (queue.list->numOfItems)++; // increments size by one
    return 1; // on success
}

// takes Pqueue as input
// error checks to see if queue is initialized
// error checks to see if any items in queue and returns NULL if necessary
// sets temp pointer to current tail
// assigns tail to next highest priority
// makes new tails nextPtr point to NULL so no reference to old tail except temp
// decrements number of items in queue
// returns temp which is reference to old tail
Student* deleteMin(PQueue queue){
    if(queue.list == NULL){ // error checks to make sure queue is initialized
        printf("error: queue is not initialized, failed in deleteMin()\n");
        return NULL;
    }
    // error checks to see if any items in queue and returns NULL if necessary
    if(queue.list->tail == NULL){
        printf("no items in queue, returning NULL");
        return NULL;
    }

    Student* temp = queue.list->tail; // sets temp pointer to current tail
    queue.list->tail = queue.list->tail->previousPtr; // assigns tail to next highest priority
    queue.list->tail->nextPtr = NULL; // makes new tails nextPtr point to NULL so no reference to old tail except temp

    (queue.list->numOfItems)--; // decrements number of items in queue
    return temp; // returns temp which is reference to old tail
}

// takes Pqueue as input
// error checks to see if queue is initialized
// error checks to see if any items in queue and returns NULL if necessary
// sets temp pointer to current head
// assigns head to next lowest priority
// makes new heads prevPtr point to NULL so no reference to old head except temp
// decrements number of items in queue
// returns temp which is reference to old head
Student* deleteMax(PQueue queue){
    if(queue.list == NULL){ // error checks to make sure queue is initialized
        printf("error: queue is not initialized, failed in deleteMax()\n");
        return NULL;
    }
    // error checks to see if any items in queue and returns NULL if necessary
    if(queue.list->head == NULL){
        printf("no items in queue, returning NULL");
        return NULL;
    }

    Student* temp = queue.list->head; // sets temp pointer to current head
    queue.list->head = queue.list->head->nextPtr; // assigns head to next lowest priority
    queue.list->head->previousPtr = NULL; // makes new heads prevPtr point to NULL so no reference to old head except temp

    (queue.list->numOfItems)--; // decrements number of items in queue
    return temp; // returns temp which is reference to old head
}

// takes Pqueue as input
// error checks to see if queue is initialized
// error checks to see if any items in queue and returns NULL if necessary
// sets pointer to tail of list which is min priority and returns pointer
// returns reference to min priority/tail
Student* returnMin(PQueue queue){
    if(queue.list == NULL){ // error checks to make sure queue is initialized
        printf("error: queue is not initialized, failed in returnMin()\n");
        return NULL;
    }
    // error checks to see if any items in queue and returns NULL if necessary
    if(queue.list->tail == NULL){
        printf("no items in queue, returning NULL");
        return NULL;
    }
    // sets pointer to tail of list which is min priority and returns pointer
    Student* temp = queue.list->tail;
    return temp;
}

// takes Pqueue as input
// error checks to see if queue is initialized
// error checks to see if any items in queue and returns NULL if necessary
// sets pointer to head of list which is max priority and returns pointer
// returns reference to max priority/head
Student* returnMax(PQueue queue){
    if(queue.list == NULL){ // error checks to make sure queue is initialized
        printf("error: queue is not initialized, failed in returnMax()\n");
        return NULL;
    }
    // error checks to see if any items in queue and returns NULL if necessary
    if(queue.list->head == NULL){
        printf("no items in queue, returning NULL");
        return NULL;
    }
    // sets pointer to head of list which is max priority and returns pointer
    Student* temp = queue.list->head;
    return temp;
}

// takes Pqueue as input
// error checks to see if queue is initialized
// loops through entire queue and prints each priority and age in desired format
// prints NULL once list is at the end
// no return value
void printPQueue(PQueue queue){
    if(queue.list == NULL){
        printf("pointer is free'd or uninitialized\n\n"); // error checks to see if queue is initialized
        return;
    }
    Student* temp = queue.list->head;

    while(temp != NULL){ // loops through entire queue and prints each priority and age in desired format
        printf("%.2f(%d) --> ", temp->priority, temp->age); 
        temp = temp->nextPtr;
    }
    printf("NULL\n\n"); // prints NULL once list is at the end
}

// takes a PQueue as input
// error checks to see if PQueue is initialized
// loops through queue and frees all nodes and sets to NULL
// frees list pointer and sets to NULL
// sets number of items to 0 since they queue was emptied
// no return value
void freePQueue(PQueue queue){
    if(queue.list == NULL){ // error checks to make sure queue is initialized
        printf("error: queue is not initialized, failed in freePQueue()\n");
        return;
    }

    Student* temp;
    while(queue.list->head != NULL){ // loops through entire list
        temp = queue.list->head; // sets temp to same address as head  
        queue.list->head = queue.list->head->nextPtr; // sets head equal to the next item on list to make a new head
        free(temp); // frees old head 
        temp = NULL; // sets free'd ptr to null
    }

    queue.list->numOfItems = 0; // resets the num of items back to 0
    free(queue.list); // free's queue list pointer at end
    queue.list = NULL; // sets free'd ptr to null
}
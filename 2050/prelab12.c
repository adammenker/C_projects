#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode{
    float key;
    struct QueueNode* next;
    struct QueueNode* prev;
} Node;

typedef struct PriorityQueueInfo{
    Node* head;
    Node* tail;
    int size;
}Accessor;

typedef struct PriorityQueue{
    Accessor* infoptr;
} PQueue;

PQueue pqInit();  // Return empty priority queue
int insertPQ(void* , float , PQueue); //priorities are floats
void * deleteMin(PQueue); 
void * deleteMax(PQueue); 
void * returnMin(PQueue); // returns but does not delete
void * returnMax(PQueue); // returns but does not delete
int getsizePQ(PQueue); // returns # of items in queue
void pqFree(PQueue); // Free all malloced space

void printForward(PQueue queue);
void printBackward(PQueue queue);


int main(void){

    PQueue priorityQueue = pqInit();

    Node* node1 = malloc(sizeof(Node));
    node1->key = 0;
    Node* node2 = malloc(sizeof(Node));
    node1->key = 0;
    Node* node3 = malloc(sizeof(Node));
    node1->key = 0;
    Node* node4 = malloc(sizeof(Node));
    node1->key = 0;


    insertPQ(node1, 3, priorityQueue);
    insertPQ(node2, 2, priorityQueue);
    insertPQ(node3, 1, priorityQueue);
    insertPQ(node4, 4, priorityQueue);

    printForward(priorityQueue);
    //printBackward(priorityQueue);

    pqFree(priorityQueue);
    insertPQ(node1, 3, priorityQueue);

    printForward(priorityQueue);


    printf("%d", getsizePQ(priorityQueue));
}


PQueue pqInit(){
    PQueue priorityQueue;
    priorityQueue.infoptr = malloc(sizeof(Accessor));

    priorityQueue.infoptr->head = priorityQueue.infoptr->tail =  NULL;
    priorityQueue.infoptr->size = 0;

    return priorityQueue;
}


int insertPQ(void* newNode, float priority, PQueue queue){
    if(queue.infoptr == NULL){
        printf("error: queue is unitialized\n");
        return -1;
    }

    Node* tempInsert = newNode;
    tempInsert->key = priority;
    Node* current = queue.infoptr->head;
    Node* tempPrev;

    if(current == NULL){ // the case that there are no nodes in the pqueue
        queue.infoptr->head = tempInsert;
        queue.infoptr->tail = tempInsert;
        tempInsert->next = NULL;
        tempInsert->prev = NULL;

        (queue.infoptr->size)++;
        return 1;
    }

    if(priority <= current->key){ // the case that there is a single node in pqueue
        tempInsert->next = current;
        current->prev = tempInsert;
        queue.infoptr->head = tempInsert;

        (queue.infoptr->size)++;
        return 1;
    }

    while(current != NULL && priority > current->key){ // more than one node
        tempPrev = current;
        current = current->next; 
    }
    tempInsert->next = tempPrev->next; // node after insert
    if(current != NULL){
        current->prev = tempInsert;
    }
    tempPrev->next = tempInsert; // node before insert
    tempInsert->prev = tempPrev;
    queue.infoptr->tail = tempInsert;

    (queue.infoptr->size)++;
    return 1;
}


void* deleteMin(PQueue queue){
    void* temp = queue.infoptr->head;
    queue.infoptr->head = queue.infoptr->head->next;
    queue.infoptr->head->prev = NULL;

    (queue.infoptr->size)--;

    return temp;
}


void* deleteMax(PQueue queue){
    void* temp = queue.infoptr->tail;
    queue.infoptr->tail = queue.infoptr->tail->prev;
    queue.infoptr->tail->next = NULL;

    (queue.infoptr->size)--;

    return temp;
}


void * returnMin(PQueue queue){
    void* temp = queue.infoptr->head;
    return temp;
}


void * returnMax(PQueue queue){
    void* temp = queue.infoptr->tail;
    return temp;
}


int getsizePQ(PQueue queue){
    int size = queue.infoptr->size;
    return size;
}


void pqFree(PQueue queue){
    queue.infoptr->size = 0;

    if(queue.infoptr == NULL){ // error checks to make sure queue is initialized
        printf("error: queue is not initialized, failed in emptyQueue()\n");
        return;
    }

    Node* temp;
    while(queue.infoptr->head != NULL){ // loops through entire list
        temp = queue.infoptr->head; // sets temp to same address as head  
        queue.infoptr->head = queue.infoptr->head->next; // sets head equal to the next item on list to make a new head
        free(temp); // frees old head 
        temp = NULL; // sets free'd ptr to null
    }

    free(queue.infoptr); // free's queue list pointer at end
    queue.infoptr = NULL; // sets free'd ptr to null
}


void printForward(PQueue queue){
    if(queue.infoptr == NULL){
        printf("pointer is free'd or uninitialized\n\n");
        return;
    }
    Node* temp = queue.infoptr->head;

    while(temp != NULL){
        printf("%f --> ", temp->key);
        temp = temp->next;
    }
    printf("NULL\n\n");
}


void printBackward(PQueue queue){
    Node* temp = queue.infoptr->tail;

    while(temp != NULL){
        printf("%f --> ", temp->key);
        temp = temp->prev;
    }
    printf("NULL\n\n");
}

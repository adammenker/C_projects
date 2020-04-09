#include <stdio.h>
#include <stdlib.h>

typedef struct Employee{
    int key;
    struct Employee* next;
    struct Employee* prev;
} Employee;

typedef struct QueueInformation{
    Employee* head;
    Employee* tail;
} QueueInfo;

typedef struct QueueStruct{
    struct QueueInformation* infoPtr;
} Queue;


Queue initQueue();  // Return empty queue
int enqueue(Employee*, Queue); // enqueue returns an int error code
Employee*dequeue(Queue); 
int getQsize(Queue); // returns # of items in queue
void freeQueue(Queue); // Free all malloced space

void printForward(Queue queue);
void printBackward(Queue queue);


int main(void){

    Queue myQ;
    myQ = initQueue();

    Employee* node = malloc(sizeof(Employee));
    node->key = 1;
    node->next = NULL;
    node->prev = NULL;

    Employee* node2 = malloc(sizeof(Employee));
    node2->key = 2;
    node2->next = NULL;
    node2->prev = NULL;

    Employee* node3 = malloc(sizeof(Employee));
    node3->key = 3;
    node3->next = NULL;
    node3->prev = NULL;


    int test = enqueue(node, myQ);
    enqueue(node2, myQ);
    enqueue(node3, myQ);
    printf("test = %d\n", test);
    printForward(myQ);
    printf("\n\n");
    printBackward(myQ);


}


Queue initQueue(){
    Queue Q;
    Q.infoPtr = malloc(sizeof(QueueInfo));

    Q.infoPtr->head = NULL;
    Q.infoPtr->tail = NULL;

    return Q;
}


int enqueue(Employee* newNode, Queue Q){
    Employee* temp;

    if(Q.infoPtr == NULL){
        printf("error: queue is not initialized, failed in enqueue()");
        return 0;
    }

    temp = Q.infoPtr->head;

    if(temp == NULL){
        newNode->next = temp;
        Q.infoPtr->head = newNode;
        return 1;
    }

    newNode->next = temp;
    temp->prev = newNode;
    
    Q.infoPtr->head = newNode;
    return 1;
}












void printForward(Queue queue){
    Employee* temp = queue.infoPtr->head;

    while(temp != NULL){
        printf("%d --> ", temp->key);
        temp = temp->next;
    }
    printf("NULL");
}


void printBackward(Queue queue){
    Employee* temp = queue.infoPtr->tail;

    while(temp != NULL){
        printf("%d --> ", temp->key);
        temp = temp->prev;
    }
    printf("NULL");
}
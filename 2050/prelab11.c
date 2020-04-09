#include <stdio.h>
#include <stdlib.h>

typedef struct empstruct{
    int id;
    int age;
    struct empstruct* nextptr;
    struct empstruct* prevptr;
} Employee;

typedef struct queueaccessor{
    int size;
    Employee* head;
    Employee* tail; 
} accessor;

typedef struct queuestruct{
    accessor* ptr;
} Queue;


Queue initQueue();  // Return empty queue
// enqueue returnsanint error code 
int enqueue(Employee*, Queue);
Employee* dequeue(Queue); 
int getQsize(Queue); // returns # of items in queue
void freeQueue(Queue); // Free all malloced space
void printForward(Queue queue);
void printBackward(Queue queue);

int main(void){
    Queue z = initQueue();

    Employee* node = malloc(sizeof(Employee));
    node->id = 1;
    node->age = 2;
    node->nextptr = NULL;
    node->prevptr = NULL;

    Employee* node2 = malloc(sizeof(Employee));
    node2->id = 5;
    node2->age = 6;
    node2->nextptr = NULL;
    node2->prevptr = NULL;

    Employee* node3 = malloc(sizeof(Employee));
    node3->id = 8;
    node3->age = 7;
    node3->nextptr = NULL;
    node3->prevptr = NULL;

    enqueue(node, z);
    enqueue(node2, z);
    enqueue(node3, z);
    dequeue(z);

    printForward(z);
    printf("\n***\n");
    printBackward(z);
    
    printf("\n\nsize: %d\n", getQsize(z));

}


Queue initQueue(){
    Queue q;
    q.ptr = malloc(sizeof(accessor));
    if(!q.ptr){
        printf("malloc failed, returning Queue with NULL accessor\n");
        return q;
    }

    q.ptr->head = NULL;
    q.ptr->tail = NULL;
    q.ptr->size = 0;

    return q;
}


int enqueue(Employee* node, Queue queue){
    if(queue.ptr == NULL){
        printf("error: queue is not initialized, failed in enqueue()");
        return 0;
    }

    Employee* temp;
    temp = queue.ptr->head;

    if(queue.ptr->size == 1){
        queue.ptr->tail = temp;
    }
    if(queue.ptr->size >= 1){ // so as to not try to assign NULL to a node
        queue.ptr->head->prevptr = node;
    }

    queue.ptr->head = node;
    node->nextptr = temp;

    (queue.ptr->size)++;

    return 1;
}


Employee* dequeue(Queue queue){
    if(queue.ptr == NULL){
        printf("error: queue is not initialized, failed in enqueue(), returning NULL ptr\nn");
        return NULL;
    }

    Employee* temp = queue.ptr->tail;
    queue.ptr->tail = queue.ptr->tail->prevptr;
    queue.ptr->tail->nextptr = NULL;

    (queue.ptr->size)--;

    return temp;
}


int getQsize(Queue queue){
    return(queue.ptr->size);
}


void freeQueue(Queue queue){
    free(queue.ptr);
}


void printForward(Queue queue){
    Employee* temp = queue.ptr->head;

    while(temp != NULL){
        printf("%d --> ", temp->age);
        temp = temp->nextptr;
    }
    printf("NULL");
}


void printBackward(Queue queue){
    Employee* temp = queue.ptr->tail;

    while(temp != NULL){
        printf("%d --> ", temp->age);
        temp = temp->prevptr;
    }
    printf("NULL");
}

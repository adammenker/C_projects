#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct studstruct{    
    int age;    
    struct studstruct *nextPtr;
} Student;

typedef struct linkedlist{    
    Student *head, *tail;    
    int numOfItems;    
    int numOfOdd;    
    int numOfEven;
} StudentList;

typedef struct queuelist{    
    StudentList* list;
} Queue;



Queue initQueue(); // done
int enQueue(int, Queue); // done
Student* deQueue(Queue); // done
int getQsize(Queue); // done
int getNumOfEven(Queue); // done
void printQueue(Queue); //done
void emptyQueue(Queue); // done


int main(void){

    Queue q;
    q = initQueue();

    enQueue(10, q);
    enQueue(11, q);
    enQueue(12, q);
    enQueue(13, q);
    enQueue(14, q);
    printf("* %d * %d * %d *\n\n", q.list->numOfItems, q.list->numOfEven, q.list->numOfOdd);
    printQueue(q);

    deQueue(q);
    deQueue(q);
    printf("* %d * %d * %d *\n\n", q.list->numOfItems, q.list->numOfEven, q.list->numOfOdd);
    printQueue(q);

    deQueue(q);
    deQueue(q);
    deQueue(q);
    deQueue(q);
    printf("* %d * %d * %d *\n\n", q.list->numOfItems, q.list->numOfEven, q.list->numOfOdd);
    printQueue(q);

    emptyQueue(q);
    printQueue(q);


}


// initializes a queue
// no input, outputs a queue with an initialized pointer
// declares variable for a queue, then mallocs space for the pointer inside the queue
// error checks malloc
// initialized the pointer inside the queue's value
// returns the queue
// O(1) complexity
Queue initQueue(){
    Queue q;
    // declares variable for a queue, then mallocs space for the pointer inside the queue
    q.list = malloc(sizeof(StudentList));
    if(!q.list){ // error checks malloc
        printf("malloc failed, returning Queue with NULL list\n");
        return q;
    }

    // initialized the pointer inside the queue's value
    q.list->head = NULL;
    q.list->tail = NULL;
    q.list->numOfItems = 0;
    q.list->numOfOdd = 0;
    q.list->numOfEven = 0;

    return q; // returns the queue
}

// adds a new node to the tail of the queue
// takes age value and a queue as input
// error checks to see if queue is initialized
// mallocs a new node
// error checks malloc 
// assigns the new nodes age value to the input age
// reasigns pointer to put the new node at the tail
// assigns head and tail to first node if no other nodes, tail to new node if at least one node
// increments numOfItems and corresponding num tracker (even or odd)
// returns 1 on success and -1 on fail
// O(1) complexity
int enQueue(int age, Queue queue){
    if(queue.list == NULL){ // error checks to see if queue is initialized
        printf("error: queue is not initialized, failed in enqueue()\n");
        return -1;
    }

    Student* node = malloc(sizeof(Student)); // mallocs a new node
    if(!node){ // error checks malloc
        printf("\nmalloc failed: returning -1 value");
        return -1;
    }
    node->age = age; // assigns the new nodes age value to the input age

    // assigns head and tail to first node if no other nodes, tail to new node if at least one node
    if(queue.list->numOfItems == 0){ // tail to first node
        queue.list->head = node;
        queue.list->tail = node;
        node->nextPtr = NULL;
    }
    else{ // tail to newest node 
        queue.list->tail->nextPtr = node;
        queue.list->tail = node;
        node->nextPtr = NULL;
    }


    (queue.list->numOfItems)++;
    if(age % 2 == 0){ // increments numOfItems and corresponding num tracker (even or odd)
        (queue.list->numOfEven)++;
    }
    else{
        (queue.list->numOfOdd)++;
    }

    return 1; // returns 1 on success and -1 on fail
}

// dequeue oldest node
// takes queue as input
// error checks to see if queue is initialized
// error checks to see if queue has items in it
// sets head (points to oldest node) to head->next (second oldest node)
// increments numOfItems and corresponding num tracker (even or odd)
// returns original head
// O(1) complexity
Student* deQueue(Queue queue){
    if(queue.list == NULL){ // error checks to see if queue is initialized
        printf("error: queue is not initialized, failed in dequeue(), returning NULL pointer\n");
        return NULL;
    }
    if(queue.list->head == NULL){ // error checks to see if queue has items in it
        printf("error: queue is already empty, returning NULL ptr\n");
        return NULL;
    }

    // increments numOfItems and corresponding num tracker (even or odd)
    (queue.list->numOfItems)--;
    if(queue.list->head->age % 2 == 0){ // checking the age of the item that will be dequeue'd
        (queue.list->numOfEven)--;
    }
    else{
        (queue.list->numOfOdd)--;
    }

    // sets head (points to oldest node) to head->next (second oldest node)
    Student* temp = queue.list->head;
    queue.list->head = queue.list->head->nextPtr;

    return temp; // returns original head
}

// takes queue as input
// error checks to see if queue is initialized
// returns the amount of items in the queue on success, -1 on fail
// O(1) complexity
int getQsize(Queue queue){
    if(queue.list == NULL){ // error checks to see if queue is initialized
        printf("error: queue is not initialized, failed in getQsize(), returning -1");
        return -1;
    }

    int size = queue.list->numOfItems;
    return size; // returns the amount of items in the queue
}

// takes queue as input
// error checks to see if queue is initialized
// returns the amount of evens in the list on success, -1 on fail
// O(1) complexity
int getNumOfEven(Queue queue){
    if(queue.list == NULL){ // error checks to see if queue is initialized
        printf("error: queue is not initialized, failed in getNumOfEven(), returning -1\n");
        return -1;
    }

    int evens = queue.list->numOfEven;
    return evens; // returns the amount of evens in the list
}

// prints all items in a queue
// takes queue as input
// error checks to make sure queue is initialized
// loops through queue and prints its 'age' value
// printed from 'first in' to 'last in' order
void printQueue(Queue queue){
    if(queue.list == NULL){ // error checks to make sure queue is initialized
        printf("error: queue is not initialized, failed in printQueue()\n");
        return;
    }

    Student* temp = queue.list->head;

    while(temp != NULL){ // loops through queue and prints its 'age' value
        printf("%d --> ", temp->age);
        temp = temp->nextPtr;
    }
    printf("NULL\n\n"); // for formatting output
}

// takes queue as input
// error checks to make sure queue is initialized
// loops through queue free'ing all allocated item
// free's queue list pointer at end
// function ends with empty and uninitialized queue
void emptyQueue(Queue queue){
    if(queue.list == NULL){ // error checks to make sure queue is initialized
        printf("error: queue is not initialized, failed in emptyQueue()\n");
        return;
    }

    Student* temp;
    while(queue.list->head != NULL){ // loops through entire list
        temp = queue.list->head; // sets temp to same address as head  
        queue.list->head = queue.list->head->nextPtr; // sets head equal to the next item on list to make a new head
        free(temp); // frees old head 
        temp = NULL; // sets free'd ptr to null
    }

    free(queue.list); // free's queue list pointer at end
    queue.list = NULL; // sets free'd ptr to null
}

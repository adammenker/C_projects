#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct studstruct{    
    int age;    
    struct studstruct *nextPtr;
} Student;

Student* initListWithDummyNode();
int insertToHead(Student*,int);
int insertToTail(Student*,int);
void printList(Student*);
void emptyList(Student*);
void freeList(Student*);

//******** custom functions ********/
//* create a node with the ginve integer as age, then returns it*/
Student* createNode(int age){
    Student* node = malloc(sizeof(Student));    
    if (node == NULL){        
        printf("Allocation failed\n"); // deduct points if no error checking        
        return NULL;    
    } 
    else {        
        node->age = age;        
        node->nextPtr = NULL;        
        return node;    
    }
}

//******* required functions **********/
//* create a linked-list with two dummy nodes, one at head, one at tail*/
Student* initListWithDummyNode(){    
    Student* head = malloc(sizeof(Student));    
    if (head == NULL){        
        printf("Allocation failed\n"); // deduct points if no error checking        
        return NULL;    
    }    
    Student* tail = malloc(sizeof(Student));    
    if (tail == NULL){        
        printf("Allocation failed\n"); // deduct points if no error checking        
        free(head); // free the previously created head first        
        return NULL;    
    }    
    
    head->nextPtr = tail;    
    tail->nextPtr = NULL;    
    
    return head;
}

/* create a new node and insert at the head location*/
int insertToHead(Student* List,int age){    
    if (List == NULL){ // should not be NULL due to dummy node        
        return 0;    
    }    
    Student* newNode = createNode(age);    
    if (newNode == NULL){        
        return 0;    
    }    
    newNode->nextPtr = List->nextPtr;    
    List->nextPtr = newNode;    
    return 1;
}

/* create a new node and insert at tail*/
int insertToTail(Student* List,int age){
    if (List == NULL){ // should not be NULL due to dummy node        
        return 0;    
    }    
    Student* newNode = createNode(age);    
    if (newNode == NULL){        
        return 0;    
    }    
    Student* temp = List;    
    while (temp->nextPtr->nextPtr != NULL){        
        temp = temp->nextPtr;    
    }    
    newNode->nextPtr = temp->nextPtr;    
    temp->nextPtr = newNode;    
    return 1;
}

/* print the list with dummy nodes*/
void printList(Student* List){    
    if (List == NULL){        
        printf("List hasn't been initialized\n");    
    } 
    else if (List->nextPtr->nextPtr == NULL){        
        // the two dummy nodes        
        printf("List is empty\n");    
    } 
    else {        
        printf("List is: Dummy head --> ");        
        Student* temp = List->nextPtr;        
        while (temp->nextPtr->nextPtr != NULL){            
            printf("%d --> ",temp->age);            
            temp = temp->nextPtr;        
        }        
        printf("%d --> Dummy tail\n",temp->age); // could put this in the while loop, but then it won't be a nice format    
    }
}

/* empty the current list, set it back to two dummy nodes*/
void emptyList(Student* List){    
    if (List == NULL || List->nextPtr->nextPtr == NULL){        
        return; // nothing, or already an empty list    
    } else {        
        Student* temp = List->nextPtr;        
        Student* currentFree;        
        while (temp->nextPtr != NULL){            
            currentFree = temp;            
            temp = temp->nextPtr;            
            free(currentFree);            
            currentFree = NULL;        
        }        
        // now we only the two dummy nodes        
        List->nextPtr = temp;    
    }
}

void freeList(Student* List){    
    Student* temp = List;
    while (temp != NULL){        
        List = List->nextPtr;        
        free(temp);        
        temp = NULL;        
        temp = List;    
    }
}
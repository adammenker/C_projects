/* Header .h file for CS 2050, 2020 SP, Wed labs. Should NOT be modified or submitted. -- Shizeng */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct studstruct{
    int age;    
    struct studstruct *nextPtr;
}Student;

typedef struct llist{
    Student* head;
    Student* tail;
} List;


Student* initListWithDummyNode();
int insertToHead(Student*,int);
int insertToTail(Student*,int);
void printList(Student*);
void emptyList(Student*);
void freeList(Student*);
void link(Student ** head, Student ** tail);


int main(void){

    List * t;
    t->head = initListWithDummyNode();
    t->tail = initListWithDummyNode();

    link(&(t->head), &(t->tail));
    Student * test = t->head;
    
    int x = insertToHead(test, 3);
    //printf("*%d\n", x);

    int y = insertToTail(test, 4);
    //printf("*%d\n", y);

    printList(test);

    emptyList(test);
    
    printf("* %p\n", &test);
    printf("* %p\n", &(test->nextPtr));

    free(test->nextPtr);

    //printList(test);

    freeList(test);

    //printList(test);

}


void link(Student ** head, Student ** tail){
    head->age = -1;
    tail->age = -2;
    head->nextPtr = tail;
    tail->nextPtr = NULL;
    return head;
}


Student* initListWithDummyNode(){
    Student * temp1 = malloc(sizeof(Student) * 2);
    // Student * temp2 = malloc(sizeof(Student));
    if(temp1 == NULL /*|| temp2 == NULL*/){
        printf("*malloc failed*");
        exit(-1);
    }

    Student * temp2 ;
    temp1->age = -1;
    temp2->age = -2;
    temp1->nextPtr = temp2;
    temp2->nextPtr = NULL;

    printf("%p\n", &temp1);
    printf("%p\n", &(temp1->nextPtr));

    return temp1;
}


int insertToHead(Student* head, int age){
    Student * temp = (Student *) malloc(sizeof(Student));
    if(temp == NULL){
        printf("malloc failed");
    }
    temp->age = age;
    temp->nextPtr = head->nextPtr;
    head->nextPtr = temp;
    if(head->nextPtr == temp && temp->age == age && head->nextPtr->nextPtr == temp->nextPtr){ //checks if data was inserted and if list pointer were reassigned properly
        return 1;
    }
    return 0;
}


int insertToTail(Student* head, int age){
    Student * newTail = (Student *) malloc(sizeof(Student));
    if(newTail == NULL){
        printf("malloc failed");
    } 
    Student * temp;
    Student * oneBeforeTail;
    temp = head;
    while(temp->nextPtr != NULL){
        temp = temp->nextPtr; // breaks once temp is a pointer to last node
        if(temp->nextPtr != NULL){
            oneBeforeTail = temp;
        }
    }
    newTail->age = age;
    newTail->nextPtr = temp;
    oneBeforeTail->nextPtr = newTail;
    
    
    if(newTail->nextPtr == temp && newTail->age == age && newTail->nextPtr->nextPtr == NULL){//checks if data was inserted and if list pointer were reassigned properl
        return 1;
    }
    return 0;
}


void printList(Student* head){
    Student * temp;
    temp = head; //creates ptr and sets to head
    while(temp != NULL){ //loops through entire list
        printf("%d\n", temp->age); //prints age of item
        temp =  temp->nextPtr; //moves pointer to next item of list
    }
    // add ->nexptr in while loop and 2nd line
    printf("\n*\n\n");
}


void emptyList(Student* head){
    Student * temp = head->nextPtr;
    Student * current; 
    while(temp->nextPtr != NULL){
        current = temp;
        head->nextPtr = current->nextPtr;
        temp = temp->nextPtr;
        free(temp);
    }
}


void freeList(Student * head){
    printf("%p\n", &head);
    printf("%p\n", &(head->nextPtr));

    // free(head->nextPtr);
    free(head);

    // Student * temp;
    // while(head != NULL){
    //     temp = head;
    //     head = head->nextPtr;
    //     printf("%p\n", &head);
        
        
    //     free(temp);


    //     // printf("-*- %d -*-", temp->age);
    // }
    // printf("\n");
}

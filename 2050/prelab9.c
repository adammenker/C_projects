#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node* next;
} List;


List * createList();
void freeList(List * head);
int getListLength(List * head);
int insertAtHead(int data, List * head);
int insertAtTail(int data, List * head);
List * copyList(List * copied);

void printList(List * head);


int main(void){ 
    List * linkedList;
    linkedList = createList();

    printList(linkedList);

    int checkHead = insertAtHead(4, linkedList);
    insertAtHead(3, linkedList);
    insertAtHead(2, linkedList);
    //printf("%d\n", checkHead);
    printList(linkedList);
    int length = getListLength(linkedList);
    printf("%d\n", length);

    int checkTail = insertAtTail(5, linkedList);
    //printf("%d\n", checkTail);
    printList(linkedList);

    length = getListLength(linkedList);
    printf("%d\n", length);

}


List * createList(){ // implemented with a dummy node
    List * temp = (List *) malloc(sizeof(List));
    temp->data = 0;
    temp->next = NULL;
    return temp;
}


void printList(List * head){
    List * temp = head->next; // jumps past dummy node
    while(temp != NULL){
        printf("%d - ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int getListLength(List * head){
    int length = head->data;
    return length;
}


int insertAtHead(int data, List * head){
    List * temp = (List *) malloc(sizeof(List));
    if(temp == NULL){
        printf("malloc failed");
    }
    temp->data = data;
    temp->next = (*head).next;
    (*head).next = temp;
    if((*head).next == temp && temp->data == data && (*head).next->next == temp->next){ //checks if data was inserted and if list pointer were reassigned properly
        head->data++; // incrementing size
        return 0;
    }
    return 1;
}


int insertAtTail(int data, List * head){
    List * newTail = (List *) malloc(sizeof(List)); 
    List * temp;
    temp = head;
    while(temp->next != NULL){
        temp = temp->next; // breaks once temp is a pointer to last node
    }
    newTail->data = data;
    newTail->next = NULL;
    temp->next = newTail;
    
    
    if(newTail->next == NULL && newTail->data == data && temp->next->next == NULL){//checks if data was inserted and if list pointer were reassigned properl
        head->data++;
        return 0;
    }
    return 1;
}


List * copyList(List * copied){
    return 0;
}
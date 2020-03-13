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
    int length = getListLength(linkedList);
    printf("%d\n", length);

    int checkHead = insertAtHead(3, linkedList);
    printf("%d\n", checkHead);

    int checkTail = insertAtTail(3, linkedList);
    printf("%d\n", checkTail);

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
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}


int getListLength(List * head){
    int length = head->data;
    return length;
}


int insertAtHead(int data, List * head){
    List * temp = (List *) malloc(sizeof(List));
    temp->data = data;
    temp->next = head->next->next;
    head->next = temp;
    if(head->next == temp && temp->data == data && head->next->next == temp->next){ //checks if data was inserted and if list pointer were reassigned properly
        return 0;
    }
    return 1;
}


int insertAtTail(int data, List * head){
    List * newTail = (List *) malloc(sizeof(List));
    newTail = head;
    List * temp;
    while(newTail != NULL){
        newTail = newTail->next;
        if(newTail->next != NULL){
            temp = newTail;
        }
    }
    temp->next = newTail;
    newTail->data = data;
    if(newTail->next == NULL && newTail->data == data && temp->next->next == NULL){
        return 0;
    }
    return 1;
}
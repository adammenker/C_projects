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
List * createNode(void);


int main(void){ 
    List * linkedList;
    linkedList = createList();

    // below tests insertAtHead(), insertAtTail(), copyList(), and getListLength()       ** as well as printList() and createNode()
    // printList(linkedList);

    // int checkHead = insertAtHead(4, linkedList);
    // insertAtHead(3, linkedList);
    // insertAtHead(2, linkedList);
    // printList(linkedList);

    // int length = getListLength(linkedList);
    // printf("%d\n", length);

    // int checkTail = insertAtTail(5, linkedList);
    // printList(linkedList);

    // length = getListLength(linkedList);
    // printf("%d\n", length);

    // List * copy;
    // copy = copyList(linkedList);
    // printList(copy);

    // length = getListLength(copy);
    // printf("%d\n", length);

    // insertAtHead(1, copy);
    // printList(copy);

    // length = getListLength(copy);
    // printf("%d\n", length);


    //******** division *********


    //below tests freeList()
    // insertAtHead(3, linkedList);
    // insertAtHead(2, linkedList);
    // printList(linkedList);
    // List * copy1 = copyList(linkedList);
    // freeList(linkedList);
    // //printList(linkedList);
    // printList(copy1);
    // freeList(copy1);
    // //printList(copy1);

}


List * createList(){ // implemented with a dummy node
    List * temp = (List *) malloc(sizeof(List));
    if(temp == NULL){
        printf("malloc failed");
    }
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
    if(newTail == NULL){
        printf("malloc failed");
    } 
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
    int size = copied->data;
    List * currentNode = copied;
    

    List * newHead = createList();
    List * copy = newHead;
    copy->data = size;

    for(int i = 0; i < size; i++){
        copy->next = createNode();
        copy = copy->next;
        currentNode = currentNode->next;
        copy->data = currentNode->data;      
    }
    return newHead;
}


List * createNode(void){
    List * newNode = (List *) malloc(sizeof(List));
    if(newNode == NULL){
        printf("malloc failed");
    }
    newNode->next = NULL;

    return newNode;
}


void freeList(List * head){
    List * temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}
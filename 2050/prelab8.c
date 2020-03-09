#include <stdio.h>
#include <stdlib.h>

typedef struct List {
    int Key;
    struct List * next;
} List;


List * initIntegerList();
void insertAtHead(List * head, int num_val);
void insertAtTail(List * head, int num_val);
void printList(List * head);
void createNode_middle(List * cur_position);
void createManyNodes(List * position, int num_nodes);
void createNode_end(List * head);
void freeList(List * head, int num_nodes);


int main(void){
    List * head;
    head = initIntegerList();


    insertAtHead(head, 10);
    createManyNodes(head, 5);
    insertAtTail(head, 15);
    printList(head);
    //freeList(head, 6);
    printList(head);
}


List * initIntegerList(){
    List * temp = malloc(sizeof(List) * 1);
    if(temp == NULL){
        printf("*malloc failed*");
        exit(-1);
    }
    (*temp).next = NULL;
    return temp;
}


void insertAtHead(List * head, int num_val){
    (*head).Key = num_val;
}


void insertAtTail(List * head, int num_val){
    List * temp = head;
    while((*temp).next != NULL){
        temp = (*temp).next;
    }
    (*temp).Key = num_val;
}


void printList(List * head){
    List * temp = head;
    while(temp != NULL){
        printf("%d - ", temp->Key);
        temp = temp->next;
    }
    printf("\n");
}


void createNode_middle(List * cur_position){

    if(cur_position->next != NULL){
        List * node = malloc(sizeof(List));
        if(node == NULL){
            printf("malloc failes: createNode_middle\n");
        }
        node->next = cur_position->next;
        cur_position->next = node;
    }
    else{
        printf("at end of list, use end of list function insertion\n");
    }
}


void createNode_end(List * head){
    List * node = malloc(sizeof(List));
    List * temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = node;
    node->next = NULL;
}


void createManyNodes(List * position, int num_nodes){
    int i;
    for(i = 0; i < num_nodes; i++){
        if(position->next != NULL){
            createNode_middle(position);
        }
        if(position->next == NULL){
            createNode_end(position);
        }
    }
}


void freeList(List * head, int num_nodes){
    List * temp, * temp2;
    temp = head->next; //first node
    temp2 = temp->next; //second node
    int i;
    for(i = 0; i < num_nodes; i++){
        temp->next = NULL;
        free(temp);
        temp = temp2;
        temp2 = temp2->next;
    }
    head = NULL;
}
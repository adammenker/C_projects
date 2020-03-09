#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node * next;
};
typedef struct node List;

List * initIntegerList();
int insertAtHead(int k, List *list);
int insertAtTail(int k, List *list);

void createNode_middle(List * cur_position);
void createNode_end(List * head);
void createManyNodes(List * position, int num_nodes);
void freeSupport(List * head);

void freeList(List ** head);
void printList(List * head);


int main(void){
    List * head;
    head = initIntegerList();
    createManyNodes(head, 5);
    int z = insertAtHead(5, head);
    int y = insertAtTail(5, head);
    printList(head);
    freeList(&head);
    printf("%d", head->data);
    printList(head);
}


List * initIntegerList(){
    List * dummy = malloc(sizeof(List));
    dummy->data = -1;
    dummy->next = NULL;

    return dummy;
}


int insertAtHead(int k, List *list){
    List * temp = malloc(sizeof(List));
    if(temp == NULL){
        printf("MALLOC FAILED\n\n");
    }
    temp->next = (list->next);
    list->next = temp;
    temp->data = k;
    
    if(list->next->data == k){
        return 0;
    }
    else{
        printf("FAILED***\n");
        return -1;
    }
    return 1;
}


int insertAtTail(int k, List *list){
    List * newNode = malloc(sizeof(List));
    if(newNode == NULL){
        printf("MALLOC FAILED\n\n");
    }
    List * current;
    current = list;
    while(current->next != NULL){
        current = current->next;
    }
    if(current->next == NULL){
        current->next = newNode;
    }
    newNode->data = k;
    newNode->next = NULL;

    List * tester;
    tester = list;
    while(tester->next != NULL){
        tester = tester->next;
    }
    if(tester->data == k){
        return 0;
    }
    else{
        return -1;
    }

    return 1;
}


void freeList(List ** head){
    freeSupport(*head);
    (*head)->next = NULL;
    //free(head);
    printf("\n***\n");
}

void freeSupport(List * head){
    List * temp, * temp2;
    if(head->next != NULL){
        temp = head->next; //first node
        if(temp->next != NULL){
            temp2 = temp->next; //second node
            int i;
            while(temp->next != NULL){
                temp->next = NULL;
                free(temp);
                temp = temp2;
                temp2 = temp2->next;
            }
        }
        else{
            free(temp);
        }
    }
}


void printList(List * head){
    List * temp = head->next;
    while(temp != NULL){
        printf("%d - ", temp->data);
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
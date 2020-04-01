#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SinglyLinkedListNode SinglyLinkedListNode;

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};


SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    SinglyLinkedListNode* temp = head;
    if(temp == NULL){
        SinglyLinkedListNode* newNode = malloc(sizeof(SinglyLinkedListNode));
        head = newNode;
        newNode->data = data;
        newNode->next = NULL;  
        return head;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    SinglyLinkedListNode* newNode2 = malloc(sizeof(SinglyLinkedListNode));
    temp->next = newNode2;
    newNode2->data = data;
    newNode2->next = NULL;
    return head;
}
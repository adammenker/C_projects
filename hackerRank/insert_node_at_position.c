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
typedef struct SinglyLinkedList SinglyLinkedList;

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};

struct SinglyLinkedList {
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;
};



SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    SinglyLinkedListNode* newNode = malloc(sizeof(SinglyLinkedListNode));
    newNode->next = head;
    SinglyLinkedListNode* currentNode;
    currentNode = head;
    for(int i = 0; i < position; i++){
        newNode->next = currentNode->next;
        if(!(i >= (position - 1))){
            currentNode = currentNode->next;
        }
    }
    currentNode->next = newNode;
    newNode->data = data;
    return head;
}
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


SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {
    int i = 0;
    SinglyLinkedListNode* temp = head;
    if(position == 0){
        return head->next;
    }
    while(i != (position - 1)){
        temp = temp->next;
        i++;
    }
    SinglyLinkedListNode* temp2 = temp->next;
    temp->next = temp2->next;
    return head;

}
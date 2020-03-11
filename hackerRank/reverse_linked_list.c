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


SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* temp = head;
    int counter = 0;
    while(temp != NULL){
        temp = temp->next;
        counter++;
    }
    int hold = counter;
    SinglyLinkedListNode* newHead;
    for(int i = 0; i < hold; i++){
        SinglyLinkedListNode* end_unreversed = head;
        SinglyLinkedListNode* previous;
        for(int x = 0; x < (counter - 1); x++){
            previous = end_unreversed;
            end_unreversed = end_unreversed->next;
        }
        end_unreversed->next = previous;
        counter--;
        if(i == 0){
            newHead = end_unreversed;
        }
    }
    head->next = NULL;
    return newHead;
}
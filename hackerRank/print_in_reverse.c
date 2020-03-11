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


void reversePrint(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* temp = head;
    int counter = 0;
    if(temp == NULL){
        return;
    }
    while(temp != NULL){
        temp = temp->next;
        counter++;
    }
    int hold = counter;
    for(int i = 0; i < hold; i++){
        SinglyLinkedListNode* reverseMover = head;
        for(int x = 0; x < counter; x++){
            if(x == (counter - 1)){
                printf("%d\n", reverseMover->data);
            }
            reverseMover = reverseMover->next;
        }
        counter--;
    }
}
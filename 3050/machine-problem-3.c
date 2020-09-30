#include <stdio.h>
#include <stdlib.h>

// created linked list and Node structures
typedef struct node{
    int vertexNumber;
    struct node* next;
} Node;

typedef struct linkedList{
    Node* head;
    int size;
} LinkedList;

void getNumberOfVerticesAndEdges(FILE* fp, int* vertices, int* edges);
void push(LinkedList* linkedList, int vertex);
Node* createNode(int vertexNumber);
void printAdjacencyLists(LinkedList** arrayOfLinkedLists, int vertices, int edges);
LinkedList** createLinkedList(int numOfVertices);
void formatList(LinkedList** array, int vertices);

int main(void){
    // creating the file pointer
    FILE *fptr = fopen("input-machine-problem-1.txt", "r");
    if (fptr == NULL) {
        printf("Error! opening file");
        return 0;
    }

    int edges;
    int vertices;
    int* edgesPtr = &edges;
    int* verticesPtr = &vertices;
    // gets the number of vertices and edges in the file
    getNumberOfVerticesAndEdges(fptr, verticesPtr, edgesPtr); // O(e)
    // creating an array of linked lists, each list stores adjacency list for a vertex
    LinkedList** arrayOfLinkedLists = createLinkedList(vertices);

    int x, y;
    if(fptr == NULL){
        return 0;
    }
    // rewind so that any outside functions (getNumberOfVerticesAndEdges for example) reading file do not move 
    // the pointer to a spot that will affect the algorithm belowe
    rewind(fptr);
    // looping for every vertice, scan and push each edge causing O(v * e) time complexity
    for(int i = 0; i < edges; i++){
        // read each edge from the file
        if(feof(fptr)){
            return 0;
        }
        fscanf (fptr, "%d %d", &x, &y);  
        push(arrayOfLinkedLists[x - 1], y);
        push(arrayOfLinkedLists[y - 1], x);
    }

    // implementation makes use of setting a temp node to each linked list initialized so funciton below removes that temp node
    formatList(arrayOfLinkedLists, vertices);
    // prints adjacency lists in readable format
    printAdjacencyLists(arrayOfLinkedLists, vertices, edges);
    // closes file
    fclose(fptr); 
}

// O(v)
// input array of LinkedLists, and int value for a new nodes vertex that is being pushed
void push(LinkedList* linkedList, int vertex){
    // creates new node with input int
    Node* newNode = createNode(vertex);
    // functionality below creates a pointer that will traverse the linked list, moving the new node over 1 position
    // until it finds a node that is greater than the new node, so new node will be node right before the first 
    // one greater than it
    Node temp;
    Node* cur = &temp;
    temp.next = linkedList->head;

    while(cur->next != NULL && cur->next->vertexNumber < newNode->vertexNumber){
        cur = cur->next;
    }
    if(cur->next->vertexNumber == newNode->vertexNumber){
        return;
    }
    newNode->next = cur->next;
    cur->next = newNode;
    linkedList->head = temp.next;
}



// removes place holder node
void formatList(LinkedList** array, int vertices){
    for(int i = 0;i < vertices; i++){
        Node* temp = array[i]->head;
        Node* prev = temp;
        while(temp->next != NULL){
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
    }
}

// creates array of linked lists and initializes each list with a temp/place holder node
LinkedList** createLinkedList(int numOfVertices){
    LinkedList** array = malloc(sizeof(LinkedList) * numOfVertices);
    for(int i = 0; i < numOfVertices; i++){
        LinkedList* newLinkedList = malloc(sizeof(LinkedList));
        Node* temp = createNode(99);
        newLinkedList->head = temp;
        array[i] = newLinkedList;
    }
    return array;
}

// allocates memory for a node and sets its vetex int value
Node* createNode(int vertexNumber){
    Node* newNode = malloc(sizeof(Node));
    if(!newNode){
        return NULL;
    }
    newNode->vertexNumber = 0;
    newNode->next = NULL;
    newNode->vertexNumber = vertexNumber;

    return newNode;
}

// scans through file and looks for greatest int and increments int holding num of edges for every new line of ints read
void getNumberOfVerticesAndEdges(FILE* fp, int* vertices, int* edges){
    int x, y;
    
    if (fp == NULL) {
        printf("Error! opening file");
        return;
    } 

    *vertices = 0;
    *edges = 0;
    while (fscanf(fp, "%d %d", &x, &y) == 2) {
        if(x > *vertices){
            *vertices = x;
        } if (y > *vertices){
            *vertices = y;
        }

        *edges = (*edges) + 1;
    }
}

// traverses each linked list and prints its vertices value
void printAdjacencyLists(LinkedList** arrayOfLinkedLists, int vertices, int edges){
    for(int i = 0; i < vertices; i++){
        printf("%d:  ", i + 1);
        if(arrayOfLinkedLists[i]->head == NULL){
            return;
        }
        Node* cur = arrayOfLinkedLists[i]->head;

        while(cur != NULL){
            printf("%d --> ", cur->vertexNumber);
            cur = cur->next;
        }
        printf("NULL\n");
        free(cur);
    }
}

/* Header .h file for CS 2050, 2020 SP, Thursday labs. Should NOT be modified or submitted. -- Shizeng */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct studstruct{
    int age;
    struct studstruct *nextPtr;
}Student;

Student* createNode(int);
Student* initList();
Student* addToHead(Student*,int);
Student* addToTail(Student*,int);
void printList(Student*);
int searchAge(Student*, int);
Student* freeList(Student*);

int main(void){
    Student* test;

    test = initList();
    test = createNode(20);
    test = addToHead(test, 19);
    test = addToHead(test, 18);
    test = addToHead(test, 17);
    test = addToTail(test, 21);

    // int val;
    // val = searchAge(test, 20);
    // printf("%d\n", val);

    printList(test);
    test = freeList(test);
}



// ************************************ Above ^ is header

// ************************************ Below v is implementation


// recieves int age as parameter
// creates new node and assigns data/key value to 'age' parameter
// sets new nodes next ptr to NULL to end the list 
// returns pointer to new node
// this function is designed to create the first node of a linked list, and should not be used any other way (the instructions did not specify (ambiguous) how this function is supposed to work, so I created it as I could best assume the expectations of its functionality)
Student* createNode(int age){
    Student * student = (Student*) malloc(sizeof(Student)); // dynamically allocates memory for new node
    if(student == NULL){ //error checks malloc
        printf("MALLOC FAILED: in createNode");
        return 0;
    }
    student->age = age; // sets new nodes age value to 'age'
    student->nextPtr = NULL; // sets the next ptr to NULL 

    return student; // return ptr to new node
}

// initialized ptr to NULL
// returns NULL pointer of a Student list
// designes to assign a listptr in main to this function so the list ptr becomes empty list with no nodes
Student* initList(){
    Student * temp = NULL; //creates NULL ptr
    return temp; // return NULL ptr
}

// recieves head to linked list and int age as input
// checks if list is empty, if so gives warning message and assigns new node to head
// checks if malloc succeeds or fails
// sets list ptr to new nody dynamically allocated
// sets new node's data to 'age' parameter
// sets new node's next pointer to previous head node
Student* addToHead(Student* head, int age){
    if(head == NULL){ //checks if list is empty and lets user know if so
        printf("\nwarning: empty list being used, item added to head of empty list, no longer empty\n");
    }
    Student* temp = (Student*) malloc(sizeof(Student)); //dynamically allocates node and pointer to it
    if(temp == NULL){ // checks if malloc failed
        printf("MALLOC FAILED: in addToHead");
        return 0;
    }
    temp->nextPtr = head; //sets new node's head to previous head node
    temp->age = age; // sets new node's data to 'age'
    return temp; // returns new head (the new node)
}

// recieves head to linked list and int age as input
// checks if list is empty, if so returns head NULL ptr and exits out of function
// dynamically allocates node ptr
// checks malloc and prints error message if no memory available 
// sets ptr to head
// loops through entire list until ptr is at last item
// sets last item's next pointer to new node dynamically allocates above
// sets new node's next pointer to NULL so that list ends with new node
// sets new nodes data to age parameter
//returns head of list with new node on the tail
Student* addToTail(Student* head, int age){
    if(head == NULL){ //checks if the list is empty, if so terminates function with warning message
        printf("\nwarning: empty list being used, add item first with 'addToHead' or 'createNode' first\n");
        return head;
    }
    Student* temp = (Student*) malloc(sizeof(Student));
    if(temp == NULL){ //checks if malloc failed
        printf("MALLOC FAILED: in addToTail");
        return 0;
    }
    
    Student* current;
    current = head; //creates ptr and sets it to heads location
    while(current->nextPtr != NULL){ // loops through entire list until the last item is arrives at by ptr
        current = current->nextPtr; // recursively sets ptr to next item
    }
    current->nextPtr = temp; // sets last item's next ptr to the node creates above
    temp->nextPtr = NULL; // sets new node's next ptr to NULL to end the list
    temp->age = age; // sets new nodes data/key value to 'age'
    

    return head; // returns head of list with new node on the tail
}

// recieves head of list as input
// sets a ptr to heads location
// loops through list until the last item is accessed and pointer is set to next value (NULL)
// prints out the age of each item in the list in order (where temp pointer is pointing to)
// sets pointer to next item
void printList(Student* head){
    Student * temp;
    temp = head; //creates ptr and sets to head
    while(temp != NULL){ //loops through entire list
        printf("%d\n", temp->age); //prints age of item
        temp =  temp->nextPtr; //moves pointer to next item of list
    }
}

// recieves head of list and an integer 'age' that is query
// sets a ptr to heads location
// ptr starts at first item and moves through until it either locates the first instance of the query (then returns the positon) or hits NULL
// query position is kept track of by 'counter', every loop through to the next element adds one to the counter
// effectivy stores position in a variable
int searchAge(Student* head, int age){
    Student * temp; 
    temp = head; //Student ptr set to head
    int counter = 0; //position counter starts at 0

    while(temp != NULL){ //loops through until the last item has been searched
        if(temp->age == age){ // if age of item matches query
            return counter; // return what the position is
        }
        counter++; // increments counter everytime query is not found in an item
        temp = temp->nextPtr; // moves pointer to next item
    }
    return -1; // returns negative one if the query is not found in linked list
}

//recieves head of linked list as input
//creates pointer equal to head, moves head to next item in list and frees what the original ptr points to
//essentially, is recursively free'ing the previous list item behind head, and moving head up one (starting at the 2nd item so the first gets free'd)
Student* freeList(Student* head){
    Student * current;
    while (head != NULL) { 
        current = head; // pointer points to heads initial location
        head = head->nextPtr;  // head getting set to the second item        
        free (current); // frees first item in list               
    }
    head = NULL; //arbitrary, but makes more readable, head would be set to NULL without this bc freed memory goes to NULL ptr
    return head; //returns head, after all items have been freed
}



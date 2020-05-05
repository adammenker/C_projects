#include<stdio.h> 
#include<stdlib.h> 
#define COUNT 6

typedef struct node { 
    int key; 
    struct node *left, *right; 
} Node; 

typedef struct binarySearchTree {
    Node* top;
} BST;


Node* newNode(int key);
void insertBST(BST* bst, int key);
BST* findBST(BST* bst, int key);
void print2DUtil(Node* root, int space);
void print2D(BST* bst);


int main(void){
    BST* myBST = malloc(sizeof(BST));
    myBST->top = NULL;
    // Node* top = newNode(10);
    insertBST(myBST, 100);
    insertBST(myBST, 90);
    insertBST(myBST, 80);
    insertBST(myBST, 10);
    insertBST(myBST, 60);
    insertBST(myBST, 50);
    insertBST(myBST, 55);
    insertBST(myBST, 45);
    insertBST(myBST, 1000035);
    print2D(myBST);

    BST* newBSTptr = findBST(myBST, 60);
    print2D(newBSTptr);
    
    printf("done\n");
}


Node* newNode(int key){ 
    struct node *temp = malloc(sizeof(Node)); 
    temp->key = key; 
    temp->left = temp->right = NULL; 
    return temp; 
} 


void insertBST(BST* bst, int key){ 
    if (bst->top == NULL){ 
        bst->top = newNode(key); 
    }
    BST* temp = malloc(sizeof(BST));
    if (key < bst->top->key){
        temp->top = bst->top->left;
        insertBST(temp, key);
        bst->top->left = temp->top; 
    }
    else if (key > bst->top->key){
        temp->top = bst->top->right;
        insertBST(temp, key);
        bst->top->right = temp->top; 
    }
} 


BST* findBST(BST* bst, int key){
    if (bst->top == NULL){ 
        printf("BST not found\n"); 
        return NULL;
    }
    if(bst->top->key == key){
        printf("\n*Found BST!\n");
        return bst;
    }
    BST* temp = malloc(sizeof(BST));
    /* Otherwise, recur down the tree */
    if (key < bst->top->key){
        temp->top = bst->top->left;
        return findBST(temp, key);
    }
    else if (key > bst->top->key){
        temp->top = bst->top->right;
        return findBST(temp, key);
    }
    return NULL;
}


void print2DUtil(Node *root, int space){ 
    if (root == NULL){return;} 

    space += COUNT; 
    print2DUtil(root->right, space); 

    for (int i = COUNT; i < space; i++){ 
        printf(" ");
    }
    printf("%6d-----|", root->key);  // handles proper formatting for up to 6 digits, change coefficient of %d to accomidate more       
    if(!root->left && !root->right){
        printf("NULL");
    }
    printf("\n");

    print2DUtil(root->left, space); 
} 

void print2D(BST* bst){ 
    if(!bst){
        return;
    }
    printf("\n");
    print2DUtil(bst->top, 0); 
}
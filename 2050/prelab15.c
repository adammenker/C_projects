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
void freeNodes(Node* root);
void freeBST(BST* bst);

BST* search(BST* bst, int key);


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

    BST* newBSTptr = search(myBST, 60);
    print2D(newBSTptr);
    
    freeBST(newBSTptr);
    
    printf("\ndone\n");

    // print2D(newBSTptr);
}


Node* newNode(int key){ 
    Node* temp = malloc(sizeof(Node)); 
    if(!temp){
        printf("malloc failed: newNode()");
    }
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
    free(temp); // not sure if this is correct, may work 99% of the time but also may leave room for runtime error
} 


BST* findBST(BST* bst, int key){
    if (bst->top == NULL){ 
        printf("BST not found\n"); 
        // free(bst);
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


BST* search(BST* bst, int key){ 
    // Base Cases: root is null or key is present at root 
    if (bst->top == NULL || bst->top->key == key){
        return bst;
    }
     
    // Key is greater than root's key 
    if (bst->top->key < key){
        BST* temp = malloc(sizeof(BST));
        temp->top = bst->top->right;
        return search(temp, key); 
    }
  
    // Key is smaller than root's key 
    BST* temp = malloc(sizeof(BST));
    temp->top = bst->top->left;
    return search(temp, key); 
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
    if(!bst || !(bst->top)){
        return;
    }
    printf("\n");
    print2DUtil(bst->top, 0); 
}


void freeNodes(Node* root){
    if(root){
        Node* tempLeft = root->left;
        Node* tempRight = root->right;
        
        free(root);
        if(tempRight){
            freeNodes(tempRight);
        }
        if(tempLeft){
            freeNodes(tempLeft);
        }
    }
}


void freeBST(BST* bst){
    freeNodes(bst->top);
    free(bst);
}
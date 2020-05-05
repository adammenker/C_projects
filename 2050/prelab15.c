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
Node* search(struct node* root, int key);
void print2DUtil(Node* root, int space);
void print2D(BST* bst);
void freeNodes(Node* root);
void freeBST(BST* bst);


int main(void){
    BST* myBST = malloc(sizeof(BST));
    myBST->top = NULL;
    // Node* top = newNode(10);
    insertBST(myBST, 100);
    insertBST(myBST, 50);
    insertBST(myBST, 150);
    insertBST(myBST, 25);
    insertBST(myBST, 175);
    insertBST(myBST, 75);
    insertBST(myBST, 125);
    insertBST(myBST, 12);
    insertBST(myBST, 35);
    print2D(myBST);
    printf("\n----------------------------\n");

    BST* newBSTptr = findBST(myBST, 50);
    print2D(newBSTptr);
    
    freeBST(newBSTptr);
    
    printf("\n----------------------------\n");

    print2D(myBST);
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


Node* search(struct node* root, int key){ 
    // Base Cases: root is null or key is present at root 
    if (root == NULL || root->key == key) 
       return root; 
     
    // Key is greater than root's key 
    if (root->key < key) 
       return search(root->right, key); 
  
    // Key is smaller than root's key 
    return search(root->left, key); 
} 


BST* findBST(BST* bst, int key){
    Node* newRoot = search(bst->top, key);
    BST* temp = malloc(sizeof(BST));
    temp->top = newRoot;
    return temp;
}


void freeNodes(Node* root){
    if(root){
        
        Node* tempLeft = root->left;
        Node* tempRight = root->right;
        
        free(root);
        root = NULL;

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



void print2DUtil(Node *root, int space){ 
    if (root == NULL){
        return;
    } 

    space += COUNT; 
    if(root->right != NULL && root != NULL){
        print2DUtil(root->right, space); 
    }

    for (int i = COUNT; i < space; i++){ 
        printf(" ");
    }
    printf("%6d-----|", root->key);  // handles proper formatting for up to 6 digits, change coefficient of %d to accomidate more       
    if(!root->left && !root->right){
        printf("NULL");
    }
    printf("\n");

    if(root->left != NULL && root != NULL){
        print2DUtil(root->left, space);
    }
} 

void print2D(BST* bst){ 
    if(!bst || !(bst->top)){
        return;
    }
    printf("\n");
    print2DUtil(bst->top, 0); 
}
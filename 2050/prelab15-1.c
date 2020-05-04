// C program to demonstrate insert operation in binary search tree. 
#include<stdio.h> 
#include<stdlib.h> 
#define COUNT 10

struct node{ 
    int key; 
    struct node *left, *right; 
}; 

// A utility function to create a new BST node 
struct node *newNode(int item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

// A utility function to do inorder traversal of BST 
void inorder(struct node *root) 
{ 
    if (root != NULL){ 
        inorder(root->left); 
        printf("%d \n", root->key); 
        inorder(root->right); 
    } 
} 

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL){ 
        return newNode(key); 
    }

    /* Otherwise, recur down the tree */
    if (key < node->key){
        node->left  = insert(node->left, key); 
    }
    else if (key > node->key){
        node->right = insert(node->right, key);
    }
    /* return the (unchanged) node pointer */
    return node; 
} 


// Function to print binary tree in 2D 
// It does reverse inorder traversal 
void print2DUtil(struct node *root, int space){ 
    if (root == NULL) 
        return; 

    space += COUNT; 

    print2DUtil(root->right, space); 
  
    printf("\n"); 
    for (int i = COUNT; i < space; i++) 
        printf(" "); 
    printf("%d\n", root->key); 

    print2DUtil(root->left, space); 
} 

void print2D(struct node *root) { 
   print2DUtil(root, 0); 
}


// Driver Program to test above functions 
int main() 
{ 
/* Let us create following BST 
                50 
            /       \ 
        30            70 
    /       \       /     \ 
  20         40   60       80 
*/
    struct node *root = NULL; 
    root = insert(root, 100); 
    insert(root, 150); 
    insert(root, 50); 
    insert(root, 125); 
    insert(root, 75); 
    insert(root, 175); 
    insert(root, 25); 

    // print inoder traversal of the BST 
    // inorder(root); 
    print2D(root);

    return 0; 
} 
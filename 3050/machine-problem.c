// Adam Menker, Ethan Loftis, Kenny Fatoki

#include <stdio.h>
#include <stdlib.h>

// My runtime for making the adjacency lists is (Ov+e). I have three relevant loops. The first is in 
// getNumberOfVerticesAndEdges(), this runs in O(e) time because it reads every edge. the next is in
// createArrayOfArrays(), this runs in O(v) time because it creates->O(1) an array for each vertex. 
// Finally, the for loop in my main iterates over every edge and pushes->O(1) so it is O(e). Combined
// the run time is O(2e+v), and since coefficients are not considered, the algorithm for creating the
// adjacency lists is O(v+e). To display the lists, I have a nested for loop that iterates for every
// vertex, so the complexity of this is O(v^2). Although this is in my main, it does not contribute to 
// the creation of the adjacency lists and is only there to provide a visual representation.

// function declarations
void getNumberOfVerticesAndEdges(FILE* fp, int* vertices, int* edges);
void push(int** arrayOfArrays, int firstVertex, int secondVertex);
int** createArrayOfArrays(int numOfVertices);
void printAdjacencyLists(int** arrayOfArray, int vertices);

int main(void){
    // setting file pointer and error checking
    FILE *fptr = fopen("input-machine-problem-1.txt", "r");
    if (fptr == NULL) {
        printf("Error! opening file");
        return 0;
    }

    // defining variables to hold the value of the number of vertices and edges
    int edges;
    int vertices;
    int* edgesPtr = &edges;
    int* verticesPtr = &vertices;
    getNumberOfVerticesAndEdges(fptr, verticesPtr, edgesPtr);

    // setting file pointer back to the top
    if(fptr == NULL){
        return 0;
    }
    rewind(fptr);

    // creating an array of arrays
    int** arrayOfArrays = createArrayOfArrays(vertices);

    // form 36 - 43 I read an edge and push one vertex to the others adjacency list and vice versa
    int x, y;
    for(int i = 0; i < edges; i++){
        if(feof(fptr)){
            return 0;
        }
        fscanf (fptr, "%d %d", &x, &y);  
        push(arrayOfArrays, x, y);
        push(arrayOfArrays, y, x);
    }
    // print the lists
    printAdjacencyLists(arrayOfArrays, vertices);
    // close the file
    fclose(fptr); 
}

// insert secondVertex in firstVertex's list
void push(int** arrayOfArrays, int firstVertex, int secondVertex){
    arrayOfArrays[firstVertex - 1][secondVertex - 1] = secondVertex;
}

// create an array of arrays structure
int** createArrayOfArrays(int numOfVertices){
    int** array = malloc(sizeof(int*) * numOfVertices);
    for(int i = 0; i < numOfVertices; i++){
        int* newArray = malloc(sizeof(int) * numOfVertices);
        array[i] = newArray;
    }
    return array;
}

// scans through file and looks for greatest int and increments int holding num of edges for every new line of ints read
void getNumberOfVerticesAndEdges(FILE* fp, int* vertices, int* edges){
    if (fp == NULL) {
        printf("Error! opening file");
        return;
    } 
    *vertices = 0;
    *edges = 0;
    int x, y;
    while (fscanf(fp, "%d %d", &x, &y) == 2) {
        if(x > *vertices){
            *vertices = x;
        } if (y > *vertices){
            *vertices = y;
        }

        *edges = (*edges) + 1;
    }
}

// prints each vertex in the order of the indexes such that it appears ascending
void printAdjacencyLists(int** arrayOfArray, int vertices){
    for(int i = 0; i < vertices; i++){
        printf("%d: ", i + 1);
        for(int j = 0; j < vertices; j++){
            if(arrayOfArray[i][j] != 0){
                printf("%d, ", arrayOfArray[i][j]);
            }
        }
        printf("\n");
    }
}


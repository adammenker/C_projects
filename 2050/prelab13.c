#include <stdio.h>
#include <stdlib.h>


int compare(void *a, void *b);
int binarySearch(int array[], int firstIndex, int lastIndex, int query);

int main(void){

    int testArr[] = {1, 5, 35, 55, 67, 89, 99, 123, 234, 345, 576};
    int n = 11;

    int val = binarySearch(testArr, 0, n-1, 123);
}


int compare(void *a, void *b){
    printf("comparing %d to %d\n", *((int*) a), *((int*) b));
    if(*((int*) a) > *((int*) b)){ 
        return 1;
    }
    else if(*((int*) b) > *((int*) a)){
        return -1;
    }
    else{return 0;}
}


int binarySearch(int array[], int firstIndex, int lastIndex, int query){
    
    if(firstIndex > lastIndex){
        return -1; // the case where the query was not found int the array
    }

    int medianIndex = (firstIndex + lastIndex) / 2;
    // printf("**%d**\n\n\n", medianIndex);

    if(compare(&query, &array[medianIndex]) > 0){ // the case that query is greater than median value
        firstIndex = medianIndex + 1;
        return binarySearch(array, firstIndex, lastIndex, query);
    }
    else if(compare(&query, &array[medianIndex]) < 0){ // the case where query is less than median value
        lastIndex = medianIndex - 1;
        return binarySearch(array, firstIndex, lastIndex, query);
    }
    else if(compare(&query, &array[medianIndex]) == 0){ // the case where query == median value
        printf("\nfound at %d\n\n", medianIndex);
        return medianIndex;

    }
    return 0;

    // if(compare(&query, &array[medianIndex]) == 0)

}
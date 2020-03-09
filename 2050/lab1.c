# include <stdlib.h>
# include <stdio.h>

int addition(int arr[], int size); //function prototype

int main(void){    //start of program
    
    int size = 5;    
    int array[5] = {5,10,8,2,13}; //declaring array and size variable

    int sum = addition(array, size);  //calling function and assigning output to variable sum
    printf("\nArray is: ");
    int i;  
    for(i = 0; i < size; i++){ //looping to print all elements of array based on size of array
        printf("%d ", array[i]);
    }
    printf("\nSum is: %d\n\n", sum); //prints summed output 
    
    return 0;
}

int addition(int arr[], int size){
    int x = 0;
    int i;
    for(i = 0; i < size; i++){ // loops through array for every element and adds it to x
        x += arr[i];
    }
    return x; //returns x once summation is complete
}
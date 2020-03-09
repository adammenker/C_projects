#include <stdio.h>
#define ARRAY_SIZE 5


void EnterDistances(int array[], int size);
float AverageDistances(int array[], int size);
void PrintDistances(int array[], int size);

float average;

int main(void){
    int Distance[ARRAY_SIZE];
    printf("\n*** Welcome to the Average Disntances program ***\n\n");
    puts("Enter 5 distances:");
    EnterDistances(Distance, ARRAY_SIZE);
    AverageDistances(Distance, ARRAY_SIZE);
    PrintDistances(Distance, ARRAY_SIZE);
    printf("\nThe average Distance is %.2f\n\n", average);
    puts("*** Thank you for using the Average Distance program ***\n");
}

void EnterDistances(int array[], int size){
    int i;
    for(i = 0; i < size; i++){
        scanf("%d", &array[i]);
    }
}

float AverageDistances(int array[], int size){
    int i;
    float total;
    for(i = 0; i < size; i++){
        total += array[i];
        average = total / size;
    }
    return average;
}

void PrintDistances(int array[], int size){
    int i;
    printf("\nThe Distances being calculated are:\n");
    for(i = 0; i < size; i++){
        printf("%d  ", array[i]);
    }
    puts("");
}

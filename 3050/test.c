#include <stdio.h>
#include <stdlib.h>


int main(void){
    FILE *fptr = fopen("input-machine-problem-1.txt", "r");
    if (fptr == NULL) {
        printf("Error! opening file");
        return 0;
    }

    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 9; j++){
            int x;
            int y;
            fscanf(fptr, "%d %d", &x, &y);
            printf("%d %d\n", x, y);
        }
        rewind(fptr);
    }
}
#include <stdio.h>

void PromptAndGetInteger(char *message, int *x);
void PromptAndGetFloat(char *message, float *x);
void PromptAndGetString(char *message, char x[11]);
void PromptAndGetArray(char *message, int x[11]);
void PrintArray(int x[11]);

int main(void){
    int i;

    float f;

    char s[11];

    int a[11];

    printf("\n***********************\n");

    printf("* Welcome to Prelab 6 *\n");

    printf("***********************\n\n");

    PromptAndGetInteger("Please enter an integer and hit enter: ",&i);

    PromptAndGetFloat("Please enter a float and hit enter: ",&f);

    PromptAndGetString("Please enter a string with no spaces and hit enter: ",s);

    PromptAndGetArray("Please enter up to 10 positive integers, entering -1 to end: ", a);

    printf("\n***********************\n");

    printf("You entered %d,%f,%s\n",i,f,s);

    PrintArray(a);
}


void PromptAndGetInteger(char *message, int *x){
    printf("%s", message);
    scanf("%d", x);
}


void PromptAndGetFloat(char *message, float *x){
    printf("%s", message);
    scanf("%f", x);
}


void PromptAndGetString(char *message, char x[11]){
    printf("Please enter a string with no spaces and hit enter: ");
    scanf("%s", x);
}


void PromptAndGetArray(char *message, int x[11]){
    int i = 0;
    printf("%s", message);
    while(i < 11){
        printf("\tArray location %d: ", i);
        scanf("%d", &x[i]);
        if(x[i] == -1){
            x[i] = 0;
            break;
        }
        i++;
    }
}


void PrintArray(int x[11]){
    int i;
    for(i = 0; i < 11; i++){
        printf("Entry %d = %d\n", i, x[i]);
    }
}







;

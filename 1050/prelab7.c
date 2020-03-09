#include <stdio.h>

void GetString(char *str);
void GetLength(char *str, int *Ptr);
void SwitchString(char *str, int length);


int main(void){
    printf("\n*************************\n** Welcome to Prelab 7 **\n*************************\n\n");

    char string1[256];
    int len = 0;
    int *lenPtr = &len;

    GetString(string1);
    GetLength(string1, lenPtr);

    printf("You entered: %s\n", string1);
    printf("The string is %d in length\n", len);

    SwitchString(string1, len);

    printf("The switched string is: %s\n", string1);
    printf("That string is %d in length\n", len);

    printf("\n*******************************\n** Thanks for doing Prelab 7 **\n*******************************\n");
}


void GetString(char *str){
    printf("Type a string: \n");
    scanf("%s", str);
}


void GetLength(char *str, int *Ptr){
    for( ;*str != '\0'; str++){
        *Ptr += 1;
    }
}


void SwitchString(char *str, int length){
    char hold;
    hold = *str;
    *str = *(str + (length - 1));
    *(str + (length - 1)) = hold;
}
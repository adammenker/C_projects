#include <stdio.h>

void GetString(char *str);
void StringReplace(char *original, char *pattern, char *replacement);
void GetLength(char *str, int *Ptr);

int main(void){
    char originalstring[256];
    char patternstring[32];
    char replacement[32];

    printf("*** Welcome to Lab 7 ***\n\n");

    printf("Please enter the original string:\n");
    GetString(originalstring);
    printf("Original String = \"%s\"\n\n", originalstring);

    printf("Please enter the pattern:\n");
    GetString(patternstring);
    printf("Pattern String = \"%s\"\n\n", patternstring);

    printf("Please enter the replacement:\n");
    GetString(replacement);
    printf("Replacement String = \"%s\"\n\n", replacement);

    StringReplace(originalstring, patternstring, replacement);

    printf("The Resultant string is %s\n", originalstring);
    printf("*** Thanks for doing Lab 7 ***\n\n");
}


void GetString(char *str){
    scanf("%s", str);
}


void GetLength(char *str, int *Ptr){
    for( ;*str != '\0'; str++){
        *Ptr += 1;
    }
}


void StringReplace(char *original, char *pattern, char *replacement){
    for(int i = 0; *(original + i) != '\0'; i++){
        if(*(pattern) == *(original + i)){
            for(int x = 0; *(pattern + x) == *(original + i + x); x++){
                if(x == 1){  
                    *(original + i + (x - 1)) = *(replacement + (x - 1));
                    *(original + i + x) = *(replacement + x);
                }
                if(x >= 2){
                    *(original + i + x) = *(replacement + x);
                }
                 printf("%d", 9); 
            }      
        }
    }
}


#include <stdio.h>

void GetString(char *str);
//void StringReplace(char *original, char *pattern, char *replacement);
void GetLength(char *str, int *Ptr);
void FindPattern(char *original, char *pattern, int len, int *patternstart);
void WriteOverPattern(char *original, char *replacement, int index, int len);

int main(void){
    char originalstring[256];
    char patternstring[32];
    char replacement[32];

    int patternlocation = -1;
    int *patternindex = &patternlocation;

    int originallen = 0;
    int *origianllenPtr = &originallen;

    int patternlen = 0;
    int *patternlenPtr = &patternlen;

    int replacementlen = 0;
    int *replacementlenPtr = &replacementlen;

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

    GetLength(originalstring, origianllenPtr);
    GetLength(patternstring, patternlenPtr);
    GetLength(replacement, replacementlenPtr);

    FindPattern(originalstring, patternstring, patternlen, patternindex);

    WriteOverPattern(originalstring, replacement, patternlocation, replacementlen);

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


void FindPattern(char *original, char *pattern, int len, int *patternstart){
    for(int x = 0 ;*(original + x) != '\0'; x++){
        if(*(original + x) == *pattern){
            for(int i = 0; i < len; i++){
                if(*(original + x + i) != *(pattern + i)){
                    //printf("error\n");
                    //*patternstart = -1;
                    break; 
                }
                else{  
                    *patternstart = x; 
                }
            }
        }  
    }
}


void WriteOverPattern(char *original, char *replacement, int index, int len){
    for(int i = 0; i < len; i++){
        //len = 3;
        //printf("%d", len);
        *(original + index + i) = *(replacement + i);
    }
}

//StringReplace(originalstring, patternstring, replacement);
/*
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
*/

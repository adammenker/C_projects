#include <stdio.h>
#include <ctype.h>
#include <string.h>


void PrintCategory(char *s);
int CheckNum(char *s);
int CheckUpper(char *s);
int CheckLower(char *s);



int CheckNum(char *s){
    int i = 0;
    int check = 0;
 
    while(isdigit(*(s + i))){
        i++;
        check++;
    }
    if(check == strlen(s)){
        return 1;
    }
    else{
        return 0;
    }
}


int CheckLower(char *s){
    int i = 0;
    int check = 0;

    while(islower(*(s + i))){
        i++;
        check++;
    }
    if(check == strlen(s)){
        return 1;
    }
    else{
        return 0;
    }
    printf("%d %lu", check, strlen(s));
}


int CheckUpper(char *s){
    int i = 0;
    int check = 0;

    while(isupper(*(s + i))){
        i++;
        check++;
    }
    if(check == strlen(s)){
        return 1;
    }
    else{
        return 0;
    }
}


void PrintCategory(char *s){
    if(CheckLower(s)){
        printf("%s is all lower case.\n", s);
    }
    else if(CheckUpper(s)){
        printf("%s is all upper case.\n", s);
    }
    else if(CheckNum(s)){
        printf("%s is all digits.\n", s);
    }
    else{
        printf("%s is a mix of various types of characters.\n", s);
    }
}



#include <stdio.h>

void welcome(void);
void scanStr(char string[256]);
int calcSegs(char string[256]);
void displayString(char str[]);

int main(void){

    welcome();

    char str[256]; 

    scanStr(str);
    printf("you entered %s\n", str);

    int segs = calcSegs(str);
    printf("there are %d segment in the string\n", segs);

}

void welcome(void){
    printf("\n***Welcome to lab 7***\n\n");
}


void scanStr(char string[256]){
    printf("please enter a string: ");
    scanf("%s", string);
}


int calcSegs(char string[256]){
    int counter = 0;
    char* ptr = string;

    while(*ptr != *("")){ // this is the complex the thing
        counter++;
        ptr++;
    }

    if(counter % 3 == 0){
        counter = counter / 3;
        return counter;
    }
    else{
        counter = (counter / 3) + 1;
        return counter;
    }
}


void displayString(char str[]) {
  printf("String: %s\n", str);
}


void reverseString(char* string, int segments){ // im bored of this, you just have to implement a way to reverse each segment of the string, so far you have the users unputted string and the number of segments, so I was going to do a for loop that made a new string based of the 3 letters of a segment, reversed that and then assigned the corresponding 3 letter of the original string to the new string. You should be able to igure out how to do this, its less about string and more about pointer/arithmetic, good luck.
    int i;
    for(i = 0; i < segments; i++){
        char* segptr = 
    }

}


// nrrauschenbach@gmail.com

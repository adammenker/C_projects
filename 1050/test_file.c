#include <stdio.h>
#include <ctype.h>


int main(void){
    char * s = "1234";
    int a = atoi(*s);
    printf("%d", s);
}
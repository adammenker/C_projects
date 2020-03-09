#include <stdio.h>
#include <stdlib.h>

int IsLowest(int a, int b, int c, int d);
void t(void);

int main(void){
    int total = 0;
    t();
    printf("%d\n", total);
}

void t(void){
    int rolls[4] = {1,1,1,1};
    int total = 0;
    int *totalptr = &total;
    for(int i = 0; i < 4; i++){
         *totalptr += rolls[i];
    }
    int low = IsLowest(rolls[0], rolls[1], rolls[2], rolls[3]);
    *totalptr -= low;
    printf("%d\n", total);
}

int IsLowest(int a, int b, int c, int d){
    if(a <= b){
        if(a <= c){
            if(a <= d){
                return a;
            }
        }
    }
    if(b <= a){
        if(b <= c){
            if(b <= d){
                return b;
            }
        }
    }
    if(c <= a){
        if(c <= b){
            if(c <= d){
                return c;
            }
        }
    }
    return d;

}

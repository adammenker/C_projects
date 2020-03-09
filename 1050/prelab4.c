#include <stdio.h>
#include <math.h>

double base, x;
int exponent, i, z;

double MyPower(double base, int exponent);
void DoTest(double base, int exponent);


double MyPower(double base, int exponent){
    double x = 1;
    for(z = 0; z < exponent; z++){
        x *= base;
    }
    return x;
}

int main(void){
    int i, j;
    for(i = 1; i < 5; i++){
        for(j = 1; j < 5; j++){
            DoTest(i,j);
        }
    }
}


void DoTest(double base, int exponent){
    double test1 = MyPower(base, exponent);
    double pow_result = pow(base, exponent);
    if(test1 == pow_result){
        printf("Testing %f to the %d power\n", base, exponent);
    }
    else{
        printf("%f to the %d is %f, result is %f\n", base, exponent, pow_result, test1);
    }
}

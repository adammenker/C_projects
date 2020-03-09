#include <stdio.h>


int x;
int amount = 0;

int years = 0;

float stock_market = 0.08;
float savings_account = 0.001;
float govt_issued_bond = 0.019;


void Welcome(void);
void futureValueScan(void);
int futureValueCalc(float method, int time);
void testInput(int x);


// initialize variables that reflect interest rates of markets so that they can be changed easily in one place and the program will still work
// this inlcludes years, markets to save money, CPI of goods to buy, possibly a salary function


//functions
// includes what you want to buy, data displays of bls.gov, how much you want to spend, compound interest function


int main(void){
    Welcome();

    futureValueScan();

    futureValueCalc(stock_market, years);
    printf("%d\n", amount);

}


void Welcome(void){
    printf("\nWelcome to the Budgetting application, in this program you will be "
          "able to \n\n**calculate the future value of your money invested in a "
          "variety of markets**\n\nor\n\n**calculate how much money you will need in "
          "the future to purchase a good in a ceratain market**\n\nType 1 for the "
          "first option or 2 for the second option\n\n");
    scanf("%d", &x);
}

int futureValueCalc(float method, int time){
    for(int i = 0;i < years;i++){
        amount *= (1 + method);
    }
    return amount; // needs to pass value back to address of amount
}

void futureValueScan(void){
    printf("how much money:\n");
    scanf("%d", &amount);
    printf("how many years:\n");
    scanf("%d", &years);
}

void testInput(int x){
    while(x != 1 && x != 2){
        printf("Invalid input, try again:\n");
        scanf("%d", &x);
        if(x == 1){ // change to while loop
            futureValueCalc(stock_market, years);
        }
        else if(x == 2){
            //buy budget function
        }
    }
}








;

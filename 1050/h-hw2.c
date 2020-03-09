#include <stdio.h>
#include <stddef.h>
#define SIZE 3

/* Prototypes */

void PrintAtBats(int atbats[]);
void CalculateBattingAverage(int atbats[], float avg[], int indexToCalculate);
void CalculateSluggingPercentage(int atbats[], float pct[], int indexToCalculate);
void PrintResult(float result[]);
void DoCalculations(int atbats1[], int atbats2[], int atbats3[], float battingavg[], float sluggingpct[]);

/* start of program */
int main(void){
    int player1[] = {0,1,0,1,2,0,0,0,0,-1}; //data set
    int player2[] = {3,0,1,0,0,4,0,0,1,0,0,0,0,0,-1};
    int player3[] = {0,0,0,4,2,0,0,0,0,0,1,-1};

    float battingavg[SIZE]; //initializing arrays
    float sluggingpct[SIZE];

    puts("");

    puts("Player 1 at-bats:"); // print statement that show data in player arrays
    PrintAtBats(player1);

    puts("Player 2 at-bats:");
    PrintAtBats(player2);

    puts("Player 3 at-bats:");
    PrintAtBats(player3);

    puts("");

    DoCalculations(player1, player2, player3, battingavg, sluggingpct); //calls function so values are set

    printf("%s\n", "Batting Averages:");
    PrintResult(battingavg); // prints values for batting average

    printf("%s\n", "Slugging Percentages:");
    PrintResult(sluggingpct); // prints values for slugging percentage

}


/* Function Implementations */
void PrintAtBats(int atbats[]){ //prints at each players array in the specified format
    int i;
    for(i = 0; atbats[i] >= 0; i++){
        printf("%d ", atbats[i]);
    }
    puts("\n");
}

void CalculateBattingAverage(int atbats[], float avg[], int indexToCalculate){ // calcualtes batting average
    int i;
    float x = 0;
    float y = 0;
    for(i = 0; atbats[i] >= 0; i++){ // loops through for each item of the array until it reacher -1
        x++; // increments x for every item in the array
        if(atbats[i] > 0){
            y++; // increments y for every 'hit' to total the number of hits in the array
        }
    }
    avg[indexToCalculate] = y / x;
}


void CalculateSluggingPercentage(int atbats[], float pct[], int indexToCalculate){ // calculates slugging average
    int i;
    float x = 0;
    float y = 0;
    for(i = 0; atbats[i] >= 0; i++){
        x++; // incrememnts x for every item in the array
        y += atbats[i]; // loops through each integer int the array up to -1 and adds it to y
    }
    pct[indexToCalculate] = y / x; // divided y by the total amount of items in the array
}


void DoCalculations(int atbats1[], int atbats2[], int atbats3[], float battingavg[], float sluggingpct[]){ // calculates the batting avg and slugging pct values for each player
    CalculateBattingAverage(atbats1, battingavg, 0); // assigns each value to the corresponding array and index
    CalculateBattingAverage(atbats2, battingavg, 1);
    CalculateBattingAverage(atbats3, battingavg, 2);
    CalculateSluggingPercentage(atbats1, sluggingpct, 0);
    CalculateSluggingPercentage(atbats2, sluggingpct, 1);
    CalculateSluggingPercentage(atbats3, sluggingpct, 2);
}

void PrintResult(float result[]){ // prints values calculated in above function to the corresponding player
    printf("%19s %.3f\n", "Player 1: ", result[0]); 
    printf("%19s %.3f\n", "Player 2: ", result[1]);
    printf("%19s %.3f\n", "Player 3: ", result[2]);
    puts("");
} // end of program





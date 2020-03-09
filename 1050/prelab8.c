#include <stdio.h>

/* all of this is in main(prelab8).c
// Symbolic Constants
#define DIGITTEST1 "12345abcd67890"

#define DIGITTEST2 "1234567890"

#define LOWERTEST1 "hifromJimRies"

#define LOWERTEST2 "hifromjimries"

#define UPPERTEST1 "JIMRIESWASHERE"

#define UPPERTEST2 "JIMRIESWASHERe"

// Prototypes
void PrintCategory(char *s);

// Main
int main(void)
{
    PrintCategory(DIGITTEST1);

    PrintCategory(DIGITTEST2);

    PrintCategory(LOWERTEST1);

    PrintCategory(LOWERTEST2);

    PrintCategory(UPPERTEST1);

    PrintCategory(UPPERTEST2);
}
*/


void TestLower(char *str, int *Ptr);
void TestUpper(char *str, int *Ptr);
void TestNumeral(char *str, int *Ptr);
void TestAscii(char *s);

int testvallower = 0;
int *PtrTestValLower = &testvallower;

int testvalupper = 0;
int *PtrTestValUpper = &testvalupper;

int testvalnum = 0;
int *PtrTestValNum = &testvalnum;


void TestLower(char *str, int *Ptr){
    for(int i = 0; *(str + i) != '\0'; i++){
        int x = *(str + i);
        if(x >= 97 && x <= 122){
            *Ptr = 1;
        }
        else{
            *Ptr = -1;
            break;
        }
    }
}


void TestUpper(char *str, int *Ptr){
    for(int i = 0; *(str + i) != '\0'; i++){
        int x = *(str + i);
        if(x >= 65 && x <= 90){
            *Ptr = 1;
        }
        else{
            *Ptr = -1;
            break;
        }
    }
}


void TestNumeral(char *str, int *Ptr){
    for(int i = 0; *(str + i) != '\0'; i++){
        int x = *(str + i);
        if(x >= 48 && x <= 57){
            *Ptr = 1;
        }
        else{
            *Ptr = -1;
            break;
        }
    }
}


void TestAscii(char *s){
    TestLower(s, PtrTestValLower);
    TestUpper(s, PtrTestValUpper);
    TestNumeral(s, PtrTestValNum);
}


void PrintCategory(char *s){
    TestAscii(s);
    printf("%s ", s);
    if(testvallower == 1){
        printf("is all lower case.\n");
    }
    else if(testvalupper == 1){
        printf("is all upper case.\n");
    }
    else if(testvalnum == 1){
        printf("is all digits.\n");
    }
    else{
        printf("is a mix of various types of characters.\n");
    }
}



#include <stdio.h>
#include <stdlib.h>

// prototypes
void GetFixedField(char * in, int size, FILE * fp);
void OrderedFields(FILE * fp, char *a, char *b, char *c, char *d, char *e);
//void IfSpace(FILE *fp);
void PrintOutput(char * last, char * first, char * key, char * ans, float score);
void CalcScore(char * key, char * ans, float score);



int main(void){ // star program
    char firstname[16];
    char lastname[16];
    char studentnumber[16];
    char key[16];
    char answers[40];
    FILE * fptr;
    fptr = fopen("lab9.txt", "r");

    if (NULL==fptr){
        printf("**Error:  Could not open prelab9.csv\n");
    }
    else{
        OrderedFields(fptr, studentnumber, key, lastname, firstname, answers);
    }
    fclose(fptr);
}



void OrderedFields(FILE * fp, char *a, char *b, char *c, char *d, char *e){ // gets field and prints output
char *buffer = e;
int y = 0;
    while(!feof(fp)){
        GetFixedField(a, 12, fp);
        GetFixedField(b, 8, fp);
        GetFixedField(c, 11, fp);
        GetFixedField(d, 12, fp);
        GetFixedField(e, 40, fp);
        
        if(y == 1){
            buffer = e;
        }
        y++;  
        //printf("\n\n%s\n\n", buffer);

        float score = 0;
        CalcScore(buffer, e, score);
        PrintOutput(c, d, b, e, score);
    } 
}




void GetFixedField(char * in, int size, FILE * fp){ // JIMR fucntion that scans
    int i;  
    for(i = 0; i < size; i++){
        in[i] = fgetc(fp);
    }
    in[i] = '\0';
    //printf("%s\n", in); 
    //IfSpace(fp);
}

/*
void IfSpace(char *in){
    char c = in[0]; 
    while(c == ' '){
        c = fgetc(fp);        
    }
}
*/


void PrintOutput(char * last, char * first, char * key, char * ans, float score){ //supposed to print output
    printf("%s    %s :\n    %s\n    %f\n", first, last, ans, score);
}   


void CalcScore(char * key, char * ans, float score){ // supposed to calculate score
    int counter = 0;
    for(int z = 0; z < 40; z++){
        if(key[z] == ans[z]){
            counter++;
        }
    }
    score = (counter / 40) * 10;
}
            





;

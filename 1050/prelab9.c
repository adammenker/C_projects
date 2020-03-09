#include <stdio.h>
#include <stdlib.h>

void GetNextCSVField(FILE * fp, char * ouptut);

int main(void){
    char firstname[16];
    char lastname[16];
    char studentnumber[16];
    char pawprint[16];
    char buffer[16];
    double score;
    FILE * fptr;
    fptr = fopen("prelab9.csv", "r");

    if (NULL==fptr){
        printf("**Error:  Could not open prelab9.csv\n");
    }
    else{
        while(!feof(fptr)){
            GetNextCSVField(fptr, lastname);
            if(!feof(fptr)){
                GetNextCSVField(fptr, firstname);
                GetNextCSVField(fptr, studentnumber);
                GetNextCSVField(fptr, pawprint);
                GetNextCSVField(fptr, buffer);
                score = atof(buffer);

                printf("FirstName=%s,LastName=%s,StudentNumber=%s,Pawprint=%s,Score=%f\n", 
                    firstname, lastname, studentnumber, pawprint, score);
            }
        }
    }
    fclose(fptr);
}


void GetNextCSVField(FILE * fp, char * output){
    char c = fgetc(fp);
    while(!feof(fp) && (c != ',' && c != '\n')){
        *output = c;
        output++;
        c = fgetc(fp);
    }
    *output = '\0';
}
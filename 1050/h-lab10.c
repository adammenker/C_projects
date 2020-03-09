#include <stdio.h>
#include <stdlib.h>

struct _Player{
    char LastName[16];
    char FirstName[16];
    char Team[16];
    int Year;
    float BA;
    float OBP;
    float SP;
};
typedef struct _Player Player;

void PrintPlayers(Player player[], int count);
void SortPlayersSP(Player player[], int count);
void SortPlayersBA(Player player[], int count);
void SortPlayersOBP(Player player[], int count);
void FilterYear(Player player[], Player yearfil[], int count, int year);
int CheckMenuChoice(int choice);
int Menu(void);
void Start(int selection, Player player[], Player yearfil[], int count, int z, int year);


int main(int argc, char *argv[]){
    char filename[20];
    char *filenameptr = filename;
    filenameptr = argv[1];
    FILE *fp;
    fp = fopen(filenameptr, "r");
    Player player[24];
    Player yearfil[24];
    int count = 0;
    int selection = 0;
    int z = -1;
    int year =0;

    if(argc == 3){
        year = atoi(argv[2]);
    }
    printf("%d", year);

    if(fp == NULL){
        printf("ERROR: FILE could not be opened");
    }
    else{
        while(!feof(fp)){
            if(7 == (fscanf(fp, "%s %s %d %s %f %f %f", 
                player[count].LastName,
                player[count].FirstName,
                &(player[count].Year),
                player[count].Team,
                &(player[count].BA),
                &(player[count].OBP),
                &(player[count].SP))))
            {
                count++;
            }
        }
        fclose(fp);
        Start(CheckMenuChoice(Menu()), player, yearfil, count, z, year);
    }
}


void PrintPlayers(Player player[], int count){
    printf("%16s %16s %16s %16s %16s %16s %16s\n", 
    "First Name", "Last Name", "Team", "Year", "Batting Avg", "On Base Pct", "Slugging Pct");
    for(int i = 0; i < count; i++){
        printf("%16s %16s %16s %16d %16.3f %16.3f %16.3f\n",                
        player[i].FirstName,                
        player[i].LastName,                
        player[i].Team,                
        player[i].Year,                
        player[i].BA,                
        player[i].OBP,                
        player[i].SP);
    }
}


void SortPlayersSP(Player player[], int count){
    for(int i = 1; i < count; i++){
        for(int j = 0; j < count; j++){
            Player temp;
            if(player[j].SP < player[j+1].SP){
                temp = player[j];
                player[j] = player[j+1];
                player[j+1] = temp;
            }
        }
    }
}


void SortPlayersBA(Player player[], int count){
    for(int i = 1; i < count; i++){
        for(int j = 0; j < count; j++){
            Player temp;
            if(player[j].BA < player[j+1].BA){
                temp = player[j];
                player[j] = player[j+1];
                player[j+1] = temp;
            }
        }
    }
}


void SortPlayersOBP(Player player[], int count){
    for(int i = 1; i < count; i++){
        for(int j = 0; j < count; j++){
            Player temp;
            if(player[j].OBP < player[j+1].OBP){
                temp = player[j];
                player[j] = player[j+1];
                player[j+1] = temp;
            }
        }
    }
}


void FilterYear(Player player[], Player yearfil[], int count, int year){
    printf("Enter the filter year: ");
    scanf("%d", &year);
    while(year != 2017 && year != 2018 && year != 2019){
        printf("Error: Invalid year, try again: ");
        scanf("%d", &year);
    }
    int x = 0;
    for(int i = 0; i < count; i++){
        if(player[i].Year == year){
            yearfil[x] = player[i];
            x++;
        }
    }
}


int Menu(void){
    int choice = -1;
    printf("*************************\n* Menu\t\t\t*\n*************************\n"
           "1. Print Player Records\n"
           "2. Sort by Batting Average\n"
           "3. Sort by On-base Percentage\n"
           "4. Sort by Slugging Percentage\n"
           "5. Filter by Year\n"
           "6. Exit\n"
           );
    scanf("%d", &choice);
    return choice;
}

int CheckMenuChoice(int choice){ 
    if(choice < 6 || choice > 1){
        return choice;
    }
    if(choice > 6 || choice < 1){
        printf("\n*** Error: selection must be 1-5 ***\n\n");
        return CheckMenuChoice(Menu()); 
    } 
    return choice;
}


void Start(int selection, Player player[], Player yearfil[], int count, int z, int year){
    while(selection > 7 || selection < 1){
        printf("Error, Try again: ");
        scanf("%d", &selection);
    }
    switch(selection){
        case 1:
            if(z == -1){
                PrintPlayers(player, count);
            }
            if(z == 1){
                PrintPlayers(yearfil, 5);
            }
            puts("");
            Start(CheckMenuChoice(Menu()), player, yearfil, count, z, year);
            break;
        case 2:
            if(z == -1){
                SortPlayersBA(player, count);
            }
            if(z == 1){
                SortPlayersBA(yearfil, 5);
            }
            puts("");
            Start(CheckMenuChoice(Menu()), player, yearfil, count, z, year);
            break;
        case 3:
            if(z == -1){
                SortPlayersOBP(player, count);
            }
            if(z == 1){
                SortPlayersOBP(yearfil, 5);
            }
            puts("");
            Start(CheckMenuChoice(Menu()), player, yearfil, count, z, year);
            break;
        case 4:
            if(z == -1){
                SortPlayersSP(player, count);
            }
            if(z == 1){
                SortPlayersSP(yearfil, 5);
            }
            puts("");
            Start(CheckMenuChoice(Menu()), player, yearfil, count, z, year);
            break;
        case 5:
            printf("%d", year);
            z = 1;
            FilterYear(player, yearfil, count, year);
            puts("");
            Start(CheckMenuChoice(Menu()), player, yearfil, count, z, year);
            break;
    }
}

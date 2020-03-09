#include <stdio.h>


struct _Player{
    char LastName[16];
    char FirstName[16];
    char Team[16];
    int Year;
    float BA;
    float OBA;
    float SP;
};
typedef struct _Player Player;


void PrintPlayers(Player player[], int count);
void SortPlayers(Player player[], int count);


int main(void){
    FILE *fp;
    fp = fopen("prelab10.dat", "r");
    Player player[24];
    int count = 0;

    if(fp == NULL){
        printf("ERROR");
    }
    else{
        while(!feof(fp)){
            if(7 == (fscanf(fp, "%s %s %d %s %f %f %f", 
                player[count].FirstName,
                player[count].LastName,
                &(player[count].Year),
                player[count].Team,
                &(player[count].BA),
                &(player[count].OBA),
                &(player[count].SP))))
            {
                count++;
            }
        }
        fclose(fp);
        printf("*** Initially:\n\n");
        PrintPlayers(player, count);
        printf("\n*** Sorted by Slugging Pct:\n\n");
        SortPlayers(player, count);
        PrintPlayers(player, count);

    }
}


void SortPlayers(Player player[], int count){
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
        player[i].OBA,                
        player[i].SP);
    }
}
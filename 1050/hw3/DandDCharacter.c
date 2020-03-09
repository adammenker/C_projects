#include "DandDCharacter.h"

void GenerateCharacter(Character * pCharacter) // sets seed to generate random numbers and assigns random int to each attribute
{
    SetSeed(-1);
    pCharacter->strength = GetScore();
    pCharacter->dexterity = GetScore();
    pCharacter->constitution = GetScore();
    pCharacter->intelligence = GetScore();
    pCharacter->wisdom = GetScore();
    pCharacter->charisma = GetScore();
}

void DisplayCharacter(Character * pCharacter) // properly prints out attributes in desired format
{
    char *anc[6] = {"human", "elf", "halfling", "dwarf", "half_elf", "half_orc"};
    printf("*********************************************************\n"
           "%s %53s *\n%s %50s *\n"
           "*********************************************************\n"
           "%s %43d *\n%s %42d *\n%s %39d *\n%s %39d *\n%s %45d *\n%s %43d *\n%s %43s *\n"
           "*********************************************************\n\n\n", "*", 
           pCharacter->charname, "* By", pCharacter->playername, "* Strength:", pCharacter->strength, 
           "* Dexterity:", pCharacter->dexterity, "* Constitution:", pCharacter->constitution, "* Intelligence:", pCharacter->intelligence,
           "* Wisdom:", pCharacter->wisdom, "* Charisma:", pCharacter->charisma, "* Ancestry:", anc[pCharacter->ancestry]);
}

void SaveCharacter(Character * pCharacter) // writes data to a new file to save it
{
    char filename[20];
    printf("Enter name of file to save (extension will automatically be .character): "); // prompt for file name
    scanf("%s", filename);
    strcat(filename,".character"); // makes filename a .character file
    FILE * fptr; 
    fptr = fopen(filename, "w");
    fprintf(fptr, "%s %s %d %d %d %d %d %d %d", pCharacter->charname, pCharacter->playername, pCharacter->strength, 
           pCharacter->dexterity, pCharacter->constitution, pCharacter->intelligence,
           pCharacter->wisdom, pCharacter->charisma, pCharacter->ancestry); // writes data into the new file
    fclose(fptr); 
}

void LoadCharacter(Character * pCharacter, char * filename)
{
    FILE * fptr;
    if((fptr = fopen(filename, "r")) == NULL){
        printf("***Error: Could not open file %s\n", filename); // checks if file exists and prints error if it doesn't
    }
    else{
        fscanf(fptr, "%s %s %d %d %d %d %d %d %d", pCharacter->charname, pCharacter->playername, &pCharacter->strength, &pCharacter->dexterity, 
            &pCharacter->constitution, &pCharacter->intelligence, &pCharacter->wisdom, &pCharacter->charisma, &pCharacter->ancestry);
        fclose(fptr);  // reads data from file into attributes if file exists 
    }  
}

int DisplayMenu() // displays the menu in proper format and returns user selection
{
    int selection=(-1);
    printf("Main Menu\n---------\n\n1) Generate New Character\n2) Save Current Character\n3) Load a Previously Saved Character\n"
           "4) Display Current Character\n5) Exit\n\nEnter a selection: ");
    scanf("%d", &selection);
    return selection;
}

//////////////////Additonal Functions///////////////////

int CheckMenuChoice(int choice){ // error checks if user input is outside of range
    if(choice > 5 || choice < 1){
        printf("*** Error: selection must be 1-5 ***\n");
        return CheckMenuChoice(DisplayMenu()); // recursively calls function until user input is in range
    } 
}


int IsLowest(int a, int b, int c, int d){ // returns lowest of the four dice
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


int GetScore(void){ // calculates the score of an attribute
    int rolls[4] = {0};
    int total = 0;
    int i = 0;  // declaration outside for bc 'make' is not in C99
    for(; i < 4; i++){
        rolls[i] = RollD6();
        total += rolls[i];
    }
    int low = IsLowest(rolls[0], rolls[1], rolls[2], rolls[3]); // finds lowest die and removes it from score
    total -= low;
    return total;
}


void GetAncestry(Character * pCharacter){ // reads user input and assigns ancestry
    int choice = -1;
    printf("Select an ancestry from this list:\n0) human\n1) elf\n2) halfling\n3) dwarf\n4) half_elf\n5) half_orc\n");
    scanf("%d", &choice);
    switch(choice){
        case 0 :
            pCharacter->ancestry = human;
            break;
        case 1 :
            pCharacter->ancestry = elf;
            break;
        case 2 :
            pCharacter->ancestry = halfling;
            break;
        case 3 :
            pCharacter->ancestry = dwarf;
            break;
        case 4 :
            pCharacter->ancestry = half_elf;
            break;
        case 5 :
            pCharacter->ancestry = half_orc;
            break;
        default :
             // error checking and recursively calls function until input is in range
            GetAncestry(pCharacter);
    }
}


void GetNames(Character * pCharacter){ // prompts user for name input and assigne it into structure
    printf("Please Enter Your Character's Name (no spaces): ");
    scanf("%s", pCharacter->charname);
    printf("Please Enter Your Name (no spaces): ");
    scanf("%s", pCharacter->playername);
}



void GetFileNameLoad(char * file){ // prompts user for file they want loaded
    printf("Enter name of file to load (extension will automatically be .character): ");
    scanf("%s", file);
    strcat(file,".character"); // formats it into a .character string
}


void OrderOne(Character * pCharacter){ // functions to be called if user selects '1' from menu
    GetAncestry(pCharacter);
    GetNames(pCharacter); 
    GenerateCharacter(pCharacter); 
}

void OrderTwo(Character * pCharacter){ // functions to be called if user selects '2' from menu 
    SaveCharacter(pCharacter);
}

void OrderThree(Character * pCharacter, char * filename){ // functions to be called if user selects '3' from menu
    char * filenameptr = filename;
    GetFileNameLoad(filenameptr);
    LoadCharacter(pCharacter, filename);
}

void OrderFour(Character * pCharacter){ // functions to be called if user selects '4' from menu
    DisplayCharacter(pCharacter);
}


void Start(int selection, Character * pCharacter, char * filename){ // checks what user input in menu and runs corresponding functions
    if(selection == 0){
        Start(CheckMenuChoice(DisplayMenu()), pCharacter, filename); // starts over again after task is complete
    }
    if(selection == 1){
        OrderOne(pCharacter);
        printf("\n\n");
        selection = 0; // assigns selection to 0 so that function will start over again once task is complete
        Start(selection, pCharacter, filename);
    }
    else if(selection == 2){
        OrderTwo(pCharacter);
        printf("\n\n");
        selection = 0;
        Start(selection, pCharacter, filename);
    }
    else if(selection == 3){
        OrderThree(pCharacter, filename);
        printf("\n\n");
        selection = 0; 
        Start(selection, pCharacter, filename);
    }
    else if(selection == 4){
        OrderFour(pCharacter);
        selection = 0;
        Start(selection, pCharacter, filename);
    }
    else if(selection == 5){
        puts("\nThanks for playing!!"); // end of program 
    }
}


#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "Random.h"
#include "DandDCharacter.h"

int main(int argc, char *argv[])
{
    char filename[20]; //creates a string to hold the name of the file used to load and save
    char * filenameptr = filename;

    struct _Character aCharacter;
    
    Character * aCharacterptr = malloc(sizeof(Character)); // dynamically allocates memory for structure
   
    strcpy(aCharacter.charname, ""); // initializes all the attributes of the structure to blank space or 0
    strcpy(aCharacter.playername, "");
    aCharacter.strength = 0;
    aCharacter.dexterity = 0;
    aCharacter.constitution = 0;
    aCharacter.intelligence = 0;
    aCharacter.wisdom = 0;
    aCharacter.charisma = 0;
    aCharacter.ancestry = 0;

    if(argc == 2){ // checks if file was specified on the command line as an argument and loads it
        filenameptr = argv[1];
        LoadCharacter(aCharacterptr, filenameptr);
    }

    printf("\n***I am attempting the bonus***\n\n");

    Start(CheckMenuChoice(DisplayMenu()), aCharacterptr, filename); // start of program functionality

    free(aCharacterptr); // frees allocated memory
}


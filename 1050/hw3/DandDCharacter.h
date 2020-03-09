///////Addtional headers//////
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // includes libraries required
#include "Random.h"
/////////////////////////////

#ifndef _DandDCharacter
/*****************************************************************************
  DandDCharacter.h
  By Jim Ries
  Version 1.0, September 16, 2019
  Version 1.1, November 6, 2019
 *****************************************************************************/
#define _DandDCharacter

// Data types
typedef enum _Ancestry 
{
  human, elf, halfling, dwarf, half_elf, half_orc
} Ancestry;

typedef struct _Character
{
    int strength;
    int dexterity;
    int constitution;
    int intelligence;
    int wisdom;
    int charisma;

    Ancestry ancestry;
    char charname[256];
    char playername[256];
} Character;

// Functions
void GenerateCharacter(Character * pCharacter);               // Fills out the Character with newly generated data
void DisplayCharacter(Character * pCharacter);                // Displays the Character to the screen
void SaveCharacter(Character * pCharacter);                   // Saves the Character to disk
void LoadCharacter(Character * pCharacter, char * filename);  // Loads the Character from disk
int DisplayMenu();                                            // Returns the # of the menu item chosen


////Additional Functions////
// Descriptions of all the functions are in comments on DandDCharacter.c
int CheckMenuChoice(int choice); 
int IsLowest(int a, int b, int c, int d);
int GetScore(void);
void GetAncestry(Character * pCharacter);
void GetNames(Character * pCharacter);
void GetFileNameLoad(char * file);
void OrderOne(Character * pCharacter);
void OrderTwo(Character * pCharacter);
void OrderThree(Character * pCharacter, char * filename);
void OrderFour(Character * pCharacter);
void Start(int selection, Character * pCharacter, char * filename);
////////////////////////////

#endif  // _DandDCharacter

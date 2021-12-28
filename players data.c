#include <stdio.h>
#include <string.h>
#include <string.h>
#include <ctype.h>
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#include"game_functions.h"
#include"interfaces1234.h"

void printData()
{
    player palyer1,player2;
     /*collecting this data in a structure (typedef struct player{  };player*/
    printf(ANSI_COLOR_CYAN "\n    player 1 name:");
    printf(ANSI_COLOR_YELLOW"\t\t\t\t\t\t\t player 2 name:\n\n");
    printf(ANSI_COLOR_CYAN"    Number of moves for player 1:");
    printf(ANSI_COLOR_YELLOW"\t\t\t\t\t Number of moves for player 2: \n\n");
    printf(ANSI_COLOR_CYAN "    player 1's score = ");
    printf(ANSI_COLOR_YELLOW"\t\t\t\t\t\t\t player 2's score = \n\n"ANSI_COLOR_RESET);
    printf("    Number of remaining lines: \t\t\t\t\t\t Time passed:\n");
}


//structure including data to be saved

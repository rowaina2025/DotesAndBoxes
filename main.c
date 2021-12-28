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


int main()
{
    Interface1();
    system("COLOR");
    return 0;
}

//void OnePlayer()
//{

  //  strcpy(player2.name,"Computer");
  //printf("\n\n\t\t\tEnter your Name: ");
   // fgets(player1.name,sizeof(player1.name),stdin);// I wrote it twice because it didn't work from the first time
    //fgets(player1.name,sizeof(player1.name),stdin);
    //puts(player1.name);
//}

//void TwoPlayer()
//{
  //  gets(player1.name);// I wrote it twice because it didn't work from the first time
    //printf("\n\n\t\t\tEnter player 1's name: ");
   // gets(player1.name);
    //puts(player1.name);
    //printf("\n\n\t\t\tEnter player 2's name: ");
    //gets(player2.name);
    //puts(player2.name);
//}

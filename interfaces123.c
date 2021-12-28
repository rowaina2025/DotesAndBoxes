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
void Interface1()
{
    system("COLOR");
    printf(ANSI_COLOR_GREEN "\n\n\tNew game(enter 1): \n\n\tLoad game(enter 2): \n\n\tExit(enter 3)\n\n\tTop Ten(enter 4):\n\n\tEnter the choice: ");
    int choice=0;
    scanf("%d",&choice);
    while(!(choice==1||choice==2||choice==3||choice==4))
    {
        system("cls");
        printf(ANSI_COLOR_CYAN"(Invalid Input)"); printf(ANSI_COLOR_GREEN"\nNew game(enter 1): \nLoad game(enter 2): \nExit(enter 3)\nTop Ten(enter 4):\nEnter the choice: ");
        scanf("%d",&choice);
    }
   switch(choice){
    case 1:{system("cls"); oneOrTwoPlayers(); break;}
    case 2:{system("cls"); printf("load"); break;}
    case 3:{system("cls"); printf("exit"); break;}
    case 4:{system("cls"); printf("top"); break;}

   }
}
void oneOrTwoPlayers()
{
  start:
  printf("1 player(VS COMPUTER)[Enter 1]\n");
  printf("2 players(VS PERSON) [Enter 2]\n\nYou Choice: ");
  int noOfPlayers;
  scanf("%d",&noOfPlayers);
  while(!(noOfPlayers==1||noOfPlayers==2))//check the validity of the input
  {
    system("cls");
    goto start;
  }
  if(noOfPlayers ==1)
  {
    twoPlayer();//should be onePlayer function but not finished jet
  }
  else if (noOfPlayers ==2)
  {
    twoPlayer();
  }
}


void twoPlayer()
{
    start:
    printf("\t\nEnter difficulty:\n\tEasy(enter 1)\n\tMeduim(enter 2)\n\tHard(enter 3)\n\n\tYour Choice: ");
    int diff;
    scanf("%d",&diff);
    while(!(diff==1||diff==2||diff==3))//check the validity of the input
    {
        system("cls");
        goto start;
    }
    if(diff==1)
    {
        twoPlayerMood(2);
    }
    else if (diff==2)
    {
        twoPlayerMood(3);
    }
    else if (diff==3)
    {
        twoPlayerMood(5);
    }

    return;
}

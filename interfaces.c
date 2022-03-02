#include <stdio.h>
#include <string.h>
#include <string.h>
#include <ctype.h>
#include<time.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define BLK "\e[0;30m"
#define BLU "\e[0;34m"
#define WHT "\e[0;37m"

#define BLKB "\e[40m"
#define REDB "\e[41m"
#define GRNB "\e[42m"
#define YELB "\e[43m"
#define BLUB "\e[44m"
#define MAGB "\e[45m"
#define CYNB "\e[46m"
#define WHTB "\e[47m"

#include"mainFuction.h"
#include"Players.h"
#include"saveLoad.h"
#include"rank.h"
#include"printData.h"
#include"check.h"

void Interface1()
{
    system("COLOR  60 ");
    start:
    printf("\n\t\t\t%c%c%c WELCOME TO DOTS AND BOXES!! %c%c%c \n\n\t - New game(enter 1): \n\n\t - Load game(enter 2): \n\n\t - Exit(enter 3)\n\n\t - Top Ten(enter 4):\n\n\t%cEnter the choice: ", 3 ,1,1,2,2,8,248);
    int choice=0;
    scanf("%d",&choice);
    fflush(stdin);
    while(!(choice==1||choice==2||choice==3||choice==4))
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\t\t\t\t%c%c%c%c Invalid Input!! %c%c%c%c",1,2,1,2,1,2,1,2); getch(); system("cls"); goto start;

    }
    switch(choice){
        case 1:{system("cls"); oneOrTwoPlayers(); break;}
        case 2:{system("cls");load(); Interface1(); break;}
        case 3:{system("cls"); printf("\n\t\t\t\t\t\tGoodbye");exit(0); break;}
        case 4:{system("cls"); loadRank(" ",0); break;}
   }
}
int oneOrTwoPlayers()
{
    system("COLOR");
    start:
    printf("\n\n - 1 player(VS COMPUTER)[Enter 1]");
    printf("\n\n - 2 players(VS PERSON) [Enter 2]\n\n - Go back [Enter 3]\n\n %cYour Choice: ",7);
    int noOfPlayers;
    scanf("%d",&noOfPlayers);
    fflush(stdin);
    while(!(noOfPlayers==1||noOfPlayers==2||noOfPlayers==3))//check the validity of the input
    {
        system("cls");
        goto start;
    }
    if(noOfPlayers ==1)
    {
        onePlayer();//should be onePlayer function but not finished jet
    }
    else if (noOfPlayers ==2)
    {
        twoPlayer();
    }
    else if(noOfPlayers==3){
        system("cls");
        Interface1();
    }
    return noOfPlayers;
}

void onePlayer()
{
    start:
    printf("\t\n - Enter difficulty:\n\n\t - Easy(enter 1)\n\n\t - Meduim(enter 2)\n\n\t - Hard(enter 3)\n\n\t - To go back enter 4 %c%c Your Choice: ",3,3);
    int diff;
    scanf("%d",&diff);
    fflush(stdin);
    while(!(diff==1||diff==2||diff==3||diff==4))//check the validity of the input
    {
        system("cls");
        goto start;
    }
    if(diff==1)
    {
        onePlayerMood(2,1,0);
    }
    else if (diff==2)
    {
        onePlayerMood(3,1,0);
    }
    else if (diff==3)
    {
        onePlayerMood(5,1,0);
    }
    else if(diff==4){
            system("cls");
        oneOrTwoPlayers();
    }

    return;
}

void twoPlayer()
{
    start:
    printf("\t\n - Enter difficulty:\n\n\t - Easy(enter 1)\n\n\t - Meduim(enter 2)\n\n\t - Hard(enter 3)\n\n\t - To go back enter 4\n\n\t %c%c Your Choice: ",3,3);

    int choice;
int diff;

    scanf("%d",&diff);
    fflush(stdin);
    while(!(diff==1||diff==2||diff==3||diff==4))//check the validity of the input
    {
        system("cls");
        goto start;
    }
    if(diff==1)
    {
        twoPlayerMood(2,1,0);
    }
    else if (diff==2)
    {
        twoPlayerMood(3,1,0);
    }
    else if (diff==3)
    {
        twoPlayerMood(5,1,0);
    }
    else if (diff==4){
            system("cls");
        oneOrTwoPlayers();
    }

    return;
}

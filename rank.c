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
#define WHT "\e[0;37m

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
#include"interfaces.h"
#include"saveLoad.h"
#include"printData.h"
#include"check.h"


void loadRank(char winnerName[20],int winnerScore)
{
    system("color 06");
    char *pch = strstr(winnerName, "\n");
    if(pch != NULL)
    strncpy(pch, "\0", 1);
    FILE *rank;
    struct users u[10] ;

    rank=fopen("Top_ten.txt","r");
    if(rank==NULL)
    {
        printf("ERROR CANNOT OPEN FILE");
        exit(1);
    }
    fread(u,sizeof(struct users),10,rank);
    int found=0;
    for(int i=0 ;i<10;i++) //2nd time for the player to play
    {
        if(stricmp(u[i].name,winnerName)==0)
        {
            if(u[i].score<winnerScore)
            {
                u[i].score=winnerScore;
                for(int j=i;j>=0;j--)
                {
                    struct users temp1;
                    if(u[j].score>u[j-1].score)
                    {
                        strcpy(temp1.name,u[j].name);
                        temp1.score=u[j].score;
                        strcpy(u[j].name,u[j-1].name);
                        u[j].score=u[j-1].score;
                        strcpy(u[j-1].name,temp1.name);
                        u[j-1].score=temp1.score;
                    }
                    else break;
                }
                found=1;
            }
        }
    }
    if(!found) //because it is sorted,first time for the player to play
    {
        for(int i=0;i<10;i++)
        {
            if(winnerScore>u[i].score)
            {
                int k=i;
                if(k==9)
                {
                    strcpy(u[k].name,winnerName);
                    u[k].score=winnerScore;
                }
                else
                {
                    for(int j=8;j>=0;j--)
                    {
                        strcpy(u[j+1].name,u[j].name);
                        u[j+1].score=u[j].score;
                        if(k==j)
                        {
                            strcpy(u[k].name,winnerName);
                            u[k].score=winnerScore;
                            found=1;
                            break;
                        }
                    }
                }
            }
            if(found)
            {
                break;
            }
        }
    }
    printf(ANSI_COLOR_RESET"\t\t\t\t\t\tTOP TEN LIST\n");
    for(int i=0;i<10;i++)
    {
        printf(ANSI_COLOR_RESET"Rank %d: ",i+1);
        puts(u[i].name);
        printf("\tscore: %d\n",u[i].score);
    }
    rank=fopen("Top_ten.txt","w");
    if(rank==NULL)
    {
        printf("ERROR CANNOT OPEN FILE");
        exit(1);
    }
    fwrite(u,sizeof(struct users),10,rank);
    //printf("Data is stored successfully");
    fclose(rank);
    printf("\n\n    enter any number to go to the main menu ");
    int r;
    scanf("%d",r);
    fflush(stdin);
    system("cls");
    Interface1();
}


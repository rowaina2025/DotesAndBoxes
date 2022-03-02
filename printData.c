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
#include"interfaces.h"
#include"saveLoad.h"
#include"rank.h"
#include"check.h"


void printGrid(int n,int A[2*n+2][2*n+2]){/*initialize array of size 2*n+2*/
//function to print grid of all modes
 int SIZE=2*n+2;
 for(int i=0;i<SIZE;i++)
 {
    printf("\t\t\t\t\t\t");
    for(int j=0;j<SIZE;j++){
        if(i==0)   /*printing horizontal numbers*/
            {
                if(j!=0)
                printf(" %d" ,j);
                else printf(" ");
            }
        if(j==0)  /*printing vertical numbers*/
            {
                if(i!=0)
                printf("%d ",i);
            }
        if( i%2==1&&j%2==1)  //printing the dots
            {
            printf("%c",3);
            }
        if(i%2==0&&j%2==1&&i!=0)
        {
            if(A[i][j]==1&&j!=0)
            {
                printf(ANSI_COLOR_CYAN"%c"ANSI_COLOR_RESET,186);//vertical line
            }
            else if(A[i][j]==2&&j!=0)
            {
                printf(ANSI_COLOR_YELLOW"%c"ANSI_COLOR_RESET,186);//vertical line
            }
            else printf(" ");       //neither filled by the first nor the second
        }
        if(i%2==1&&j%2==0&&j!=0)
        {
            if(A[i][j]==1)
            {
                printf(ANSI_COLOR_CYAN"%c%c%c"ANSI_COLOR_RESET,205,205,205);//horizontal line
            }
            else if(A[i][j]==2)
            {
                printf(ANSI_COLOR_YELLOW"%c%c%c"ANSI_COLOR_RESET,205,205,205);//horizontal line
            }
            else printf("   ");       //neither filled by the first nor the second
       }
      if(i%2==0 && j%2==0)            //printing boxes
      {
           if(A[i][j]==0&&i!=0&&j!=0) //box is empty
               printf("   ");         //neither filled by the first nor the second
           if(A[i][j]!=0)             //box is filled
                if(A[i][j]==3)        //filled by first player
                     printf(ANSI_COLOR_CYAN "%c%c%c"ANSI_COLOR_RESET,219,219,219);//print boxes
                if(A[i][j]==4)        //filled by the second player
                     printf(ANSI_COLOR_YELLOW "%c%c%c" ANSI_COLOR_RESET,219,219,219);//print boxes
      }
    }
    printf("\n");
 }
}


void printData(int trn,clock_t t3)
{
/*collecting this data in a structure (typedef struct player{  };player*/
    printf(ANSI_COLOR_CYAN "\n    player 1 name: %s",&ply[1].name1);
    printf(ANSI_COLOR_YELLOW"\t\t\t\t\t\t\t\t\t player 2 name: %s\n",&ply[1].name2);
    printf(ANSI_COLOR_CYAN"    Number of moves for player 1: %d",ply[trn].moves1);
    printf(ANSI_COLOR_YELLOW"\t\t\t\t\t Number of moves for player 2:%d \n\n",ply[trn].moves2);
    printf(ANSI_COLOR_CYAN "    player 1's score = %d",ply[trn].score1);
    printf(ANSI_COLOR_YELLOW"\t\t\t\t\t\t player 2's score = %d\n\n"ANSI_COLOR_RESET,ply[trn].score2);
    printf("    Number of remaining lines: %d\t\t\t\t\t\t\n",ply[trn].remLines);
    printf("\t\t\t\t\t\tTime passed: %d:%d\n\n",t3/60,t3%60);

}

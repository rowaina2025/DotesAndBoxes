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


void printGrid(int n,int A[2*n+2][2*n+2]){/*initialize array of size 2*n+2*/
    //function to print grid of all moods
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
            printf("%c",254);
            }
        if(i%2==0&&j%2==1&&i!=0)
        {
            if(A[i][j]==1&&j!=0)
            {
                printf(ANSI_COLOR_CYAN"%c"ANSI_COLOR_RESET,186);
                line.player1++;//vertical line
            }
            else if(A[i][j]==2&&j!=0)
            {
                printf(ANSI_COLOR_YELLOW"%c"ANSI_COLOR_RESET,186);
                line.player2++;//vertical line
            }
            else printf(" ");//neither filled by the first nor the second
        }
        if(i%2==1&&j%2==0&&j!=0)
        {
            if(A[i][j]==1)
            {
                printf(ANSI_COLOR_CYAN"%c%c%c"ANSI_COLOR_RESET,205,205,205);//horizontal line
                line.player1++;
            }
            else if(A[i][j]==2)
            {
                printf(ANSI_COLOR_YELLOW"%c%c%c"ANSI_COLOR_RESET,205,205,205);
                line.player2++;//horizontal line
            }
            else printf("   "); //neither filled by the first nor the second
       }
      if(i%2==0 && j%2==0) //printing boxes
      {
           if(A[i][j]==0&&i!=0&&j!=0) //box is empty
               printf("   "); //neither filled by the first nor the second
           if(A[i][j]!=0) //box is filled
                if(A[i][j]==1)//filled by first player
                     printf(ANSI_COLOR_CYAN "%c%c%c"ANSI_COLOR_RESET,219,219,219);
                     score.player1++;]//print boxes
                if(A[i][j]==2)//filled by the second player
                     printf(ANSI_COLOR_YELLOW "%c%c%c" ANSI_COLOR_RESET,219,219,219);
                     score.player2++;//print boxes
      }
    }
    printf("\n");
 }
}

int check(int row,int col,int n,int A[2*n+2][2*n+2],int player)
{
    //checking boxes after each play for all moods
    int x=0;
    //if row is odd,col is even
    if(row%2==1&&col%2==0)
    {
        if(A[row-1][col-1]&& A[row-2][col]&&A[row-1][col+1])
        {
            x++;
            if(player%2==0)
            {
                A[row-1][col]=1;
                player=2;
            }
            else
            {
                A[row-1][col]=2;
                player =1;
            }
       }
       if(A[row+1][col-1]&& A[row+2][col]&&A[row+1][col+1])
       {
            x++;
            if(player%2==0)
            {
                A[row+1][col]=1;player =2;
            }
            else
            {
                A[row+1][col]=2;player =1;
            }
        }
    }
    if(row%2==0&&col%2==1)
    {
        if(A[row][col-2]&& A[row-1][col-1]&&A[row+1][col-1])
        {
            x++;//counter to check if player should change or not
            if(player%2==0)
            { //It will be player 1 turn because of player++;
                A[row][col-1]=1;player =2;
            }
            else
            {
                A[row][col-1]=2;
                player =1;
            }
        }

        if(A[row-1][col+1]&& A[row][col+2]&&A[row+1][col+1])
        {
            x++;
            if(player%2==0)
            {
                A[row][col+1]=1;player =2;
            }
            else
            {
                A[row][col+1]=2;
                player =1;
            }//same player again
        }
    }
    system("cls");
    printData();
    printGrid(n,A);
    return x;
}

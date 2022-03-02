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
#include"printData.h"



int check1(int row,int col,int n,int A[2*n+2][2*n+2],int player)
{
    //checking boxes after each turn
    int x=0;
    //if row is odd,col is even
    if(row%2==1&&col%2==0)
    {
        if(A[row-1][col-1]&& A[row-2][col]&&A[row-1][col+1])
        {
            x++;
            if(player%2==0)//player2
            {
                A[row-1][col]=4;
                player=2;
            }
            else//player1
            {
                A[row-1][col]=3;
                player =1;
            }
       }
       if(A[row+1][col-1]&& A[row+2][col]&&A[row+1][col+1])
       {
            x++;
            if(player%2==0)
            {
                A[row+1][col]=4;
                player =2;
            }
            else
            {
                A[row+1][col]=3;
                player =1;
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
                A[row][col-1]=4;
                player =2;//same player continue
            }
            else
            {
                A[row][col-1]=3;
                player =1;//same player continue
            }
        }

        if(A[row-1][col+1]&& A[row][col+2]&&A[row+1][col+1])
        {
            x++;
            if(player%2==0)
            {
                A[row][col+1]=4;
                player =2;
            }
            else
            {
                A[row][col+1]=3;
                player =1;
            }//same player again
        }
    }
    system("cls");
    return x;
}
//game moods


int check2(int row,int col,int n,int A[2*n+2][2*n+2],int player)
{
    //checking boxes after each turn
    int x=0;
    //if row is odd,col is even
    if(row%2==1&&col%2==0)
    {
        if(A[row-1][col-1]&& A[row-2][col]&&A[row-1][col+1])
        {
            x++;
            if(player%2==0)//player2
            {
                A[row-1][col]=3;
                player=2;
            }
            else//player1
            {
                A[row-1][col]=4;
                player =1;
            }
       }
       if(A[row+1][col-1]&& A[row+2][col]&&A[row+1][col+1])
       {
            x++;
            if(player%2==0)
            {
                A[row+1][col]=3;
                player =2;
            }
            else
            {
                A[row+1][col]=4;
                player =1;
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
                A[row][col-1]=3;
                player =2;//same player continue
            }
            else
            {
                A[row][col-1]=4;
                player =1;//same player continue
            }
        }

        if(A[row-1][col+1]&& A[row][col+2]&&A[row+1][col+1])
        {
            x++;
            if(player%2==0)
            {
                A[row][col+1]=3;
                player =2;
            }
            else
            {
                A[row][col+1]=4;
                player =1;
            }//same player again
        }
    }
    system("cls");
    return x;
}




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


void twoPlayerMood(int n){
    player player1,player2;
    printf("Entre the name of the first player: ");
    scanf("%s",player1.name);
    printf("\n");
    printf("Entre the name of the first player: ");
    scanf("%s",palyer2.name);
    system("CLS");
    //any difficulty(number of boxes) according to n
    //the idea of  the grid is a 2-D array of integer takes value of 0 if the grid is empty, value if 1 if player 1 has entered a line, value of 2 if player two has entered the line
    int SIZE=2*n+2;  //Size of the 2-D array
    printData(); //Print players data
    int A[SIZE][SIZE];//declare 2-D arrays if size SIZE
    int noOfMoves=2*n*(n+1);//total number of moves decreases one each turn
    for (int i=0;i<SIZE;i++) //initialize the array
    {
        for (int j=0;j<SIZE;j++)
        {
            A[i][j]=0;
        }
    }
    int player=1; //if player odd-->player 1//if player even-->player 2
    int row,col,temp,Error; //temp takes the value of the input element of array
    start: ;//empty statement
    printGrid(n,A); //print the grid

    while(noOfMoves!=0)//loop of the game stops when no more lines existing//start the game
    {
        if(player%2==1)//check if the 1's or the 2's turn
           printf(ANSI_COLOR_CYAN"It's player 1's turn\n"ANSI_COLOR_RESET);

        else
           printf(ANSI_COLOR_YELLOW"It's player 2's turn\n"ANSI_COLOR_RESET);

        printf("Enter row: ");
        scanf("%d",&row);
        printf("Enter col: ");
        scanf("%d",&col);
        if((row%2==0&&col%2==1)||(row%2==1&&col%2==0)) //checking the validity of the input
        {
            temp=A[row][col];
            if(temp==0) //if no lines added before
            {
                if(player%2==0) //player 2
                {
                    A[row][col]=2;
                }
                else  //player 1
                    A[row][col]=1;
                noOfMoves--; //decrease number of lines by one//decrement the counter of while loop
                player++; //change player from odd to even and vise versa
                system("cls");
                printData();
                printGrid(n,A);
           }
           else//error procedures-->temp!=0 means the array has line or box added
           {
                system("cls");
                printf(ANSI_COLOR_RED"\t\t\t\t\t\tInvalid input\n"ANSI_COLOR_RESET);
                printData();
                printf("no of moves =%d\n",noOfMoves);
                goto start;
           }

       }
       else //error procedures
       {
            system("cls");
            printf(ANSI_COLOR_RED"\t\t\t\t\t\tInvalid input\n"ANSI_COLOR_RESET);
            printData();
            printf("no of moves =%d\n",noOfMoves);
            goto start;
       }
       int x=check(row,col,n,A,player);//check boxes each turn
       if(x==1)
            player++;
       else if(x==2)
             player--;
   }

}


//one player mood

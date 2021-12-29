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

int check(int row,int col,int n,int A[2*n+2][2*n+2],int player);
void Interface1();
void twoPlayer();
void oneOrTwoPlayers();
void printGrid(int n,int A[2*n+2][2*n+2]);
void printData();
void twoPlayerMood(int n);
void onePlayer();
void onePlayerMood(int n);


 struct Player  {
 int score1;
 int score2;
 int moves1;
 int moves2;
 int remLines;
 char name1[20];
 char name2[20];
 int arr[12][12];
};
struct Player ply[40];


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

void onePlayer()
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
        onePlayerMood(2);
    }
    else if (diff==2)
    {
        onePlayerMood(3);
    }
    else if (diff==3)
    {
        onePlayerMood(5);
    }

    return;
}


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
                printf(ANSI_COLOR_CYAN"%c"ANSI_COLOR_RESET,186);//vertical line
            }
            else if(A[i][j]==2&&j!=0)
            {
                printf(ANSI_COLOR_YELLOW"%c"ANSI_COLOR_RESET,186);//vertical line
            }
            else printf(" ");//neither filled by the first nor the second
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
            else printf("   "); //neither filled by the first nor the second
       }
      if(i%2==0 && j%2==0) //printing boxes
      {
           if(A[i][j]==0&&i!=0&&j!=0) //box is empty
               printf("   "); //neither filled by the first nor the second
           if(A[i][j]!=0) //box is filled
                if(A[i][j]==3)//filled by first player
                     printf(ANSI_COLOR_CYAN "%c%c%c"ANSI_COLOR_RESET,219,219,219);//print boxes
                if(A[i][j]==4)//filled by the second player
                     printf(ANSI_COLOR_YELLOW "%c%c%c" ANSI_COLOR_RESET,219,219,219);//print boxes
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
                A[row-1][col]=4;
                player=2;
            }
            else
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



void twoPlayerMood(int n){
    //the idea of the grid is a 2-D array of integer takes value of 0 if the grid is empty, value if 1 if player 1 has entered a line, value of 2 if player two has entered the line value of 3 when box filled ny player 1, 4 when box filled by player 2
    int SIZE=2*n+2;       //Size of the 2-D array
    int A[SIZE][SIZE];//declare 2-D arrays if size SIZE
    int noOfMoves=2*n*(n+1);   //total number of moves decreases one each turn
    int mA=0,mB=0,sA=0,sB=0;
    int x; //indicator for undo
    for (int i=0;i<SIZE;i++)   //initialize the array
    {
        for (int j=0;j<SIZE;j++)
        {
            A[i][j]=0;
        }
    }
    printf(ANSI_COLOR_YELLOW"\n\tEnter the name of the first player ");
    scanf("%s", ply[1].name1);
    printf(ANSI_COLOR_YELLOW"\n\tEnter the name of the second player ");
    scanf("%s", ply[1].name2);
    getchar();
    int trn=1;       //iteration for turns to save the array of structures of each turn(MAXIMUM==2*n+2)
    system("CLS");
    //the initial values of members of structure player
    ply[trn].moves1=mA;
    ply[trn].moves2=mB;
    ply[trn].remLines=noOfMoves;
    ply[trn].score1=sA;
    ply[trn].score2=sB;
    for(int i=0;i<2*n+2;i++){
        for(int j=0;j<2*n+2;j++){
            ply[trn].arr[i][j]=A[i][j];
        }
    }
    int player=1; //if player odd-->player 1//if player even-->player 2
    int row,col,temp; //temp takes the value of the input element of array
    start:

    while(noOfMoves!=0)//loop of the game stops when no more lines existing//start the game
    {
        system("CLS");
        printData(trn); //printing the interface
        printGrid(n,A);
        if(player%2==1)//check if the 1's or the 2's turn
           printf(ANSI_COLOR_CYAN"It's player %s's turn\n"ANSI_COLOR_RESET,ply[1].name1);

        else
           printf(ANSI_COLOR_YELLOW"It's player %s's turn\n"ANSI_COLOR_RESET,ply[1].name2);

        printf("\n\tFor undo enter 55 5, redo enter 66 6, save the game enter 77 7\n\tEnter row then column...\n\tYour Choice: ");
        x=0;
        scanf("%d%d",&row,&col);
        //indicator for undo
        if(row==55&&col==5&&trn!=1) //undo
        {
            x++;
            trn--;
            mA=ply[trn].moves1;
            mB=ply[trn].moves2;
            noOfMoves=ply[trn].remLines;
            sA=ply[trn].score1;
            sB=ply[trn].score2;
            for(int i=0;i<2*n+2;i++){
                for(int j=0;j<2*n+2;j++){
                    A[i][j]=ply[trn].arr[i][j];
                }
            }
        }

        else if (row==66&&col==6)  //redo
        {
            trn++;
            mA=ply[trn].moves1;
            mB=ply[trn].moves2;
            noOfMoves=ply[trn].remLines;
            sA=ply[trn].score1;
            sB=ply[trn].score2;
            for(int i=0;i<2*n+2;i++){
                for(int j=0;j<2*n+2;j++){
                    A[i][j]=ply[trn].arr[i][j];
                }
            }
        }
        // if (row==77&&col==7) {/*save*/}
        else if((row%2==0&&col%2==1)||(row%2==1&&col%2==0)) //checking the validity of the input
        {
            temp=A[row][col];
            if(temp==0) //if no lines added before
            {
                if(player%2==0) //player 2
                {
                    A[row][col]=2; mB++;
                }
                else
                {  //player 1
                    A[row][col]=1; mA++;
                }
                noOfMoves--; //decrease number of lines by one//decrement the counter of while loop
                player++; //change player from odd to even and vise versa
               //check scores
                trn++;
                system("cls");

           }
           else//error procedures-->temp!=0 means the array has line or box added
           {
                system("cls");
                printf(ANSI_COLOR_RED"\t\t\t\t\t\tInvalid input\n"ANSI_COLOR_RESET);
                goto start;
           }
           int x=check(row,col,n,A,player);//check boxes each turn
            if(x==1)
                player++;
            else if(x==2)
                player--;
                sA=0; sB=0;
        for(int i=0;i<2*n+2;i++){
            for(int j=0;j<2*n+2;j++){
                if(A[i][j]==3)
                    sA++;
                else if(A[i][j]==4)
                    sB++;
            }
        }

        ply[trn].moves1=mA;
        ply[trn].moves2=mB;
        ply[trn].remLines=noOfMoves;
        ply[trn].score1=sA;
        ply[trn].score2=sB;
        for(int i=0;i<2*n+2;i++){
            for(int j=0;j<2*n+2;j++){
                ply[trn].arr[i][j]=A[i][j];
            }
        }

       }

        system("CLS");
        printData(trn);
        printGrid(n,A);
    }


   // Score,move,arr,totmoves,name
  //LOAD DATA TO THE ARRAY OF STRUCTURES
if (sA>sB){
    printf(ANSI_COLOR_MAGENTA"\n\t\t\t\tThe Winner Is %s",ply[1].name1);
}
else if(sA<sB){
    printf(ANSI_COLOR_MAGENTA"\n\t\t\tThe Winner Is %s",ply[1].name2);
}
else if(sA==sB){
    printf(ANSI_COLOR_MAGENTA"\n\t\t\t\t TIE!!!");
}

}

//one player mood




void Interface1()
{
    system("COLOR");
    printf(ANSI_COLOR_YELLOW"\n\n\tNew game(enter 1): \n\n\tLoad game(enter 2): \n\n\tExit(enter 3)\n\n\tTop Ten(enter 4):\n\n\tEnter the choice: ");
    int choice=0;
    scanf("%d",&choice);
    while(!(choice==1||choice==2||choice==3||choice==4))
    {
        system("cls");
        printf(ANSI_COLOR_CYAN"(Invalid Input)"); printf(ANSI_COLOR_YELLOW"\nNew game(enter 1): \nLoad game(enter 2): \nExit(enter 3)\nTop Ten(enter 4):\nEnter the choice: ");
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
  system("COLOR");
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
    onePlayer();//should be onePlayer function but not finished jet
  }
  else if (noOfPlayers ==2)
  {
    twoPlayer();
  }
}


void printData(int trn)
{

    /*collecting this data in a structure (typedef struct player{  };player*/
    printf(ANSI_COLOR_CYAN "\n    player 1 name: %s",&ply[1].name1);
    printf(ANSI_COLOR_YELLOW"\t\t\t\t\t\t\t player 2 name: %s\n\n",&ply[1].name2);
    printf(ANSI_COLOR_CYAN"    Number of moves for player 1: %d",ply[trn].moves1);
    printf(ANSI_COLOR_YELLOW"\t\t\t\t\t Number of moves for player 2:%d \n\n",ply[trn].moves2);
    printf(ANSI_COLOR_CYAN "    player 1's score = %d",ply[trn].score1);
    printf(ANSI_COLOR_YELLOW"\t\t\t\t\t\t\t player 2's score = %d\n\n"ANSI_COLOR_RESET,ply[trn].score2);
    printf("    Number of remaining lines: %d\t\t\t\t\t\t Time passed:\n",ply[trn].remLines);

}


void onePlayerMood(int n){
    //the idea of the grid is a 2-D array of integer takes value of 0 if the grid is empty, value if 1 if player 1 has entered a line, value of 2 if player two has entered the line value of 3 when box filled ny player 1, 4 when box filled by player 2
    int SIZE=2*n+2;       //Size of the 2-D array
    int A[SIZE][SIZE];//declare 2-D arrays if size SIZE
    int noOfMoves=2*n*(n+1);   //total number of moves decreases one each turn
    int mA=0,mB=0,sA=0,sB=0;
    int x; //indicator for undo
    for (int i=0;i<SIZE;i++)   //initialize the array
    {
        for (int j=0;j<SIZE;j++)
        {
            A[i][j]=0;
        }
    }
    printf(ANSI_COLOR_YELLOW"\n\tEnter the name of the player ");
    scanf("%s", ply[1].name1);
    int trn=1;       //iteration for turns to save the array of structures of each turn(MAXIMUM==2*n+2)
    system("CLS");
    //the initial values of members of structure player
    ply[trn].moves1=mA;
    ply[trn].moves2=mB;
    ply[trn].remLines=noOfMoves;
    ply[trn].score1=sA;
    ply[trn].score2=sB;
    for(int i=0;i<2*n+2;i++){
        for(int j=0;j<2*n+2;j++){
            ply[trn].arr[i][j]=A[i][j];
        }
    }
    int player=1; //if player odd-->player 1//if player even-->player 2
    int row,col,temp; //temp takes the value of the input element of array
    start:

    while(noOfMoves!=0)//loop of the game stops when no more lines existing//start the game
    {
        strcpy(ply[1].name2, "Computer");
        system("CLS");
        printData(trn); //printing the interface
        printGrid(n,A);
        printf(ANSI_COLOR_CYAN"It's player %s's turn\n"ANSI_COLOR_RESET,ply[1].name1);
        printf("\n\tFor undo enter 55 5, redo enter 66 6, save the game enter 77 7\n\tEnter row then column...\n\tYour Choice: ");
        scanf("%d%d",&row,&col);
        //indicator for undo
        if(row==55&&col==5&&trn!=1) //undo
        {
            x++;
            trn-=2;
            mA=ply[trn].moves1;
            mB=ply[trn].moves2;
            noOfMoves=ply[trn].remLines;
            sA=ply[trn].score1;
            sB=ply[trn].score2;
            for(int i=0;i<2*n+2;i++){
                for(int j=0;j<2*n+2;j++){
                    A[i][j]=ply[trn].arr[i][j];
                }
            }
        }

        else if (row==66&&col==6)  //redo
        {
            trn+=2;
            mA=ply[trn].moves1;
            mB=ply[trn].moves2;
            noOfMoves=ply[trn].remLines;
            sA=ply[trn].score1;
            sB=ply[trn].score2;
            for(int i=0;i<2*n+2;i++){
                for(int j=0;j<2*n+2;j++){
                    A[i][j]=ply[trn].arr[i][j];
                }
            }
        }
        // if (row==77&&col==7) {/*save*/}
        else if((row%2==0&&col%2==1)||(row%2==1&&col%2==0)) //checking the validity of the input
        {
            temp=A[row][col];
            if(temp==0) //if no lines added before
            {   if(player%2==1){
                  A[row][col]=1; mA++; player++;
                }
                if(player%2==0){
                    for(int i=0;i<2*n+2;i++){
                        if(player%2==1) break;
                        for(int j=0;j<2*n+2;j++){
                            if(i%2==0&&j%2==1&&i!=0&&A[i][j]==0){
                                A[i][j]=2; mB++; player++; break;
                            }
                        }
                     }
                        for(int i=0;i<2*n+2;i++){
                            if(player%2==0) break;
                            for(int j=0;j<2*n+2;j++){
                                if(player%2==0&&A[i][j]==0&&i%2==1&&j%2==0&&j!=0){
                                    A[i][j]=2; mB++; player++; break;
                                }
                            }
                        }
                    }
                }
                noOfMoves-=2; //decrease number of lines by one//decrement the counter of while loop
               //change player from odd to even and vise versa
               //check scores
                trn+=2;
                system("cls");

           }
           else//error procedures-->temp!=0 means the array has line or box added
           {
                system("cls");
                printf(ANSI_COLOR_RED"\t\t\t\t\t\tInvalid input\n"ANSI_COLOR_RESET);
                goto start;
           }
           int x=check(row,col,n,A,player);//check boxes each turn
            if(x==1)
                player++;
            else if(x==2)
                player--;
                sA=0; sB=0;
        for(int i=0;i<2*n+2;i++){
            for(int j=0;j<2*n+2;j++){
                if(A[i][j]==3)
                    sA++;
                else if(A[i][j]==4)
                    sB++;
            }
        }

        ply[trn].moves1=mA;
        ply[trn].moves2=mB;
        ply[trn].remLines=noOfMoves;
        ply[trn].score1=sA;
        ply[trn].score2=sB;
        for(int i=0;i<2*n+2;i++){
            for(int j=0;j<2*n+2;j++){
                ply[trn].arr[i][j]=A[i][j];
            }
        }

       }

        system("CLS");
        printData(trn);
        printGrid(n,A);



   // Score,move,arr,totmoves,name
  //LOAD DATA TO THE ARRAY OF STRUCTURES
  if (sA>sB){
    printf(ANSI_COLOR_MAGENTA"\n\t\t\t\tThe Winner Is %s",ply[1].name1);
  }
  else if(sA<sB){
    printf(ANSI_COLOR_MAGENTA"\n\t\t\tThe Winner Is %s",ply[1].name2);
  }
  else if(sA==sB){
    printf(ANSI_COLOR_MAGENTA"\n\t\t\t\t TIE!!!");
  }
}


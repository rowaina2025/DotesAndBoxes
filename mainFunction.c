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
#define ANSI_COLOR_GREEN "\x1b[32m
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


#include"Players.h"
#include"interfaces.h"
#include"saveLoad.h"
#include"rank.h"
#include"printData.h"
#include"check.h"

//maria


clock_t t1,t2;
int t3=0,t4=0;//t3 is total time for player 1, t4 is total time for player 2


void onePlayerMood(int n, int trn, int ld)
{
    system("color 60");
    int SIZE=2*n+2;
    int A[SIZE][SIZE];
    int noOfMoves,mA,mB,sA,sB;
    int row,col,temp,player=1;
    int noOfPlayers=1;
    int x;
    if(ld==0)  //Game not loaded
    {   g.box=n;  //number of boxes
        g.oneTwo=1;  //number of players
        g.trns=1;  //turn
        for(int i=0;i<SIZE;i++){ //initialize the array of grid
            for(int j=0;j<SIZE;j++){
                A[i][j]=0;
                ply[1].arr[i][j]=A[i][j];
            }
        }
        mA=0; mB=0; sA=0; sB=0; noOfMoves=2*n*(n+1); player=1; //first values of game data
        //set the values to the array of structures
        ply[trn].moves1=mA;
        ply[trn].moves2=mB;
        ply[trn].score1=sA;
        ply[trn].score2=sB;
        ply[trn].remLines=noOfMoves;
        ply[trn].turn=player;
        ply[trn].T=trn;
        x=0;
        //ask for the name of the player
        printf(BLU YELB"\n\tEnter the name of the player ");
        fgets( ply[1].name1,50,stdin);
        system("cls");

    }
    else if(ld==1) //game loaded
    {   //g.trns indicates the last turn from the loaded game
        //giving game data their values
        trn=g.trns;
        trn=ply[trn].T;
        t3=g.t;
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                A[i][j]=ply[trn].arr[i][j];
            }
        }
        x=g.un;
        mA=ply[trn].moves1;
        mB=ply[trn].moves2;
        sA=ply[trn].score1;
        sB=ply[trn].score2;
        noOfMoves=ply[trn].remLines;
        player=ply[trn].turn;
    }

    start:
    while(noOfMoves!=0)//loop of the game stops when no more lines existing//start the game
    {

        system ("color 06");
        printf("%d",ply[trn].turn);
        strcpy(ply[1].name2, "Computer\n");
        system("CLS");
        t1=clock();
        printData(trn,t3); //printing the interface data
        printGrid(n,A);   //printing grid
        debug(n,A);
        printf(ANSI_COLOR_CYAN"It's player 1's turn\n"ANSI_COLOR_RESET);
        printf("\n\tFor undo enter 44 4, redo enter 55 5, save the game enter 66 6, load enter 77 7,main menu enter 88 8,\n\t exit game enter 99 9\n\t\n\n\t %c YOUR CHOICE: ",3);
        scanf("%d%d",&row,&col);
        fflush(stdin);
        //time data
        t2=clock();
        t3=t3+(int)(t2-t1)/CLOCKS_PER_SEC;
        t1=0,t2=0;
        //indicator for undo
        if(row==44&&col==4) //undo
        {
            for(int i=trn-1;i>0;i--){
                if(ply[i].turn%2==1){
                    x++;
                    trn=i;
                    break;
                }
           }
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
            player=ply[trn].turn;
            ply[trn].T=trn;
        }

        else if (row==55&&col==5&&g.trns>=trn)  //redo
        {
            for(int i=trn+1;i<55;i++){
                if(ply[i].turn%2==1&&x!=0){
                    x--;
                    trn=i;
                    break;
                }
           }
            //the increase turns till reach player 1
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
            ply[trn].T=trn;
            player=ply[trn].turn;
        }
        else if (row==66&&col==6) { //save game
            //getchar();
            save(n,A,trn,t3);
        }
        else if (row==77&&col==7){ //load
            system("cls");
            load();
        }

        else if (row==88&&col==8){ //main menu
            system("cls");
            Interface1();
        }
        else if(row==99&&col==9){
            system("cls");
            exit(1);
        }

        else if((row%2==0&&col%2==1)||(row%2==1&&col%2==0)) //checking the validity of the input
        {
            x=0;
            temp=A[row][col];
            if(temp==0) //if no lines added before
            {
                if(player%2==1){
                    A[row][col]=1;
                    mA++;
                    trn++;
                    ply[trn].T=trn;
                    g.trns=trn;
                    g.t=t3;
                    ply[trn].moves1=mA;
                    ply[trn].remLines=noOfMoves--;
                    noOfMoves--;
                    int x=check1(row,col,n,A,player);
                    if(x==0) {player++; ply[trn].turn=player;} //no boxes comptleted
                    else if(x>0) {noOfMoves++; ply[trn].turn=player;} //one or more boxes completed
}
                if(player%2==0) //computer
                {
                    for(int i=0;i<2*n+2;i++)
                    {
                        if(player%2==1) break;
                        for(int j=0;j<2*n+2;j++)
                        {
                            if(i%2==0&&j%2==1&&i!=0&&A[i][j]==0) //i is row,j is col
                            {
                                A[i][j]=2;
                                mB++;
                                trn++;
                                ply[trn].T=trn;
                                g.trns=trn;
                                g.t=t3;
                                ply[trn].moves2=mB;
                                ply[trn].remLines=noOfMoves--;
                                noOfMoves--;
                                int x=check1(i,j,n,A,player);//check boxes each turn
                                if(x==0){player++; ply[trn].turn=player; break;}
                            }
                        }
                    }
                    for(int i=0;i<2*n+2;i++)
                    {
                        if(player%2==1) break;
                        for(int j=0;j<2*n+2;j++)
                        {
                            if(player%2==0&&A[i][j]==0&&i%2==1&&j%2==0&&j!=0)
                            {
                                A[i][j]=2;
                                mB++;
                                trn++;
                                ply[trn].T=trn;
                                g.trns=trn;
                                g.t=t3;
                                ply[trn].moves2=mB;
                                ply[trn].remLines=noOfMoves--;
                                noOfMoves--;
                                int x=check1(i,j,n,A,player);//check boxes each turn
                                if(x==0){player++; ply[trn].turn=player; break;}
                                else if(x>0) {noOfMoves--;}
                            }
                        }
                    }
                }
            }
            noOfMoves=(2*n+2)-(mA+mB); // for checking
            system("cls");
        }
        else//error procedures-->temp!=0 means the array has line or box added
        {
            system("cls");
            printf(ANSI_COLOR_RED"\t\t\t\t\t\tInvalid input\n"ANSI_COLOR_RESET);
            goto start;
        }
        sA=0; sB=0;
        for(int i=0;i<2*n+2;i++){
            for(int j=0;j<2*n+2;j++){
                if(A[i][j]==3)
                    sA++;
                else if(A[i][j]==4)
                    sB++;
            }
        }
         //save data again before the game loop
        trn=mA+mB+1;
        ply[trn].T=trn;
        g.trns=trn;
        g.t=t3;
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
        if(noOfMoves!=2*n*(n+1)-mA-mB){
            noOfMoves=2*n*(n+1)-mA-mB;
            ply[trn].remLines=noOfMoves;
        }
    }
    ///End of while loop (game loop)
    system("CLS");
    printData(trn,t3);
    printGrid(n,A);
    debug(n,A);
    //check sores and save ranks after the end of the game
    char winnerName[20];int winnerScore;
    if (sA>sB){
        printf(ANSI_COLOR_MAGENTA"\n\t\t\t\tThe Winner Is %s \n",ply[1].name1);
        system("pause");
        strcpy(winnerName,ply[1].name1);
        winnerScore=ply[trn].score1;
        system("cls");
        loadRank(winnerName,winnerScore);
    }
    else if(sA<sB){ //player 2 winner
        printf(ANSI_COLOR_MAGENTA"\n\t\t\tThe Winner Is %s \n",ply[1].name2);
        system("pause");
        strcpy(winnerName,ply[1].name2);
        winnerScore=ply[trn].score2;
        system("cls");
        loadRank(winnerName,winnerScore);
    }
    else if(sA==sB&&noOfMoves==0){ //tie
        printf(ANSI_COLOR_MAGENTA"\n\t\t\t\t TIE!!!    \n");
    }
}


void twoPlayerMood(int n,int trn, int ld)
{   // declare game's variables
    system ("color 60");
    int SIZE=2*n+2; //size of array (grid)
    int A[SIZE][SIZE];
    int noOfMoves,mA,mB,sA,sB;
    int row,col,temp,player=1;
    int noOfPlayers=2;
    if(ld==0) //new game
    {
       g.box=n;
       g.trns=1;
       g.oneTwo=2;
        for(int i=0;i<SIZE;i++)
        {
            for(int j=0;j<SIZE;j++)
            {
                A[i][j]=0;
                ply[1].arr[i][j]=A[i][j];
            }
        }
        mA=0; mB=0; sA=0; sB=0; noOfMoves=2*n*(n+1); player=1;
        ply[trn].moves1=mA;
        ply[trn].moves2=mB;
        ply[trn].score1=sA;
        ply[trn].score2=sB;
        ply[trn].remLines=noOfMoves;
        ply[trn].turn=player;
        ply[trn].T=trn;
        printf(BLU YELB "\n\t%c%c Enter the name of the first player ",3,3);
        fgets( ply[1].name1,50,stdin);
        printf(BLU YELB"n\n\t%c%c Enter the name of the second player ",3,3);
        fgets( ply[1].name2,50,stdin);
        fflush(stdin);

    }
    else if(ld==1)  //loaded
    {   // set game's variables to the loaded data
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                A[i][j]=ply[trn].arr[i][j];
            }
        }
        g.trns=trn;
        t3=g.t;
        mA=ply[trn].moves1;
        mB=ply[trn].moves2;
        sA=ply[trn].score1;
        sB=ply[trn].score2;
        noOfMoves=ply[trn].remLines;
        player=ply[trn].turn;
    }

    start:
    while(noOfMoves!=0)//loop of the game stops when no more lines existing//start the game
    {
        system("color 06");
        system("CLS");
        printData(trn,t3); //printing the interface
        printGrid(n,A);  //printing grid
        debug(n,A);
        t1=clock(); //timing
        if(player%2==1) //check if the 1's or the 2's turn
        {
           printf(ANSI_COLOR_CYAN"It's player 1's turn\n"ANSI_COLOR_RESET);

        }
        else
        {
           printf(ANSI_COLOR_YELLOW"It's player 2's turn\n"ANSI_COLOR_RESET);

        }
        printf("\n\tFor undo enter 44 4, redo enter 55 5, save the game enter 66 6, load enter 77 7, main menu enter 88 8, \n\texit enter 99 9\n\n\t\%c YOUR CHOICE: ",3);
        scanf("%d%d",&row,&col); //user's choice
        fflush(stdin);
        t2=clock(); //timing
        t3=t3+(int)(t2-t1)/CLOCKS_PER_SEC;
        t1=0,t2=0;
        //indicator for undo
        if(row==44&&col==4&&trn>1) //undo
        {
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
            ply[trn].T=trn;
            player=ply[trn].turn;
            g.t=t3;
        }

        else if (row==55&&col==5&&ply[trn].T>0&&g.trns>trn)  //redo
        {
            trn++;
            ply[trn].T=trn;
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
            player=ply[trn].turn;
            g.t=t3;

        }
         else if (row==66&&col==6) { //save
            //getchar();
            save(n,A,trn,t3);
        }
        else if(row==99&&col==9){ //exit
            exit(1);
        }
        else if(row==88&&col==8){  //main menu
            system("cls");
            Interface1();
        }
        else if(row==77&&col==7){
            system("cls");
            load();
        }
        else if((row%2==0&&col%2==1)||(row%2==1&&col%2==0)) //checking the validity of the input
        {
            temp=A[row][col];
            if(temp==0) //if no lines added before
            {
                if(player%2==0) //player 2
                {
                    A[row][col]=2; mB++; //increment no of moves and add line
                    noOfMoves--; //decrease number of lines by one//decrement the counter of while loop
                    player++; //change player from odd to even and vise versa
                    trn++;   // increment turns
                    g.trns=trn;
                    ply[trn].moves2=mB;
                    ply[trn].turn=player;
                    g.t=t3;
                }
                else
                {  //player 1
                    A[row][col]=1; mA++;//increment no of moves and add line
                    noOfMoves--; //decrease number of lines by one//decrement the counter of while loop
                    player++; //change player from odd to even and vise versa
                    trn++;   // increment turns
                    g.trns=trn;
                    ply[trn].turn=player;
                    g.t=t3;

                }
                system("cls");  //clearing the screan for new turn

           }
           else//error procedures-->temp!=0 means the array has line or box added
           {
                system("cls");
                printf(ANSI_COLOR_RED"\t\t\t\t\t\tInvalid input\n"ANSI_COLOR_RESET);
                goto start;
           }

            int x=check2(row,col,n,A,player);//check boxes each turn
            if(x==1)
            {
                player++;
                ply[trn].turn=player;
            }
            else if(x==2)
            {
                player--;
                ply[trn].turn=player;
            }
            sA=0; sB=0; //setting scores to 0 ro recount them
            for(int i=0;i<2*n+2;i++)
            {
                for(int j=0;j<2*n+2;j++)
                {
                    if(A[i][j]==3)
                        sA++; //cyan(1)
                    else if(A[i][j]==4)
                        sB++; //yellow (2)
                }
            }
            // data of the turn int the array of structures
            g.trns=trn;
            g.t=t3;
            ply[trn].T=trn;
            g.trns=trn;
            ply[trn].moves1=mA;
            ply[trn].moves2=mB;
            ply[trn].remLines=noOfMoves;
            ply[trn].score1=sA;
            ply[trn].score2=sB;
            for(int i=0;i<2*n+2;i++)
            {
                for(int j=0;j<2*n+2;j++)
                {
                    ply[trn].arr[i][j]=A[i][j];
                }
            }
        } //end of the turn
        // in case there is error in number of moves to avoid getting out from the loop
        if(noOfMoves!=2*n*(n+1)-mA-mB)
        {
            noOfMoves=2*n*(n+1)-mA-mB;
            ply[trn].remLines=noOfMoves;
        }
        system("CLS");
        printData(trn,t3);
        printGrid(n,A);
        debug(n,A);

    } //End of game loop

    // checking scores to know the winners
    // assign names and sores to struct "users" for ranking
    char winnerName[20];int winnerScore;
    if (sA>sB) //player 1 winner
    {
        printf(ANSI_COLOR_MAGENTA"\n\t\t\t\tThe Winner Is %s",ply[1].name1);
        system("pause");
        strcpy(winnerName,ply[1].name1);
        winnerScore=ply[trn].score1;
        system("cls");
        loadRank(winnerName,winnerScore);
    }
    else if(sA<sB) //player 2 winner
    {
        printf(ANSI_COLOR_MAGENTA"\n\t\t\tThe Winner Is %s",ply[1].name2);
        system("pause");
        strcpy(winnerName,ply[1].name2);
        winnerScore=ply[trn].score2;
        system("cls");
        loadRank(winnerName,winnerScore);
    }
    else if(sA==sB&&noOfMoves==0)//tie
    {
        printf(ANSI_COLOR_MAGENTA"\n\t\t\t\t TIE!!!\n");
        system("pause");
        strcpy(winnerName,ply[1].name2);
        winnerScore=ply[trn].score2;
        system("cls");
        loadRank(winnerName,winnerScore);
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_GREEN "\x1b[32m"
int trn=1;       //iteration for turns to save the array of structures of each turn(MAXIMUM==2*n+2)
int noOfPlayers;
clock_t tA1,tB1,tA2,tB2;
int t3=0,t4=0;//t3 is total time for player 1, t4 is total time for player 2

int check1(int row,int col,int n,int A[2*n+2][2*n+2],int player);
void Interface1();
void twoPlayer();
int oneOrTwoPlayers();
void printGrid(int n,int A[2*n+2][2*n+2]);
void printData();
void onePlayer();
void onePlayerMood(int n);
int check2(int row,int col,int n,int A[2*n+2][2*n+2],int player);
void twoPlayerMood(int n );


typedef struct{

 int score1;
 int score2;
 int moves1;
 int moves2;
 int remLines;
 char name1[20];
 char name2[20];
 int arr[12][12];
 int turn[40];
 int rank1;
 int rank2; //time_score
 int trn;
}Player;
Player ply[40];

typedef struct {
    int z;
    int noOfPlayers;
}game;
game g;//this is a struct containing n and no of players

struct users{
    char name[20];
    int score;
};
void save(int n,int A[2*n+2][2*n+2]){
    FILE *fp;
    //Player ply[40];
    system("CLS");
    CHOICE: ;//empty statement

    char choice;
    printf("Choose where you want to save the file (1 or 2 or 3): ");
   choice=getchar();
    if(choice=='1'){
        fp=fopen("SavingGame1.bin","wb");
    }
    else if(choice=='2'){
     fp=fopen("SavingGame2.bin","wb");
    }else if(choice =='3'){
    fp=fopen("SavingGame3.bin","wb");
    }else if(choice!='1'||choice!='2'||choice!='3') {
        system("cls");
        printf(ANSI_COLOR_RED"\n\n\t\tInvalid Input\n\n\n"ANSI_COLOR_RESET);
        goto CHOICE;
    }

    if(fp==NULL){
        printf("\nError cannot open file");
        exit(1);
    }
    fprintf(fp,"%d\n",n);
    fprintf(fp,"%d\n",trn);
    fprintf(fp,"%d\n",noOfPlayers);
    //fwrite(printGrid,sizeof(int),1,fp);

    for(int i=0;i<2*n+2;i++){
        for(int j=0;j<2*n+2;j++)
        {
            fprintf(fp,"%d\n",A[i][j]);
        }
    }
    fprintf(fp,"%s",ply[1].name1);
    if(strcmp(ply[1].name2,"Computer")==0){
        fprintf(fp,"%s\n",ply[1].name2);
    }
    else fprintf(fp,"%s",ply[1].name2);
    fprintf(fp,"%d\n",ply[trn].score1);
    fprintf(fp,"%d",ply[trn].score2);
    printf("\nData is stored succesfully to file %c.txt",choice);

    fclose(fp);

}
void load()
{
    FILE *fp;
   system("cls");
    CHOICE: ;//empty statement

    char choice;
    printf("Choose where you want to load the file (1 or 2 or 3): ");
   choice=getchar();
    if(choice=='1'){
        fp=fopen("SavingGame1.bin","rb");
    }
    else if(choice=='2'){
     fp=fopen("SavingGame2.bin","rb");
    }else if(choice =='3'){
    fp=fopen("SavingGame3.bin","rb");
    }else if(choice!='1'||choice!='2'||choice!='3') {
        system("cls");
        printf(ANSI_COLOR_RED"\n\n\t\tInvalid Input\n\n\n"ANSI_COLOR_RESET);
        goto CHOICE;
    }

    if(fp==NULL){
        printf("\nError cannot open file");
        exit(1);
    }
    int n,trn,noOfPlayers,A[2*n+2][2*n+2];

   fscanf(fp,"%d",&n);
    fscanf(fp,"%d",&trn);
    fscanf(fp,"%d",&noOfPlayers);
    //fwrite(printGrid,sizeof(int),1,fp);

    for(int i=0;i<2*n+2;i++){
        for(int j=0;j<2*n+2;j++)
        {
            fscanf(fp,"%d",&A[i][j]);
        }
    }
    fscanf(fp,"%[^\n]",&ply[1].name1);
    if(strcmp(ply[1].name2,"Computer")==0){
        fscanf(fp,"%[^\n]",&ply[1].name2);
    }
    else fscanf(fp,"%s",ply[1].name2);
    fscanf(fp,"%d\n",&ply[trn].score1);
    fscanf(fp,"%d",&ply[trn].score2);
    fclose(fp);
    printGrid(n,A);
    printData(trn,t3,t4);

}
//void readFile(FILE * fPtr)
//{
//    char ch;
//
//    do
//    {
//        ch = fgetc(fPtr);
//
//        putchar(ch);
//
//    } while (ch != EOF);
//}
//
//void TopTen(){
//    FILE *top;
//    fopen("TopTen.txt", "a");
//        if (top == NULL)
//    {
//
//        printf("\nUnable to open file.\n");
//        exit(1);
//    }
//
//    /* Append data to file */
//    if(ply[1].score1>ply[1].score2){
//        fprintf(ply[1].name1, top);
//        fprintf(ply[1].score1,top);
//    }else{
//        fprintf(ply[1].name2, top);
//        fprintf(ply[1].score2,top);
//    }
//    freopen("TopTen.txt", "r", top);
//    system("cls");
//    readFile(top);
//    fclose(top);
//
//}

void enterRank(){
FILE *rank;
    struct users u[10] ;
    int i;
    rank=fopen("Top_ten.txt","w");
    if(rank==NULL)
    {
        printf("ERROR CANNOT OPEN FILE");
        exit(1);
    }
    for(i=0;i<10;i++){
        printf("Enter %d User name: ",i+1);
        fflush(stdin);
        gets(u[i].name);
        printf("Enter %d User score: ",i+1);
        scanf("%d",&u[i].score);
    }fwrite(u,sizeof(struct users),10,rank);
    printf("Data is stored successfully");
   fclose(rank);
}
void loadRank(char winnerName[20],int winnerScore){

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
    }fread(u,sizeof(struct users),10,rank);
        int found=0;
    for(int i=0 ;i<10;i++){//2nd time for the player to play
        if(strcmp(u[i].name,winnerName)==0){
            if(u[i].score<winnerScore){
                u[i].score=winnerScore;
                found=1;
                printf("FOUND\n");

                //printf("FOUND\n");
                //printf("%d\n",u[i].score);
            } break;
        }
    }
    if(!found){//because it is sorted,first time for the player to play
        for(int i=0;i<10;i++){
            if(winnerScore>u[i].score){
                int k=i;
                if(k==9){
                    strcpy(u[k].name,winnerName);
                    u[k].score=winnerScore;
                }else{
                    for(int j=8;j>=0;j--){
                         strcpy(u[j+1].name,u[j].name);
                        u[j+1].score=u[j].score;
                        if(k==j){
                            strcpy(u[k].name,winnerName);
                            u[k].score=winnerScore;
                            found=1;
                            break;
                        }
                    }
                }

            }
            if(found){
                break;
        }

    }

        }
        printf(ANSI_COLOR_RESET"\t\t\t\t\t\tTOP TEN LIST\n");
for(int i=0;i<10;i++){
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

}
void twoPlayer()
{
    start:
    printf("\t\nEnter difficulty:\n\tEasy(enter 1)\n\tMeduim(enter 2)\n\tHard(enter 3)\n\n\tYour Choice: ");

    int choice;
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

int check1(int row,int col,int n,int A[2*n+2][2*n+2],int player)
{
    //checking boxes after each play for all moods
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
    //checking boxes after each play for all moods
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
//game moods


//one player mood




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
    case 2:{system("cls");load(); break;}
    case 3:{system("cls"); printf("exit"); break;}
    case 4:{system("cls"); loadRank(" ",0); break;}

   }
}
int oneOrTwoPlayers()
{
  system("COLOR");
  start:
  printf("1 player(VS COMPUTER)[Enter 1]\n");
  printf("2 players(VS PERSON) [Enter 2]\n\nYour Choice: ");
   noOfPlayers;

  scanf("%d",&noOfPlayers);
  g.noOfPlayers= noOfPlayers;
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
  return noOfPlayers;
}


void printData(int trn,clock_t t3,clock_t t4)
{
    printf("n= %d",g.z);
    /*collecting this data in a structure (typedef struct player{  };player*/
printf(ANSI_COLOR_CYAN "\n    player 1 name: %s",&ply[1].name1);
    printf(ANSI_COLOR_YELLOW"\t\t\t\t\t\t\t player 2 name: %s\n\n",&ply[1].name2);
    printf(ANSI_COLOR_CYAN"    Number of moves for player 1: %d",ply[trn].moves1);
    printf(ANSI_COLOR_YELLOW"\t\t\t\t\t Number of moves for player 2:%d \n\n",ply[trn].moves2);
    printf(ANSI_COLOR_CYAN "    player 1's score = %d",ply[trn].score1);
    printf(ANSI_COLOR_YELLOW"\t\t\t\t\t\t\t player 2's score = %d\n\n"ANSI_COLOR_RESET,ply[trn].score2);
    printf("    Number of remaining lines: %d\t\t\t\t\t\t\n",ply[trn].remLines);

    printf("    Time passed for player 1: %d\t\t\t\t\t\t Time passed for player 2:%d\n",t3,t4);

}


void onePlayerMood(int n){
    g.z = n;
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
    fgets( ply[1].name1,50,stdin);
    fgets( ply[1].name1,50,stdin);

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
    int player=1; //if player odd-->player 1//if player even-->player 2(computer)
    int row,col,temp; //temp takes the value of the input element of array
    start:

    while(noOfMoves>=0)//loop of the game stops when no more lines existing//start the game
    {
        strcpy(ply[1].name2, "Computer");
        system("CLS");
        printData(trn,t3,t4); //printing the interface
        printGrid(n,A);
        printf(ANSI_COLOR_CYAN"It's player 1's turn\n"ANSI_COLOR_RESET);
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
        else if (row==77&&col==7) {
                getchar();
                save(g.z,A);
                break;
            }
        else if((row%2==0&&col%2==1)||(row%2==1&&col%2==0)) //checking the validity of the input
        {
            temp=A[row][col];
            if(temp==0) //if no lines added before
            {   if(player%2==1){
                  A[row][col]=1;
                   mA++;
                   int x=check1(row,col,n,A,player);
                   if(x==0) player++;
                   else if(x>0) noOfMoves++;
}
                if(player%2==0){//computer
                    for(int i=0;i<2*n+2;i++){
                        if(player%2==1) break;
                        for(int j=0;j<2*n+2;j++){
                            if(i%2==0&&j%2==1&&i!=0&&A[i][j]==0){ //i is row,j is col
                                A[i][j]=2; mB++;
                                int x=check1(i,j,n,A,player);//check boxes each turn
                                if(x==0){player++; break;}

                            }
                        }
                     }
                    for(int i=0;i<2*n+2;i++){
                            if(player%2==1) break;
                            for(int j=0;j<2*n+2;j++){
                                if(player%2==0&&A[i][j]==0&&i%2==1&&j%2==0&&j!=0){
                                    A[i][j]=2; mB++;
                                    int x=check1(i,j,n,A,player);//check boxes each turn
                                     if(x==0){player++; break;}
                                        else if(x>0) noOfMoves--;
                                     }
                            }
                        }
                    }
                }
                 noOfMoves-=2; //decrease number of lines by 2 because of the computer's turn//decrement the counter of while loop
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
        printData(trn,t3,t4);
        printGrid(n,A);



   // Score,move,arr,totmoves,name
  //LOAD DATA TO THE ARRAY OF STRUCTURES
  char winnerName[20];int winnerScore;
  if (sA>sB){
    printf(ANSI_COLOR_MAGENTA"\n\t\t\t\tThe Winner Is %s",ply[1].name1);
    system("pause");
    strcpy(winnerName,ply[1].name1);
    winnerScore=ply[trn].score1;
    system("cls");
    loadRank(winnerName,winnerScore);
  }
  else if(sA<sB){
    printf(ANSI_COLOR_MAGENTA"\n\t\t\tThe Winner Is %s",ply[1].name2);
    system("pause");
    strcpy(winnerName,ply[1].name2);
    winnerScore=ply[trn].score2;
    system("cls");
    loadRank(winnerName,winnerScore);
  }
  else if(sA==sB&&noOfMoves==0){
    printf(ANSI_COLOR_MAGENTA"\n\t\t\t\t TIE!!!");
  }

}


void twoPlayerMood(int n){
    g.z=n;
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
    fgets( ply[1].name1,50,stdin);
    fgets( ply[1].name1,50,stdin);
    printf(ANSI_COLOR_YELLOW"\n\tEnter the name of the second player ");
    fgets( ply[1].name2,50,stdin);


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
        printData(trn,t3,t4); //printing the interface
        printGrid(n,A);
        if(player%2==1){//check if the 1's or the 2's turn
           printf(ANSI_COLOR_CYAN"It's player 1's turn\n"ANSI_COLOR_RESET);
            tA1=clock();
        }
        else{tB1=clock();
           printf(ANSI_COLOR_YELLOW"It's player 2's turn\n"ANSI_COLOR_RESET);

        }
        printf("\n\tFor undo enter 55 5, redo enter 66 6, save the game enter 77 7\n\tEnter row: ");
        scanf("%d",&row);
        printf("\tEnter Col: ");
        scanf("%d",&col);
        //indicator for undo
        if(row==55&&col==5&&trn!=1) //undo
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
         else if (row==77&&col==7) { //save
            getchar();
            save(g.z,A);
            break;         }

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
                 if(player%2==1){
                    tA2=clock();
                    t3=t3+(int)(tA2-tA1)/CLOCKS_PER_SEC;
                    }
                else
                {
                    tB2=clock();
                    t4=t4+(int)(tB2-tB1)/CLOCKS_PER_SEC;
                }
                tA1=0,tA2=0,tB2=0,tB1=0;
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

            int x=check2(row,col,n,A,player);//check boxes each turn
            if(x==1)
                player++;
            else if(x==2)
                player--;
                sA=0; sB=0;
            for(int i=0;i<2*n+2;i++){
                for(int j=0;j<2*n+2;j++){
                    if(A[i][j]==3)
                        sA++; //cyan
                    else if(A[i][j]==4)
                        sB++; //yellow
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
        printData(trn,t3,t4);
        printGrid(n,A);
    }


   // Score,move,arr,totmoves,name
//LOAD DATA TO THE ARRAY OF STRUCTURES
  char winnerName[20];int winnerScore;
  if (sA>sB){
    printf(ANSI_COLOR_MAGENTA"\n\t\t\t\tThe Winner Is %s",ply[1].name1);
    system("pause");
    strcpy(winnerName,ply[1].name1);
    winnerScore=ply[trn].score1;
    system("cls");
    loadRank(winnerName,winnerScore);
  }
  else if(sA<sB){
    printf(ANSI_COLOR_MAGENTA"\n\t\t\tThe Winner Is %s",ply[1].name2);
    system("pause");
    strcpy(winnerName,ply[1].name2);
    winnerScore=ply[trn].score2;
    system("cls");
    loadRank(winnerName,winnerScore);
  }
  else if(sA==sB&&noOfMoves==0){
    printf(ANSI_COLOR_MAGENTA"\n\t\t\t\t TIE!!!\n");
  }

}

#ifndef GAME_FUNCTIONS_H_INCLUDED
#define GAME_FUNCTIONS_H_INCLUDED

void printGrid(int n,int A[2*n+2][2*n+2]);
void printData();
int check(int row,int col,int n,int A[2*n+2][2*n+2],int player);
void twoPlayerMood(int n);
void oneOrTwoPlayers();
typedef struct player(){
 int score;//read value of scores  /*1*/
 int moves;//moves for each player  /*2*/
 int time;//time by each turn  /*3*/
 char name[20];//name of the players  /*4*/
 int boxes;//number of boxes /*5*/
 int A[2*n+2][2*n+2];//array indicates the statue of the grid  /*6*/
};

#endif // GAME_FUNCTIONS_H_INCLUDED

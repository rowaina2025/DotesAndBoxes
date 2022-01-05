#ifndef GAME_FUNCTIONS_H_INCLUDED
#define GAME_FUNCTIONS_H_INCLUDED

void printGrid(int n,int A[2*n+2][2*n+2]);
void Interface1();
void twoPlayer();
void printData();
int check1(int row,int col,int n,int A[2*n+2][2*n+2],int player);
void twoPlayerMood(int n );
int oneOrTwoPlayers();
void onePlayer();
void onePlayerMood(int n);
int check2(int row,int col,int n,int A[2*n+2][2*n+2],int player);


#endif // GAME_FUNCTIONS_H_INCLUDED

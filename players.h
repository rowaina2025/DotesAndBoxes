#ifndef PLAYERS_H_INCLUDED
#define PLAYERS_H_INCLUDED

typedef struct{

 int score1; //scores player 1
 int score2;  //scores player 2
 int moves1;  //moves player 1
 int moves2;  //moves player 2
 int remLines;  //remaining lines for the whole game
 char name1[20]; //name of first player
 char name2[20];  //name of the second player
 int arr[12][12]; //array of grid
 int turn; //even for second player and odd for the first player
 int rank1; //first rank
 int rank2; //second rank
 int T; //turn of the game
}Player;  //for game data overall
Player ply[55]; //array of the defined structure where each index contain the whole game data

struct users{
    char name[20];
    int score;
}; //for ranks

typedef struct { //for saving and loading data of the game which is not needed to be changed each turn
    int box; //number of boxes
    int trns; //the turn at which saved and loaded
    int oneTwo; //one or two players
    int t; //time
    int un; //to count number of undo moves so that redo does not exceed this number of moves

}game;
game g;

#endif // PLAYERS_H_INCLUDED

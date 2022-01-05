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
#include"mainFuction.h"

 struct Player{
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
};


int main()
{
    struct Player ply[40];
    Interface1();
    system("COLOR");
    return 0;
}

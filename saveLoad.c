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
#include"rank.h"
#include"printData.h"
#include"check.h"


void save(int n, int *A, int trn,int t3)
{
    FILE *fp;
    system("CLS");
    CHOICE: ;//empty statement
    int choice;
    printf("\n\n\n\t\t %c Choose where you want to save the file (1 or 2 or 3): \n\n\t\t main menu Enter 4\n\n\tTo go back Enter 5\n\n\t\tYOUR CHOICE: ",2); //select the file of saving
    scanf("%d",&choice);
    if(choice==1)
    {
        fp=fopen("SavingGame1.txt","w");
    }
    else if(choice==2)
    {
        fp=fopen("SavingGame2.txt","w");
    }
    else if(choice ==3)
    {
        fp=fopen("SavingGame3.txt","w");
    }
    else if(choice==4)
    {
        system("cls");
        Interface1();
    }
    else if(choice==5){
        system("cls");
        return;
    }
    else if(choice!=1||choice!=2||choice!=3||choice!=4)
    {
        system("cls");
        printf(BLU "\n\n\t\tInvalid Input\n\n\n"ANSI_COLOR_RESET);
        getch();
        goto CHOICE;
    }
    n=g.box;
    g.trns=trn;
    g.t=t3;
    fprintf(fp,"%d\n%d\n%d\n%d\n%d\n",g.box,g.trns, g.oneTwo, t3,g.un);
    for(int i=0;i<55;i++)
    {
        fprintf(fp,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",ply[i].moves1,ply[i].moves2,ply[i].score1,ply[i].score2,ply[i].T,ply[i].rank1,ply[i].rank2,ply[i].remLines,ply[i].turn);
    }
    for(int i=1;i<55;i++)
    {
        for(int j=0;j<2*n+2;j++)
        {
            for(int k=0;k<2*n+2;k++)
            {
            fprintf(fp,"%d\n",ply[i].arr[j][k]);
            }
        }
    }
    fprintf(fp,"%s ",ply[1].name1);
    fprintf(fp,"%s ",ply[1].name2);
    printf("\nData is stored successfully to your file!! %c\n ",3);
    getch();
    fclose(fp); //close file//data saved successfully!

}
void load() //load saved file
{
    system("color DF");
    FILE *fp;
    system("cls");
    CHOICE: ;//empty statement

    int choice;
    printf("\n\n\n\t\t %c Choose from which file you want to load your game (1 or 2 or 3): \n\n\t\t main menu Enter 4\n\n\t\tTo return enter 5:\n\n\tYOUR CHOICE: ", 1);
    scanf("%d",&choice);
    if(choice==1)
    {
        fp=fopen("SavingGame1.txt","r");
    }
    else if(choice==2)
    {
        fp=fopen("SavingGame2.txt","r");
    }
    else if(choice==3)
    {
        fp=fopen("SavingGame3.txt","r");
    }
    else if(choice==4)
    {
        system("cls");
        Interface1();
    }
    else if(choice==5)
    {
        system("cls");
        return;
    }
    else if(choice!=1||choice!=2||choice!=3||choice!=4||choice!=5 )
    {
        printf("\n\tINVALID INPUT!!");
        system("cls");
        goto CHOICE;
    }
    if(fp==NULL)
    {
        printf( BLU "\n\tFILE NOT FOUND!! ");
        //getch();
        goto CHOICE;
    }
    else
    {
        fscanf(fp,"%d%d%d%d%d",&g.box,&g.trns,&g.oneTwo,&g.t,&g.un);
        int n=g.box;
        for(int i=0;i<55;i++)
        {
            fscanf(fp,"%d%d%d%d%d%d%d%d%d",&ply[i].moves1,&ply[i].moves2,&ply[i].score1,&ply[i].score2,&ply[i].T,&ply[i].rank1,&ply[i].rank2,&ply[i].remLines,&ply[i].turn);
        }
        for(int i=1;i<55;i++)
        {
            for(int j=0;j<2*n+2;j++)
            {
                for(int k=0;k<2*n+2;k++)
                {
                    fscanf(fp,"%d",&ply[i].arr[j][k]);
                }
            }
        }
        fgets(ply[1].name1,20,fp);
        fgets(ply[1].name1,20,fp);
        fgets(ply[1].name2,20,fp);
        getch();
        fclose(fp);
        if(g.oneTwo==1)
        {
            onePlayerMood(g.box,g.trns,1);
        }
        else if(g.oneTwo==2)
        {
            twoPlayerMood(g.box,g.trns,1);
        }
    }
}

void debug(int n,int A[2*n+2][2*n+2])
{
    FILE *fp;
    fp=fopen("debug.txt","w");
    for(int i=0;i<2*n+2;i++){
        for(int j=0;j<2*n+2;j++){
            fprintf(fp,"%d ",A[i][j]);
        }fprintf(fp,"\n");
    }
    fclose(fp);
}




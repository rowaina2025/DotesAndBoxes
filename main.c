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
#include"check.h"


int main()
{
    Interface1();//start the whole program
    return 0;
}

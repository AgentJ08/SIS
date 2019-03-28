#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void heading()
{
    printf("\t\t\t\t  Tic Tac Toe Game:\n\n\n\n");
}
void layout(char a[])
{
    int i,j,k;
    printf("\t\t\t\t      |\t      |\n");
    //printf("\t\t\t%d",a[0]);
    printf("\t\t\t\t   %c  |\t  %c   |\t  %c\n",a[0],a[1],a[2]);
    printf("\t\t\t\t");
    for(i=0;i<9;i++) {printf("_ "); if((i+1)%3==0 && i!=8) printf("| ");}
    printf("\n\t\t\t\t      |\t      |\n\t\t\t\t   %c  |\t  %c   |\t  %c\n",a[3],a[4],a[5]);
    printf("\t\t\t\t");
    for(i=0;i<9;i++) {printf("_ "); if((i+1)%3==0 && i!=8) printf("| ");}
    printf("\n\t\t\t\t      |\t      |\n\t\t\t\t   %c  |\t  %c   |\t  %c\n",a[6],a[7],a[8]);
    printf("\t\t\t\t      |\t      |\n\n\n");
}
int checkwin(char a[])
{
    if((a[0]==a[1]&&a[1]==a[2])||(a[3]==a[4]&&a[4]==a[5])||(a[6]==a[7]&&a[7]==a[8])||(a[0]==a[3]&&a[3]==a[6])||(a[1]==a[4]&&a[4]==a[7])||(a[2]==a[5]&&a[5]==a[8])||(a[0]==a[4]&&a[4]==a[8])||(a[2]==a[4]&&a[4]==a[6])) return 1;
    else return 0;
}
void multigame(char a[], char p1[], char s1, char p2[], char s2)
{
    int i,j,k,count=1, place,cwin=0;
    layout(a);
    printf("Both players just have to enter the place where they want there move to be!\n\n\t\t\tAnd the game starts now...\n\n");
    while(count!=10)
    {
        cwin=0;
        if(count%2!=0)
        {
            printf("%s's turn: ",p1);
            scanf("%d",&place);
            if(((int)a[place-1] - (int)'0')!=place) {printf("Invalid Move!\n"); continue;}
            else
            {
                a[place-1] = s1;
                layout(a);
            }
            cwin = checkwin(a);
            if(cwin)
            {
                printf("\n%s won the match!",p1);
                break;
            }
        }
        else
        {
            printf("%s's turn: ",p2);
            scanf("%d",&place);
            if(((int)a[place-1] - (int)'0')!=place) {printf("Invalid Move!\n"); continue;}
            else
            {
                a[place-1] = s2;
                layout(a);
            }
            cwin = checkwin(a);
            if(cwin)
            {
                printf("\n%s won the match!",p2);
                break;
            }
        }
        count++;
        if(count==10) printf("Match Drawn! You both are winners! :3\n");
    }
}
void easysinglegame(char a[], char p1[], char s1, char p2[], char s2)
{
    int i,j,k,count=1, place,cwin=0;
    layout(a);
    printf("Both players just have to enter the place where they want there move to be!\n\n\t\t\tAnd the game starts now...\n\n");
    while(count!=10)
    {
        cwin=0;
        if(count%2!=0)
        {
            printf("%s's turn: ",p1);
            scanf("%d",&place);
            if(((int)a[place-1] - (int)'0')!=place) {printf("Invalid Move!\n"); continue;}
            else
            {
                a[place-1] = s1;
                layout(a);
            }
            cwin = checkwin(a);
            if(cwin)
            {
                printf("\n%s won the match!",p1);
                break;
            }
        }
        else
        {
            place=(rand()%9)+1;
            if(((int)a[place-1] - (int)'0')!=place) {/*printf("Invalid Move!\n");*/ continue;}
            else
            {
                printf("%s's turn: ",p2);
                printf("%d\n",place);
                a[place-1] = s2;
                layout(a);
            }
            cwin = checkwin(a);
            if(cwin)
            {
                printf("\n%s won the match!",p2);
                break;
            }
        }
        count++;
        if(count==10) printf("Match Drawn! You both are winners! :3\n");
    }
}
int findhardplace(char a[])
{
    int place;
    if(a[0]==a[1] && a[0] == 'o' && ((int)a[2] - (int)'3') == 0) place=3;
    else if(a[3]==a[4] && a[3] == 'o' && ((int)a[5] - (int)'6') == 0) place=6;
    else if(a[6]==a[7] && a[6] == 'o' && ((int)a[8] - (int)'9') == 0) place=9;
    else if(a[0]==a[2] && a[0] == 'o' && ((int)a[1] - (int)'2') == 0) place=2;
    else if(a[3]==a[5] && a[3] == 'o' && ((int)a[4] - (int)'5') == 0) place=5;
    else if(a[6]==a[8] && a[6] == 'o' && ((int)a[7] - (int)'8') == 0) place=8;
    else if(a[1]==a[2] && a[1] == 'o' && ((int)a[0] - (int)'1') == 0) place=1;
    else if(a[4]==a[5] && a[4] == 'o' && ((int)a[3] - (int)'4') == 0) place=4;
    else if(a[7]==a[8] && a[7] == 'o' && ((int)a[6] - (int)'7') == 0) place=7;
    else if(a[0]==a[3] && a[0] == 'o' && ((int)a[6] - (int)'7') == 0) place=7;
    else if(a[0]==a[6] && a[0] == 'o' && ((int)a[3] - (int)'4') == 0) place=4;
    else if(a[3]==a[6] && a[3] == 'o' && ((int)a[0] - (int)'1') == 0) place=1;
    else if(a[1]==a[4] && a[1] == 'o' && ((int)a[7] - (int)'8') == 0) place=8;
    else if(a[1]==a[7] && a[1] == 'o' && ((int)a[4] - (int)'5') == 0) place=5;
    else if(a[4]==a[7] && a[4] == 'o' && ((int)a[1] - (int)'2') == 0) place=2;
    else if(a[2]==a[5] && a[2] == 'o' && ((int)a[8] - (int)'9') == 0) place=9;
    else if(a[2]==a[8] && a[2] == 'o' && ((int)a[5] - (int)'6') == 0) place=6;
    else if(a[5]==a[8] && a[5] == 'o' && ((int)a[2] - (int)'3') == 0) place=3;
    else if(a[0]==a[4] && a[0] == 'o' && ((int)a[8] - (int)'9') == 0) place=9;
    else if(a[0]==a[8] && a[0] == 'o' && ((int)a[4] - (int)'5') == 0) place=5;
    else if(a[4]==a[8] && a[4] == 'o' && ((int)a[0] - (int)'1') == 0) place=1;
    else if(a[2]==a[4] && a[2] == 'o' && ((int)a[6] - (int)'7') == 0) place=7;
    else if(a[2]==a[6] && a[2] == 'o' && ((int)a[4] - (int)'5') == 0) place=5;
    else if(a[4]==a[6] && a[4] == 'o' && ((int)a[2] - (int)'3') == 0) place=3;
    else if(a[0]==a[1] && ((int)a[2] - (int)'3') == 0) place=3;
    else if(a[3]==a[4] && ((int)a[5] - (int)'6') == 0) place=6;
    else if(a[6]==a[7] && ((int)a[8] - (int)'9') == 0) place=9;
    else if(a[0]==a[2] && ((int)a[1] - (int)'2') == 0) place=2;
    else if(a[3]==a[5] && ((int)a[4] - (int)'5') == 0) place=5;
    else if(a[6]==a[8] && ((int)a[7] - (int)'8') == 0) place=8;
    else if(a[1]==a[2] && ((int)a[0] - (int)'1') == 0) place=1;
    else if(a[4]==a[5] && ((int)a[3] - (int)'4') == 0) place=4;
    else if(a[7]==a[8] && ((int)a[6] - (int)'7') == 0) place=7;
    else if(a[0]==a[3] && ((int)a[6] - (int)'7') == 0) place=7;
    else if(a[0]==a[6] && ((int)a[3] - (int)'4') == 0) place=4;
    else if(a[3]==a[6] && ((int)a[0] - (int)'1') == 0) place=1;
    else if(a[1]==a[4] && ((int)a[7] - (int)'8') == 0) place=8;
    else if(a[1]==a[7] && ((int)a[4] - (int)'5') == 0) place=5;
    else if(a[4]==a[7] && ((int)a[1] - (int)'2') == 0) place=2;
    else if(a[2]==a[5] && ((int)a[8] - (int)'9') == 0) place=9;
    else if(a[2]==a[8] && ((int)a[5] - (int)'6') == 0) place=6;
    else if(a[5]==a[8] && ((int)a[2] - (int)'3') == 0) place=3;
    else if(a[0]==a[4] && ((int)a[8] - (int)'9') == 0) place=9;
    else if(a[0]==a[8] && ((int)a[4] - (int)'5') == 0) place=5;
    else if(a[4]==a[8] && ((int)a[0] - (int)'1') == 0) place=1;
    else if(a[2]==a[4] && ((int)a[6] - (int)'7') == 0) place=7;
    else if(a[2]==a[6] && ((int)a[4] - (int)'5') == 0) place=5;
    else if(a[4]==a[6] && ((int)a[2] - (int)'3') == 0) place=3;
    else place=(rand()%9)+1;
    return place;
}
void hardsinglegame(char a[], char p1[], char s1, char p2[], char s2)
{
    int i,j,k,count=1, place,cwin=0;
    layout(a);
    printf("Both players just have to enter the place where they want there move to be!\n\n\t\t\tAnd the game starts now...\n\n");
    while(count!=10)
    {
        cwin=0;
        if(count%2!=0)
        {
            printf("%s's turn: ",p1);
            scanf("%d",&place);
            if(((int)a[place-1] - (int)'0')!=place) {printf("Invalid Move!\n"); continue;}
            else
            {
                a[place-1] = s1;
                layout(a);
            }
            cwin = checkwin(a);
            if(cwin)
            {
                printf("\n%s won the match!",p1);
                break;
            }
        }
        else
        {
            place = findhardplace(a);
            if(((int)a[place-1] - (int)'0')!=place) {/*printf("Invalid Move!\n");*/ continue;}
            else
            {
                printf("%s's turn: ",p2);
                printf("%d\n",place);
                a[place-1] = s2;
                layout(a);
            }
            cwin = checkwin(a);
            if(cwin)
            {
                printf("\n%s won the match!",p2);
                break;
            }
        }
        count++;
        if(count==10) printf("Match Drawn! You both are winners! :3\n");
    }
}
int main()
{
    int singmulti;
    char a[]={'1','2','3','4','5','6','7','8','9'};
    heading();
    char p1[30], p2[30],s1,s2;
    printf("Wanna play single-player or multi-player?\nPress 1 for single player and 2 for multiplayer: ");
    scanf("%d",&singmulti);
    if(singmulti==2)
    {
        printf("Name of player 1: ");
        scanf("%s",p1);
        s1='x';
        printf("Name of player 2: ");
        scanf("%s",p2);
        s2='o';
        multigame(a,p1,s1,p2,s2);
    }
    else if(singmulti==1)
    {
        printf("Name of player 1: ");
        scanf("%s",p1);
        s1='x';
        strcpy(p2,"Tac");
        s2='o';
        printf("%s, your symbol is %c and you are now playing with %s whose symbol is %c!\n",p1,s1,p2,s2);
        printf("Press 1 for easy opponent, and 2 for hard opponent: ");
        int level;
        scanf(" %d",&level);
        if(level==1) easysinglegame(a,p1,s1,p2,s2);
        else if(level==2) hardsinglegame(a,p1,s1,p2,s2);
        else printf("Invalid Entry! Exiting the Game!\n");
    }
    else printf("Invalid Entry! Exiting the Game!\n");
    return 0;
}

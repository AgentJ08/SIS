#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <windows.h>
#include<string.h>
#include<ctype.h>
#include<dos.h>
#include<time.h>
#include<stdbool.h>
void setcolor(int ForgC)
{
     WORD wColor;
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
}
//Displays date and time on the top right corner of the screen
void date(){
    time_t t = time(NULL);
struct tm tm = *localtime(&t);

printf(" \t\t\t\t\t\t\t\t\t\t\tDate:%d-%d-%d \n \t\t\t\t\t\t\t\t\t\t\tTime:%d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec");
}
int checkunamesignup(char uname[])
{
    FILE *p;
    p = fopen("users.txt","r");
    int count=0, uexist=0;
    char a[1000][30];
    while(!feof(p))
    {
        fscanf(p,"%s",a[count]);
        if(!strcmp(uname,a[count]))
        {
            count=count+2;
            uexist=1;
            break;
        }
    }
    return uexist;
}
int signup()
{
    int checkuname;
    char uname[30], pass[30];
    printf("Enter following credentials to signup on SIS:-\n\nEnter your username:\n");
    scanf("%s",uname);
    while(checkunamesignup(uname))
    {
        printf("Username already taken! Please try again...");
        scanf("%s",uname);
    }
    printf("Enter your password:\n");
    scanf("%s",pass);
    FILE *p;
    p = fopen("users.txt","a");
    fprintf(p,"%s\n%s\n",uname,pass);
    fclose(p);
    printf("Thank you for creating an account, %s!", uname);
    return 1;
}
void login()
{
    FILE *p;
    p = fopen("users.txt","r");
    char uname[30], pass[30];
    printf("Enter following credentials to login on SIS:-\n\nEnter your username:\n");
    scanf("%s",uname);
    printf("Enter your password:\n");
    scanf("%s",pass);
    int count=0, uexist=0;
    char a[1000][30];
    while(!feof(p))
    {
        fscanf(p,"%s",a[count]);
        if(!strcmp(uname,a[count]))
        {
            count++;
            fscanf(p,"%s",a[count]);
            if(!strcmp(pass,a[count]))
            {
                printf("User Exist!");
                uexist = 1;
                count++;
                break;
            }
        }
        count++;
    }
    if(!uexist) printf("User does not exist in databse!");
}
int main()
{
    setcolor(10);
    int su;
    printf("New user? Press 1 for sign up!\nOr press 2 to login...\n");
    scanf("%d",&su);
    if(su==1)
    {
        if(signup())
        {
            system("cls");
            printf("*Redirecting you to login page...*\n\nEnter your login credentials:-\n\n");
            //system("cls");
            login();
        }
    }
    else if(su==2) login();
    else printf("Invalid Entry!\n");
    return 0;
}

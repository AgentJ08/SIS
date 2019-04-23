#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
int checkunamesignup(char uname[])
{
    FILE *p;
    p = fopen("users.txt","r");
    int count=0, uexist=0;
    char a[1000][30];
    if(p)
    {
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
        //printf("In while!\n");
        printf("Username already taken! Please try again...\n");
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
    int count=0, uexist=0, wrongpass=0;
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
            else {printf("Password is not correct. Try again...\n"); wrongpass=1; login(); break;}
        }
        count=count+2;
    }
    if(!uexist&&!wrongpass) printf("User does not exist in databse!");
}
int main()
{
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

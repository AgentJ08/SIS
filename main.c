#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
int signup(char uname[], char pass[])
{
    FILE *p;
    p = fopen("users.txt","a");
    fprintf(p,"%s\n%s\n",uname,pass);
    fclose(p);
    printf("Thank you for creating an account, %s!", uname);
    return 1;
}
void login(char uname[], char pass[])
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
    char uname[30], pass[30];
    printf("Enter following credentials to signup on SIS:-\n\nEnter your username:\n");
    scanf("%s",uname);
    printf("Enter your password:\n");
    scanf("%s",pass);
    if(signup(uname,pass))
    {
        system("cls");
        printf("*Redirecting you to login page...*\n\nEnter your login credentials:-\n\n");
        //system("cls");
        printf("Enter your username:\n");
        scanf("%s",uname);
        printf("Enter your password:\n");
        scanf("%s",pass);
        login(uname,pass);
    }
    return 0;
}

#include<stdio.h>

#include<string.h>

#include<stdlib.h>

#include<math.h>
/*#include<conio.h>

#include <windows.h>

#include<ctype.h>

#include<dos.h>

#include<time.h>

#include<stdbool.h>*/




#define Student struct Stud



void add(FILE * fp); //to add to list

FILE * del(FILE * fp);//to delete from list

void modify(FILE * fp);//to modify a record

void displayList(FILE * fp);//display whole list

void searchRecord(FILE *fp);//find a particular record

void printChar(char ch,int n);//printing a character ch n times

void printHead();//printing head line for each screen

void attendance(FILE *fp); //to perform advance algorithm functions

void createdebarred(FILE *fp,int deb);

void mercy(int extra,int deb);

void saveall(int deb);

void saveplot(int deb);

struct node
    {
        char name[100];
        int roll;
        struct node *ptr;
        int present;
        int total;
        int p;
    };
typedef struct node NODE;

NODE *head, *first, *temp = 0;

struct SUB{


    int present;

    int p;

    int total;

};

struct Stud

{

    char name[100];

    char branch[50];

    int roll;

    float sgpa[8];

    float cgpa;

    struct SUB sdf,math,physics,es;


};



int main()

{

 FILE * fp;

 first=0;

 Student s;

int option;

char another;



if((fp=fopen("studentInfo.txt","rb+"))==NULL)

{

    if((fp=fopen("studentInfo.txt","wb+"))==NULL)

       {

           printf("can't open file");

           return 0;

       }

}



printHead();

printf("\n\n\t\t\t  CREATED BY  ");

printf("\n\n\t\t\t CODING NINJAS ");

printf("\n\n\t\t\t JIIT");

printf("\n\n\n\n\n\n\n \t\tPress Any Key To Continue.................");

getch();



while(1)

{

    printHead();

    printf("\n\t");

    printChar('-',64);



    printf("\n\n\t\t\t1. ADD Student");

    printf("\n\n\t\t\t2. DELETE Student");

    printf("\n\n\t\t\t3. MODIFY Student");

    printf("\n\n\t\t\t4. DISPLAY Student LIST");

    printf("\n\n\t\t\t5. Search Record");

    printf("\n\n\t\t\t6. Advanced Attendance System ");

    printf("\n\n\t\t\t0. EXIT");



    printf("\n\n\t\tEnter Your Option :--> ");

    scanf("%d",&option);



    switch(option)

    {

        case 0: return 1;

                break;

        case 1: add(fp);

                break;

        case 2: fp=del(fp);

                break;

        case 3: modify(fp);

                break;

        case 4: displayList(fp);

                break;

        case 5: searchRecord(fp);

                break;

        case 6: attendance(fp);
                break;

        default: printf("\n\t\tYou Pressed wrong key");

                  printf("\n\t\tProgram terminated");

                  getch();

                  exit(0);



    }

}

return 1;



}



//----printing character ch at n times ------



void printChar(char ch,int n)

{

    while(n--)

    {

        putchar(ch);

    }

}



//-----Printing Head Line of the program -----



void printHead()

{ system("cls");



printf("\n\n\t");

printChar('=',16);

printf("[STUDENT] [INFORMATION] [SYSTEM]");

printChar('=',16);

printf("\n");

}





// ==========ADDING NEW RECORD==========================



void add(FILE * fp)

{

printHead();



char another='y';

Student s;

int i;

float cgpa;



fseek(fp,0,SEEK_END);

while(another=='y'||another=='Y')

{



    printf("\n\n\t\tEnter Full Name of Student\t");

    fflush(stdin);

    fgets(s.name,100,stdin); //fgets takes an extra \n character as input

    s.name[strlen(s.name)-1]='\0';



    printf("\n\n\t\tEnter Branch\t");

    fflush(stdin);

    fgets(s.branch,50,stdin);

    s.branch[strlen(s.branch)-1]='\0';



    printf("\n\n\t\tEnter Roll number \t");

    scanf("%d",&s.roll);



    printf("\n\n\tEnter SGPA for 8 semesters\n\t");

    for(i=0,cgpa=0;i<8;i++)

    {
    scanf("%f",&s.sgpa[i]);
    printf("\n\t");
    cgpa+=s.sgpa[i];



    }



    cgpa/=8.0;

    s.cgpa=cgpa;

    fflush(stdin);

    printf("\n\n\t Enter total number of classes of SDF held during the semester : ");
    scanf("%d",&s.sdf.total);

    printf("\n\n\t Enter total number of classes attented during the semester   : ");
    scanf("%d",&s.sdf.present);

    s.sdf.p=s.sdf.present*100;
    s.sdf.p=s.sdf.p/s.sdf.total;

    printf("\n\n\t Enter total number of classes of MATH held during the semester :   ");
    scanf("%d",&s.math.total);

    printf("\n\n\t Enter total number of classes attented during the semester     :   ");
    scanf("%d",&s.math.present);

    s.math.p=s.math.present*100;
    s.math.p=s.math.p/s.math.total;

    printf("\n\n\t Enter total number of classes of ES held during the semester :  ");
    scanf("%d",&s.es.total);

    printf("\n\n\t Enter total number of classes attented during the semester   :  ");
    scanf("%d",&s.es.present);

    s.es.p=s.es.present*100;
    s.es.p=s.es.p/s.es.total;

    printf("\n\n\t Enter total number of classes of PHYSICS held during the semester :  ");
    scanf("%d",&s.physics.total);

    printf("\n\n\t Enter total number of classes attented during the semester        :  ");
    scanf("%d",&s.physics.present);

    s.physics.p=s.physics.present*100;
    s.physics.p=s.physics.p/s.physics.total;


    fwrite(&s,sizeof(s),1,fp);



    printf("\n\n\t\tWant to enter another student info (Y/N)\t");

    fflush(stdin);

    another=getchar();

}

}





//===================DELETING A RECORD FROM LIST ============

FILE * del(FILE * fp)

{

 printHead();



Student s;

int flag=0,tempRoll,siz=sizeof(s);

FILE *ft;



if((ft=fopen("temp.txt","wb+"))==NULL)

{

    printf("\n\n\t\t\t\\t!!! ERROR !!!\n\t\t");

    system("pause");

     return fp;

}



printf("\n\n\tEnter Roll number of Student to Delete the Record");

printf("\n\n\t\t\tRoll No. : ");

scanf("%d",&tempRoll);



rewind(fp);





while((fread(&s,siz,1,fp))==1)

{

    if(s.roll==tempRoll)

    { flag=1;

    printf("\n\tRecord Deleted for");

    printf("\n\n\t\t%s\n\n\t\t%s\n\n\t\t%d\n\t",s.name,s.branch,s.roll);

    continue;

    }



    fwrite(&s,siz,1,ft);

}





fclose(fp);

fclose(ft);



remove("studentInfo.txt");

rename("temp.txt","studentInfo.txt");



if((fp=fopen("studentInfo.txt","rb+"))==NULL)

{

    printf("ERROR");

    return  NULL;

}



if(flag==0) printf("\n\n\t\t!!!! ERROR RECORD NOT FOUND \n\t");



printChar('-',65);

printf("\n\t");

system("pause");

return fp;

}





//===========MODIFY A RECORD ===========================



void modify(FILE * fp)

{

printHead();



Student s;

int i,flag=0,tempRoll,siz=sizeof(s);

float cgpa;



printf("\n\n\tEnter Roll Number of Student to MODIFY the Record : ");

scanf("%d",&tempRoll);



rewind(fp);



while((fread(&s,siz,1,fp))==1)

{

    if(s.roll==tempRoll)

        {flag=1;

        break;

        }

}



if(flag==1)

    {

    fseek(fp,-siz,SEEK_CUR);

    printf("\n\n\t\tRECORD FOUND");

    printf("\n\n\t\tEnter New Data for the Record");



    printf("\n\n\t\tEnter Full Name of Student\t");

    fflush(stdin);

    fgets(s.name,100,stdin);

    s.name[strlen(s.name)-1]='\0';



    printf("\n\n\t\tEnter Branch\t");

    fflush(stdin);

    fgets(s.branch,50,stdin);

    s.branch[strlen(s.branch)-1]='\0';



    printf("\n\n\t\tEnter Roll number \t");

    scanf("%d",&s.roll);





    printf("\n\n\tEnter SGPA for 8 semesters\n\t");

    for(i=0,cgpa=0;i<8;i++)

    {scanf("%f",&s.sgpa[i]);
    printf("\n\t");
    cgpa+=s.sgpa[i];



    }

    cgpa=cgpa/8.0;

    printf("\n\n\t Enter total number of classes of SDF held during the semester : ");
    scanf("%d",&s.sdf.total);

    printf("\n\n\t Enter total number of classes attented during the semester   : ");
    scanf("%d",&s.sdf.present);

    s.sdf.p=s.sdf.present*100;
    s.sdf.p=s.sdf.p/s.sdf.total;

    printf("\n\n\t Enter total number of classes of MATH held during the semester :   ");
    scanf("%d",&s.math.total);

    printf("\n\n\t Enter total number of classes attented during the semester     :   ");
    scanf("%d",&s.math.present);

    s.math.p=s.math.present*100;
    s.math.p=s.math.p/s.math.total;

    printf("\n\n\t Enter total number of classes of ES held during the semester :  ");
    scanf("%d",&s.es.total);

    printf("\n\n\t Enter total number of classes attented during the semester   :  ");
    scanf("%d",&s.es.present);

    s.es.p=s.es.present*100;
    s.es.p=s.es.p/s.es.total;

    printf("\n\n\t Enter total number of classes of PHYSICS held during the semester :  ");
    scanf("%d",&s.physics.total);

    printf("\n\n\t Enter total number of classes attented during the semester        :  ");
    scanf("%d",&s.physics.present);

    s.physics.p=s.physics.present*100;
    s.physics.p=s.physics.p/s.physics.total;

    fwrite(&s,sizeof(s),1,fp);

}



else printf("\n\n\t!!!! ERROR !!!! RECORD NOT FOUND");



printf("\n\n\t");

system("pause");



}



//====================DISPLAY THE LIST =================

void displayList(FILE * fp)

{   printHead();

    Student s;

    int i,siz=sizeof(s);



    rewind(fp);



    while((fread(&s,siz,1,fp))==1)

    {

        printf("\n\t\tNAME : %s",s.name);

        printf("\n\n\t\tBRANCH : %s",s.branch);

        printf("\n\n\t\tROLL : %d",s.roll);

        printf("\n\n\tSGPA: ");



        for(i=0;i<8;i++)

            printf("| %.2f |",s.sgpa[i]);

        printf("\n\n\t\tCGPA : %.2f\n\t",s.cgpa);

        printChar('-',65);

        printf("\n\n\t Attendance Status \n\t");

        printf("\n\n\t     SDF = %d out of %d (Percentage = %d ) \n\t",s.sdf.present,s.sdf.total,s.sdf.p);
        printf("\n\n\t   Maths = %d out of %d (Percentage = %d ) \n\t",s.math.present,s.math.total,s.math.p);
        printf("\n\n\t      ES = %d out of %d (Percentage = %d ) \n\t",s.es.present,s.es.total,s.es.p);
        printf("\n\n\t Physics = %d out of %d (Percentage = %d ) \n\t",s.physics.present,s.physics.total,s.physics.p);


    }

    printf("\n\n\n\t");

     printChar('*',65);

    printf("\n\n\t");

    system("pause");

}

void attendance(FILE * fp)

{
    int deb=60,flag=0;

    int choice=1,extra;

    printHead();

    while(choice)
    {


        printf("\n\n\t\t\t ----- Advance Attendance System ----");
        printf("\n\n\n\n\t\t\t Debarred At - %d Percent ",deb);

        Student s;

        printf("\n\n\t\t\t1. Calculate Number Students who will be Debarred");

        printf("\n\n\t\t\t2. Number of Extra Classes and Number of Student Saved From It ");

        printf("\n\n\t\t\t3. Number of Extra Classes Required to Save Everyone");

        printf("\n\n\t\t\t4. Plot Table of Extra Classes to Students Saved");

        printf("\n\n\t\t\t5. Change Debarred At Value");

        printf("\n\n\t\t\t0. EXIT");



        printf("\n\n\t\tEnter Your Option :--> ");

        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : createdebarred(fp,deb);
                     printf("\n\n\t Press Any Key To Continue........................");
                     getch();
                     system("cls");
                     break;

            case 2 : printf("\n\n\t\t\t Enter Number of Extra classes you can manage  - ");
                     scanf("%d",&extra);
                     mercy(extra,deb);
                     printf("\n\n\n\t\t Press Any Key To Continue........................");
                     getch();
                     system("cls");
                     break;

            case 3 : saveall(deb);
                     printf("\n\n\n\t\t Press Any Key To Continue........................");
                     getch();
                     system("cls");
                     break;

            case 4 : saveplot(deb);
                     printf("\n\n\n\t\t Press Any Key To Continue........................");
                     getch();
                     system("cls");
                     break;

            case 5: printf(" \n\n\n\t Enter the new Value of Debarred At ( Current value is %d %)  ",deb);
                    scanf("%d",&deb);
                    printf("\n\n\n\t\t Press Any Key To Continue........................");
                    getch();
                    system("cls");
                    break;
        }
    }

}

void saveplot(int deb)
{
    int i=0;

    for(i=0;i<10;i++)
    {
        mercy(i,deb);
    }
}

void saveall(int deb)
{
    NODE *temp2;
    int countsaveall=0;
    int lowest;
    temp=first;
    temp2=temp;
    lowest=temp->p;
    while(temp!=0)
    {
        if(lowest>(temp->p))
        {
            temp2=temp;
        }
        temp=temp->ptr;
    }
    while((temp2->p)< deb)
    {
        temp2->present+=1;
        temp2->total+=1;
        temp2->p=(temp2->present)*100;
        temp2->p=(temp2->p)/(temp2->total);
        countsaveall++;
    }
    printf("\n\n\t Number of Extra Classes Required To Save Everyone = %d ",countsaveall);
    temp2->present-=countsaveall;
    temp2->total-=countsaveall;
    temp2->p=(temp2->present)*100;
    temp2->p=(temp2->p)/(temp2->total);

}
void mercy(int extra,int deb)
{

    temp=first;
    int countsaved=0;
    while(temp!=0)
    {
        temp->present+=extra;
        temp->total+=extra;
        temp->p=(temp->present)*100;
        temp->p=(temp->p)/(temp->total);
        if((temp->p) > deb)
            countsaved++;
        temp->present-=extra;
        temp->total-=extra;
        temp->p=(temp->present)*100;
        temp->p=(temp->p)/(temp->total);
        temp=temp->ptr;
    }
    printf("\n\n\t Number of Students Saved From %d Extra Classes are %d ",extra,countsaved);

}
void createdebarred( FILE *fp, int deb)
{
    int countd=0;
    Student s;
    int siz;
    rewind(fp);
    siz=sizeof(s);
    while((fread(&s,siz,1,fp))==1)
    {

        if(s.sdf.p <= deb)
        {
            countd++;
            head = (NODE *)malloc(sizeof(NODE));
            head->roll=s.roll;
            head->p=s.sdf.p;
            head->present=s.sdf.present;
            head->total=s.sdf.total;
            if (first != 0)
            {
                temp->ptr = head;
                temp = head;
            }
            else
            {
                first = temp = head;
            }
        }

    }
    temp->ptr = 0;
    printf("\n\n\n\t  Number Of Students debarred is - %d" ,countd);
}


void searchRecord(FILE *fp)

{printHead();



int tempRoll,flag,siz,i;

Student s;

char another='y';



siz=sizeof(s);



while(another=='y'||another=='Y')

{

printf("\n\n\tEnter Roll Number of Student to search the record : ");

scanf("%d",&tempRoll);



rewind(fp);



while((fread(&s,siz,1,fp))==1)

{

    if(s.roll==tempRoll)

        {flag=1;

        break;

        }

}



if(flag==1)

    {

    printf("\n\t\tNAME : %s",s.name);

        printf("\n\n\t\tBRANCH : %s",s.branch);

        printf("\n\n\t\tROLL : %d",s.roll);

        printf("\n\n\tSGPA: ");



        for(i=0;i<8;i++)

            printf("| %.2f |",s.sgpa[i]);

        printf("\n\n\t\tCGPA : %.2f\n\t",s.cgpa);

        printf("\n\n\t Attendance Status \n\t");

        printf("\n\n\t     SDF = %d out of %d (Percentage = %d ) \n\t",s.sdf.present,s.sdf.total,s.sdf.p);
        printf("\n\n\t   Maths = %d out of %d (Percentage = %d ) \n\t",s.math.present,s.math.total,s.math.p);
        printf("\n\n\t      ES = %d out of %d (Percentage = %d ) \n\t",s.es.present,s.es.total,s.es.p);
        printf("\n\n\t Physics = %d out of %d (Percentage = %d ) \n\t",s.physics.present,s.physics.total,s.physics.p);

        printChar('-',65);



}

else printf("\n\n\t\t!!!! ERROR RECORD NOT FOUND !!!!");

printf("\n\n\t\tWant to enter another search (Y/N)");

fflush(stdin);

another=getchar();

}

}
/*
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
setcolor(10);//this goes in main
*/


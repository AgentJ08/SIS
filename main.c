#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <math.h>

#include<conio.h>

#include <windows.h>

#include<ctype.h>

#include<dos.h>

#include<time.h>

#include<stdbool.h>

#define Student struct Stud

void AddStudentRecord(FILE *fp); //TO ADD NEW STUDENTS TO THE LIST

FILE *del(FILE *fp); //TO DELETE STUDENTS RECORDS

void ModifyStudentRecord(FILE *fp); //TO MODIFIY A PREVIOUS RECORD

void DisplayListOfStudentRecord(FILE *fp); //DISPLAY ALL THE RECORDS

void SearchStudentRecord(FILE *fp); //TO SEARCH FOR A SPECIFIC RECORD

void PrintNTimes(char ch, int n); //PRINTING A CHAR CH N TIMES //USED FOR HEADINGS

void SystemHeading(); //TO CREATE HEADLINES

void Attendance(FILE *fp); //TO PERFORM DIFFERENT FUNCTIONS ON ATTENDANCE

void CreateDebarredList(FILE *fp, int deb); //GENERATES NUMBER OF DEBARRED STUDENTS

void Mercy(int extra, int deb); //TO CALCULATE NUMBER OF STUDENTS SAVED FROM SPECIFIC NUMBER OF EXTRA CLASSES

void SaveAll(int deb); //TO SAVE EVERYONE FROM GETTING DEBARRED

void ExtraclassVsDebarred(int deb); //TO PLOT TABLE OF NUMBER OF STUDENTS SAVED AS EXTRA CLASSES ARE INCREASED

void CheckPassword(int attempt); //TO CHECK FOR PASSWORD

void setcolor(int ForgC);        //TO CHANGE TEXT COLOR

void tictactoe(); //EASTER EGG;

void heading();   //EASTER EGG;
int checkwin(char a[]);  //EASTER EGG;
void hardsinglegame(char a[], char p1[], char s1, char p2[], char s2);//EASTER EGG;
int findhardplace(char a[]); //EASTER EGG;
void easysinglegame(char a[], char p1[], char s1, char p2[], char s2);//EASTER EGG;
void multigame(char a[], char p1[], char s1, char p2[], char s2);//EASTER EGG;

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

struct SUB
{

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

    struct SUB sdf, math, physics, es;
};

int main()

{
    setcolor(11);

    FILE *fp;

    first = 0;

    int attempt = 3;

    Student s;

    int option;

    char another;

    if ((fp = fopen("studentInfo.txt", "rb+")) == NULL)

    {

        if ((fp = fopen("studentInfo.txt", "wb+")) == NULL)

        {

            printf("can't open file");

            return 0;
        }
    }

    SystemHeading();

    printf("\n\n\t\t\t  CREATED BY  ");

    printf("\n\n\t\t\t CODING NINJAS \n\n\t\t\t Gaurav Yadav \n\t\t\t Arpit Maheswari \n\t\t\t Sahil Rastogi \n\t\t\t Pranjay Tiwari");

    printf("\n\n\t\t\t JIIT");

    printf("\n\n\n\n\n\n\n\t *********************** Press Any Key To Continue **********************");

    getch();

    CheckPassword(attempt);

    while (1)

    {

        SystemHeading();

        printf("\n\t");

        PrintNTimes('*', 64);

        printf("\n\n\t\t\t1. ADD Student");

        printf("\n\n\t\t\t2. DELETE Student");

        printf("\n\n\t\t\t3. MODIFY Student");

        printf("\n\n\t\t\t4. DISPLAY Student LIST");

        printf("\n\n\t\t\t5. Search Record");

        printf("\n\n\t\t\t6. Advanced Attendance System ");

        printf("\n\n\t\t\t0. EXIT");

        printf("\n\n\t\tEnter Your Option :--> ");

        scanf("%d", &option);

        switch (option)

        {

        case 0:
            return 1;

            break;

        case 1:
            AddStudentRecord(fp);

            break;

        case 2:
            fp = del(fp);

            break;

        case 3:
            ModifyStudentRecord(fp);

            break;

        case 4:
            DisplayListOfStudentRecord(fp);

            break;

        case 5:
            SearchStudentRecord(fp);

            break;

        case 6:
            Attendance(fp);
            break;

        default:
            printf("\n\t\tYou Pressed wrong key");

            printf("\n\t\tProgram terminated");

            getch();

            exit(0);
        }
    }

    return 1;
}

//----printing character ch at n times ------

void PrintNTimes(char ch, int n)

{

    while (n--)

    {

        putchar(ch);
    }
}

//-----Printing Head Line of the program -----

void SystemHeading()

{
    system("cls");

    printf("\n\n\t");

    PrintNTimes('*', 16);

    printf("[STUDENT] [INFORMATION] [SYSTEM]");

    PrintNTimes('*', 16);

    printf("\n");
}

//************************GRAPHICS ******************************
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

//************************PASSWORD CHECK ************************

void CheckPassword(int attempt)
{
    system("cls");
    char password[10];

    printf("\n\n\t\t\t\t Number of Attempt Left - %d ", attempt);
    printf("\n\n\n\n\t\t\t\t ENTER PASSWORD - ");
    scanf("%s", &password);

    if (strcmp(password, "EasterEgg") == 0)
    {
        printf("\n\n\n\n ******************YOU JUST UNLOCKED THE EASTER EGG HAVE FUN PLAYING TICK TACK TOE **************** \n\n ");
        tictactoe();
    }
    if (strcmp(password, "letmein") == 0)
    {
        return;
    }
    else
    {
        printf("\n\n\t\t\t\t WRONG PASSWORD ");
        attempt--;
        if (attempt < 0)
        {
            printf("\n\n\n\t\t\t\t EXITING PROGRAMME TOO MANY FAILED ATTEMPT");
            getch();
            exit(0);
        }
        getch();
        CheckPassword(attempt);
    }
}
//***********************EASTER EGG ******************************
void tictactoe()
{
    int singmulti;
    char a[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    heading();
    char p1[30], p2[30], s1, s2;
    printf("Wanna play single-player or multi-player?\nPress 1 for single player and 2 for multiplayer: ");
    scanf("%d", &singmulti);
    if (singmulti == 2)
    {
        printf("Name of player 1: ");
        scanf("%s", p1);
        s1 = 'x';
        printf("Name of player 2: ");
        scanf("%s", p2);
        s2 = 'o';
        multigame(a, p1, s1, p2, s2);
    }
    else if (singmulti == 1)
    {
        printf("Name of player 1: ");
        scanf("%s", p1);
        s1 = 'x';
        strcpy(p2, "Tac");
        s2 = 'o';
        printf("%s, your symbol is %c and you are now playing with %s whose symbol is %c!\n", p1, s1, p2, s2);
        printf("Press 1 for easy opponent, and 2 for hard opponent: ");
        int level;
        scanf(" %d", &level);
        if (level == 1)
            easysinglegame(a, p1, s1, p2, s2);
        else if (level == 2)
            hardsinglegame(a, p1, s1, p2, s2);
        else
            printf("Invalid Entry! Exiting the Game!\n");
    }
    else
        printf("Invalid Entry! Exiting the Game!\n");
}
void heading()
{
    printf("\t\t\t\t  Tic Tac Toe Game:\n\n\n\n");
}
void layout(char a[])
{
    int i, j, k;
    printf("\t\t\t\t      |\t      |\n");
    //printf("\t\t\t%d",a[0]);
    printf("\t\t\t\t   %c  |\t  %c   |\t  %c\n", a[0], a[1], a[2]);
    printf("\t\t\t\t");
    for (i = 0; i < 9; i++)
    {
        printf("_ ");
        if ((i + 1) % 3 == 0 && i != 8)
            printf("| ");
    }
    printf("\n\t\t\t\t      |\t      |\n\t\t\t\t   %c  |\t  %c   |\t  %c\n", a[3], a[4], a[5]);
    printf("\t\t\t\t");
    for (i = 0; i < 9; i++)
    {
        printf("_ ");
        if ((i + 1) % 3 == 0 && i != 8)
            printf("| ");
    }
    printf("\n\t\t\t\t      |\t      |\n\t\t\t\t   %c  |\t  %c   |\t  %c\n", a[6], a[7], a[8]);
    printf("\t\t\t\t      |\t      |\n\n\n");
}
int checkwin(char a[])
{
    if ((a[0] == a[1] && a[1] == a[2]) || (a[3] == a[4] && a[4] == a[5]) || (a[6] == a[7] && a[7] == a[8]) || (a[0] == a[3] && a[3] == a[6]) || (a[1] == a[4] && a[4] == a[7]) || (a[2] == a[5] && a[5] == a[8]) || (a[0] == a[4] && a[4] == a[8]) || (a[2] == a[4] && a[4] == a[6]))
        return 1;
    else
        return 0;
}
void multigame(char a[], char p1[], char s1, char p2[], char s2)
{
    int i, j, k, count = 1, place, cwin = 0;
    layout(a);
    printf("Both players just have to enter the place where they want there move to be!\n\n\t\t\tAnd the game starts now...\n\n");
    while (count != 10)
    {
        cwin = 0;
        if (count % 2 != 0)
        {
            printf("%s's turn: ", p1);
            scanf("%d", &place);
            if (((int)a[place - 1] - (int)'0') != place)
            {
                printf("Invalid Move!\n");
                continue;
            }
            else
            {
                a[place - 1] = s1;
                layout(a);
            }
            cwin = checkwin(a);
            if (cwin)
            {
                printf("\n%s won the match!", p1);
                break;
            }
        }
        else
        {
            printf("%s's turn: ", p2);
            scanf("%d", &place);
            if (((int)a[place - 1] - (int)'0') != place)
            {
                printf("Invalid Move!\n");
                continue;
            }
            else
            {
                a[place - 1] = s2;
                layout(a);
            }
            cwin = checkwin(a);
            if (cwin)
            {
                printf("\n%s won the match!", p2);
                break;
            }
        }
        count++;
        if (count == 10)
            printf("Match Drawn! You both are winners! :3\n");
    }
}
void easysinglegame(char a[], char p1[], char s1, char p2[], char s2)
{
    int i, j, k, count = 1, place, cwin = 0;
    layout(a);
    printf("Both players just have to enter the place where they want there move to be!\n\n\t\t\tAnd the game starts now...\n\n");
    while (count != 10)
    {
        cwin = 0;
        if (count % 2 != 0)
        {
            printf("%s's turn: ", p1);
            scanf("%d", &place);
            if (((int)a[place - 1] - (int)'0') != place)
            {
                printf("Invalid Move!\n");
                continue;
            }
            else
            {
                a[place - 1] = s1;
                layout(a);
            }
            cwin = checkwin(a);
            if (cwin)
            {
                printf("\n%s won the match!", p1);
                break;
            }
        }
        else
        {
            place = (rand() % 9) + 1;
            if (((int)a[place - 1] - (int)'0') != place)
            { /*printf("Invalid Move!\n");*/
                continue;
            }
            else
            {
                printf("%s's turn: ", p2);
                printf("%d\n", place);
                a[place - 1] = s2;
                layout(a);
            }
            cwin = checkwin(a);
            if (cwin)
            {
                printf("\n%s won the match!", p2);
                break;
            }
        }
        count++;
        if (count == 10)
            printf("Match Drawn! You both are winners! :3\n");
    }
}
int findhardplace(char a[])
{
    int place;
    if (a[0] == a[1] && a[0] == 'o' && ((int)a[2] - (int)'3') == 0)
        place = 3;
    else if (a[3] == a[4] && a[3] == 'o' && ((int)a[5] - (int)'6') == 0)
        place = 6;
    else if (a[6] == a[7] && a[6] == 'o' && ((int)a[8] - (int)'9') == 0)
        place = 9;
    else if (a[0] == a[2] && a[0] == 'o' && ((int)a[1] - (int)'2') == 0)
        place = 2;
    else if (a[3] == a[5] && a[3] == 'o' && ((int)a[4] - (int)'5') == 0)
        place = 5;
    else if (a[6] == a[8] && a[6] == 'o' && ((int)a[7] - (int)'8') == 0)
        place = 8;
    else if (a[1] == a[2] && a[1] == 'o' && ((int)a[0] - (int)'1') == 0)
        place = 1;
    else if (a[4] == a[5] && a[4] == 'o' && ((int)a[3] - (int)'4') == 0)
        place = 4;
    else if (a[7] == a[8] && a[7] == 'o' && ((int)a[6] - (int)'7') == 0)
        place = 7;
    else if (a[0] == a[3] && a[0] == 'o' && ((int)a[6] - (int)'7') == 0)
        place = 7;
    else if (a[0] == a[6] && a[0] == 'o' && ((int)a[3] - (int)'4') == 0)
        place = 4;
    else if (a[3] == a[6] && a[3] == 'o' && ((int)a[0] - (int)'1') == 0)
        place = 1;
    else if (a[1] == a[4] && a[1] == 'o' && ((int)a[7] - (int)'8') == 0)
        place = 8;
    else if (a[1] == a[7] && a[1] == 'o' && ((int)a[4] - (int)'5') == 0)
        place = 5;
    else if (a[4] == a[7] && a[4] == 'o' && ((int)a[1] - (int)'2') == 0)
        place = 2;
    else if (a[2] == a[5] && a[2] == 'o' && ((int)a[8] - (int)'9') == 0)
        place = 9;
    else if (a[2] == a[8] && a[2] == 'o' && ((int)a[5] - (int)'6') == 0)
        place = 6;
    else if (a[5] == a[8] && a[5] == 'o' && ((int)a[2] - (int)'3') == 0)
        place = 3;
    else if (a[0] == a[4] && a[0] == 'o' && ((int)a[8] - (int)'9') == 0)
        place = 9;
    else if (a[0] == a[8] && a[0] == 'o' && ((int)a[4] - (int)'5') == 0)
        place = 5;
    else if (a[4] == a[8] && a[4] == 'o' && ((int)a[0] - (int)'1') == 0)
        place = 1;
    else if (a[2] == a[4] && a[2] == 'o' && ((int)a[6] - (int)'7') == 0)
        place = 7;
    else if (a[2] == a[6] && a[2] == 'o' && ((int)a[4] - (int)'5') == 0)
        place = 5;
    else if (a[4] == a[6] && a[4] == 'o' && ((int)a[2] - (int)'3') == 0)
        place = 3;
    else if (a[0] == a[1] && ((int)a[2] - (int)'3') == 0)
        place = 3;
    else if (a[3] == a[4] && ((int)a[5] - (int)'6') == 0)
        place = 6;
    else if (a[6] == a[7] && ((int)a[8] - (int)'9') == 0)
        place = 9;
    else if (a[0] == a[2] && ((int)a[1] - (int)'2') == 0)
        place = 2;
    else if (a[3] == a[5] && ((int)a[4] - (int)'5') == 0)
        place = 5;
    else if (a[6] == a[8] && ((int)a[7] - (int)'8') == 0)
        place = 8;
    else if (a[1] == a[2] && ((int)a[0] - (int)'1') == 0)
        place = 1;
    else if (a[4] == a[5] && ((int)a[3] - (int)'4') == 0)
        place = 4;
    else if (a[7] == a[8] && ((int)a[6] - (int)'7') == 0)
        place = 7;
    else if (a[0] == a[3] && ((int)a[6] - (int)'7') == 0)
        place = 7;
    else if (a[0] == a[6] && ((int)a[3] - (int)'4') == 0)
        place = 4;
    else if (a[3] == a[6] && ((int)a[0] - (int)'1') == 0)
        place = 1;
    else if (a[1] == a[4] && ((int)a[7] - (int)'8') == 0)
        place = 8;
    else if (a[1] == a[7] && ((int)a[4] - (int)'5') == 0)
        place = 5;
    else if (a[4] == a[7] && ((int)a[1] - (int)'2') == 0)
        place = 2;
    else if (a[2] == a[5] && ((int)a[8] - (int)'9') == 0)
        place = 9;
    else if (a[2] == a[8] && ((int)a[5] - (int)'6') == 0)
        place = 6;
    else if (a[5] == a[8] && ((int)a[2] - (int)'3') == 0)
        place = 3;
    else if (a[0] == a[4] && ((int)a[8] - (int)'9') == 0)
        place = 9;
    else if (a[0] == a[8] && ((int)a[4] - (int)'5') == 0)
        place = 5;
    else if (a[4] == a[8] && ((int)a[0] - (int)'1') == 0)
        place = 1;
    else if (a[2] == a[4] && ((int)a[6] - (int)'7') == 0)
        place = 7;
    else if (a[2] == a[6] && ((int)a[4] - (int)'5') == 0)
        place = 5;
    else if (a[4] == a[6] && ((int)a[2] - (int)'3') == 0)
        place = 3;
    else
        place = (rand() % 9) + 1;
    return place;
}
void hardsinglegame(char a[], char p1[], char s1, char p2[], char s2)
{
    int i, j, k, count = 1, place, cwin = 0;
    layout(a);
    printf("Both players just have to enter the place where they want there move to be!\n\n\t\t\tAnd the game starts now...\n\n");
    while (count != 10)
    {
        cwin = 0;
        if (count % 2 != 0)
        {
            printf("%s's turn: ", p1);
            scanf("%d", &place);
            if (((int)a[place - 1] - (int)'0') != place)
            {
                printf("Invalid Move!\n");
                continue;
            }
            else
            {
                a[place - 1] = s1;
                layout(a);
            }
            cwin = checkwin(a);
            if (cwin)
            {
                printf("\n%s won the match!", p1);
                break;
            }
        }
        else
        {
            place = findhardplace(a);
            if (((int)a[place - 1] - (int)'0') != place)
            { /*printf("Invalid Move!\n");*/
                continue;
            }
            else
            {
                printf("%s's turn: ", p2);
                printf("%d\n", place);
                a[place - 1] = s2;
                layout(a);
            }
            cwin = checkwin(a);
            if (cwin)
            {
                printf("\n%s won the match!", p2);
                break;
            }
        }
        count++;
        if (count == 10)
            printf("Match Drawn! You both are winners! :3\n");
    }
}

//************************ADDING NEW RECORDS *********************

void AddStudentRecord(FILE *fp)

{

    SystemHeading();

    char another = 'y';

    Student s;

    int i;

    float cgpa;

    fseek(fp, 0, SEEK_END);

    while (another == 'y' || another == 'Y')

    {

        printf("\n\n\t\tEnter Full Name of Student\t");

        fflush(stdin);

        fgets(s.name, 100, stdin); //fgets takes an extra \n character as input

        s.name[strlen(s.name) - 1] = '\0';

        printf("\n\n\t\tEnter Branch\t");

        fflush(stdin);

        fgets(s.branch, 50, stdin);

        s.branch[strlen(s.branch) - 1] = '\0';

        printf("\n\n\t\tEnter Roll number \t");

        scanf("%d", &s.roll);

        printf("\n\n\tEnter SGPA for 8 semesters\n\t");

        for (i = 0, cgpa = 0; i < 8; i++)

        {
            scanf("%f", &s.sgpa[i]);
            printf("\n\t");
            cgpa += s.sgpa[i];
        }

        cgpa /= 8.0;

        s.cgpa = cgpa;

        fflush(stdin);

        printf("\n\n\t Enter total number of classes of SDF held during the semester : ");
        scanf("%d", &s.sdf.total);

        printf("\n\n\t Enter total number of classes attented during the semester   : ");
        scanf("%d", &s.sdf.present);

        s.sdf.p = s.sdf.present * 100;
        s.sdf.p = s.sdf.p / s.sdf.total;

        printf("\n\n\t Enter total number of classes of MATH held during the semester :   ");
        scanf("%d", &s.math.total);

        printf("\n\n\t Enter total number of classes attented during the semester     :   ");
        scanf("%d", &s.math.present);

        s.math.p = s.math.present * 100;
        s.math.p = s.math.p / s.math.total;

        printf("\n\n\t Enter total number of classes of ES held during the semester :  ");
        scanf("%d", &s.es.total);

        printf("\n\n\t Enter total number of classes attented during the semester   :  ");
        scanf("%d", &s.es.present);

        s.es.p = s.es.present * 100;
        s.es.p = s.es.p / s.es.total;

        printf("\n\n\t Enter total number of classes of PHYSICS held during the semester :  ");
        scanf("%d", &s.physics.total);

        printf("\n\n\t Enter total number of classes attented during the semester        :  ");
        scanf("%d", &s.physics.present);

        s.physics.p = s.physics.present * 100;
        s.physics.p = s.physics.p / s.physics.total;

        fwrite(&s, sizeof(s), 1, fp);

        printf("\n\n\t\tWant to enter another student info (Y/N)\t");

        fflush(stdin);

        another = getchar();
    }
}

//************************DELETEING A RECORD ************************

FILE *del(FILE *fp)

{

    SystemHeading();

    Student s;

    int flag = 0, tempRoll, siz = sizeof(s);

    FILE *ft;

    if ((ft = fopen("temp.txt", "wb+")) == NULL)

    {

        printf("\n\n\t\t\t\\t!!! ERROR !!!\n\t\t");

        system("pause");

        return fp;
    }

    printf("\n\n\tEnter Roll number of Student to Delete the Record");

    printf("\n\n\t\t\tRoll No. : ");

    scanf("%d", &tempRoll);

    rewind(fp);

    while ((fread(&s, siz, 1, fp)) == 1)

    {

        if (s.roll == tempRoll)

        {
            flag = 1;

            printf("\n\tRecord Deleted for");

            printf("\n\n\t\t%s\n\n\t\t%s\n\n\t\t%d\n\t", s.name, s.branch, s.roll);

            continue;
        }

        fwrite(&s, siz, 1, ft);
    }

    fclose(fp);

    fclose(ft);

    remove("studentInfo.txt");

    rename("temp.txt", "studentInfo.txt");

    if ((fp = fopen("studentInfo.txt", "rb+")) == NULL)

    {

        printf("ERROR");

        return NULL;
    }

    if (flag == 0)
        printf("\n\n\t\t!!!! ERROR RECORD NOT FOUND \n\t");

    PrintNTimes('*', 65);

    printf("\n\t");

    system("pause");

    return fp;
}

//************************ MODIFY A RECORD ************************

void ModifyStudentRecord(FILE *fp)

{

    SystemHeading();

    Student s;

    int i, flag = 0, tempRoll, siz = sizeof(s);

    float cgpa;

    printf("\n\n\tEnter Roll Number of Student to MODIFY the Record : ");

    scanf("%d", &tempRoll);

    rewind(fp);

    while ((fread(&s, siz, 1, fp)) == 1)

    {

        if (s.roll == tempRoll)

        {
            flag = 1;

            break;
        }
    }

    if (flag == 1)

    {

        fseek(fp, -siz, SEEK_CUR);

        printf("\n\n\t\tRECORD FOUND");

        printf("\n\n\t\tEnter New Data for the Record");

        printf("\n\n\t\tEnter Full Name of Student\t");

        fflush(stdin);

        fgets(s.name, 100, stdin);

        s.name[strlen(s.name) - 1] = '\0';

        printf("\n\n\t\tEnter Branch\t");

        fflush(stdin);

        fgets(s.branch, 50, stdin);

        s.branch[strlen(s.branch) - 1] = '\0';

        printf("\n\n\t\tEnter Roll number \t");

        scanf("%d", &s.roll);

        printf("\n\n\tEnter SGPA for 8 semesters\n\t");

        for (i = 0, cgpa = 0; i < 8; i++)

        {
            scanf("%f", &s.sgpa[i]);
            printf("\n\t");
            cgpa += s.sgpa[i];
        }

        cgpa = cgpa / 8.0;

        printf("\n\n\t Enter total number of classes of SDF held during the semester : ");
        scanf("%d", &s.sdf.total);

        printf("\n\n\t Enter total number of classes attented during the semester   : ");
        scanf("%d", &s.sdf.present);

        s.sdf.p = s.sdf.present * 100;
        s.sdf.p = s.sdf.p / s.sdf.total;

        printf("\n\n\t Enter total number of classes of MATH held during the semester :   ");
        scanf("%d", &s.math.total);

        printf("\n\n\t Enter total number of classes attented during the semester     :   ");
        scanf("%d", &s.math.present);

        s.math.p = s.math.present * 100;
        s.math.p = s.math.p / s.math.total;

        printf("\n\n\t Enter total number of classes of ES held during the semester :  ");
        scanf("%d", &s.es.total);

        printf("\n\n\t Enter total number of classes attented during the semester   :  ");
        scanf("%d", &s.es.present);

        s.es.p = s.es.present * 100;
        s.es.p = s.es.p / s.es.total;

        printf("\n\n\t Enter total number of classes of PHYSICS held during the semester :  ");
        scanf("%d", &s.physics.total);

        printf("\n\n\t Enter total number of classes attented during the semester        :  ");
        scanf("%d", &s.physics.present);

        s.physics.p = s.physics.present * 100;
        s.physics.p = s.physics.p / s.physics.total;

        fwrite(&s, sizeof(s), 1, fp);
    }

    else
        printf("\n\n\t!!!! ERROR !!!! RECORD NOT FOUND");

    printf("\n\n\t");

    system("pause");
}

//************************DISPLAY ALL RECORDS ************************

void DisplayListOfStudentRecord(FILE *fp)

{
    SystemHeading();

    Student s;

    int i, siz = sizeof(s);

    rewind(fp);

    while ((fread(&s, siz, 1, fp)) == 1)

    {

        printf("\n\t\tNAME : %s", s.name);

        printf("\n\n\t\tBRANCH : %s", s.branch);

        printf("\n\n\t\tROLL : %d", s.roll);

        printf("\n\n\tSGPA: ");

        for (i = 0; i < 8; i++)

            printf("| %.2f |", s.sgpa[i]);

        printf("\n\n\t\tCGPA : %.2f\n\t", s.cgpa);

        PrintNTimes('*', 65);

        printf("\n\n\t Attendance Status \n\t");

        printf("\n\n\t     SDF = %d out of %d (Percentage = %d ) \n\t", s.sdf.present, s.sdf.total, s.sdf.p);
        printf("\n\n\t   Maths = %d out of %d (Percentage = %d ) \n\t", s.math.present, s.math.total, s.math.p);
        printf("\n\n\t      ES = %d out of %d (Percentage = %d ) \n\t", s.es.present, s.es.total, s.es.p);
        printf("\n\n\t Physics = %d out of %d (Percentage = %d ) \n\t", s.physics.present, s.physics.total, s.physics.p);
    }

    printf("\n\n\n\t");

    PrintNTimes('*', 65);

    printf("\n\n\t");

    system("pause");
}
//************************ ADFVANCED FUNCTION ON ATTENDANCE ************************

void Attendance(FILE *fp)

{
    int deb = 60, flag = 0;

    int choice = 1, extra;

    SystemHeading();

    while (choice)
    {

        printf("\n\n\t\t\t ----- Advance Functions Attendance ----");
        printf("\n\n\n\n\t\t\t Debarred At - %d Percent ", deb);

        Student s;

        printf("\n\n\t\t\t1. Calculate Number Students who will be Debarred");

        printf("\n\n\t\t\t2. Number of Extra Classes and Number of Student Saved From It ");

        printf("\n\n\t\t\t3. Number of Extra Classes Required to Save Everyone");

        printf("\n\n\t\t\t4. Plot Table of Extra Classes to Students Saved");

        printf("\n\n\t\t\t5. Change Debarred At Value");

        printf("\n\n\t\t\t0. EXIT");

        printf("\n\n\t\tEnter Your Option :--> ");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            CreateDebarredList(fp, deb);
            printf("\n\n\n\t*********************** Press Any Key To Continue **********************");
            getch();
            system("cls");
            break;

        case 2:
            printf("\n\n\t\t\t Enter Number of Extra classes you can manage  - ");
            scanf("%d", &extra);
            Mercy(extra, deb);
            printf("\n\n\n\t*********************** Press Any Key To Continue **********************");
            getch();
            system("cls");
            break;

        case 3:
            SaveAll(deb);
            printf("\n\n\n\t*********************** Press Any Key To Continue **********************");
            getch();
            system("cls");
            break;

        case 4:
            ExtraclassVsDebarred(deb);
            printf("\n\n\n\t*********************** Press Any Key To Continue **********************");
            getch();
            system("cls");
            break;

        case 5:
            printf(" \n\n\n\t Enter the new Value of Debarred At ( Current value is %d %)  ", deb);
            scanf("%d", &deb);
            printf("\n\n\n\t*********************** Press Any Key To Continue **********************");
            getch();
            system("cls");
            break;
        }
    }
}

//************************ PLOTS NUMBER OF STUDENTS SAVED PER CLASS ADDED ************************
void ExtraclassVsDebarred(int deb)
{
    int i = 0;

    for (i = 0; i < 10; i++)
    {
        Mercy(i, deb);
    }
}

//************************CALCULATE NUMBER OF EXTRA CLASSES REQUIRED TO SAVE EVERYONE ************************
void SaveAll(int deb)
{
    NODE *temp2;
    int countSaveAll = 0;
    int lowest;
    temp = first;
    temp2 = temp;
    lowest = temp->p;
    while (temp != 0)
    {
        if (lowest > (temp->p))
        {
            temp2 = temp;
        }
        temp = temp->ptr;
    }
    while ((temp2->p) < deb)
    {
        temp2->present += 1;
        temp2->total += 1;
        temp2->p = (temp2->present) * 100;
        temp2->p = (temp2->p) / (temp2->total);
        countSaveAll++;
    }
    printf("\n\n\t Number of Extra Classes Required To Save Everyone = %d ", countSaveAll);
    temp2->present -= countSaveAll;
    temp2->total -= countSaveAll;
    temp2->p = (temp2->present) * 100;
    temp2->p = (temp2->p) / (temp2->total);
}

//************************ SEE HOW MANY STUDENTS CAN BE SAVED FROM A GIVEN NUMBER OF EXTRA CLASSES ************************
void Mercy(int extra, int deb)
{

    temp = first;
    int countsaved = 0;
    while (temp != 0)
    {
        temp->present += extra;
        temp->total += extra;
        temp->p = (temp->present) * 100;
        temp->p = (temp->p) / (temp->total);
        if ((temp->p) > deb)
            countsaved++;
        temp->present -= extra;
        temp->total -= extra;
        temp->p = (temp->present) * 100;
        temp->p = (temp->p) / (temp->total);
        temp = temp->ptr;
    }
    printf("\n\n\t Number of Students Saved From %d Extra Classes are %d ", extra, countsaved);
}
void CreateDebarredList(FILE *fp, int deb)
{
    int countd = 0;
    Student s;
    int siz;
    rewind(fp);
    siz = sizeof(s);
    while ((fread(&s, siz, 1, fp)) == 1)
    {

        if (s.sdf.p <= deb)
        {
            countd++;
            head = (NODE *)malloc(sizeof(NODE));
            head->roll = s.roll;
            head->p = s.sdf.p;
            head->present = s.sdf.present;
            head->total = s.sdf.total;
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
    printf("\n\n\n\t  Number Of Students debarred is - %d", countd);
}

//************************ SEARCH FILE RECORD ************************

void SearchStudentRecord(FILE *fp)

{
    SystemHeading();

    int tempRoll, flag, siz, i;

    Student s;

    char another = 'y';

    siz = sizeof(s);

    while (another == 'y' || another == 'Y')

    {

        printf("\n\n\tEnter Roll Number of Student to search the record : ");

        scanf("%d", &tempRoll);

        rewind(fp);

        while ((fread(&s, siz, 1, fp)) == 1)

        {

            if (s.roll == tempRoll)

            {
                flag = 1;

                break;
            }
        }

        if (flag == 1)

        {

            printf("\n\t\tNAME : %s", s.name);

            printf("\n\n\t\tBRANCH : %s", s.branch);

            printf("\n\n\t\tROLL : %d", s.roll);

            printf("\n\n\tSGPA: ");

            for (i = 0; i < 8; i++)

                printf("| %.2f |", s.sgpa[i]);

            printf("\n\n\t\tCGPA : %.2f\n\t", s.cgpa);

            printf("\n\n\t Attendance Status \n\t");

            printf("\n\n\t     SDF = %d out of %d (Percentage = %d ) \n\t", s.sdf.present, s.sdf.total, s.sdf.p);
            printf("\n\n\t   Maths = %d out of %d (Percentage = %d ) \n\t", s.math.present, s.math.total, s.math.p);
            printf("\n\n\t      ES = %d out of %d (Percentage = %d ) \n\t", s.es.present, s.es.total, s.es.p);
            printf("\n\n\t Physics = %d out of %d (Percentage = %d ) \n\t", s.physics.present, s.physics.total, s.physics.p);

            PrintNTimes('*', 65);
        }

        else
            printf("\n\n\t\t!!!! ERROR RECORD NOT FOUND !!!!");

        printf("\n\n\t\tWant to enter another search (Y/N)");

        fflush(stdin);

        another = getchar();
    }
}

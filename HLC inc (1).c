/********************************************************
    Programmers : Joshua Prabahar, Davin Simpson, Rhea Braithwaite, Chadric Nathan, Ezekiel Abrahams, Aman Sharma
    Date        : 17/11/2018
    File Name   : Shipping Calculator
    Purpose     : To determine the cost of shipping a package to another country.
********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 500

///prototype modules
void logo();
void programMenu();
void errorMessage();
void endDisplay();
int weightMenu(int);
float costCalc(int, float);
float destination(int);


int main()
{
    int custNum = 0, x = 0, a, num[SIZE], weight, option;
    float rate[SIZE][10], cost[SIZE][10];
    char name[SIZE][35];

    logo();
    system("cls");
    programMenu();
    system("cls");

    scanf(" %d", &option);
    switch (option)
    {
    case 1:
        for (x=0; x<SIZE; x++)
        {
            fflush(stdin);
            printf("Name: ");
            gets(name[x]);
            printf("\nEnter the number of packages: ");
            scanf(" %d", &num[x]);

            for (a=1;a<=num[x];a++)
            {
                rate[x][a-1]=destination(a);
                weight=weightMenu(a);
                cost[x][a-1]=costCalc(weight,rate[x][a-1]);
                printf("cost $%.2f\n",cost[x][a-1]);
                system("pause"); //remember to change this later to make it look more professional
                system("cls");
            }
            custNum++;
            fflush(stdin);
            break;
    case 2:
            if (strcmp(name," ")!=0)
            {
                errorMessage();
            }
    case 3:
        printf("Change this too.\n");
        }
    case 4:
        endDisplay();
    }
    return 0;
}

void logo()
{
printf("dP     dP  dP         a00000b.    dP                                                                              dP                  dP\n");
printf("00     00  00        d0'   `00    00                                                                              00                  00\n");
printf("00aaaaa00  00        00           00 00d000b. .d0000b.  .d0000b.   00d000b. 00d000b. .d0000b. 00d000b. .d0000b. d0000P .d0000b. .d000b00\n");
printf("00     00  00        00           00 00'  `00 00'  `""   00'   `00   00    00 00'  `00 00'  `00 00'  `00 00'  `00   00   00ooood0 00'  `00\n");
printf("00     00  00        Y0.   .00    00 00    00 00.  ... 00.   .00   00       00.  .00 00.  .00 00       00.  .00   00   00.  ... 00.  .00\n");
printf("dP     dP  00000000P  Y00000P'    dP dP    dP `00000P'  `00000P'   dP       00Y000P' `00000P' dP       `00000P0   dP   `00000P' `00000P0\n");
printf("\t\t\t\t\t\t\t\t\t    00                                                          \n");
printf("\t\t\t\t\t\t\t\t\t    dP                                                          \n");

printf("\t\t\t\t\t\t\t*=============================================*\n");
printf("\t\t\t\t\t\t\t*                     |\\                      *\n");
printf("\t\t\t\t\t\t\t*               |\\    | \\)                    *\n");
printf("\t\t\t\t\t\t\t*               =>]))))))))))))               *\n");
printf("\t\t\t\t\t\t\t*               |/    | /)                    *\n");
printf("\t\t\t\t\t\t\t*                     |/                      *\n");
printf("\t\t\t\t\t\t\t*                                             *\n");
printf("\t\t\t\t\t\t\t*            ...Connecting the world          *\n");
printf("\t\t\t\t\t\t\t*                      one package at a time. *\n");
printf("\t\t\t\t\t\t\t*=============================================*\n\n");
printf("\n\n\nPRESS ANY KEY TO CONTINUE.");
getch();
}
void programMenu()
{
    int option;

    printf("Please select from the following options: \n\n");
    printf("**********************************************\n");
    printf("* 1) Enter shipping info                     *\n");
    printf("* 2) Search shipping info                    *\n");
    printf("* 3) Display all shipping info               *\n");
    printf("* 4) Exit Program                            *\n");
    printf("**********************************************\n");


}

float destination(int number)
{
    int shipDest;
    float rate;

    printf("Shipment Destination (Package %d): \n", number);
    printf("1)US \n2)Canada \n3)China \n4)Europe \n5)Africa\n\n");
    printf("\nEnter number corresponding to destination: ");
    scanf(" %d", &shipDest);
    switch(shipDest)
    {
    case 1:
        rate=25.00;
        break;
    case 2:
        rate=30.25;
        break;
    case 3:
        rate=37.50;
        break;
    case 4:
        rate=40.00;
        break;
    case 5:
        rate=50.00;
        break;
    }
    return rate;
}

int weightMenu(int package)
{
    int weightCat;

    printf("Please choose from the following weight categories for package %d: ", package);
    printf("\n1)0-5 kg\n2)6-10 kg\n3)11-20\n4)greater than 20 kg\n\n");
    scanf("%d", &weightCat);

    switch(weightCat)
    {
    case 1:
        weightCat=150;
        break;
    case 2:
        weightCat=200;
        break;
    case 3:
        weightCat=250;
        break;
    case 4:
        weightCat=350;
        break;

    }
    return weightCat;

}

float costCalc(int destRate, float rateCalc)
{
    float shipCost;

    shipCost= (float)destRate*rateCalc;
    return shipCost;
}

void endDisplay()
{

}

//Need an error message to say no data entered

void errorMessage( char name[][35])
{
    printf("\nError:\n\tNo Data Has Been Entered");

}
//Data already entered do you want to delete existing data or return to menu


#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

void login()
{
	int a=0,i=0;
    char username[10],c=' ';
    char pword[10],code[10];
    char user[10]="vijay";
    char pass[10]="1707";
    do
{

    printf("\n ADMIN LOGIN PORTAL");
    printf(" \n\n                  USERNAME:-");
	scanf("%s", &username);
	printf(" \n\n                  PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	i=0;
		if(strcmp(username,"vijay")==0 && strcmp(pword,"1707")==0)
	{
	printf("  \n\n\n      LOGIN IS SUCCESSFUL....");
	printf("\n\n\n\t\t\t\tPress ENTER key to continue...");
	getch();
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;

		getch();

	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();

		}
		system("cls");

}

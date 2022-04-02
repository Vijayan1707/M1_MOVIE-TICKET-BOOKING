#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
void viewAll()
{

	char ch;
	FILE *fp;

	fp = fopen("data1.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{
		system("cls");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);

	}

	fclose(fp);

}

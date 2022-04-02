#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
void old_record()
{
	char ch;
	FILE *fp;

	fp = fopen("oldTransection.txt","r");
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

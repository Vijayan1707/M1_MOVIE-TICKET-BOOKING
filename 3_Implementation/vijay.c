#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include"fun.h"
#include"login.c"
#include"old_record.c"
#include"viewAll.c"

struct book
{
	char code[20];
	char name[20];
	char date[20];
	int cost;


}b;

int seat = 60 ;

void insert_details();
void viewAll();
void find();
void book_ticket();
void old_record();

void main()
{
    int chn=0;
    printf("\n  1. Admin Login ");
    printf("\n  2. Customer Booking \n");
    scanf("%d",&chn);
    if(chn==1){
    login();
    }
	 int ch;
 	do{
            if(chn==2){
                printf("\n----------------------------------------");
	printf("\n");
	printf("\t Movie Ticket booking ");
	printf("\n----------------------------------------");
	printf("\n");
   	printf("\nEnter >1< To View All Movie");
	printf("\nEnter >2< To Book Tickets");
   	printf("\nEnter >0< To Exit ");
   	printf("\n");
   	printf("\nEnter your Choice :");
   	scanf("%d",&ch);
	   system("cls");
   	switch (ch)
   	{
		case 1:
    		viewAll();
   		break;
        
		case 2:
            book_ticket();
		break;

    		case 0:
    		main();
    		break;

    		default:
    		printf("Wrong choice !");
    		break;
   	}
            }
            else if(chn==1){
	printf("\n----------------------------------------");
	printf("\n");
	printf("\t Movie Ticket booking ");
	printf("\n----------------------------------------");
    printf("\n");
	printf("\nEnter >1< To Insert Movie");
	printf("\nEnter >2< To View All Movie");
    printf("\nEnter >3< To View All Transactions");
   	printf("\nEnter >0< To Exit ");
    printf("\n");
   	printf("\nEnter your Choice :");
   	scanf("%d",&ch);
	   system("cls");

   	switch (ch)
   	{
        case 1 :
         insert_details();
   		break;

   		case 2 :
   		 viewAll();
   		break;

		case 3:
		 old_record();
		break;

        case 0:
        main();
        break;

        default:
        printf("Wrong choice !");
        break;
   	}
 }
 else{printf("Invalid Number");
    exit(0);
 }
 }while(ch!=0);
}
void insert_details()
{

	FILE *fp;
	struct book b;

	printf("Enter movie code :- ");
	scanf("%s",b.code);
	printf("Enter  name :- ");
	scanf("%s",b.name);
	printf("Enter Release Date:- ");
	scanf("%s",b.date);
	printf("Enter Ticket Price:- ");
	scanf("%d",&b.cost);

	fp=fopen("data1.txt","a");

	if(fp == NULL)
	{
		printf("FIle not Found");
	}
	else
	{
		fprintf(fp,"%s %s %s %d \n",b.code,b.name,b.date,b.cost);
		printf("Recorded Successfully");
	}
		printf("\n");
	fclose(fp);
	system("cls");
}
void book_ticket()
{
 struct book b;
	FILE *fp;

	FILE *ufp;

	int total_seat,mobile,total_amount;
	char name[20];


	char ch;
	char movie_code[20];

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
    printf("\n");
	printf("\n For Exit close the tab \n");
	printf("\n Enter movie code :");
	scanf("%s",movie_code);
	fp = fopen("data1.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{
		while(getc(fp) != EOF)
		{
			fscanf(fp,"%s %s %s %d",b.code,b.name,b.date,&b.cost);
			if(strcmp(b.code, movie_code) == 0)

			{
				printf("\n Record Found\n");
				printf("\n\t\tCode ::%s",b.code);
				printf("\n\t\tMovie name ::%s",b.name);
				printf("\n\t\tdate name ::%s",b.date);
				printf("\n\t\tPrice of ticket::%d",b.cost);
			}
		}

	}
	printf("\n* Fill Details  *");
	printf("\n your name :");
	scanf("%s",name);
	printf("\n mobile number :");
	scanf("%d",&mobile);
	printf("\n Total number of tickets :");
	scanf("%d",&total_seat);



    printf("\n ENJOY MOVIE \n");
    printf("\n\t\tname : %s",name);
    printf("\n\t\tmobile Number : %d",mobile);
    printf("\n\t\tTotal seats : %d",total_seat);
    fseek(fp, 0, 0);
	while(getc(fp) != EOF)
		{
			fscanf(fp,"%s %s %s %d",b.code,b.name,b.date,&b.cost);
			if(strcmp(b.code, movie_code) == 0)

			{
                printf("\n\t\tmovie name : %s",b.name);
                printf("\n\t\tcost per ticket : %d",b.cost);

                total_amount = b.cost * total_seat;
                printf("\n\t\tTotal Amount : %d",total_amount);

                break;

			}
		}

	ufp=fopen("oldTransection.txt","a");
	if(ufp == NULL)
	{
		printf("File not Found");
	}
	else
	{
		fprintf(ufp,"%s %d %d %s %d %d\n",name,mobile,total_seat,b.name,b.cost,total_amount);
		printf("\n Record insert sucessfully to the old record file");
	}
		printf("\n");
	fclose(ufp);
	fclose(fp);

}

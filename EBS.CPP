#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<dos.h>

void gotoxy();


void main()
{
FILE *fp,*ft;
  char another,choice;
struct user
  {
  char name[46];
  char id[34];
  char address[34];
 long int presentunit;
 long int previousunit;
char status[10];
  long int bill;
  };


  int kwh;
  struct user u;
  char username[45],sik[23];
  long int recsize;
clrscr();

fp=fopen("user.DAT","rb+");

  if(fp==NULL)
  {
    fp=fopen("user.DAT","wb+");
    if(fp==NULL)
    {
    puts("cannot open file");
    exit(0);
    }
  }
clrscr();
recsize=sizeof(u);

textcolor(WHITE+BLINK);
gotoxy(1,1);
cprintf("-");
sleep(1.5);
clrscr();
textcolor(WHITE+BLINK);
gotoxy(2,1);
cprintf("_");
sleep(1);
clrscr();

textcolor(GREEN);
gotoxy(5,30);
cprintf(" WELCOME TO ");
gotoxy(6,15);
cprintf(" NEPAL ELECTRICITY BILL MAINTAINING SYSTEM");
gotoxy(19,6);
cprintf("programmed by:");
textcolor(BROWN+128);
gotoxy(19,21);
cprintf("Suman");

 gotoxy(21,40);
sleep(2);
textcolor(GREEN);
    cprintf("Wait for a while");
	gotoxy(21,57);
	cprintf(".");
    sleep(3);
    gotoxy(21,58);
    cprintf(".");
    sleep(2.5);
    gotoxy(21,59);
    cprintf(".");
    sleep(1);

clrscr();
textcolor(CYAN);
char pass[10]="mike",ans,check[20];
int t=1;
int i;

  while(t<=3)
	{
			i=0;
			clrscr();
			gotoxy(7,12);
			textcolor(CYAN);
		 gotoxy(7,12);
			cprintf("Only authorized users are allowed:");
		gotoxy(9,14);
		cprintf("enter security password:");

		while((ans=getch())!='\r' && i<19)
			{
					printf("*");
					check[i]=ans;
					i++;
			}
			check[i]='\0';
			if(strcmp(pass,check)==0)
			{
					clrscr();

					break;
			 }
			 else
			 {
					if(t==3)
					{
							clrscr();
							textcolor(RED+BLINK);
							cprintf("\n\a ACCESS DENIED. YOU ARE NOT ALLOW TO ENTER");
							getch();
							exit(1);
					 }
					 else
					 {
							textcolor(LIGHTCYAN);
							gotoxy(20,12);
							cprintf("\nYOU HAVE ENTERED THE WRONG PASSWORD. TRY AGAIN");
							delay(3000);
					 }

			  }
			t++;
		  }

while(1)
{
clrscr();
textcolor(GREEN);
gotoxy(4,19);
cprintf("NEPAL ELECTRICITY BILL MAINTAINING");
gotoxy(6,29);
cprintf("Main menu");

textcolor(CYAN);
gotoxy(8,18);
cprintf("\nPress 1 to add records");
 gotoxy(9,24);
cprintf("\n2. costumer records");
gotoxy(10,24);
cprintf("\n3.Edit records");
gotoxy(11,24);
cprintf("\n4.Cash collection");
gotoxy(12,24);
cprintf("\n5.Delete records");
gotoxy(13,24);
cprintf("\n6.List of paid costumers:");
gotoxy(14,24);
cprintf("\n7.List of default costumers:");
gotoxy(15,24);
cprintf("\n0.Exit");
gotoxy(16,24);
cprintf("\nChoose an option<1,2,3,4,5,0>:");
  fflush(stdin);
  choice=getchar();
  clrscr();

  switch(choice)
  {
 case'1':


  fseek(fp,0,SEEK_END);
  another='Y';

  while(another=='Y'||another=='y')
  {
gotoxy(1,0);
printf("costumername:-");
printf("\ncostumer ID.:-");
printf("\nAddress:-");
printf("\npresent unit:- ");
printf("\nprevious unit:-");
printf("\nCustomer Status (Type unpaid):");
gotoxy(1,16);
scanf("%s",&u.name);
gotoxy(2,15);
scanf("%s",&u.id);
gotoxy(3,10);
scanf("%s",&u.address);
gotoxy(4,15);
scanf("%ld",&u.presentunit);
gotoxy(5,16);
scanf("%ld",&u.previousunit);
gotoxy(6,30);
scanf("%s",&u.status);
    fwrite(&u,sizeof(u),1,fp);
kwh=u.presentunit-u.previousunit;
if(kwh<=20)
u.bill=80;
else
u.bill=(kwh-20)*7.5+80;
printf("\n Add another record(Y/N)");

    fflush(stdin);
    another=getchar();
 }

  break;



  case'2':
textcolor(CYAN);
gotoxy(4,14);
cprintf("press 1 to view all");
gotoxy(5,20);
cprintf("2.view one");
gotoxy(7,25);
cprintf("enter your choice");
fflush(stdin);
choice=getchar();
clrscr();

  switch(choice)
  {
case'1':

rewind(fp);
while(fread(&u,recsize,1,fp)==1)
{
printf("\n Name=%s",u.name);
printf("\n ID=%s",u.id);
printf("\n address=%s",u.address);
printf("\n presentunit=%ld",u.presentunit);
printf("\n previousunit=%ld",u.previousunit);
getch();
printf("\n");
}
printf("\n\tTHANK YOU!!");
getch();
break;

case'2':

printf("\n enter costumer id to find record:");
scanf("%s",username);

rewind(fp);
while(fread(&u,recsize,1,fp)==1)
{

if(strcmp(u.id,username)==0)
 {
printf("\n Name=%s",u.name);
printf("\n ID=%s",u.id);
printf("\n address=%s",u.address);
printf("\n presentunit=%ld",u.presentunit);
printf("\n previousunit=%ld",u.previousunit);
printf("\n");

 }
}
		      printf("\n\tTHANK YOU!");




getch();
break;
}
break;

 case'3':

     another='Y';
    while(another=='Y'||another=='y')
    {


clrscr();
      printf("\n Enter costumer id. to edit\n");
      scanf("%s",&username);
rewind(fp);
      while(fread(&u,recsize,1,fp)==1)
      {
	if(strcmp(u.id,username)==0)
	  {


cprintf("\n Enter the new name:-");
	  scanf("%s",u.name);
printf("\ncostumerId.:- ");
scanf("%s",&u.id);
printf("\n address:-");
scanf("%s",&u.address);
printf("\npresentunit:-");
scanf("%ld",&u.presentunit);
printf("\n previousunit:-");
scanf("%ld",&u.previousunit);

kwh=u.presentunit-u.previousunit;
if(kwh<=20)
u.bill=80;
else
u.bill=(kwh-20)*7.5+80;


printf("TOtal Bill:-%ld",u.bill);

	  fseek(fp,-recsize,SEEK_CUR);
	  fwrite(&u,recsize,1,fp);
	  printf("\n Record has been succesively edited");
	  break;
	  }
      }
      printf("\n Edit another record(Y?N)");
      fflush(stdin);
      another=getchar();
    }
    break;



case'4':

float amount;
float a;
char month[45];
char amp[]="5 amp";
gotoxy(1,1);
printf("enter costumer's id.:");
scanf("%s",&sik);
gotoxy(2,1);
printf("enter month:");
scanf("%s",&month);

rewind(fp);
while(fread(&u,recsize,1,fp)==1)
 {
if(strcmp(u.id,sik)==0)
  {
yz:


printf("\ncostumer name=%s",u.name);
printf("\npresent reading=%ld",u.presentunit);
printf("\nprevious reading=%ld",u.previousunit);
kwh=u.presentunit-u.previousunit;
if(kwh<=20)
u.bill=80;
else
u.bill=(kwh-20)*7.5+80;
printf("\nTotal bill=%ld",u.bill);
printf("\nenter the amount you want to pay:");
scanf("%f",&amount);
if(amount<u.bill)
 {
clrscr();
printf("\nenter amount more or equal to total bill");
goto yz;
}
else
{
printf("\n cash paid=RS.%.2f",amount);
a=amount-u.bill;
printf("\n Amount to be returned to costumer:RS.%.2f",a);
printf("\nCustomer Status (Type paid):");
      scanf("%s",u.status);
printf("\n\tpress enter to make bill");
getch();
clrscr();
gotoxy(3,16);
printf("****NEPAL ELECTRICITY AUTHORITY****");
gotoxy(4,21);
printf("electricity service bill");
gotoxy(7,7);
printf("costumer name:%s",u.name);
gotoxy(8,7);
printf("costumer id=:%s",u.id);
gotoxy(9,7);
printf("Address=%s",u.address);
gotoxy(10,7);
printf("present unit:%ld",u.presentunit);
gotoxy(11,7);
printf("previous unit:%ld",u.previousunit);
gotoxy(12,7);
kwh=u.presentunit-u.previousunit;
if(kwh<=20)
u.bill=80;
else
u.bill=(kwh-20)*7.5+80;
printf("Used unit:%d",kwh);
gotoxy(7,42);
printf("Month:%s",month);
gotoxy(8,42);
printf("Capacity:%s",amp);
gotoxy(10,32);
printf("Minimum electricity cost:80.00");
gotoxy(11,32);
printf("Total bill:RS.%ld",u.bill);
gotoxy(23,40);
printf("\n\tPress any key to continue...");
getch();
}
fseek(fp,-recsize,SEEK_CUR);
fwrite(&u,recsize,1,fp);

}
getch();
}
break;


 case'5':
while(t<=3)
	{
			i=0;
			clrscr();
			gotoxy(7,12);
			textcolor(CYAN);
			cprintf("\nEnter the security password :");

			while((ans=getch())!='\r' && i<19)
			{
					printf("*");
					check[i]=ans;
					i++;
			}
			check[i]='\0';
			if(strcmp(pass,check)==0)
			{
					clrscr();
					break;
			 }
			 else
			 {
					if(t==3)
					{
							clrscr();
							textcolor(RED+BLINK);
							cprintf("\n\a ACCESS DENIED. YOU ARE NOT ALLOW TO ENTER");
							getch();
							exit(1);
					 }
					 else
					 {
							textcolor(LIGHTCYAN);
							gotoxy(20,12);
							cprintf("\nYOU HAVE ENTERED THE WRONG PASSWORD. TRY AGAIN");
							delay(3000);
					 }

			  }
			t++;
		  }



 another='Y';

 while(another=='Y'||another=='y')
  {
clrscr();
    printf("\n Enter the id. of costumer to delete\n");
    scanf("%s",username);
    ft=fopen("TEMP.DAT","wb");
    rewind(fp);

    while(fread(&u,recsize,1,fp)==1)
    {
      if(strcmp(u.id,username)!=0)
      fwrite(&u,recsize,1,ft);
    }

    fclose(fp);
    fclose(ft);
    remove("user.DAT");
    rename("TEMP.DAT","user.DAT");
    fp=fopen("user.DAT","rb+");
printf("\n\tDELETED!!");
    cprintf("\nDelete another record(Y/N)");
    fflush(stdin);
    another=getchar();

}
break;

case'6':

clrscr();
rewind(fp);

    while(fread(&u,recsize,1,fp)==1)
    {
      if(strcmp(u.status,"paid")==0)
     {
printf("\n Name=%s",u.name);
printf("\n ID=%s",u.id);
printf("\n address=%s",u.address);
printf("\n");
     }
	 }
  printf("\nTHANK YOU");

getch();
break;

case'7':

clrscr();
rewind(fp);

    while(fread(&u,recsize,1,fp)==1)
    {
      if(strcmp(u.status,"unpaid")==0)
     {
printf("\n Name=%s",u.name);
printf("\n ID=%s",u.id);
printf("\n address=%s",u.address);
printf("\n");
     }
}
printf("\n\t\tTHANK YOU!!");

getch();
break;


case'0':
textcolor(GREEN);
gotoxy(3,7);
printf(" A MINI PROJECT ON ELECTRICITY BILLING SYSTEM");
gotoxy(5,18);
cprintf("By: ");
sleep(2);
gotoxy(6,15);
cprintf("suman humagain");
sleep(2);

sleep(2);
clrscr();
textcolor(RED);
gotoxy(14,14);
cprintf("\n\nThanks for your visit");
getch();
fclose(fp);
    exit(0);
  }
 }
}
void gotoxy(int r,int c)
{
	union REGS i,o;
	i.h.ah=2;
	i.h.bh=0;
	i.h.dh=r;
	i.h.dl=c;

	int86(16,&i,&o);

}



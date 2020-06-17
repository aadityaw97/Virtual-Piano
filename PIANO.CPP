#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <process.h>
#include <dos.h>

void SA()
{   sound(240);      //SA
}
void RE()
{   sound(270);      //RE
}
void GA()
{   sound(300);      //GA
}
void MA()
{   sound(320);      //MA
}
void PA()
{   sound(350);      //PA
}
void DHA()
{  sound(390);       //DHA
}
void NI()
{  sound(440);       //NI
}
void SAA()
{  sound(460);       //SA^
}

void pno_plp1()
{
	FILE *f1;
	char c;
	f1 = fopen("PNO_PLP1.cpp","r");
	while((c=getc(f1))!=EOF)
	{
	 printf("%c",c);
	}
	fclose(f1);
}

void pno_plp2()
{
	FILE *f1;
	char c;
	f1 = fopen("PNO_PLP2.cpp","r");
	while((c=getc(f1))!=EOF)
	{
	 printf("%c",c);
	}
	fclose(f1);
}

void main_piano(char tone,char mode,int tempo,int bps,char song[],int pos)
{
	clrscr();
	pno_plp1();
	printf("\n>>");
	for(int h=0; h<74; h++)
	printf(" ");
	printf(">>");
	printf("\n>>\t\t=========================================\t\t    >>");
	printf("\n>>\t\t=                                       =\t\t    >>");
	printf("\n>>\t\t=  TONE: %c MODE: %c  TEMPO: %dx BPS: %d    =\t\t    >>",tone,mode,tempo,bps);
	printf("\n>>\t\t=                                       =\t\t    >>");
	printf("\n>>\t\t=========================================\t\t    >>");
	printf("\n>>\t\t=    =    =    =    =    =    =    =    =\t\t    >>");
	printf("\n>>\t\t= SA = RE = GA = MA = PA = DH = NI = SA =\t\t    >>");
	printf("\n>>\t\t=    =    =    =    =    =    =    =    =\t\t    >>");
	printf("\n>>\t\t=========================================\t\t    >>\n>>\t\t");
	for(char i='1'; i<tone; i++)
	printf("     ");
	printf("  ^^");
	for( i='8' ; i>tone; i--)
	printf("     ");
	for(int j=0 ; j<21; j++)
	printf(" ");
	printf(">>\n");
	pno_plp2();
	for(int x=0; song[x]!=NULL; x++)
	{
		if(x==pos)
		printf("|");
		printf("%c",song[x]);
		if(x==pos)
		printf("|");
		if((x+1)%bps==0)
		printf(" ");
	}
}

void PLAY(char i)
{
	switch(i)
	{
		case '1': {SA();break;}
		case '2': {RE();break;}
		case '3': {GA();break;}
		case '4': {MA();break;}
		case '5': {PA();break;}
		case '6': {DHA();break;}
		case '7': {NI();break;}
		case '8': {SAA();break;}
		default:{break;}
	}
}

void PS(int tempo,int beat,char ch[],char mode)	//Play Song
{
	char i;
	int j=0;
	i=ch[j];
	while(i!=NULL)
	{
	       //printf("\ni=%c\n",i);

		if(i>'0'&&i<='8')
		{
		main_piano(i,mode,tempo,beat,ch,j);       //To Display Piano
		PLAY(i);				//To Play Sound
		delay(1000/tempo);
		}
		j++;
		i=ch[j];
	}
	printf("\n=>END");
	nosound();
}

void TY()
{
	clrscr();
	textcolor(WHITE+BLINK);
	FILE *f1;
	char c;
	f1 = fopen("ty.txt","r");
	while((c=getc(f1))!=EOF)
	{
	 printf("%c",c);
	}
	fclose(f1);
	getch();
}

void INB_SONG(int num)
{
	if(num==1)
	{
		char mode='A',song1[100]="8855885555555544556644555555558855885555554545443322231111";
		int spd=4,beat=4;
		PS(spd,beat,song1,mode);
	}
}


void get_song()
{
	char ch[100];
	int spd=1;
	printf("SPEED(1X,2X,4X,8X) : ");
	scanf("%d",&spd);
	printf("ENTER : ");
	scanf("%s",ch);
	PS(spd,4,ch,'M');
}

void MAINMENU()
{
	pass:

	int password;
	clrscr();
	printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t");

	printf("ENTER PASSWORD : ");
	scanf("%d",&password);

	if(password==1089)
	clrscr();
	else
	{
		printf("\n\n\n\t\t\tINCORRECT PASSWORD!");
		delay(1500);
		printf("\n\t\t\t   PRESS ENTER TO TRY AGAIN.");
		getch();
		goto pass;
	}

	here:

	clrscr();
	FILE *f1;
	char c;
	int main_opt;
	f1 = fopen("PNO_MENU.cpp","r");
	while((c=getc(f1))!=EOF)
	{
	 printf("%c",c);
	}
	fclose(f1);

	scanf("%d",&main_opt);

	switch(main_opt)
	{
		case 1:{ get_song();break;}
		case 2:{ INB_SONG(1);break;}
		case 3:{TY();exit(0);break;}
		default:{}
	}
	getch();
	goto here;

}


void main()
{
	clrscr();
	MAINMENU();
	getch();
}
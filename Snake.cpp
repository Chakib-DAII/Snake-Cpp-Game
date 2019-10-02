// Snake.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<Windows.h>
#include<conio.h>
#include<iostream>
//numeros de la fleche de clavier
#define haut 72
#define gauche 75
#define droite 77
#define bas 80 
#define esc  27
int snake[200][2];//pour enregistrer les coordonnées du snake
int n=1;
int tam=14;//la longueur du snake 
int x=10,y=5;//les coordonnées du snake
int dir=3;//direction 
int xc=30,yc=15;//les coordonnées de la nourriture
int vitesse=200,h=1;
int score=0;
char tecla;//caractere saisie
//fonction qui positionne le curseur
void gotoxy(int x , int y)
{ HANDLE hCon;
  COORD dwPos;
  dwPos.X=x;
  dwPos.Y=y;
  hCon=GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleCursorPosition(hCon,dwPos);
}
//fonction de repture de l'execution
void sleep(unsigned long int n)
{unsigned i = 0;
 unsigned long int max = n * 100000;
 do{i++;} while(i <= max);
}
//fonction de cadrage
void cadre()
{//lignes horizontales
	for(int i=2;i<78;i++)
	  {gotoxy(i,3);printf("%c",205);
	   gotoxy(i,23);printf("%c",205);}
//lignes verticales
	for(int i=4;i<23;i++)
	  {gotoxy(2,i);printf("%c",186);
	   gotoxy(78,i);printf("%c",186);}
//les coins
  gotoxy(2,3);printf("%c",201);
  gotoxy(2,23);printf("%c",200);
  gotoxy(78,3);printf("%c",187);
  gotoxy(78,23);printf("%c",188);
}
//fonction qui garde la position du snake
void garder_position()
{snake[n][0]=x;
    snake[n][1]=y;
	n++;
	if(n==tam)n=1;
}
//fonction qui imprime le snake
void imprime_snake()
{for(int j=1;j<tam;j++)
     {gotoxy(snake[j][0],snake[j][1]);printf("*");}
}
//fonction qui assure le deplacement du snake
void deplace_snake()
{ gotoxy(snake[n][0],snake[n][1]);printf(" ");
}
//fonction de direction
void direction(){if(kbhit())
	{tecla=getch();
	switch(tecla)
	  {case haut : if(dir != 2)dir=1;break;
	   case bas : if(dir != 1)dir=2;break;
	   case droite : if(dir != 4)dir=3;break;
	   case gauche:if(dir != 3)dir=4;break;

	}
	}} 
//fonction qui augmente la vitesse du snake
void augmenter_vitesse()
{if(score==h*20)
  {vitesse-=5;
   h++;}
}
bool test_snake()
{for(int i=tam-1;i>0;i--)
		{if((xc==snake[i][0])&&(yc==snake[i][1]))
			return false;}
return true;
}
//la nourriture du snake 
void nourriture()
{if(x==xc && y==yc)
     {gotoxy(65,1);printf("Bravo !!");
	  do{xc=(rand()%73)+4;
      yc=(rand()%19)+4;
	  }while(!test_snake());
	  tam++;
	  score+=10;
      gotoxy(xc,yc);printf("%c",4);
      augmenter_vitesse();}
  
}
//test de fin de jeux
bool game_over()
{if(y==3 || y==23 || x==2 || x==78)
      return true;
for(int i=tam-1;i>0;i--)
	if(snake[i][0]==x && snake[i][1]==y)
	  return true;
 return false;
  }
//fonction qu'imprime score
void imprime_points()
{gotoxy(3,1);printf("score %d",score);}
//fonction qu'imprime longueur
void imprime_long()
{gotoxy(15,1);printf("longueur %d",tam-1);}
//fonction qu'imprime longueur
void change_color()
{if(score/50==1)
system("color 79");
else if(score/50==2)
system("color 72");
else if(score/50==3)
system("color 7c");
else if(score/50==4)
system("color 7e");
else if(score/50==5)
system("color 7f");
else if(score/50==6)
system("color 7e");
else if(score/50==7)
system("color 72");
else if(score/50==8)
system("color 7c");
else if(score/50==9)
system("color 7e");
else if(score/50==10)
system("color 7c");
else if(score/50==11)
system("color 79");
else if(score/50==12)
system("color 72");
else if(score/50==13)
system("color 7c");
else if(score/50==14)
system("color 7e");
else if(score/50==15)
system("color 7f");
else if(score/50==16)
system("color 7e");
else if(score/50==17)
system("color 72");
else if(score/50==18)
system("color 7c");
else if(score/50==19)
system("color 7e");
else if(score/50==20)
system("color 7e");
else 
system("color 7f");
}
//fonction de demarrage
void debut()
{//s
	for(int i=17;i<24;i++)
	  {gotoxy(i,8);printf("*");
	   gotoxy(i,17);printf("*");
	   gotoxy(i,12);printf("*");}
		for(int i=9;i<12;i++)
	  {gotoxy(17,i);printf("*");
	   gotoxy(24,i+3);printf("*");
		gotoxy(24,i+6);printf("*");}
     sleep(70);
//n
		for(int i=8;i<18;i++)
	  {gotoxy(27,i);printf("*");
		gotoxy(35,i);printf("*");}
		for(int i=27;i<35;i++)
		{gotoxy(i,i-19);printf("*");}
        sleep(70);
//a
	for(int i=39;i<44;i++)
	  {gotoxy(i,8);printf("*");
	   gotoxy(i,12);printf("*");}
	for(int i=9;i<18;i++)
	  {gotoxy(38,i);printf("*");
		gotoxy(44,i);printf("*");}
	sleep(70);
//k
	for(int i=8;i<18;i++)
	  {gotoxy(47,i);printf("*");}
	for(int i=47,j=11,k=13;i<54;i++,j++,k--)
		{gotoxy(i,j);printf("*");
	     gotoxy(i,k);if(k>7)printf("*");}
	sleep(70);
//e
	for(int i=8;i<18;i++)
	  {gotoxy(56,i);printf("*");}
	for(int i=57;i<62;i++)
	  {gotoxy(i,8);printf("*");
	   gotoxy(i,17);printf("*");
	   gotoxy(i,12);printf("*");}
	sleep(150);
//imprime nom du developpeur:p
gotoxy(48,18);printf("By DAII Chakib");
//snake qui bouge
int i=0;
while(i<56)
	{deplace_snake();
	garder_position();
	imprime_snake();
	x++;i++;
	sleep(vitesse);
	}
	dir=2;i=0;
	while(i<16)
	{deplace_snake();
	garder_position();
	imprime_snake();
	y++;i++;
	sleep(vitesse);
	}
	dir=4;i=0;
	while(i<25)
	{deplace_snake();
	garder_position();
	imprime_snake();
	x--;i++;
	sleep(vitesse);
	}
	system("cls");
	gotoxy(40,12);printf("1");
	sleep(400);
    gotoxy(40,12);printf(" ");
	sleep(400);
    gotoxy(40,12);printf("2");
	sleep(400);
	gotoxy(40,12);printf(" ");
	sleep(400);
	gotoxy(40,12);printf("3");
	sleep(400);
	gotoxy(40,12);printf(" ");
	sleep(400);
	gotoxy(38,12);printf("Go ...");
	sleep(200);
	system("cls");
}
//fonction qui initialise le jeux
void initialise()
  { system("cls");
	cadre();
	tam=3;dir=3;
	x=10,y=5;
	n=1;
	vitesse=300;
	score=0;
	tecla=droite;
gotoxy(xc,yc);printf("%c",4);}
//fonction de fin de jeux
void fin()
{system("cls");
//s
	for(int i=17;i<24;i++)
	  {gotoxy(i,8);printf("*");
	   gotoxy(i,17);printf("*");
	   gotoxy(i,12);printf("*");}
		for(int i=9;i<12;i++)
	  {gotoxy(17,i);printf("*");
	   gotoxy(24,i+3);printf("*");
		gotoxy(24,i+6);printf("*");}
     sleep(70);
//n
		for(int i=8;i<18;i++)
	  {gotoxy(27,i);printf("*");
		gotoxy(35,i);printf("*");}
		for(int i=27;i<35;i++)
		{gotoxy(i,i-19);printf("*");}
        sleep(70);
//a
	for(int i=39;i<44;i++)
	  {gotoxy(i,8);printf("*");
	   gotoxy(i,12);printf("*");}
	for(int i=9;i<18;i++)
	  {gotoxy(38,i);printf("*");
		gotoxy(44,i);printf("*");}
	sleep(70);
//k
	for(int i=8;i<18;i++)
	  {gotoxy(47,i);printf("*");}
	for(int i=47,j=11,k=13;i<54;i++,j++,k--)
		{gotoxy(i,j);printf("*");
	     gotoxy(i,k);if(k>7)printf("*");}
	sleep(70);
//e
	for(int i=8;i<18;i++)
	  {gotoxy(56,i);printf("*");}
	for(int i=57;i<62;i++)
	  {gotoxy(i,8);printf("*");
	   gotoxy(i,17);printf("*");
	   gotoxy(i,12);printf("*");}
	sleep(150);
//imprime nom du developpeur:p
	gotoxy(48,18);printf("By DAII Chakib");
    sleep(2000);

	exit (-1);}
int _tmain(int argc, _TCHAR* argv[])
{	system("title Snake");
	cadre();
	debut();
game:initialise();
pause:tecla=droite;
	gotoxy(38,12);printf("      ");
	while(!game_over())
	{change_color();
	deplace_snake();
	garder_position();
	imprime_snake(); 
	nourriture();
	imprime_points();
	imprime_long();
	direction();
	direction();
	direction();
	direction();
	if(dir==1)y--;
	if(dir==2)y++;
	if(dir==3)x++;
	if(dir==4)x--;
	sleep(vitesse);
	gotoxy(65,1);printf("           ");
	if(tecla==esc){gotoxy(38,12);printf("Pause");do{if(kbhit()){tecla=getch();if(tecla==esc)goto pause;}}while(kbhit()!=esc);}
	}
	do{gotoxy(55,21);printf("HAUT : Play Again");
	   gotoxy(55,22);printf("ESC : Quit");
		gotoxy(36,12);printf("GAME OVER");
	   if(kbhit()){tecla=getch();if(tecla==haut)goto game;
	                             else if(tecla==esc)goto quit;}
	   sleep(400);
	   if(kbhit()){tecla=getch();if(tecla==haut)goto game;
	                             else if(tecla==esc)goto quit;}
	   gotoxy(36,12);printf("         ");
	     if(kbhit()){tecla=getch();if(tecla==haut)goto game;
	                             else if(tecla==esc)goto quit;}
	   sleep(400);
	     if(kbhit()){tecla=getch();if(tecla==haut)goto game;
	                             else if(tecla==esc)goto quit;}
	  }while(kbhit()!=esc);
    quit:fin();
	return 0;
}


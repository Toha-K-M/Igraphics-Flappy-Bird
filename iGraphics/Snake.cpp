#include "iGraphics.h"//array//level
#include<conio.h>
#include<string.h>
#include<stdlib.h>

int fruit_x, fruit_y;
int dx, dy;
int snake_x,snake_y; 
int a=30,b=15;
int f=1;
int flag =1,straight=0;
int temp;
int m1x,m1y;
int points=0;
char p[20];
int g=0;
int level=10;

void iDraw()
{
	//place your drawing codes here	

	iClear();

	iSetColor(255, 0, 10);
	iFilledRectangle(fruit_x, fruit_y, 5,5);
	iSetColor(0,255,0);
	iFilledRectangle(snake_x,snake_y,a,b);
	
	iSetColor(255, 255, 255);
	iText(10, 10, "Press p for pause, r for resume, END for exit.");

	iSetColor(150,255,150);
	iText(250,390,"GOAL : SCORE 10");

	iSetColor(0,0,255);
	iFilledRectangle(0,40,30,10);
	iFilledRectangle(0,40,10,30);
	iFilledRectangle(370,370,30,10);
	iFilledRectangle(390,370,10,30);
	
	
	iSetColor(0,0,255);
	sprintf(p,"%d",points);
	printf("%s\n",p);
	char temp[20]="SCORE: ";
	strcat(temp,p);
	iText(10,390,temp );

	if(g==1)
	{
		iSetColor(255,255,255);
		iText(150,200,"GAME OVER");
	}

	iSetColor(0,0,255);
if(points==10)
	{	

		iText(120,250,"GAME OVER");
		iText(120,225,"YOU WIN");
		iText(120,200,"YOUR SCORE : 10");
		iText(120,175,"HIGHEST SCORE : 10");
		iPauseTimer(0); }
}

void iMouseMove(int mx, int my)
{
	//place your codes here
}

void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
}

void iKeyboard(unsigned char key)
{
	if(key == 'p')
	{
		//do something with 'q'
		iPauseTimer(0);
	}
	if(key == 'r')
	{
		iResumeTimer(0);
	}
	//place your codes for other keys here
}

void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	if(key == GLUT_KEY_UP)
	{
		snake_y+=1;
		flag=0;
		f=1;
		if(straight==0){
			temp=a;a=b;b=temp;
			straight=1;}
	
	}
	if(key == GLUT_KEY_DOWN)
	{
		snake_y-=1;
		flag=0;
		f=-1;
		if(straight==0)
		{temp=a;a=b;b=temp;straight=1;}
		

	}
	if(key == GLUT_KEY_RIGHT)
	{
		snake_x+=1;
		flag=1;
		f=1;
		
		if(straight==1){temp=a;a=b;b=temp;}
		straight=0;
	}
	if(key == GLUT_KEY_LEFT)
	{
		snake_x-=1;
		flag=1;
		f=-1;
		if(straight ==1){temp=a;a=b;b=temp;}
		straight=0;

		
	}

	//place your codes for other keys here
}

void solidsnake(){

	fruit_x=dx; fruit_y=dy;

	if(flag==1)snake_x+=f;
	if(flag==0){snake_y+=f;}

	if(snake_x > 400 )snake_x=0;
	if(snake_x <0 )snake_x=400;
	if(snake_y > 400)snake_y=0;
	if(snake_y < 0)snake_y=400;

	//m1x=dx+dx+5/2;
	//m1y=dy+dy+5/2;
	
	//intersection
	if((straight==0 && dx== snake_x && snake_y < dy && snake_y+15>dy)          ||
	   (straight==0 && dx+5== snake_x && snake_y < dy && snake_y+15 >dy)       ||
	   (straight==0 && dx+5== snake_x && snake_y < dy+5 && snake_y+15 >dy+5)   ||
	   (straight==0 && dx==snake_x && snake_y < dy+5 && snake_y+15 > dy+5)     ||
	   (straight==0 && dx== snake_x+30 && snake_y < dy && snake_y+15>dy)       ||
	   (straight==0 && dx+5== snake_x+30 && snake_y < dy && snake_y+15 >dy)    ||
	   (straight==0 && dx+5== snake_x+30 && snake_y < dy+5 && snake_y+15 >dy+5)||
	   (straight==0 && dx==snake_x+30 && snake_y < dy+5 && snake_y+15 > dy+5))
	{	
		a=a+20;
		dx=rand()%350;
		dy=rand()%350;
		points++;
	}	
	if((straight==1 && dy==snake_y && snake_x < dx && snake_x+30>dx)           ||     
	   (straight==1 && dy==snake_y && snake_x < dx+5 && snake_x+30>dx+5)	   ||
	   (straight==1 && dy+5==snake_y && snake_x < dx+5 && snake_x+30>dx+5)     ||
	   (straight==1 && dy+5==snake_y && snake_x < dx && snake_x+30>dx)         ||
	   (straight==1 && dy==snake_y+30 && snake_x < dx && snake_x+30>dx)        ||     
	   (straight==1 && dy==snake_y+30 && snake_x < dx+5 && snake_x+30>dx+5)	   ||
	   (straight==1 && dy+5==snake_y+30 && snake_x < dx+5 && snake_x+30>dx+5)  ||
	   (straight==1 && dy+5==snake_y+30 && snake_x < dx && snake_x+30>dx))
	{
		b=b+20;
		dx=rand()%350;
		dy=rand()%350;
		points++;
	}
	//obstacle
	if((straight==0 && 0== snake_x && snake_y < 40 && snake_y+15>40)           ||
	   (straight==0 && 0+30== snake_x && snake_y < 40 && snake_y+15 >40)       ||
	   (straight==0 && 0+30== snake_x && snake_y < 40+30 && snake_y+15 >40+30)   ||
	   (straight==0 && 0==snake_x && snake_y < 40+30 && snake_y+15 > 40+30)     ||
	   (straight==0 && 0== snake_x+30 && snake_y < 40 && snake_y+15>40+30)       ||
	   (straight==0 && 0+35== snake_x+30 && snake_y < 40 && snake_y+15 >40+30)    ||
	   (straight==0 && 0+35== snake_x+30 && snake_y < 40+30 && snake_y+15 >40+30)||
	   (straight==0 && 0==snake_x+30 && snake_y < 40+30 && snake_y+15 > 40+30))
	{	
		g=1;
		iPauseTimer(0);
		
	}

    if((straight==1 && 40==snake_y && snake_x < 0 && snake_x+30>0)           ||     
	   (straight==1 && 40==snake_y && snake_x < 0+10 && snake_x+30>0+10)	   ||
	   (straight==1 && 40+30==snake_y && snake_x < 0+10 && snake_x+30>0+10)     ||
	   (straight==1 && 40+30==snake_y && snake_x < 0 && snake_x+30>0)         ||
	   (straight==1 && 40==snake_y+30 && snake_x < 0 && snake_x+30>0)        ||     
	   (straight==1 && 40==snake_y+30 && snake_x < 0+10 && snake_x+30>0+10)	   ||
	   (straight==1 && 40+30==snake_y+30 && snake_x < 0+10 && snake_x+30>0+10)  ||
	   (straight==1 && 40+30==snake_y+30 && snake_x < 0 && snake_x+30>0))
	{	
		g=1;
		iPauseTimer(0);
		
	}
	if((straight==0 && 370== snake_x && snake_y < 370 && snake_y+15>370)           ||
	   (straight==0 && 370+30== snake_x && snake_y < 370 && snake_y+15 >370)       ||
	   (straight==0 && 370+30== snake_x && snake_y < 370+30 && snake_y+15 >370+30)   ||
	   (straight==0 && 370==snake_x && snake_y < 370+30 && snake_y+15 > 370+30)     ||
	   (straight==0 && 370== snake_x+30 && snake_y < 370 && snake_y+15>370+30)       ||
	   (straight==0 && 370+35== snake_x+30 && snake_y < 3700 && snake_y+15 >370+30)    ||
	   (straight==0 && 370+35== snake_x+30 && snake_y < 370+30 && snake_y+15 >370+30)||
	   (straight==0 && 370==snake_x+30 && snake_y < 370+30 && snake_y+15 > 370+30))
	{	
		g=1;
		iPauseTimer(0);
		
	}
    if((straight==1 && 370==snake_y && snake_x < 370 && snake_x+30>370)           ||     
	   (straight==1 && 370==snake_y && snake_x < 370+10 && snake_x+30>370+10)	   ||
	   (straight==1 && 370+30==snake_y && snake_x < 370+10 && snake_x+30>370+10)     ||
	   (straight==1 && 370+30==snake_y && snake_x < 370 && snake_x+30>370)         ||
	   (straight==1 && 370==snake_y+30 && snake_x < 370 && snake_x+30>370)        ||     
	   (straight==1 && 370==snake_y+30 && snake_x < 370+10 && snake_x+30>370+10)	   ||
	   (straight==1 && 370+30==snake_y+30 && snake_x < 370+10 && snake_x+30>370+10)  ||
	   (straight==1 && 370+30==snake_y+30 && snake_x < 370 && snake_x+30>370))
	{	
		g=1;
		iPauseTimer(0);
		
	}
	if(points>=5)
	{
		iSetTimer(300,solidsnake);
	}

}

int main()
{
	//place your own initialization codes here. 
	if(points<5)
	{iSetTimer(10, solidsnake);
	
	}
	
	dx = 150;
	dy = 50;
	
	iInitialize(400, 400, "Snake");
	return 0;
}	
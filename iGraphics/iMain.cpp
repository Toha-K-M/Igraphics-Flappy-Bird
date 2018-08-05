#include "iGraphics.h"//array//level
#include<stdio.h>
#include<Windows.h>
#include<MMSystem.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

int x=350,y=400;
int down=0;
int z;
int rrrx=400,rrry=550;
int mod=10;

char one[20]="1 two.bmp";
char four[20]="4 two.bmp";
char seven[20]="7 two.bmp";
char five[20]="5 two.bmp";
//pillar
int rx=800,ry;
int rx1=1150,ry1;//rx5
int rx2=1500,ry2;//rx6
int rx3=1850,ry3;//rx7
int rx8=2200,ry8;//rx8
int rx10=2550,ry10;//rx10

int rx4=800,ry4=550;
int rx5=1150,ry5=650;
int rx6=1500,ry6=550;
int rx7=1850,ry7=450;
int rx9=2200,ry9=750;
int rx11=2550,ry11=650;
//temporary pillar

int f=-8;
int flag =1,straight=0;

//points
int temp;
int points=0;
char p[20];
int g=0;
int score=0;
//

char t1[20]="fpillar1.bmp";//100,310
int  ht1=310;

char t2[20]="fpillar.bmp";//100,410
int ht2=410;

char t4[20]="fpillar111.bmp";//100,310
int  ht4=310;

char t3[20]="fpillar11.bmp";//100,210
int ht3=210;

char t5[20]="fpillar1111.bmp";//100,510
int ht5=510;

char t6[20]="fpillar11111.bmp";
int ht6=410;

//fixed

char fix1[20]="fpillar1.bmp";//100,310


char fix2[20]="fpillar.bmp";//100,410


char fix4[20]="fpillar111.bmp";//100,310


char fix3[20]="fpillar11.bmp";//100,210


char fix5[20]="fpillar1111.bmp";//100,510


char fix6[20]="fpillar11111.bmp";
//

char u[20]="fpillar2.bmp";//100,500


//temporary v
char v[20]={0},v1[20]={0},v2[20]={0},v3[20]={0},v4[20]={0};
int h,h1,h2,h3,h4,m,m1,m2,m3,m4;

int game=1;int bb = 0;


void iDraw()
{
	
	//place your drawing codes here	

	iClear();
if(game==1){

	iShowBMP(0,0,"1flappybackground.bmp");
	
//pillar
	iSetColor(0,250,0);
	iShowBMP(rx,ry,  t1);//100,310 ht1
	iShowBMP(rx1,ry1,t2);//100,410 ht2
	iShowBMP(rx2,ry2,t4);//100,310 ht1
	iShowBMP(rx3,ry3,t3);//100,210 ht3
	iShowBMP(rx8,ry8,t5);//100,510 ht5
	iShowBMP(rx10,ry10,t6);
	iShowBMP(rx4,ry4,u);
	iShowBMP(rx5,ry5,u);//100,500
	iShowBMP(rx6,ry6,u);
	iShowBMP(rx7,ry7,u);
	iShowBMP(rx9,ry9,u);
	iShowBMP(rx11,ry11,u);

	iShowBMP(rrrx,rrry,"ready.bmp");
//bird
	//iSetColor(255,255,255);
	if(down==1){
	iShowBMP(x,y,"bird.bmp");//60,45
	}
	if(down==0)
	{
		iShowBMP(x,y,"dbird.bmp");
	}
	
//points
/*	iSetColor(0,0,255);
	sprintf(p,"%d",points);
	printf("%s\n",p);
	char temp[20]="SCORE: ";
	strcat(temp,p);
	iText(10,790,temp );*/

	/*if(g==1)
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
		iPauseTimer(0);
	}*/

//points animation
if(points>=10 && points<20)
{
	mod=10;
	iShowBMP(16,745,"1.bmp");
}
if(points>=20 && points<30){
	mod=20;
	iShowBMP(16,745,"2.bmp");
}
if(points>=30 && points<40){
	mod=30;
	iShowBMP(16,745,"3.bmp");
}
if(points>=40 && points<50){
	mod=40;
	iShowBMP(16,745,"4.bmp");
}
if(points>=50 && points<60){
	mod=50;
	iShowBMP(16,745,"5.bmp");
}

if(points%mod==0)
{iShowBMP(40,745,"0.bmp");}
if(points%mod==1)
{iShowBMP(40,745,"1.bmp");}
if(points%mod==2)
{iShowBMP(40,745,"2.bmp");}
if(points%mod==3)
{iShowBMP(40,745,"3.bmp");}
if(points%mod==4)
{iShowBMP(40,745,"4.bmp");}
if(points%mod==5)
{iShowBMP(40,745,"5.bmp");}
if(points%mod==6)
{iShowBMP(40,745,"6.bmp");}
if(points%mod==7)
{iShowBMP(40,745,"7.bmp");}
if(points%mod==8)
{iShowBMP(40,745,"8.bmp");}
if(points%mod==9)
{iShowBMP(40,745,"9.bmp");}


}
	if(game==0){
		iShowBMP(0,80,"game-over1222.bmp");
	//	iText(400,250, points);

		if(points>=10 && points<20)
		{
			mod=10;
			iShowBMP(450,468,one);
		}
		if(points>=20 && points<30){
			mod=20;
			iShowBMP(450,468,"2.bmp");
		}
		if(points>=30 && points<40){
			mod=30;
			iShowBMP(450,468,"3.bmp");
		}
		if(points>=40 && points<50){
			mod=40;
			iShowBMP(450,468,four);
		}
		if(points>=50 && points<60){
			mod=50;
			iShowBMP(450,468,five);
		}

		if(points%mod==0)
		{iShowBMP(484,468,"0.bmp");}
		if(points%mod==1)
		{iShowBMP(484,468,one);}
		if(points%mod==2)
		{iShowBMP(484,468,"2.bmp");}
		if(points%mod==3)
		{iShowBMP(484,468,"3.bmp");}
		if(points%mod==4)
		{iShowBMP(484,468,four);}
		if(points%mod==5)
		{iShowBMP(484,468,five);}
		if(points%mod==6)
		{iShowBMP(484,468,"6.bmp");}
		if(points%mod==7)
		{iShowBMP(484,468,seven);}
		if(points%mod==8)
		{iShowBMP(484,468,"8.bmp");}
		if(points%mod==9)
		{iShowBMP(484,468,"9.bmp");}
				

	}
	if(bb==0)
	{
		iPauseTimer(0);
		iShowBMP(0,80,"startmenu1.bmp");
	}



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
		iPauseTimer(0);
	}
	if(key == 'r')
	{
		iResumeTimer(0);
	}
//restart
	if(key=='1')
	{
		game=1;
	 x=350,y=400;
	 	
 down=0;

//pillar

 rx=800,ry;//rx4
 rx1=1150,ry1;//rx5
 rx2=1500,ry2;//rx6
 rx3=1850,ry3;//rx7
 rx8=2200,ry8;//rx8
 rx10=2550,ry10;//rx10

 rx4=800,ry4=550;
 rx5=1150,ry5=650;
 rx6=1500,ry6=550;
 rx7=1850,ry7=450;
 rx9=2200,ry9=750;
 rx11=2550,ry11=650;
//temporary pillar

//pillar d
 
 ht1=310;

ht2=410;

 ht4=310;

ht3=210;

ht5=510;

ht6=410;

 strcpy(t1,fix1);
 strcpy(t2,fix2);
 strcpy(t4,fix4);
 strcpy(t3,fix3);
 strcpy(t5,fix5);
 strcpy(t6,fix6);

 



//points
 temp;
 points=0;
 p[20];
 g=0;

 rrry=550;
 rrrx=400;



	}
	if(key==' ')
	{bb=1;game=1;iResumeTimer(0);
	PlaySound(TEXT("start.wav"), NULL, SND_ASYNC);}


	if(key=='n'||key=='N')
		exit(0);
}

void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{	

		exit(0);	
	}
	if(key == GLUT_KEY_UP)
	{
		PlaySound(TEXT("up.wav"), NULL, SND_ASYNC);
		y+=1;
		down=1;	
		z=y;
		
	}
	
	
}

void solidsnake(){

if(y>=z+90){down=0;}
if(down==1){y+=10;}
if(down==0)
{y-=8;

}

rrrx+=f;
	//pillar
	rx+=f;
	rx1+=f;
	rx2+=f;
	rx3+=f;
	rx4+=f;
	rx5+=f;
	rx6+=f;
	rx7+=f;
	rx8+=f;
	rx9+=f;
	rx10+=f;
	rx11+=f;
//1
	if(rx <=0 )  {
					rx=2150; 
					strcpy(v,t1);
					strcpy(t1,t2);

					h=ht1;
					ht1=ht2;

				}
	if(rx4 <= 0 ){rx4=2150;
					
					m=ry4;
					ry4=ry5;
	}
//2
	if(rx1 <= 0 ){
		
					rx1=2150;
					strcpy(v1,t2);
					strcpy(t2,v);

					h1=ht2;
					ht2=h;
//strcpy(v1,t2);strcpy(t2,v);
	}
	if(rx5 <= 0 ){rx5=2150;
					m1=ry5;
					ry5=m;
	//h1=ry5;ry5=h;
	}
//3
	if(rx2 <= 0 ){
					rx2=2150;
					strcpy(v2,t4);
					strcpy(t4,t3);

					h2=ht4;
					ht4=ht3;
	}
	if(rx6 <= 0 ){rx6=2150;
					m2=ry6;
					ry6=ry7;
	}
//4
	if(rx3 <= 0 ){rx3=2150;
				 
					strcpy(v3,t3);
					strcpy(t3,v2);

					h3=ht3;
					ht3=h2;


	}
	if(rx7 <= 0 ){rx7=2150;
					m3=ry7;
					ry7=m2;
	}
//5
	if(rx8<=0){rx8=2150;
					
					strcpy(v4,t5);
					strcpy(t5,t6);

					h4=ht5;
					ht5=ht6;

	}
	if(rx9<=0){rx9=2150;
	
					m4=ry9;
					ry9=ry11;
	}
//6
	if(rx10<=0){rx10=2150;
					strcpy(t6,v4);

					ht6=h4;
	}
	if(rx11<=0){
				rx11=2150;
				ry11=m4;
	}
	
//collision

	if(//1 
		(x+60>=rx  && x+60<=rx+100 && y>=ry && y<=ry+ht1)  ||
		(y>=ry && y<=ry+ht1 && x>=rx && x<=rx+100)         ||
		(x+60>=rx4  && x+60<=rx4+100 && y+45>=ry4 && y+45<=800)  ||
		(y+45>=ry4 && y+45<=800 && x>=rx4 && x<=rx4+100)         
	  )
	{
		iPauseTimer(0);game=0;
		PlaySound(TEXT("smash.wav"), NULL, SND_ASYNC);
	}
	if(//2
		(x+60>=rx1  && x+60<=rx1+100 && y>=ry1 && y<=ry1+ht2)  ||
		(y>=ry1 && y<=ry1+ht2 && x>=rx1 && x<=rx1+100)         ||
		(x+60>=rx5  && x+60<=rx5+100 && y+45>=ry5 && y+45<=800)  ||
		(y+45>=ry5 && y+45<=800 && x>=rx5 && x<=rx5+100)         
	  )
	{
		iPauseTimer(0);game=0;
		PlaySound(TEXT("smash.wav"), NULL, SND_ASYNC);
	}
	if(//3
		(x+60>=rx2  && x+60<=rx2+100 && y>=ry2 && y<=ry2+ht4)  ||
		(y>=ry2 && y<=ry2+ht4 && x>=rx2 && x<=rx2+100)         ||
		(x+60>=rx6  && x+60<=rx6+100 && y+45>=ry6 && y+45<=800)  ||
		(y+45>=ry6 && y+45<=800 && x>=rx6 && x<=rx6+100)         
	  )
	{
		iPauseTimer(0);game=0;
		PlaySound(TEXT("smash.wav"), NULL, SND_ASYNC);
	}
	if(//4
		(x+60>=rx3  && x+60<=rx3+100 && y>=ry3 && y<=ry3+ht3)  ||
		(y>=ry3 && y<=ry3+ht3 && x>=rx3 && x<=rx3+100)         ||
		(x+60>=rx7  && x+60<=rx7+100 && y+45>=ry7 && y+45<=800)  ||
		(y+45>=ry7 && y+45<=800 && x>=rx7 && x<=rx7+100)         
	  )
	{
		iPauseTimer(0);game=0;
		PlaySound(TEXT("smash.wav"), NULL, SND_ASYNC);
	}
	if(//5
		(x+60>=rx8  && x+60<=rx8+100 && y>=ry8 && y<=ry8+ht5)  ||
		(y>=ry8 && y<=ry8+ht5 && x>=rx8 && x<=rx8+100)         ||
		(x+60>=rx9  && x+60<=rx9+100 && y+45>=ry9 && y+45<=800)  ||
		(y+45>=ry9 && y+45<=800 && x>=rx9 && x<=rx9+100)         
	  )
	{
		iPauseTimer(0);game=0;
		PlaySound(TEXT("smash.wav"), NULL, SND_ASYNC);
	}
	if(//6
		(x+60>=rx10  && x+60<=rx10+100 && y>=ry10 && y<=ry10+ht6)  ||
		(y>=ry10 && y<=ry10+ht6 && x>=rx10 && x<=rx10+100)         ||
		(x+60>=rx11  && x+60<=rx11+100 && y+45>=ry11 && y+45<=800)  ||
		(y+45>=ry11 && y+45<=800 && x>=rx11 && x<=rx11+100)         
	  )
	{
		iPauseTimer(0);game=0;
		PlaySound(TEXT("smash.wav"), NULL, SND_ASYNC);
	}
	if(x<0 || y+45>800)
	{
		iPauseTimer(0);game=0;
	}
	if( x>rx+100 && x<rx+108 || x>rx1+100 && x<rx1+108 || x>rx2+100 && x<rx2+108 || x>rx3+100 && x<rx3+108 || x>rx8+100 && x<rx8+108 || 
		x>rx10+100 && x<rx10+108)
	{
		points++;
		
		PlaySound(TEXT("coin.wav"), NULL, SND_ASYNC);
	}
}


int main()
{	
	
	iSetTimer(1, solidsnake);
	
	iInitialize(800, 800, "flappybird");
	return 0;
}	
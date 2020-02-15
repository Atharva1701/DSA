#include<iostream>
#include<stdio.h>
#include<graphics.h>
#include<math.h>
using namespace std;
void koch(int x1,int y1,int x2,int y2,int it)
{
	int theta=60*(M_PI/180);
	int x3=(2*x1+x2)/3;
	int x4=(x1+2*x2)/3;
	int y3=(2*y1+y2)/3;
	int y4=(y1+2*y2)/3;
	
	int x=x3+(x4-x3)*cos(theta)+(y4-y3)*sin(theta);
	int y=y3-(x4-x3)*sin(theta)+(y4-y3)*cos(theta);
	
	if(it>0)
	{
		koch(x1,y1,x3,y3,it-1);
		koch(x3,y3,x,y,it-1);
		koch(x,y,x4,y4,it-1);
		koch(x4,y4,x2,y2,it-1);
	}
	else
	{
		line(x1,y1,x3,y3);
		line(x3,y3,x,y);
		line(x,y,x4,y4);
		line(x4,y4,x2,y2);	
	} 
}
void seedFill(int x,int y,int col)
{
	int g=getpixel(x,y);
	if(g!=col && g!=WHITE)
	{
		putpixel(x,y,col);
		seedFill(x+1,y,col);
		seedFill(x-1,y,col);
		seedFill(x,y+1,col);
		seedFill(x,y-1,col);
	}
}
int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	char *p=(char*)"Koch SnowFlake->";
	outtextxy(20,30,p);
	koch(200,266,100,100,5);
	koch(100,100,300,100,5);
	koch(300,100,200,266,5);
	seedFill(150,150,15);
	int n=getchar();
	closegraph();
}

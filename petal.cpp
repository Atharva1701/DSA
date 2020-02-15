#include<iostream>
#include<graphics.h>
#include<stdio.h>
#include<math.h>
using namespace std;
void petal(int x1[4],int y1[4])
{
	int x,y;
	for(double u=0;u<1;u+=0.0005)
	{
		x=x1[3]*(pow(u,3))+3*x1[2]*(pow(u,2))*(1-u)+3*x1[1]*u*pow((1-u),2)+x1[0]*pow((1-u),3);
		y=y1[3]*(pow(u,3))+3*y1[2]*(pow(u,2))*(1-u)+3*y1[1]*u*pow((1-u),2)+y1[0]*pow((1-u),3);
		putpixel(x,y,GREEN);
		delay(1);
	}
}
int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	char *p=(char*)"Bezier Curve Flower =>";
	outtextxy(20,10,p);
	int x1[4]={200,160,240,200},y1[4]={200,160,160,200};
	int x2[4]={200,240,240,200},y2[4]={200,160,240,200};
	int x3[4]={200,240,160,200},y3[4]={200,240,240,200};
	int x4[4]={200,160,160,200},y4[4]={200,240,160,200};
	int x5[4]={200,0,400,200},y5[4]={200,0,0,200};
	int x6[4]={200,400,400,200},y6[4]={200,0,400,200};
	int x7[4]={200,400,0,200},y7[4]={200,400,400,200};
	int x8[4]={200,0,0,200},y8[4]={200,400,0,200};	
	int x9[4]={200,100,300,200},y9[4]={200,100,100,200};
	int x10[4]={200,300,300,200},y10[4]={200,100,300,200};
	int x11[4]={200,300,100,200},y11[4]={200,300,300,200};
	int x12[4]={200,100,100,200},y12[4]={200,300,100,200};	
	petal(x1,y1);
	petal(x2,y2);
	petal(x3,y3);
	petal(x4,y4);
	petal(x9,y9);
	petal(x10,y10);
	petal(x11,y11);
	petal(x12,y12);
	petal(x5,y5);
	petal(x6,y6);
	petal(x7,y7);
	petal(x8,y8);
	getchar();
	closegraph();
}

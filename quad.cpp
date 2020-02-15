#include<iostream>
#include<math.h>
using namespace std;
class Quad
{
	float a,b,c,determinant;
	public:
	Quad()
	{
		a=b=c=determinant=0;	
	}
	Quad(float a,float b,float c,float determinant)
	{
		this->a=a;
		this->b=b;
		this->c=c;
		this->determinant=determinant;	
	}
	friend istream &operator>>(istream&,Quad&);
	friend ostream &operator<<(ostream&,Quad&);
	void roots();
	Quad operator+(Quad);
	void eval(float); 
	
};
istream &operator>>(istream &in,Quad &q)
{
	cout<<"\nEnter the coefficients in order of ax^2,bx,c :";
 	in>>q.a>>q.b>>q.c;
}
ostream &operator<<(ostream &out,Quad& q)
{
		if(q.b>0 && q.c>0)
		out<<q.a<<"x"<<"^2"<<"+"<<q.b<<"x"<<"+"<<q.c<<" = 0"<<endl;
		else if(q.b>0 && q.c<0)
		out<<q.a<<"x"<<"^2"<<"+"<<q.b<<"x"<<q.c<<" = 0"<<endl;
		else if(q.b<0 && q.c>0)
		out<<q.a<<"x"<<"^2"<<q.b<<"x"<<"+"<<q.c<<" = 0"<<endl;
		else if(q.b<0 && q.c<0)
		out<<q.a<<"x"<<"^2"<<q.b<<"x"<<q.c<<" = 0"<<endl;
}
void Quad::roots()
{
	float x1,x2;
	determinant=b*b-4*a*c;
	if(determinant>0)
	{
	x1=(-b+sqrt(determinant))/2*a;
	x2=(-b-sqrt(determinant))/2*a;
	cout<<"\nx1 = "<<x1;
	cout<<"\nx2 = "<<x2;
	cout<<"\nThe roots of the equation are real and unequal as the determinant is greater than 0."<<endl;	
	}
	else if(determinant==0)
	{
	x1=x2=-b/2*a;
	cout<<"\nx1 = "<<x1;
	cout<<"\nx2 = "<<x2;
	cout<<"\nThe roots of the equation are real and equal as the determinant is equal to 0."<<endl;	
	}
	else if(determinant<0)
	{
	cout<<"\nThe roots of the equation are unreal as the determinant is less than 0."<<endl;	
	}
	
}
Quad Quad:: operator+(Quad q)
{
	Quad temp;
	temp.a=a+q.a;
	temp.b=b+q.b;
	temp.c=c+q.c;
	return temp;
	
}
void Quad :: eval(float x)
{
	float result;
	result=(a*x*x)+(b*x)+c;
	cout<<"\nThe result of x is :"<<result<<endl;
}
int main()
{
	float x,y;
	int ch;
	Quad q1,q2,q3;
	cout<<"\n *-+*+-*+-*+-*-+*+-*+-*+-\n  Quadratic operations\n *-+*+-*+-*+-*-+*+-*+-*+-";
	cout<<"\nEnter the 1st Quadratic Equation :";
	cin>>q1;
	cout<<"\nEnter the 2nd Quadratic Equation :";
	cin>>q2;
	cout<<"\nEquation 1 is :"<<endl;
	cout<<q1;
	cout<<"\nEquation 2 is :"<<endl;
	cout<<q2;
	do
	{
		cout<<"\nEnter the operation you want to perform :-\n1.Find the roots of equation 1.\n2.Find the roots of equation 2.\n3.Add equations 1 and 2.\n4.Evaluate a value in equation 1.\n5.Evaluate a value in equation 2.\n6.Exit.\nEnter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:	
				cout<<"\nThe roots of equation 1 are :"<<endl;
				q1.roots();
				break;
			case 2:
				cout<<"\nThe roots of equation 2 are :"<<endl;
				q2.roots();
				break;
			case 3:
				q3=q1+q2;
				cout<<"\nThe addition of the two equations is :"<<endl;
				cout<<q3;
				break;
			case 4:
				cout<<"\nEnter the value of x to evaluate equation 1 :";
				cin>>x;
				q1.eval(x);
				break;
			case 5:	
				cout<<"\nEnter the value of x to evaluate equation 2 :";
				cin>>y;
				q2.eval(y);
				break;
			case 6:
				return 0;					
		}
	}while(ch!=6);
}

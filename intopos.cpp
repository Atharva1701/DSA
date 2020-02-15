#include<iostream>
//#include"stack.h"
using namespace std;
class Stack
{
	char* stk;
	int top;
	int capacity;
	public:
	Stack(int n)
	{
		stk=new char[n];
		top=-1;
		capacity=n;	
	}
	void push(char c)
	{
		stk[++top]=c;
	}
	char pop()
	{
		return stk[top--];	
	}
	int isEmpty()
	{
		if(top==-1)
			return 1;
		return 0;	
	}
	int isFull()
	{
		if(top==capacity-1)
			return 1;
		return 0;
	}
	char retTop()
	{
		if(top==-1)
			return 0;
		return stk[top];	
	}	
};
int getPrio(char c)
{
	if(c=='^')
		return 3;
	if(c=='*'||c=='/')
		return 2;
	return 1;	
}
int main()
{
	cout<<"***Conversion of Infix To Postfix***";
	char infix[50],postfix[50];
	int k,opr,z;
	cout<<"\nEnter an infix string :"<<endl;
	cin>>infix;
	k=opr=0;
	while(infix[k])
	{
		if(infix[k]=='^'||infix[k]=='*'||infix[k]=='/'||infix[k]=='+'||infix[k]=='-')
			opr++;
		k++;
	}
	Stack s(opr);
	k=z=0;
	while(infix[k])
	{
		if(infix[k]=='^'||infix[k]=='*'||infix[k]=='/'||infix[k]=='+'||infix[k]=='-')
			{
				if(s.isEmpty())
					s.push(infix[k]);
				else
					if(getPrio(infix[k])>getPrio(s.retTop()))
						s.push(infix[k]);
				else
				  	do
					{
						postfix[z++]=s.pop();
						if(s.isEmpty()||getPrio(s.retTop())<getPrio(infix[k]))
						{
							s.push(infix[k]);
							break;
						}
					}while(1);
			}
		else
			postfix[z++]=infix[k];
		k++;
	}
	while(s.retTop())
		postfix[z++]=s.pop();
	postfix[z]=0;
	cout<<"\nPostfix Expression : "<<postfix<<endl;
}

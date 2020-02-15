#include<iostream>
#include<cstring>
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
void rev(char str[])
{
	int i=0,j=strlen(str)-1;
	while(i<j)
	{
		char temp=str[i];
		str[i]=str[j];
		str[j]=temp;
		i++,j--;
	}
	i=0;
	/*while(str[i])
	{
		if(str[i]=='(')
			str[i]=')';
		else if(str[i]==')')
			str[i]='(';
		i++;	
	}*/
}
int main()
{
	cout<<"***Conversion of Infix To Prefix***";
	char infix[50],prefix[50];
	int k,opr,z;
	cout<<"\nEnter an infix string :"<<endl;
	cin>>infix;
	rev(infix);
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
						prefix[z++]=s.pop();
						if(s.isEmpty()||getPrio(s.retTop())<=getPrio(infix[k]))
						{
							s.push(infix[k]);
							break;
						}
					}while(1);
			}
		else
			prefix[z++]=infix[k];
		k++;
	}
	while(s.retTop())
		prefix[z++]=s.pop();	
	prefix[z]=0;
	rev(prefix);	
	cout<<"\nPrefix Expression : "<<prefix<<endl;
}

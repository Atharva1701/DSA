#include<iostream>
#include<cstdlib>
#include<ctype.h>
#include<string.h>
using namespace std;
class Stack
{
	char* a;
	int top;
	int capacity;
	public:
	Stack(){}
	Stack(int);
	void push(char);
	char pop();
	int isFull();
	int isEmpty();
	void refresh()
	{
		top=-1;		
	}
};
Stack::Stack(int n)
{
	capacity=n;
	a=new char[n];
	top=-1;
}
void Stack::push(char c)
{
	if(!isFull())
	 	a[++top]=c;
}
char Stack::pop()
{
	if(!isEmpty())
		return a[top--];
}
int Stack::isEmpty()
{
 	if(top==-1)
		return 1;
	else
		return 0;
}
int Stack::isFull()
{
	if(top==capacity-1)
		return 1;
	else
		return 0;
}
void convert(char str[])
{
	int i=0,j=0;
	char str2[100];
	strcpy(str2,str);
	while(str2[j])
	{
		if(isalpha(str2[j]))
	          {
			if(isupper(str2[j]))
				str[i]=tolower(str2[j]);
			else
			   	str[i]=str2[j];
			i++;
   		  }
		j++;	
	}
	str[i]=0;
}
void check(char str[],Stack& stack,int len)
{
	int i=0;
	stack.refresh();
	while(i<len/2)
		stack.push(str[i++]);
	if(len&1)
		i++;
	while(!stack.isEmpty() && str[i]==stack.pop())
		i++;
	if(str[i]=='\0' && stack.isEmpty())
		cout<<"The entered string is a Palindrome."<<endl;
	else
		cout<<"\nThe entered string is not a Palindrome."<<endl;
}
int main()
{
	char str[100];
	int i;
	cout<<"\nEnter a String to check for Palindrome:";
	cin.getline(str,100);
	Stack stack(strlen(str));
	do
	{
		cout<<"\n\nMenu\n\n";
		cout<<"\n1.Check Palindrome of normal string.\n2.Print in reverse.\n3.Check for Palindrome(Ignore Spaces,Special Symbols,Cases....).\n4.Exit.\nEnter Your Choice:";
		int n;
		cin>>n;
		switch(n)
		{
			case 1:
				check(str,stack,strlen(str));
				break;
			case 2:
				stack.refresh();
				i=0;
				while(str[i])
					{
						stack.push(str[i]);
						i++;
					}
				cout<<"\nString in Reverse :";
				while(!stack.isEmpty())
					cout<<stack.pop();
				break;
			case 3:
				convert(str);
				check(str,stack,strlen(str));
				break;
			case 4:
				exit(1);
			default:
				cout<<"\nEnter valid choice!!!";
				
		}
	}while(1);
}

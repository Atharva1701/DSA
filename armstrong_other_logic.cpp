#include<iostream>
using namespace std;
static int power(int n,int r)
{
    int c,p=1;
    for(c=1;c<=r;c++)
        p = p*n;
        
        
    return p;
}
int main()
{
	int n,t,sum = 0,rem,digits = 0;
	cout<<"\nEnter the number to check for armstrong :";
	cin>>n;
	
	t=n;
	while(t!=0)
	{
	    digits++;
	    t=t/10;
	}
	t=n;
	while(t!=0)
	{
	    rem = t%10;
	    sum = sum + power(rem,digits);
	    t=t/10;
	}

	if(n==sum)
		cout<<"The number is armstrong!\n";
	else
		cout<<"\nThe number is not armstrong!\n";
}

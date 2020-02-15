#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
int main()
{
	int n,sum=0;
	cout<<"\nEnter number of digits :";
	cin>>n;
	
	int* arm=new int[n];
	
	cout<<"\nEnter the number in array to check for armstrong number :";
	for(int i=0;i<n;i++)
		cin>>arm[i];
		
		
	for(int i=0;i<n;i++)
		sum+=pow(arm[i],n);

	int check=0;
	for(int i=0;i<n;i++)
		check=10*check+arm[i];

	if(sum==check)
		cout<<"The number is armstrong!\n";
	else
		cout<<"\nThe number is not armstrong!\n";
}

#include<iostream>
using namespace std;
class graph
{
	int **a;
	int n,m,i,vertex;
	public:
		graph(int vertex)
		{
			this->vertex=vertex;
			a=new int*[vertex];
			for(i=0;i<vertex;i++)
				a[i]=new int[vertex];
		}
		void isEdge(int,int);
		void disp();
};
void graph::disp()
{
	for(int i=0;i<vertex;i++)
	{
		cout<<i<<": ";
		for(int j=0;j<vertex;j++)
			cout<<a[i][j]<<" ";
		cout<<"\n";
	}
}
void graph::isEdge(int i,int j)
{
	if(i>vertex || j>vertex || i<0 || j<0)
		cout<<"\nInvalid edge!!";
	else
	{
		a[i][j]=1;
		a[j][i]=1;
	}
}
int main()
{
	int v,maxEdge,i,j;
	cout<<"\nEnter the no. of vertices :";
	cin>>v;
	graph g(v);
	maxEdge=v*(v-1);
	for(int k=0;k<maxEdge;k++)
	{
		cout<<"Enter edges(Enter -1 -1 to exit):";
		cin>>i>>j;
		if(i==-1 &&j==-1)
			break;
		g.isEdge(i,j);
	}
	cout<<"\nThe adjacency matrix is:"<<endl;
	cout<<"  ";
	for(int q=0;q<v;q++)
		cout<<" "<<q;
	cout<<endl;	
	g.disp();
}

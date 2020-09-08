#include<iostream>
#define MAX 10
using namespace std;
template<typename h>
class hashtable;
template<class t>
class node
{
	t record;
	node<t> *next;
	friend class hashtable<t>;
};
template<typename h>
class hashtable
{
	node<h> *ht[MAX];
	typedef node<h>  Node;
	public:
		hashtable();
		int hash(h);
		void insert(h);
		void search(int);
		void del(int);
		void disp();
};
template<typename h>
hashtable<h>::hashtable()
{
	for(int i=0;i<MAX;i++)
		ht[i]=NULL;
}
template<typename h>
int hashtable<h>::hash(h key)
{
	return (key%MAX);
}
template<typename h>
void hashtable<h>::insert(h key)
{
	int pos=hash(key);
	Node *curr,*temp;
	curr=new Node;
	curr->record=key;
	curr->next=NULL;
	if(ht[pos]==NULL)
		ht[pos]=curr;
	else
	{
		temp=ht[pos];
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=curr;	
	}
	
}
template<typename h>
void hashtable<h>::disp()
{
	Node *temp;
	cout<<"\nThe hashtable is-=> "<<endl;
	int v;
	for(v=0;v<MAX;++v)
	{
		cout<<"\n"<<v<<" ";
		temp=ht[v];
		while(temp!=NULL)
		{
			cout<<"--> "<<temp->record;
			temp=temp->next;
		}
	}
	cout<<endl;
}
template<typename h>
void hashtable<h>::search(int key)
{
	int pos=hash(key);
	Node *temp;
	temp=ht[pos];
	while(temp!=NULL)
	{
		if(temp->record==key)
		{
			cout<<"\nKey found!!!"<<endl;
			return;
		}
		temp=temp->next;
			
	}
	cout<<"\nNot Found!!"<<endl;
}
template<typename h>
void hashtable<h>::del(int key)
{
	int pos=hash(key);
	Node *temp,*temp1;
	temp=ht[pos];
	while(temp!=NULL && temp->record==key)
	{
		cout<<"\nDeleted!!!"<<endl;
		ht[pos]=temp->next;
		delete temp;
		return;
	}
	while(temp!=NULL && temp->record!=key)
	{
		temp1=temp;
		temp=temp->next;
	}
	if(temp==NULL)
	{
		cout<<"\nNot found,cannot delete!!"<<endl;
		return;
	}
	cout<<"\nDeleted!!!"<<endl;
	temp1->next=temp->next;
	delete temp;
}
int main()
{
	hashtable<int> h;
	hashtable<char> h1;
	int i,n,key,key1,key2;
	char a;
	cout<<"\n\t*+-*+-*+-*-*-+- \n\t    Hashing \n\t*-+*+-*+-*+-*+-";
	cout<<"\nHow many records ? :";
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cout<<"\nEnter "<<i<<" records :";
		cin>>key;
		h.insert(key);
	}
	h.disp();
	/*for(i=1;i<=n;i++)
	{
		cout<<"\nEnter "<<i<<" records :";
		cin>>a;
		h1.insert(a);
	}
	h1.disp();*/
	cout<<"\nEnter the record you want to search :";
	cin>>key1;
	h.search(key1);
	cout<<"\nEnter the record you want to delete :";
	cin>>key2;
	h.del(key2);
	h.disp();
}

#include<iostream>
using namespace std;
template<typename h,typename v>
class probing;
template<typename h,typename v>
class linear
{
	h key;
	v value;
	linear(h key,v value)
	{
		this->key=key;
		this->value=value;
	}
	friend class probing<h,v>;
};
template<typename h,typename v>
class probing
{
	linear<h,v> **a;
	int capacity;
	int size;
	linear<h,v> *dum;
	typedef linear<h,v> node;
	public:
	probing()
	{
		capacity=20;
		size=0;
		a=new node*[capacity];
		for(int i=0;i<capacity;i++)
			a[i]=NULL;
		dum=new node(-1,"");	
	}
	int hashCode(h);
	void insert(h,v);
	v deletNode(h);
	v get(h);
	void disp();
	int sizeMap()
	{
		return size;
	}
	bool isEmpty()
	{
		return size==0;
	}
};
template<typename h,typename v>
int probing<h,v> :: hashCode(h key)
{
	return key%capacity;
}
template<typename h,typename v>
void probing<h,v> :: insert(h key,v value)
{
	node *temp=new node(key,value);
	int hash=hashCode(key);
	while(a[hash]!=NULL && a[hash]->key!=key && a[hash]->key!=-1)
	{
		hash++;
		hash%=capacity;
	}
	if(a[hash]==NULL || a[hash]->key==-1) 
            size++; 
    a[hash]=temp;
}
template<typename h,typename v>
v probing<h,v>:: deletNode(h key)
{
        int hash=hashCode(key); 
        while(a[hash]!=NULL) 
        { 
            if(a[hash]->key==key) 
            { 
                node *temp=a[hash]; 
                a[hash]=dum; 
                size--; 
                return temp->value; 
            } 
            hash++; 
            hash%=capacity; 
        } 
        return NULL; 
}
template<typename h,typename v>
v probing<h,v>::get(h key)
{
        int hash=hashCode(key); 
        int counter=0; 
        while(a[hash]!=NULL) 
        {    int counter=0; 
             if(counter++ > capacity)  
                return NULL;         
            if(a[hash]->key==key) 
                return a[hash]->value; 
            hash++; 
            hash%=capacity; 
        } 
        return NULL; 
}
template<typename h,typename v>
void probing<h,v>::disp()
{
        for(int i=0;i<capacity;i++) 
        { 
            if(a[i]!=NULL && a[i]->key != -1) 
                cout<<"key = " <<a[i]->key<<"  value = "<<a[i]->value<<endl; 
        }  
}
int main()
{
	probing<long unsigned int,string> *h = new probing<long unsigned int,string>; 
    h->insert(9764333433,"atharva"); 
    h->insert(8796665144,"raju"); 
    h->insert(7499363113,"ashish");
    h->insert(8499348345,"rahul");
    h->insert(9468793154,"pranav"); 
    h->disp(); 
    cout<<h->sizeMap()<<endl; 
    cout<<h->deletNode(9764333433)<<endl; 
    h->disp(); 
    cout<<h->sizeMap()<<endl; 
    cout<<h->isEmpty()<< endl; 
    cout<<h->get(8796665144)<<endl;
    h->disp(); 
    return 0; 
}

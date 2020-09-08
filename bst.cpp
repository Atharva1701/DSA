#include<iostream>
#include<iomanip>
using namespace std;
class BST;
class node
{
	int data;
	node *right,*left;
	public:
	int retData()
	{
		return data;
	}
	friend class BST;
};
class BST
{
	public:
	node *root;
	BST()
	{
		root=NULL;	
	}
	void create();
	void display(node*,int);
	void inorder(node*);
	void preorder(node*);
	void postorder(node*);
	int search(node*,int);
	node* inordersucc(node*);
	node* del(node*,int);
	int height(node*);
};
void BST::create()
{
	node *curr,*temp;
	char ch;
	do
	{
	curr=new node;
	cout<<"\nEnter the value of the node :";
	cin>>curr->data;
	curr->right=curr->left=NULL;
	if(root==NULL)
		root=curr;
	else
	{
		temp=root;
		while(1)
		{
			if(curr->data < temp->data)
			{
				if(temp->left==NULL)
				{
					temp->left=curr;
					break;			
				}
				else
					temp=temp->left;		
			}
			else
			{
				if(temp->right==NULL)
				{
					temp->right=curr;
					break;
				}
				else
					temp=temp->right;
			}
		}		
	}
	cout<<"\nDo you want to add more (y/n)?";
	cin>>ch;
	}while(ch=='y'||ch=='Y');
}
void BST::display(node *root,int space)
{
	int i;
	if(root==NULL)
		return;
	/*else
	{
		display(root->right,space+2);
		cout<<"\n";
		for(i=0;i<space;i++)
			cout<<"       ";
		if(this->root==root)
			cout<<"Root-> ";
		cout<<root->data;
		display(root->left,space+2);
	}*/
	if(root!=NULL)
	{
        	if(root->right)
            		display(root->right,space+4);
       		if(space)
            		cout<<setw(space)<<' ';
		if(root->right)
			cout<<" /\n"<<setw(space)<<' ';
		cout<<root->data<<"\n ";
		if(root->left) 
		{
		    cout<<setw(space)<<' '<<" \\\n";
		    display(root->left,space+4);
		}
   	}
		
}
void BST::inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<"\t"<<root->data;
		inorder(root->right);
	}
}
void BST::preorder(node *root)
{
	if(root!=NULL)
	{
		cout<<"\t"<<root->data;
		preorder(root->left);
		preorder(root->right);
	}
}
void BST::postorder(node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<"\t"<<root->data;
	}
}
int BST::search(node *root,int key)
{
	if(root==NULL)
		return -1;
	if(root!=NULL)
	{
		if(root->data==key)
			return 1;
		else if(root->data>key)
			search(root->left,key);
		else if(root->data<key)
			search(root->right,key);
		else 
			return 0;
	}
}
node* BST :: inordersucc(node* root)
{
	node * current =root;
	while(current->left!=NULL)
		current=current->left;
	return current;
}
node* BST::del(node *root,int item)
{
	if(root==NULL)
		return root;
	else if(item < root->data)
		root->left=del(root->left,item);
	else if(item>root->data)
		root->right=del(root->right,item);
	else
	{
			if(root->right == NULL && root->left == NULL)
			{
				delete root;
				root=NULL;
			}
			else if(root->left==NULL)
			{
				node* temp=root;
				root=root->right;
				delete temp;
			}
			else if(root->right==NULL)
			{
				node* temp=root;
				root=root->left;
				delete temp;
			}
			else
			{
				node* temp=inordersucc(root->right);
				root->data=temp->data;
				root->right=del(root->right,temp->data);
			}
	}
	return root;
}
int BST::height(node* root)
{
	if(root==NULL)
		return 0;
	else
	{
		int l=height(root->left);
		int r=height(root->right);
		return max(l,r)+1;
	}
}
int main()
{
	BST b;
	int ch;
	do
	{
		cout<<"\n\t\t*-+*+-*+--+**+-*-+*-+*+-*+--+**+-*-+ \n\t\t    Binary Search Tree Operations \n\t\t*-+*+-*+--+**+-*-+*-+*+-*+--+**+-*-+"<<endl;
		cout<<"\n1.Enter the data in BST.\n2.Display BST.\n3.In-Order Traversal.";
		cout<<"\n4.Pre-Order Traversal.\n5.Post-order Traversal.\n6.Search.\n7.Delete.\n8.Height Of BST.\n9.Exit.";
		cout<<"\nEnter you choice :";
		cin>>ch;
		        switch(ch)
		        {
		        	case 1:
		        	{
		        		b.create();
					cout<<"\n";
					break;
				}
				case 2:
				{
					cout<<"\nRoot is:"<<b.root->retData()<<endl<<endl;
					b.display(b.root,0);
					cout<<endl;
					break;
				}
				case 3:
				{
					cout<<"\nIn-Order Traversal : ";
					b.inorder(b.root);
					break;
				}
				case 4:
				{
					cout<<"\nPre-Order Traversal : ";
					b.preorder(b.root);
					break;
				}
				case 5:	
				{
					cout<<"\nPost-Order Traversal : ";
					b.postorder(b.root);
					break;
				}
				case 6:
				{
					int key;
					cout<<"\nEnter the key you want to search :";
					cin>>key;
					int x=b.search(b.root,key);
					if(x==1)
						cout<<"\nKey Found!"<<endl;
					else
						cout<<"\nKey not found!"<<endl;
					break;
				}
				case 7:
				{
					int item;
					cout<<"\nEnter the element to be deleted:";
					cin>>item;
					int y=b.search(b.root,item);
					if(y==1)
					{
						cout<<"\n"<<item<<" Deleted!";
						b.del(b.root,item);
					}
					else
						cout<<"\nNot Found,cannot delete!";
					break;
				}
				case 8:
					{
						cout<<"\nThe Height of the Binary Search Tree is :"<<b.height(b.root)<<endl;
						break;
					}
				case 9:
				{
					return 0;
		        	}
		        	default:
		        		{
		        			cout<<"\nInvalid choice!!!Enter a valid choice!!"<<endl;
		        		}
		        }
	}while(ch!=9);
	cout<<endl<<endl;
}

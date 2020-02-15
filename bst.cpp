#include<iostream>
#include<cstdlib>
using namespace std;
class BST;
class node
{
	int data;
	node *right,*left;
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
	node* del(node*,int);
	node* inordersucc(node*);
	int height(node*);
};
void BST::create() //insert/create node in bst
{
	node *curr,*temp;
	char ch;
	do
	{
		curr=new node;
		cout<<"\nEnter the data :";
		cin>>curr->data;
		curr->left=curr->right=NULL;
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
	cout<<"\nDo you want to add more ?(y/n)"<<endl;
	cin>>ch;
	}while(ch=='Y'||ch=='y');
}
void BST::display(node *root,int space) //display bst
{
	int i;
	if(root==NULL)
	  return;
	else
	{
	//process right child first
	display(root->right,space+1);
	//print current node after space count
	cout<<"\n";
	for(i=0;i<space;i++)
		cout<<"    ";
	cout<<root->data;
	//process left child
	display(root->left,space+1);
	}
}
void BST::inorder(node* root) //inorder
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<"\t"<<root->data;
		inorder(root->right);
	}	
}
void BST::preorder(node* root) //preorder
{
	if(root!=NULL)
	{
		cout<<"\t"<<root->data;
		preorder(root->left);
		preorder(root->right);
	}
}
void BST::postorder(node* root) //postorder
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<"\t"<<root->data;
	}
}
int BST::search(node *root,int key) //search
{
	if(root!=NULL)
	{
		if(root->data==key)
			return 1;
		else if(root->data>key)
				search(root->left,key);
		else if(root->data<key)
				search(root->right,key);
	}
	else
		return 0;
}
node* BST::inordersucc(node *root) //find inorder successor
{
	node *current=root;
	while(current->left!=NULL)
		current=current->left;
	return current;
}
node* BST::del(node* root,int key) //del a node in bst
{
	if(root==NULL)
		return NULL;
	else if(root->data>key)
			root->left=del(root->left,key);
	else if(root->data<key)
			root->right=del(root->right,key);
	else
	{
			if(root->left==NULL)
			{
				node *temp=root->right;
				delete root;
				return temp;
			}
			else if(root->right==NULL)
			{
				node *temp=root->left;
				delete root;
				return temp;
			}
			node *temp=inordersucc(root->right);
			root->data=temp->data;
			root->right=del(root->right,temp->data);
	}
	return root;
}
int BST::height(node* root) //calc height of bst
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
	int key,ch,x,key1;
	//menu-driven
	do
	{
	cout<<"\n\t\t*=+*=+*=+*=+*=+*=+*=+*=+*=+*=+*=+*=+ \n\t\t    Binary Search Tree Operations \n\t\t*=+*=+*=+*=+*=+*=+*=+*=+*=+*=+*+=*=+";
	cout<<"\n1.Create a Binary Search Tree.\n2.Display.\n3.In-Order traversal.\n4.Pre-Order traversal.\n5.Post-Order traversal.\n6.Search.\n7.Delete Node.\n8.Height Of BST.\n9.Exit.\nEnter your Choice:";
	cin>>ch;
	switch(ch)
	{
		case 1:
				b.create();
				break;
		case 2:
			cout<<"\nDisplay Binary Search Tree -=>"<<endl;
			b.display(b.root,1);
			break;
		case 3:
				cout<<"\n\n\n";
				cout<<"In-Order traversal: ";
				b.inorder(b.root);
				break;
		case 4:
				cout<<"\n";
				cout<<"Pre-Order traversal: ";
				b.preorder(b.root);
				break;
		case 5:
				cout<<"\n";
				cout<<"Post-Order traversal: ";
				b.postorder(b.root);
				break;
		case 6:
				cout<<"\n";
				cout<<"\nSearch an element-->"<<endl;
				cout<<"\nEnter the key to be searched :";
				cin>>key;
				x=b.search(b.root,key);
				if(x==1)
					cout<<"\nFound!!"<<endl;
				else
					cout<<"\nNot Found!!"<<endl;
				break;
		case 7:
				cout<<"\nDelete a Node-->"<<endl;
				cout<<"\nEnter the key to be deleted :";
				cin>>key1;
				x=b.search(b.root,key1);
				if(x==1)
				{
					cout<<"\nDeleted!!"<<endl;
					b.del(b.root,key1);
				}
				else
					cout<<"\nNot Found,cannot delete!!"<<endl;
				break;
		case 8:
				cout<<"\nHeight of the binary search tree is : "<<b.height(b.root)<<endl;
				break;
		case 9:
				return 0;
		default:
				cout<<"\nInvalid Choice!!"<<endl;
	}
	}while(ch!=9);
}

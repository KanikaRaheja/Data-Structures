//implementing Binary Search Tree
#include<iostream>
#include<conio.h>
#include"Stack_19007.cpp"
#include"queue_07.cpp"
using namespace std;
template<class type>
class Bnode
{
	public:
   	type data;
   	Bnode<type> *left;
   	Bnode<type> *right;
   	public:
   		Bnode()
   		{
   		 left=NULL;
		 right=NULL;	
		}
};
template<class type>
class BST
{
 
    public:
	   BST();
	   void insert(type&);
	   void iterativepreorder();
	   void iterativepostorder();
	   void iterativeinorder();
	   void levelbylevel();
	   void recursivepreorder(Bnode<type> *p);
	   void recursivepostorder(Bnode<type> *p);
	   void recursiveinorder(Bnode<type> *p);
	   void deletebymerging(const type);
	   void deletebymerging(Bnode<type>*&);
	   void deletebycopy(const type&);
	   void deletebycopy(Bnode<type>*&);
	   int height();
	   int height(Bnode<type>*);
	   	Bnode<type> *root;
};
 
//constructor
template<class type>
BST<type>::BST()
{
	root=NULL;
}
//insertion in BST
template<class type>
void BST<type>::insert(type& value)
{
	Bnode<type> *temp=root;
	Bnode<type> *v=new Bnode<type>;
	Bnode<type> *p=NULL;
	v->data=value;
	if(root==NULL) //when first node is insert
	{
		root=v;
	}
	else
	{
	if(temp->data==value)
	cout<<"\nDuplicate value found";
	else
	{
	while(temp!=NULL)
	{
		p=temp;
		if(temp->data>value)
		temp=temp->left;
		else
		temp=temp->right;
	}
	if(p->data>value)
	p->left=v;
	else
	p->right=v;
   }
   }
}
//iterative preorder traversal
template<class type>
void BST<type>::iterativepreorder()
{
	Bnode<type> *p=root;
	StackLinkedList<Bnode<type>*> S;
	if(root==NULL)
	cout<<"\n\nBinary search tree is empty";
	else
	{
	cout<<"\n\nElements of BST in preorder are:- ";
    if(p!=NULL)
    {
    	S.push(p);
    	while(!S.empty())
    	{
    		p=S.Top();
    		S.pop();
    		cout<<p->data<<" ";
    		if(p->right!=NULL)
    		S.push(p->right);
    		if(p->left!=NULL)
    		S.push(p->left);
		}
	}
}
}
//iterative postorder traversal
template<class type>
void BST<type>::iterativepostorder()
{
	Bnode<type> *p=root;
	Bnode<type> *q=root;
	StackLinkedList<Bnode<type>*> S;
	if(root==NULL)
	cout<<"\n\nBinary search tree is empty";
	else
	{
		cout<<"\n\nElements of BST in postorder are:- ";
		while(p!=NULL)
		{
		 for(;p->left!=NULL;p=p->left)
		 S.push(p);
		 while(p->right==NULL || p->right==q)
		 {
		 	cout<<p->data<<" ";
		 	q=p;
		 	if(S.empty())
		 	return;
		 	p=S.Top();
		 	S.pop();
		 }
		 S.push(p);
		 p=p->right;
	    }
    }
}
//iterative inorder traversal
template <class type>
void BST<type>::iterativeinorder()
{
	Bnode<type> *p=root;
	StackLinkedList<Bnode<type>*> S;
	if(root==NULL)
	cout<<"\n\nBinary search tree is empty";
	else
	{
		cout<<"\n\nElements of BST in inorder are:- ";
	while(p!=NULL)
	{
	 while(p!=NULL)
	 {
	 	if(p->right)
	 	S.push(p->right);
	 	S.push(p);
	 	p=p->left;
	 }
	 p=S.Top();
	 S.pop();
	 while(!S.empty() && p->right==NULL)
	 {
	 	cout<<p->data<<" ";
	 	p=S.Top();
	 	S.pop();
	 }
	 cout<<p->data<<" ";
	 if(!S.empty())
	 {
	 	p=S.Top();
	 	S.pop();
	 }
	 else
	 p=NULL;
    }
}
}
//level by level taversal
template<class type>
void BST<type>::levelbylevel ()
{
	Bnode<type> *p=root;
	Linkedqueue<Bnode<type>*> Q;
	if(root==NULL)
	cout<<"\n\nBinary search tree is empty";
	else
	{
		cout<<"\n\nElements of BST in level by level traversal are:- ";
		Q.enqueue(p);
		while(!Q.empty())
		{
			p=Q.front();
			Q.dequeue();
			cout<<" "<<p->data;
			if(p->left!=0)
			Q.enqueue(p->left);
			if(p->right!=0)
			Q.enqueue(p->right);
		}
	}
}
//recursive preorder traversal
template<class type>
void BST<type>::recursivepreorder(Bnode<type> *p)
{
	if(p==NULL)
	return;
	else
	{
		cout<<p->data<<" ";
		recursivepreorder(p->left);
		recursivepreorder(p->right);
	}
}
//recursive postorder traversal
template<class type>
void BST<type>::recursivepostorder(Bnode<type> *p)
{
	if(p==NULL)
	return;
	else
	{
		recursivepostorder(p->left);
		recursivepostorder(p->right);
		cout<<p->data<<" ";
	}
}
//recursive inorder traversal
template<class type>
void BST<type>::recursiveinorder(Bnode<type> *p)
{
	if(p==NULL)
    return;
	else
	{
		recursiveinorder(p->left);
		cout<<p->data<<" ";
		recursiveinorder(p->right);
	}
}
 
template<class type>
void BST<type>::deletebymerging(const type e)
{
	Bnode<type>*node=root, *prev=0;
	while(node!=0)
		{
			if(node->data==e)
				break;
			prev=node;
			if(e<node->data)
				node=node->left;
			else node=node->right;
		}
		
	if(node!=0 && node->data==e)
		if(node==root)
			deletebymerging(root);
		else if(prev->left==node)
			deletebymerging(prev->left);
		else	
			deletebymerging(prev->right);
	else if(root!=0)
		cout<<"\nElement "<<e<<" is not present in the tree";
	else
		cout<<"\nTree is empty";
}

template<class type>
void BST<type>::deletebymerging(Bnode<type>*&node)
{
	Bnode<type>*temp=node;
	if(node!=0)
	{
		if(!node->right)
			node=node->left;
		else if(node->left==0)
			node=node->right;
		else
			{
				temp=node->left;
				while(temp->right!=NULL)
					temp=temp->right;
				temp->right=node->right;
				temp=node;
				node=node->left;
				
			}
			delete temp;
	}
	else
		cout<<"\nElement is not present in the tree";
}
//deletion by copying
template<class type>
void BST<type>::deletebycopy(const type& e)
{
	Bnode<type>*node=root, *prev=0;
	
	while(node!=0)
		{
			if(node->data==e)
				break;
			prev=node;
			if(e<node->data)
				node=node->left;
			else node=node->right;
		}
		
	if(node!=0 && node->data==e)
		if(node==root)
			deletebycopy(root);
		else if(prev->left==node)
			deletebycopy(prev->left);
		else	
			deletebycopy(prev->right);
	else if(root!=0)
		cout<<"\nElement "<<e<<" is not present in the tree";
	else
		cout<<"\nTree is empty";
}

template<class type>
void BST<type>::deletebycopy(Bnode<type>*&node)
{
	Bnode<type>*prev, *temp=node;
	if(node->right==0)
			node=node->left;
	else if(node->left==0)
			node=node->right;
	
	else
		{
			temp=node->left;
			prev=node;;
			while(temp->right!=0)
			{
					prev=temp;
					temp=temp->right;
			}
			node->data=temp->data;
			if(prev==node)
				prev->left=temp->left;
			else
				prev->right=temp->left;
		}
		delete temp;
}
//find the height of the tree
template<class type>
int BST<type>::height()
{
	return height(root);
}
template<class type>
int BST<type>::height(Bnode<type> *node)
{
	if(node==NULL)
	return 0;
	else
	{
		int l=height(node->left);
		int r=height(node->right);
		if(l>r)
		return l+1;
		else
		return r+1;
	}
}
int main()
{
	int choose,ch;
	char ans;
	cout<<"\nData types are:-\n1.int\n2.char\n3.float";
	cout<<"\n\nYour data type please:- ";
	cin>>choose;
	switch(choose)
	{
		case 1:
			{
				BST<int> i;
				do
				{
				    cout<<"\n\nOperations are:-\n1.insert()-insert an element x in binary search tree.\n2.iterativepreorder()-display elements in iterative preorder.\n3.iterativepostorder()-display elements in iterative postorder.\n4.iterativeinorder()-display the elements in iterative inorder\n5.levelbylevel()-display the elements in BST in Breadth First Traversal.\n6.recursivepreorder()-displaying the elements in recursive preorder trtaversal\n7.recursivepostorder()-displaying the elements in recursive postorder trtaversal\n8.recursiveinorder()-displaying the elements in recursive inorder trtaversal\n9.deletebymerging()-delete the node in BST by using merging\n10.deletebycopy()-delete the element in BST by using DELETE BY COPY method\n11.height()-find the height of binary search tree";
				    cout<<"\n\nYour choice please:- ";
				    cin>>ch;
				    switch(ch)
				    {
				    	case 1:
				    		{
				    			int value;
				    			cout<<"\n\nEnter the value you want to insert in BST:- ";
				    			cin>>value;
				    			i.insert(value);
				    			break;
							}
						case 2:
							{
								i.iterativepreorder();
								break;
							}
						case 3:
							{
								i.iterativepostorder();
								break;
							}
						case 4:
							{
								i.iterativeinorder();
								break;
							}
						case 5:
							{
								i.levelbylevel();
								break;
							}
						case 6:
							{
								cout<<"\nElements of BST in recursive preorder are:- ";
								i.recursivepreorder(i.root);
								break;
							}
						case 7:
							{
								cout<<"\nElements of BST in recursive postorder are:- ";
								i.recursivepostorder(i.root);
								break;
							}
						case 8:
							{
								cout<<"\nElements of BST in recursive inorder are:- ";
								i.recursiveinorder(i.root);
								break;
							}
						case 9:
							{
								int value;
								cout<<"\nEnter the value you want to delete from BST:- ";;
								cin>>value;
								i.deletebymerging(value);
								break;
							}
						case 10:
							{
								int value;
								cout<<"\nEnter the value you want to delete from BST:- ";;
								cin>>value;
								i.deletebycopy(value);
								break;
							}
						case 11:
							{
								cout<<"\n\nheight of the binary tree is:- "<<i.height();
								break;
							}
						default:
							cout<<"\n\nWrong Choice re-enter your choice:- ";
					}
					cout<<"\n\nDo you want more opeartion to perform press y:- ";
					cin>>ans;
				}while(ans=='y');
				break;
			}
			case 2:
			{
				BST<char> c;
				do
				{
				    cout<<"\n\nOperations are:-\n1.insert()-insert an element x in binary search tree.\n2.iterativepreorder()-display elements in iterative preorder.\n3.iterativepostorder()-display elements in iterative postorder.\n4.iterativeinorder()-display the elements in iterative inorder\n5.levelbylevel()-display the elements in BST in Breadth First Traversal.\n6.recursivepreorder()-displaying the elements in recursive preorder trtaversal\n7.recursivepostorder()-displaying the elements in recursive postorder trtaversal\n8.recursiveinorder()-displaying the elements in recursive inorder trtaversal\n9.deletebymerging()-delete the node in BST by using merging\n10.deletebycopy()-delete the element in BST by using DELETE BY COPY method\n11.height()-find the height of binary search tree";
				    cout<<"\n\nYour choice please:- ";
				    cin>>ch;
				    switch(ch)
				    {
				    	case 1:
				    		{
				    			char value;
				    			cout<<"\n\nEnter the value you want to insert in BST:- ";
				    			cin>>value;
				    			c.insert(value);
				    			break;
							}
						case 2:
							{
								c.iterativepreorder();
								break;
							}
						case 3:
							{
								c.iterativepostorder();
								break;
							}
						case 4:
							{
								c.iterativeinorder();
								break;
							}
						case 5:
							{
								c.levelbylevel();
								break;
							}
						case 6:
							{
								cout<<"\nElements of BST in recursive preorder are:- ";
								c.recursivepreorder(c.root);
								break;
							}
						case 7:
							{
								cout<<"\nElements of BST in recursive postorder are:- ";
								c.recursivepostorder(c.root);
								break;
							}
						case 8:
							{
								cout<<"\nElements of BST in recursive inorder are:- ";
								c.recursiveinorder(c.root);
								break;
							}
						case 9:
							{
								char value;
								cout<<"\nEnter the value you want to delete from BST:- ";;
								cin>>value;
								c.deletebymerging(value);
								break;
							}
						case 10:
							{
								char value;
								cout<<"\nEnter the value you want to delete from BST:- ";;
								cin>>value;
								c.deletebycopy(value);
								break;
							}
						case 11:
							{
								cout<<"\n\nheight of the binary tree is:- "<<c.height();
								break;
							}
						default:
							cout<<"\n\nWrong Choice re-enter your choice:- ";
					}
					cout<<"\n\nDo you want more opeartion to perform press y:- ";
					cin>>ans;
				}while(ans=='y');
				break;
			}
			case 3:
			{
				BST<float> f;
				do
				{
				    cout<<"\n\nOperations are:-\n1.insert()-insert an element x in binary search tree.\n2.iterativepreorder()-display elements in iterative preorder.\n3.iterativepostorder()-display elements in iterative postorder.\n4.iterativeinorder()-display the elements in iterative inorder\n5.levelbylevel()-display the elements in BST in Breadth First Traversal.\n6.recursivepreorder()-displaying the elements in recursive preorder trtaversal\n7.recursivepostorder()-displaying the elements in recursive postorder trtaversal\n8.recursiveinorder()-displaying the elements in recursive inorder trtaversal\n9.deletebymerging()-delete the node in BST by using merging\n10.deletebycopy()-delete the element in BST by using DELETE BY COPY method\n11.height()-find the height of binary search tree";
				    cout<<"\n\nYour choice please:- ";
				    cin>>ch;
				    switch(ch)
				    {
				    	case 1:
				    		{
				    			float value;
				    			cout<<"\n\nEnter the value you want to insert in BST:- ";
				    			cin>>value;
				    			f.insert(value);
				    			break;
							}
						case 2:
							{
								f.iterativepreorder();
								break;
							}
						case 3:
							{
								f.iterativepostorder();
								break;
							}
						case 4:
							{
								f.iterativeinorder();
								break;
							}
						case 5:
							{
								f.levelbylevel();
								break;
							}
						case 6:
							{
								cout<<"\nElements of BST in recursive preorder are:- ";
								f.recursivepreorder(f.root);
								break;
							}
						case 7:
							{
								cout<<"\nElements of BST in recursive postorder are:- ";
								f.recursivepostorder(f.root);
								break;
							}
						case 8:
							{
								cout<<"\nElements of BST in recursive inorder are:- ";
								f.recursiveinorder(f.root);
								break;
							}
						case 9:
							{
								float value;
								cout<<"\nEnter the value you want to delete from BST:- ";;
								cin>>value;
								f.deletebymerging(value);
								break;
							}
						case 10:
							{
								float value;
								cout<<"\nEnter the value you want to delete from BST:- ";;
								cin>>value;
								f.deletebycopy(value);
								break;
							}
						case 11:
							{
								cout<<"\n\nheight of the binary tree is:- "<<f.height();
								break;
							}
						default:
							cout<<"\n\nWrong Choice re-enter your choice:- ";
					}
					cout<<"\n\nDo you want more opeartion to perform press y:- ";
					cin>>ans;
				}while(ans=='y');
				break;
			}
	}
	getch();
	return 0;
}
/*
Data types are:-
1.int
2.char
3.float

Your data type please:- 1


Operations are:-
1.insert()-insert an element x in binary search tree.
2.iterativepreorder()-display elements in iterative preorder.
3.iterativepostorder()-display elements in iterative postorder.
4.iterativeinorder()-display the elements in iterative inorder
5.levelbylevel()-display the elements in BST in Breadth First Traversal.
6.recursivepreorder()-displaying the elements in recursive preorder trtaversal
7.recursivepostorder()-displaying the elements in recursive postorder trtaversal
8.recursiveinorder()-displaying the elements in recursive inorder trtaversal
9.deletebymerging()-delete the node in BST by using merging
10.deletebycopy()-delete the element in BST by using DELETE BY COPY method
11.height()-find the height of binary search tree

Your choice please:- 1


Enter the value you want to insert in BST:- 10


Do you want more opeartion to perform press y:- y


Operations are:-
1.insert()-insert an element x in binary search tree.
2.iterativepreorder()-display elements in iterative preorder.
3.iterativepostorder()-display elements in iterative postorder.
4.iterativeinorder()-display the elements in iterative inorder
5.levelbylevel()-display the elements in BST in Breadth First Traversal.
6.recursivepreorder()-displaying the elements in recursive preorder trtaversal
7.recursivepostorder()-displaying the elements in recursive postorder trtaversal
8.recursiveinorder()-displaying the elements in recursive inorder trtaversal
9.deletebymerging()-delete the node in BST by using merging
10.deletebycopy()-delete the element in BST by using DELETE BY COPY method
11.height()-find the height of binary search tree

Your choice please:- 1


Enter the value you want to insert in BST:- 15


Do you want more opeartion to perform press y:- y


Operations are:-
1.insert()-insert an element x in binary search tree.
2.iterativepreorder()-display elements in iterative preorder.
3.iterativepostorder()-display elements in iterative postorder.
4.iterativeinorder()-display the elements in iterative inorder
5.levelbylevel()-display the elements in BST in Breadth First Traversal.
6.recursivepreorder()-displaying the elements in recursive preorder trtaversal
7.recursivepostorder()-displaying the elements in recursive postorder trtaversal
8.recursiveinorder()-displaying the elements in recursive inorder trtaversal
9.deletebymerging()-delete the node in BST by using merging
10.deletebycopy()-delete the element in BST by using DELETE BY COPY method
11.height()-find the height of binary search tree

Your choice please:- 1


Enter the value you want to insert in BST:- 5


Do you want more opeartion to perform press y:- y


Operations are:-
1.insert()-insert an element x in binary search tree.
2.iterativepreorder()-display elements in iterative preorder.
3.iterativepostorder()-display elements in iterative postorder.
4.iterativeinorder()-display the elements in iterative inorder
5.levelbylevel()-display the elements in BST in Breadth First Traversal.
6.recursivepreorder()-displaying the elements in recursive preorder trtaversal
7.recursivepostorder()-displaying the elements in recursive postorder trtaversal
8.recursiveinorder()-displaying the elements in recursive inorder trtaversal
9.deletebymerging()-delete the node in BST by using merging
10.deletebycopy()-delete the element in BST by using DELETE BY COPY method
11.height()-find the height of binary search tree

Your choice please:- 1


Enter the value you want to insert in BST:- 6


Do you want more opeartion to perform press y:- y


Operations are:-
1.insert()-insert an element x in binary search tree.
2.iterativepreorder()-display elements in iterative preorder.
3.iterativepostorder()-display elements in iterative postorder.
4.iterativeinorder()-display the elements in iterative inorder
5.levelbylevel()-display the elements in BST in Breadth First Traversal.
6.recursivepreorder()-displaying the elements in recursive preorder trtaversal
7.recursivepostorder()-displaying the elements in recursive postorder trtaversal
8.recursiveinorder()-displaying the elements in recursive inorder trtaversal
9.deletebymerging()-delete the node in BST by using merging
10.deletebycopy()-delete the element in BST by using DELETE BY COPY method
11.height()-find the height of binary search tree

Your choice please:- 1


Enter the value you want to insert in BST:- 18


Do you want more opeartion to perform press y:- y


Operations are:-
1.insert()-insert an element x in binary search tree.
2.iterativepreorder()-display elements in iterative preorder.
3.iterativepostorder()-display elements in iterative postorder.
4.iterativeinorder()-display the elements in iterative inorder
5.levelbylevel()-display the elements in BST in Breadth First Traversal.
6.recursivepreorder()-displaying the elements in recursive preorder trtaversal
7.recursivepostorder()-displaying the elements in recursive postorder trtaversal
8.recursiveinorder()-displaying the elements in recursive inorder trtaversal
9.deletebymerging()-delete the node in BST by using merging
10.deletebycopy()-delete the element in BST by using DELETE BY COPY method
11.height()-find the height of binary search tree

Your choice please:- 1


Enter the value you want to insert in BST:- 4


Do you want more opeartion to perform press y:- y


Operations are:-
1.insert()-insert an element x in binary search tree.
2.iterativepreorder()-display elements in iterative preorder.
3.iterativepostorder()-display elements in iterative postorder.
4.iterativeinorder()-display the elements in iterative inorder
5.levelbylevel()-display the elements in BST in Breadth First Traversal.
6.recursivepreorder()-displaying the elements in recursive preorder trtaversal
7.recursivepostorder()-displaying the elements in recursive postorder trtaversal
8.recursiveinorder()-displaying the elements in recursive inorder trtaversal
9.deletebymerging()-delete the node in BST by using merging
10.deletebycopy()-delete the element in BST by using DELETE BY COPY method
11.height()-find the height of binary search tree

Your choice please:- 2


Elements of BST in preorder are:- 10 5 4 6 15 18

Do you want more opeartion to perform press y:- y


Operations are:-
1.insert()-insert an element x in binary search tree.
2.iterativepreorder()-display elements in iterative preorder.
3.iterativepostorder()-display elements in iterative postorder.
4.iterativeinorder()-display the elements in iterative inorder
5.levelbylevel()-display the elements in BST in Breadth First Traversal.
6.recursivepreorder()-displaying the elements in recursive preorder trtaversal
7.recursivepostorder()-displaying the elements in recursive postorder trtaversal
8.recursiveinorder()-displaying the elements in recursive inorder trtaversal
9.deletebymerging()-delete the node in BST by using merging
10.deletebycopy()-delete the element in BST by using DELETE BY COPY method
11.height()-find the height of binary search tree

Your choice please:- 6

Elements of BST in recursive preorder are:- 10 5 4 6 15 18

Do you want more opeartion to perform press y:- y


Operations are:-
1.insert()-insert an element x in binary search tree.
2.iterativepreorder()-display elements in iterative preorder.
3.iterativepostorder()-display elements in iterative postorder.
4.iterativeinorder()-display the elements in iterative inorder
5.levelbylevel()-display the elements in BST in Breadth First Traversal.
6.recursivepreorder()-displaying the elements in recursive preorder trtaversal
7.recursivepostorder()-displaying the elements in recursive postorder trtaversal
8.recursiveinorder()-displaying the elements in recursive inorder trtaversal
9.deletebymerging()-delete the node in BST by using merging
10.deletebycopy()-delete the element in BST by using DELETE BY COPY method
11.height()-find the height of binary search tree

Your choice please:- 5


Elements of BST in level by level traversal are:-  10 5 15 4 6 18

Do you want more opeartion to perform press y:- y


Operations are:-
1.insert()-insert an element x in binary search tree.
2.iterativepreorder()-display elements in iterative preorder.
3.iterativepostorder()-display elements in iterative postorder.
4.iterativeinorder()-display the elements in iterative inorder
5.levelbylevel()-display the elements in BST in Breadth First Traversal.
6.recursivepreorder()-displaying the elements in recursive preorder trtaversal
7.recursivepostorder()-displaying the elements in recursive postorder trtaversal
8.recursiveinorder()-displaying the elements in recursive inorder trtaversal
9.deletebymerging()-delete the node in BST by using merging
10.deletebycopy()-delete the element in BST by using DELETE BY COPY method
11.height()-find the height of binary search tree

Your choice please:- 3


Elements of BST in postorder are:- 4 6 5 18 15 10

Do you want more opeartion to perform press y:- y


Operations are:-
1.insert()-insert an element x in binary search tree.
2.iterativepreorder()-display elements in iterative preorder.
3.iterativepostorder()-display elements in iterative postorder.
4.iterativeinorder()-display the elements in iterative inorder
5.levelbylevel()-display the elements in BST in Breadth First Traversal.
6.recursivepreorder()-displaying the elements in recursive preorder trtaversal
7.recursivepostorder()-displaying the elements in recursive postorder trtaversal
8.recursiveinorder()-displaying the elements in recursive inorder trtaversal
9.deletebymerging()-delete the node in BST by using merging
10.deletebycopy()-delete the element in BST by using DELETE BY COPY method
11.height()-find the height of binary search tree

Your choice please:- 7

Elements of BST in recursive postorder are:- 4 6 5 18 15 10

Do you want more opeartion to perform press y:- y


Operations are:-
1.insert()-insert an element x in binary search tree.
2.iterativepreorder()-display elements in iterative preorder.
3.iterativepostorder()-display elements in iterative postorder.
4.iterativeinorder()-display the elements in iterative inorder
5.levelbylevel()-display the elements in BST in Breadth First Traversal.
6.recursivepreorder()-displaying the elements in recursive preorder trtaversal
7.recursivepostorder()-displaying the elements in recursive postorder trtaversal
8.recursiveinorder()-displaying the elements in recursive inorder trtaversal
9.deletebymerging()-delete the node in BST by using merging
10.deletebycopy()-delete the element in BST by using DELETE BY COPY method
11.height()-find the height of binary search tree

Your choice please:- 4


Elements of BST in inorder are:- 4 5 6 10 15 18

Do you want more opeartion to perform press y:- y


Operations are:-
1.insert()-insert an element x in binary search tree.
2.iterativepreorder()-display elements in iterative preorder.
3.iterativepostorder()-display elements in iterative postorder.
4.iterativeinorder()-display the elements in iterative inorder
5.levelbylevel()-display the elements in BST in Breadth First Traversal.
6.recursivepreorder()-displaying the elements in recursive preorder trtaversal
7.recursivepostorder()-displaying the elements in recursive postorder trtaversal
8.recursiveinorder()-displaying the elements in recursive inorder trtaversal
9.deletebymerging()-delete the node in BST by using merging
10.deletebycopy()-delete the element in BST by using DELETE BY COPY method
11.height()-find the height of binary search tree

Your choice please:- 8

Elements of BST in recursive inorder are:- 4 5 6 10 15 18

Do you want more opeartion to perform press y:- y


Operations are:-
1.insert()-insert an element x in binary search tree.
2.iterativepreorder()-display elements in iterative preorder.
3.iterativepostorder()-display elements in iterative postorder.
4.iterativeinorder()-display the elements in iterative inorder
5.levelbylevel()-display the elements in BST in Breadth First Traversal.
6.recursivepreorder()-displaying the elements in recursive preorder trtaversal
7.recursivepostorder()-displaying the elements in recursive postorder trtaversal
8.recursiveinorder()-displaying the elements in recursive inorder trtaversal
9.deletebymerging()-delete the node in BST by using merging
10.deletebycopy()-delete the element in BST by using DELETE BY COPY method
11.height()-find the height of binary search tree

Your choice please:- 11


height of the binary tree is:- 3

Do you want more opeartion to perform press y:- y


Operations are:-
1.insert()-insert an element x in binary search tree.
2.iterativepreorder()-display elements in iterative preorder.
3.iterativepostorder()-display elements in iterative postorder.
4.iterativeinorder()-display the elements in iterative inorder
5.levelbylevel()-display the elements in BST in Breadth First Traversal.
6.recursivepreorder()-displaying the elements in recursive preorder trtaversal
7.recursivepostorder()-displaying the elements in recursive postorder trtaversal
8.recursiveinorder()-displaying the elements in recursive inorder trtaversal
9.deletebymerging()-delete the node in BST by using merging
10.deletebycopy()-delete the element in BST by using DELETE BY COPY method
11.height()-find the height of binary search tree

Your choice please:- 9

Enter the value you want to delete from BST:- 3

Element 3 is not present in the tree

Do you want more opeartion to perform press y:- y


Operations are:-
1.insert()-insert an element x in binary search tree.
2.iterativepreorder()-display elements in iterative preorder.
3.iterativepostorder()-display elements in iterative postorder.
4.iterativeinorder()-display the elements in iterative inorder
5.levelbylevel()-display the elements in BST in Breadth First Traversal.
6.recursivepreorder()-displaying the elements in recursive preorder trtaversal
7.recursivepostorder()-displaying the elements in recursive postorder trtaversal
8.recursiveinorder()-displaying the elements in recursive inorder trtaversal
9.deletebymerging()-delete the node in BST by using merging
10.deletebycopy()-delete the element in BST by using DELETE BY COPY method
11.height()-find the height of binary search tree

Your choice please:- 9

Enter the value you want to delete from BST:- 5


Do you want more opeartion to perform press y:- y


Operations are:-
1.insert()-insert an element x in binary search tree.
2.iterativepreorder()-display elements in iterative preorder.
3.iterativepostorder()-display elements in iterative postorder.
4.iterativeinorder()-display the elements in iterative inorder
5.levelbylevel()-display the elements in BST in Breadth First Traversal.
6.recursivepreorder()-displaying the elements in recursive preorder trtaversal
7.recursivepostorder()-displaying the elements in recursive postorder trtaversal
8.recursiveinorder()-displaying the elements in recursive inorder trtaversal
9.deletebymerging()-delete the node in BST by using merging
10.deletebycopy()-delete the element in BST by using DELETE BY COPY method
11.height()-find the height of binary search tree

Your choice please:- 2


Elements of BST in preorder are:- 10 4 6 15 18

Do you want more opeartion to perform press y:- y


Operations are:-
1.insert()-insert an element x in binary search tree.
2.iterativepreorder()-display elements in iterative preorder.
3.iterativepostorder()-display elements in iterative postorder.
4.iterativeinorder()-display the elements in iterative inorder
5.levelbylevel()-display the elements in BST in Breadth First Traversal.
6.recursivepreorder()-displaying the elements in recursive preorder trtaversal
7.recursivepostorder()-displaying the elements in recursive postorder trtaversal
8.recursiveinorder()-displaying the elements in recursive inorder trtaversal
9.deletebymerging()-delete the node in BST by using merging
10.deletebycopy()-delete the element in BST by using DELETE BY COPY method
11.height()-find the height of binary search tree

Your choice please:- 10

Enter the value you want to delete from BST:- 15


Do you want more opeartion to perform press y:- y


Operations are:-
1.insert()-insert an element x in binary search tree.
2.iterativepreorder()-display elements in iterative preorder.
3.iterativepostorder()-display elements in iterative postorder.
4.iterativeinorder()-display the elements in iterative inorder
5.levelbylevel()-display the elements in BST in Breadth First Traversal.
6.recursivepreorder()-displaying the elements in recursive preorder trtaversal
7.recursivepostorder()-displaying the elements in recursive postorder trtaversal
8.recursiveinorder()-displaying the elements in recursive inorder trtaversal
9.deletebymerging()-delete the node in BST by using merging
10.deletebycopy()-delete the element in BST by using DELETE BY COPY method
11.height()-find the height of binary search tree

Your choice please:- 3


Elements of BST in postorder are:- 6 4 18 10

Do you want more opeartion to perform press y:- y


Operations are:-
1.insert()-insert an element x in binary search tree.
2.iterativepreorder()-display elements in iterative preorder.
3.iterativepostorder()-display elements in iterative postorder.
4.iterativeinorder()-display the elements in iterative inorder
5.levelbylevel()-display the elements in BST in Breadth First Traversal.
6.recursivepreorder()-displaying the elements in recursive preorder trtaversal
7.recursivepostorder()-displaying the elements in recursive postorder trtaversal
8.recursiveinorder()-displaying the elements in recursive inorder trtaversal
9.deletebymerging()-delete the node in BST by using merging
10.deletebycopy()-delete the element in BST by using DELETE BY COPY method
11.height()-find the height of binary search tree

Your choice please:- 11


height of the binary tree is:- 3

Do you want more opeartion to perform press y:-
*/

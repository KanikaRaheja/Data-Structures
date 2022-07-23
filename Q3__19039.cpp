#include<iostream>
#include<conio.h>
#include<exception>
using namespace std;

template<class type>
class node
{
	public:
	type data;
    node<type>* next;
};
template<class type>
class LinkedList
{
	public:
	LinkedList();
	void addfront(const type&);
	void addeleati(int,const type &);
	void removefront();
	void removeeleati(int);
	void concatenate();
	void input(const type&);
	void display();
	void search(type);
	private:
	class node<type>* head;
	class node<type> *head1;
	int n;
};
template<class type>
LinkedList<type>::LinkedList()
{
	 n=0;
	head=NULL;
	head1=NULL;
}
template<class type>
void LinkedList<type>::addfront(const type& element)
{
 	node<type> *v=new node<type>;
	v->data=element;
	v->next=head;
	head=v;
	n++;
}
template<class type>
void LinkedList<type>::addeleati(int i,const type& element)
{
	int count=1;
	node<type>* temp=head;
	node<type>* x=new node<type>;
	x->data=element;
	x->next=NULL;
	if(temp==NULL)
	cout<<"\n\nThe list is empty at present"<<endl;
	else
	{
		if((i>1) && (i<=n))
		{
  while(count<i-1)
  {
  	temp=temp->next;
  	count++;
  }
	x->next=temp->next;
	temp->next=x;
	n++;
   }
   else if(i==1)
   {
   	x->next=head;
   	head=x;
   	n++;
   }
   else if(i>n)
   {
   	cout<<"\n\nSize of the list exceed"<<endl;
   }
}
}
template<class type>
void LinkedList<type>::removefront()
{
	if(head==NULL)
	cout<<"\nList is empty.\nNo element to delete"<<endl;
	else
	{
	node<type> *temp=head;
	head=temp->next;
	delete temp;
   }
   n--;
}
template<class type>
void LinkedList<type>::removeeleati(int i)
{
  if(i<=n)
  {	
    node<type> *temp=head;
    node<type> *old;
	int count=1;
	if(head==NULL)
	cout<<"\nList is empty.\nNo element to delete"<<endl;
	else
	{
	if(i>1)
	{
	 while(count<i-1)
	{
	 temp=temp->next;
	 count++;
	 
    }
	old=temp->next;
	temp->next=old->next;
	delete old;
   }
   else
   {
   	old=temp;
   	head=old->next;
   	delete old;
   }
   n--;
}
}
else
cout<<"\n\nSize of list exceed"<<endl;
}
template<class type>
void LinkedList<type>::search(type x)
{
	int i=1;
	node<type> *temp=head;
	if(head==NULL)
	cout<<"\nList is empty"<<endl;
	else
	{
	while(temp->next!=NULL)
	{
			if(temp->data==x)
		{
		cout<<"\nElement "<<temp->data<<" found at "<<i<<" position"<<endl;
		break;
	    }
			temp=temp->next;
			i++;
	}
	if(temp->next==NULL)
	{
	if(temp->data==x)
	cout<<"\n\nElement "<<x<<"  found at "<<i<<" position"<<endl;
	else
	cout<<"\n\nElement "<<x<<" not found in the list"<<endl;
    }
   }
}
template<class type>
void LinkedList<type>::input(const type& element)
{
 	node<type> *u=new node<type>;
	u->data=element;
	u->next=head1;
	head1=u;
}
template <class type>
void LinkedList<type>::concatenate()
{
	node<type> *temp=head;
	 if(temp==NULL)
	{
		cout<<"\nThe first list is empty"<<endl;
			head=head1;
	}
	else
	{
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
		temp->next=head1;
	}
}
template<class type>
void LinkedList<type>::display()
{
	
 	node<type> *temp;
	temp=head;
	if (head==NULL)
	cout<<"\n\nList is empty.\nNo element to display"<<endl;
	else
	{
	while(temp->next!=NULL)
	{
		cout<<"  "<<temp->data;
		temp=temp->next;
	}
	cout<<"  "<<temp->data;
   }
   cout<<endl;
}
int main()
{
	LinkedList<int> l;
	LinkedList<char> c;
	LinkedList<float> f;
	int ch,choice;
	char ans;
	cout<<"\nEnter data type\n1.int\n2.char\n3.float";
	cout<<"\nYour choice please:- ";
	cin>>choice;
	switch(choice)
	{
	case 1:
		{
				do
	{
	cout<<"\nEnter your choice\n1.addfront()-add the at the beginning of the list\n2.addeleati()-add element at given position\n3.removefront()-remove an element from the front\n4.removeeleati()-remove the element at i position from the list\n5.search()-search for the given element in the list\n6.concatenate()-concatenate two singly linked lists.\n7.display()-display the elements of the list";
	cout<<"\nYour choice please:- ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			{
				int value;
				cout<<"\nEnter the element you want to insert in the list:- ";
				cin>>value;
				l.addfront(value);
				break;
			}
		case 2:
			{
				int pos,element;
				cout<<"\nEnter the position at which you enter the element:- ";
				cin>>pos;
				cout<<"\nEnter the element you want to enter at given position:- ";
				cin>>element;
				l.addeleati(pos,element);
				break;
			}
		case 3:
			{
				l.removefront();
				break;
			}
		case 4:
			{
				int pos;
				cout<<"\nEnter the position from which you want to remove the element:- ";
				cin>>pos;
				l.removeeleati(pos);
				break;
			}
			case 5:
				{
					int element;
					cout<<"\nEnter the element you want to search in the list:- ";
					cin>>element;
					l.search(element);
					break;
				}
			case 6:
				{
					int n;
					int count=1;
					int ele;
					cout<<"\nEnter how many elements you want to insert in the 2nd Linked list:- ";
					cin>>n;
					cout<<"\nEnter the elements for 2nd Linked list for concatenation:- ";
				 for(int i=1;i<=n;i++)
					{
					cin>>ele;
					l.input(ele);
		     	}
				l.concatenate();
				break;
				}
			case 7:
				{
					cout<<"\nElements of the linked lists are:- ";
					l.display();
					break;
				}
				default:
					cout<<"\nWrong choice Please reenter your choice:- ";
				}
				cout<<"\nDo you want more opeartion to perform then press y:- ";
				cin>>ans;
			}while(ans=='y');
		break;
		}
		case 2:
	{
				do
	{
	cout<<"\nEnter your choice\n1.addfront()-add the at the beginning of the list\n2.addeleati()-add element at given position\n3.removefront()-remove an element from the front\n4.removeeleati()-remove the element at i position from the list\n5.search()-search for the given element in the list\n6.concatenate()-concatenate two singly linked lists.\n7.display()-display the elements of the list";
	cout<<"\nYour choice please:- ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			{
				char value;
				cout<<"\nEnter the element you want to insert in the list:- ";
				cin>>value;
				c.addfront(value);
				break;
			}
		case 2:
			{
				int pos;
				char element;
				cout<<"\nEnter the position at which you enter the element:- ";
				cin>>pos;
				cout<<"\nEnter the element you want to enter at given position:- ";
				cin>>element;
				c.addeleati(pos,element);
				break;
			}
		case 3:
			{
				c.removefront();
				break;
			}
		case 4:
			{
				int pos;
				cout<<"\nEnter the position from which you want to remove the element:- ";
				cin>>pos;
				c.removeeleati(pos);
				break;
			}
			case 5:
				{
					char element;
					cout<<"\nEnter the element you want to search in the list:- ";
					cin>>element;
					c.search(element);
					break;
				}
			case 6:
				{
					int n;
					int count=1;
					char ele;
					cout<<"\nEnter how many elements you want to insert in the 2nd Linked list:- ";
					cin>>n;
					cout<<"\nEnter the elements for 2nd Linked list for concatenation:- ";
				 for(int i=1;i<=n;i++)
					{
					cin>>ele;
					c.input(ele);
		     	}
				c.concatenate();
				break;
				}
			case 7:
				{
					cout<<"\nElements of the linked lists are:- ";
					c.display();
					break;
				}
				default:
					cout<<"\nWrong choice Please reenter your choice:- ";
				}
				cout<<"\nDo you want more opeartion to perform then press y:- ";
				cin>>ans;
			}while(ans=='y');
		break;
		}
		case 3:
				{
				do
	{
	cout<<"\nEnter your choice\n1.addfront()-add the at the beginning of the list\n2.addeleati()-add element at given position\n3.removefront()-remove an element from the front\n4.removeeleati()-remove the element at i position from the list\n5.search()-search for the given element in the list\n6.concatenate()-concatenate two singly linked lists.\n7.display()-display the elements of the list";
	cout<<"\nYour choice please:- ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			{
				float value;
				cout<<"\nEnter the element you want to insert in the list:- ";
				cin>>value;
				f.addfront(value);
				break;
			}
		case 2:
			{
				int pos;
				float element;
				cout<<"\nEnter the position at which you enter the element:- ";
				cin>>pos;
				cout<<"\nEnter the element you want to enter at given position:- ";
				cin>>element;
				f.addeleati(pos,element);
				break;
			}
		case 3:
			{
				f.removefront();
				break;
			}
		case 4:
			{
				int pos;
				cout<<"\nEnter the position from which you want to remove the element:- ";
				cin>>pos;
				f.removeeleati(pos);
				break;
			}
			case 5:
				{
					float element;
					cout<<"\nEnter the element you want to search in the list:- ";
					cin>>element;
					f.search(element);
					break;
				}
			case 6:
				{
					int n;
					int count=1;
					float ele;
					cout<<"\nEnter how many elements you want to insert in the 2nd Linked list:- ";
					cin>>n;
					cout<<"\nEnter the elements for 2nd Linked list for concatenation:- ";
				 for(int i=1;i<=n;i++)
					{
					cin>>ele;
					l.input(ele);
		     	}
				f.concatenate();
				break;
				}
			case 7:
				{
					cout<<"\nElements of the linked lists are:- ";
					f.display();
					break;
				}
				default:
					cout<<"\nWrong choice Please reenter your choice:- ";
				}
				cout<<"\nDo you want more opeartion to perform then press y:- ";
				cin>>ans;
			}while(ans=='y');
		break;
		}
		default:
			cout<<"\nWrong choice reenter your choice:- ";
		}
		getch();
		return 0;
	}
	
/*
OUTPUT
Enter data type
1.int
2.char
3.float
Your choice please:- 2

Enter your choice
1.addfront()-add the at the beginning of the list
2.addeleati()-add element at given position
3.removefront()-remove an element from the front
4.removeeleati()-remove the element at i position from the list
5.search()-search for the given element in the list
6.concatenate()-concatenate two singly linked lists.
7.display()-display the elements of the list
Your choice please:- 1

Enter the element you want to insert in the list:- f

Do you want more opeartion to perform then press y:- y

Enter your choice
1.addfront()-add the at the beginning of the list
2.addeleati()-add element at given position
3.removefront()-remove an element from the front
4.removeeleati()-remove the element at i position from the list
5.search()-search for the given element in the list
6.concatenate()-concatenate two singly linked lists.
7.display()-display the elements of the list
Your choice please:- 1

Enter the element you want to insert in the list:- g

Do you want more opeartion to perform then press y:- y

Enter your choice
1.addfront()-add the at the beginning of the list
2.addeleati()-add element at given position
3.removefront()-remove an element from the front
4.removeeleati()-remove the element at i position from the list
5.search()-search for the given element in the list
6.concatenate()-concatenate two singly linked lists.
7.display()-display the elements of the list
Your choice please:- 1

Enter the element you want to insert in the list:- k

Do you want more opeartion to perform then press y:- y

Enter your choice
1.addfront()-add the at the beginning of the list
2.addeleati()-add element at given position
3.removefront()-remove an element from the front
4.removeeleati()-remove the element at i position from the list
5.search()-search for the given element in the list
6.concatenate()-concatenate two singly linked lists.
7.display()-display the elements of the list
Your choice please:- 1

Enter the element you want to insert in the list:- l

Do you want more opeartion to perform then press y:- y

Enter your choice
1.addfront()-add the at the beginning of the list
2.addeleati()-add element at given position
3.removefront()-remove an element from the front
4.removeeleati()-remove the element at i position from the list
5.search()-search for the given element in the list
6.concatenate()-concatenate two singly linked lists.
7.display()-display the elements of the list
Your choice please:- 7

Elements of the linked lists are:-   l  k  g  f

Do you want more opeartion to perform then press y:- y

Enter your choice
1.addfront()-add the at the beginning of the list
2.addeleati()-add element at given position
3.removefront()-remove an element from the front
4.removeeleati()-remove the element at i position from the list
5.search()-search for the given element in the list
6.concatenate()-concatenate two singly linked lists.
7.display()-display the elements of the list
Your choice please:- 2

Enter the position at which you enter the element:- 3

Enter the element you want to enter at given position:- d

Do you want more opeartion to perform then press y:- y

Enter your choice
1.addfront()-add the at the beginning of the list
2.addeleati()-add element at given position
3.removefront()-remove an element from the front
4.removeeleati()-remove the element at i position from the list
5.search()-search for the given element in the list
6.concatenate()-concatenate two singly linked lists.
7.display()-display the elements of the list
Your choice please:- 7

Elements of the linked lists are:-   l  k  d  g  f

Do you want more opeartion to perform then press y:- y

Enter your choice
1.addfront()-add the at the beginning of the list
2.addeleati()-add element at given position
3.removefront()-remove an element from the front
4.removeeleati()-remove the element at i position from the list
5.search()-search for the given element in the list
6.concatenate()-concatenate two singly linked lists.
7.display()-display the elements of the list
Your choice please:- 3

Do you want more opeartion to perform then press y:- y

Enter your choice
1.addfront()-add the at the beginning of the list
2.addeleati()-add element at given position
3.removefront()-remove an element from the front
4.removeeleati()-remove the element at i position from the list
5.search()-search for the given element in the list
6.concatenate()-concatenate two singly linked lists.
7.display()-display the elements of the list
Your choice please:- 7

Elements of the linked lists are:-   k  d  g  f

Do you want more opeartion to perform then press y:- y

Enter your choice
1.addfront()-add the at the beginning of the list
2.addeleati()-add element at given position
3.removefront()-remove an element from the front
4.removeeleati()-remove the element at i position from the list
5.search()-search for the given element in the list
6.concatenate()-concatenate two singly linked lists.
7.display()-display the elements of the list
Your choice please:- 4

Enter the position from which you want to remove the element:- 6


Size of list exceed

Do you want more opeartion to perform then press y:- y

Enter your choice
1.addfront()-add the at the beginning of the list
2.addeleati()-add element at given position
3.removefront()-remove an element from the front
4.removeeleati()-remove the element at i position from the list
5.search()-search for the given element in the list
6.concatenate()-concatenate two singly linked lists.
7.display()-display the elements of the list
Your choice please:- 4

Enter the position from which you want to remove the element:- 1

Do you want more opeartion to perform then press y:- y

Enter your choice
1.addfront()-add the at the beginning of the list
2.addeleati()-add element at given position
3.removefront()-remove an element from the front
4.removeeleati()-remove the element at i position from the list
5.search()-search for the given element in the list
6.concatenate()-concatenate two singly linked lists.
7.display()-display the elements of the list
Your choice please:- 7

Elements of the linked lists are:-   d  g  f

Do you want more opeartion to perform then press y:- y

Enter your choice
1.addfront()-add the at the beginning of the list
2.addeleati()-add element at given position
3.removefront()-remove an element from the front
4.removeeleati()-remove the element at i position from the list
5.search()-search for the given element in the list
6.concatenate()-concatenate two singly linked lists.
7.display()-display the elements of the list
Your choice please:- 4

Enter the position from which you want to remove the element:- 3

Do you want more opeartion to perform then press y:- y

Enter your choice
1.addfront()-add the at the beginning of the list
2.addeleati()-add element at given position
3.removefront()-remove an element from the front
4.removeeleati()-remove the element at i position from the list
5.search()-search for the given element in the list
6.concatenate()-concatenate two singly linked lists.
7.display()-display the elements of the list
Your choice please:- 7

Elements of the linked lists are:-   d  g

Do you want more opeartion to perform then press y:- y

Enter your choice
1.addfront()-add the at the beginning of the list
2.addeleati()-add element at given position
3.removefront()-remove an element from the front
4.removeeleati()-remove the element at i position from the list
5.search()-search for the given element in the list
6.concatenate()-concatenate two singly linked lists.
7.display()-display the elements of the list
Your choice please:- 1

Enter the element you want to insert in the list:- a

Do you want more opeartion to perform then press y:- y

Enter your choice
1.addfront()-add the at the beginning of the list
2.addeleati()-add element at given position
3.removefront()-remove an element from the front
4.removeeleati()-remove the element at i position from the list
5.search()-search for the given element in the list
6.concatenate()-concatenate two singly linked lists.
7.display()-display the elements of the list
Your choice please:- 1

Enter the element you want to insert in the list:- h

Do you want more opeartion to perform then press y:- y

Enter your choice
1.addfront()-add the at the beginning of the list
2.addeleati()-add element at given position
3.removefront()-remove an element from the front
4.removeeleati()-remove the element at i position from the list
5.search()-search for the given element in the list
6.concatenate()-concatenate two singly linked lists.
7.display()-display the elements of the list
Your choice please:- 7

Elements of the linked lists are:-   h  a  d  g

Do you want more opeartion to perform then press y:- y

Enter your choice
1.addfront()-add the at the beginning of the list
2.addeleati()-add element at given position
3.removefront()-remove an element from the front
4.removeeleati()-remove the element at i position from the list
5.search()-search for the given element in the list
6.concatenate()-concatenate two singly linked lists.
7.display()-display the elements of the list
Your choice please:- 5

Enter the element you want to search in the list:- k


Element k not found in the list

Do you want more opeartion to perform then press y:- y

Enter your choice
1.addfront()-add the at the beginning of the list
2.addeleati()-add element at given position
3.removefront()-remove an element from the front
4.removeeleati()-remove the element at i position from the list
5.search()-search for the given element in the list
6.concatenate()-concatenate two singly linked lists.
7.display()-display the elements of the list
Your choice please:- 5

Enter the element you want to search in the list:- g


Element g  found at 4 position

Do you want more opeartion to perform then press y:- y

Enter your choice
1.addfront()-add the at the beginning of the list
2.addeleati()-add element at given position
3.removefront()-remove an element from the front
4.removeeleati()-remove the element at i position from the list
5.search()-search for the given element in the list
6.concatenate()-concatenate two singly linked lists.
7.display()-display the elements of the list
Your choice please:- 6

Enter how many elements you want to insert in the 2nd Linked list:- 3

Enter the elements for 2nd Linked list for concatenation:- a b c

Do you want more opeartion to perform then press y:- y

Enter your choice
1.addfront()-add the at the beginning of the list
2.addeleati()-add element at given position
3.removefront()-remove an element from the front
4.removeeleati()-remove the element at i position from the list
5.search()-search for the given element in the list
6.concatenate()-concatenate two singly linked lists.
7.display()-display the elements of the list
Your choice please:- 7

Elements of the linked lists are:-   h  a  d  g  c  b  a

Do you want more opeartion to perform then press y:- y

Enter your choice
1.addfront()-add the at the beginning of the list
2.addeleati()-add element at given position
3.removefront()-remove an element from the front
4.removeeleati()-remove the element at i position from the list
5.search()-search for the given element in the list
6.concatenate()-concatenate two singly linked lists.
7.display()-display the elements of the list
Your choice please:- 2

Enter the position at which you enter the element:- 1

Enter the element you want to enter at given position:- r

Do you want more opeartion to perform then press y:- y

Enter your choice
1.addfront()-add the at the beginning of the list
2.addeleati()-add element at given position
3.removefront()-remove an element from the front
4.removeeleati()-remove the element at i position from the list
5.search()-search for the given element in the list
6.concatenate()-concatenate two singly linked lists.
7.display()-display the elements of the list
Your choice please:- 7

Elements of the linked lists are:-   r  h  a  d  g  c  b  a

Do you want more opeartion to perform then press y:-





*/
				
				

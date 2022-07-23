//Extension
/* Q3)
Write a program to implement singly linked list which supports the following operations:
(i) Insert an element x at the beginning of the singly linked list
(ii) Insert an element x at position i in the singly linked list
(iii)Remove an element from the beginning of the singly linked list
(iv) Remove an element from position i in the singly linked list.
(v) Search for an element x in the singly linked list
(vi) Concatenate two singly linked lists.
(vii) Insert an element x at the end of the singly linked list
(viii) Remove an element from the end of the singly linked list
(ix) Insert an element x after an element y in the singly linked list
(x) Insert an element x before an element y in the singly linked list
(xi) Reverse the singly linked list*/
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
class Llist
{
	private:
	class node<type>* head;
	class node<type> *head1;
	int n;
	public:
	Llist();
	void add_front(const type&);
	void add_element(int,const type &);
	void remove_front();
	void remove_element(int);
	void concatenate();
	void input(const type&);
	void display();
	void search(type);
	void add_end(const type& element);
	void remove_end();
	void add_after_y(type,type);
	void add_before_y(type,type);
	void reverse();

	
};
//constructor
template<class type>
Llist<type>::Llist()
{
	 n=0;
	head=NULL;
	head1=NULL;
}
// Add  element at the beginning of the singly linked list
template<class type>
void Llist<type>::add_front(const type& element)
{
 	node<type> *v=new node<type>;
	v->data=element;
	v->next=head;
	head=v;
	n++;
}
//Add element at position i in the singly linked list
template<class type>
void Llist<type>::add_element(int i,const type& element)
{
	int count=1;
	node<type>* temp=head;
	node<type>* x=new node<type>;
	x->data=element;
	x->next=NULL;
	if(temp==NULL)
	cout<<"\n\nList is Empty !"<<endl;
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
   	cout<<"\n\nList Size EXCEEDED "<<endl;
   }
}
}
//Remove element from the beginning of the singly linked list
template<class type>
void Llist<type>::remove_front()
{
	if(head==NULL)
	cout<<"\nList is Empty !\nNo element to Remove..."<<endl;
	else
	{
	node<type> *temp=head;
	head=temp->next;
	delete temp;
   }
   n--;
}
//Remove element from position i in the singly linked list.
template<class type>
void Llist<type>::remove_element(int i)
{
  if(i<=n)
  {	
    node<type> *temp=head;
    node<type> *old;
	int count=1;
	if(head==NULL)
	cout<<"\nList is Empty !\nNo element to Remove.."<<endl;
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
cout<<"\n\nList Size EXCEEDED"<<endl;
}
//Search for an element in the singly linked list
template<class type>
void Llist<type>::search(type x)
{
	int i=1;
	node<type> *temp=head;
	if(head==NULL)
	cout<<"\nList is Empty!"<<endl;
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
	cout<<"\n\nElement "<<x<<"  found at "<<i<<" position."<<endl;
	else
	cout<<"\n\nElement "<<x<<" is not present in the list."<<endl;
    }
   }
}
//Input
template<class type>
void Llist<type>::input(const type& element)
{
 	node<type> *u=new node<type>;
	u->data=element;
	u->next=head1;
	head1=u;
}
// Concatenate two singly linked lists.
template <class type>
void Llist<type>::concatenate()
{
	node<type> *temp=head;
	 if(temp==NULL)
	{
		cout<<"\nThe first list is Empty !"<<endl;
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
//Insert an element from end
template<class type>
void Llist<type>::add_end(const type& element)
{
   node<type> *v=new node<type>;
   v->data=element;
   v->next=NULL;
   node<type> *temp=head;
	if(head==NULL)
	{
	   head=v; 	
	}
	else
	{
   while(temp->next!=NULL)
   {
   	temp=temp->next;
	   }	
	temp->next=v;
	n++;
   }
}
//remove an element from end
template<class type>
void Llist<type>::remove_end()
{
	n=0;
	node<type> *p=head;
	node<type> *q=NULL;
	while(p!=NULL)
	{
		p=p->next;
		n++;
	}
		p=head;
	if(head==NULL)
	cout<<"\n\nList is empty"<<endl;
	else if(n==1)
	{
		delete p;
		head=NULL;
	}
	else
	{
	while(p->next!=NULL)
	{
		q=p;
		p=p->next;
	}
	q->next=NULL;
	delete p;
	n--;
   }
}
//Insert an element x after an element y 
template<class type>
void Llist<type>::add_after_y(type x,type y)
{
	node<type> *v=new node<type>;
	node<type> *temp=head;
	v->data=x;
	if(head==NULL)
	cout<<"\n\nList is empty"<<endl;
	else
	{
		while(temp!=NULL)
		{
	 if(temp->data==y)
	 {
	 	n++;
	v->next=temp->next;
	temp->next=v;
	break;
     }
     	temp=temp->next;
     }
	if(temp==NULL)
	{
		cout<<"\n\nThere is no element "<<y<<" in the list"<<endl;
		}	
	}
}
//Insert an element x before an element y 
template<class type>
void Llist<type>::add_before_y(type x,type y)
{
	node<type> *v=new node<type>;
	node<type> *q=NULL;
	node<type> *temp=head;
	v->data=x;
	if(head==NULL)
	cout<<"\n\nList is empty"<<endl;
	else
	{
		 if(head->data==y)
		 {
		 	v->next=head;
		 	head=v;
		 }
		 else
		 {
	 while(temp->data!=y)
	 {
	 	q=temp;
	temp=temp->next;
     }
     v->next=q->next;
	q->next=v;
	n++;
	if(temp==NULL)
	{
		cout<<"\n\nThere is no element "<<y<<" in the list"<<endl;
		}
	}
}
}
//Reverse
template<class type>
void Llist<type>::reverse()
{
	node<type> *curr=head;
	node<type> *prev=NULL;
	node<type> *currnext=NULL;
	if(head==NULL)
	cout<<"\n\nList is empty."<<endl;
	else
	{
	while(curr!=NULL)
	{
		currnext=curr->next;
		curr->next=prev;
		prev=curr;
		curr=currnext;
	}
	head=prev;
  }
}
template<class type>
void Llist<type>::display()
{
	
 	node<type> *temp;
	temp=head;
	if (head==NULL)
	cout<<"\n\nList is Empty ! \n Nothing to Display."<<endl;
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
    Llist<int> l;
	Llist<char> c;
    Llist<float> f;
	int ch,choice;
	char ans;
	cout<<"\n Data types:\n1.int\n2.char\n3.float";
	cout<<"\nEnter your choice for same :";
	cin>>choice;
	switch(choice)
	{
	case 1:
	{  
		
	do
	{
	cout<<"\nMENU:";
	cout<<"\n1.add_front()-add the at the beginning of the list";
	cout<<"\n2.add_element()-add element at given position";
	cout<<"\n3.remove_front()-remove an element from the front";
	cout<<"\n4.remove_element()-remove the element at i position from the list";
	cout<<"\n5.search()-search for the given element in the list";
	cout<<"\n6.concatenate()-concatenate two singly linked lists";
	cout<<"\n7.display()-display the elements of the list";
	cout<<"\n8.add_end()-to insert the element at the end of list";
	cout<<"\n9.remove_end()-to remove the element from the end of list";
	cout<<"\n10.add_after_y()- to Insert an element x after an element y in the singly linked list";
	cout<<"\n11.add_before_y()-to Insert an element x before an element y in the singly linked list";
	cout<<"\n12.reverse() - to reverse the singly linkrd list";
	cout<<"\nEnter Your Choice :";
	cin>>ch;
	switch(ch)
{
		case 1:
			{
				int value;
				cout<<"\nEnter the element to insert in the list: ";
				cin>>value;
				l.add_front(value);
				break;
			}
		case 2:
			{
				int pos,element;
				cout<<"\nEnter the position to enter the element:";
				cin>>pos;
				cout<<"\nNow, Enter the element at your given position:";
				cin>>element;
				l.add_element(pos,element);
				break;
			}
		case 3:
			{
				l.remove_front();
				break;
			}
		case 4:
			{
				int pos;
				cout<<"\nEnter the position to remove the element: ";
				cin>>pos;
				l.remove_element(pos);
				break;
			}
			case 5:
				{
					int element;
					cout<<"\nEnter the element to search in the list: ";
					cin>>element;
					l.search(element);
					break;
				}
			case 6:
				{
					int n;
					int count=1;
					int ele;
					cout<<"\nEnter How many elements you want to insert in the Second Linked list: ";
					cin>>n;
					cout<<"\nFor conactenation, Enter the elements for Second Linked list : ";
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
					cout<<"\nElements of the linked lists are: ";
					l.display();
					break;
				}
				
			case 8:
				{
					int ele;
					cout<<"\nEnter the element you want to add at the back of list :";
					cin>>ele;
					l.add_end(ele);
					break;
				}
			case 9:
				{
					l.remove_end();
					break;
				}
			case 10:
				{
					int x,y;
					cout<<"\nEnter the element you want to insert:- ";
					cin>>x;
					cout<<"\nEnter the element after which you want to enter "<<x<<"  : ";
					cin>>y;
					l.add_after_y(x,y);
					break;
				}
			case 11:
				{
						int x,y;
					cout<<"\nEnter the element you want to insert : ";
					cin>>x;
					cout<<"\nEnter the element before which you want to enter "<<x<<" : ";
					cin>>y;
					l.add_before_y(x,y);
					break;
				}
			case 12:
				{
					l.reverse();
					break;
				}
				default:
					cout<<"\nWrong Choice";
		}
			
				cout<<"\nDo you want more opeartion to perform then press y or Y : ";
				cin>>ans;
			}while(ans=='y'||ans=='Y');
		break;
     }
		case 2:
	{
				do
	{
		cout<<"\nMENU:";
	cout<<"\n1.add_front()-add the at the beginning of the list";
	cout<<"\n2.add_element()-add element at given position";
	cout<<"\n3.remove_front()-remove an element from the front";
	cout<<"\n4.remove_element()-remove the element at i position from the list";
	cout<<"\n5.search()-search for the given element in the list";
	cout<<"\n6.concatenate()-concatenate two singly linked lists";
	cout<<"\n7.display()-display the elements of the list";
	cout<<"\n8.add_end()-to insert the element at the end of list";
	cout<<"\n9.remove_end()-to remove the element from the end of list";
	cout<<"\n10.add_after_y()- to Insert an element x after an element y in the singly linked list";
	cout<<"\n11.add_before_y()-to Insert an element x before an element y in the singly linked list";
	cout<<"\n12.reverse() - to reverse the singly linkrd list";
	cout<<"\nEnter Your Choice :";
	
	cin>>ch;
	switch(ch)
	{
		case 1:
			{
				char value;
				cout<<"\nEnter the element to insert in the list: ";
				cin>>value;
				c.add_front(value);
				break;
			}
		case 2:
			{
				int pos;
				char element;
				cout<<"\nEnter the position to enter the element:";
				cin>>pos;
				cout<<"\nNow, Enter the element at your given position:";
				cin>>element;
				c.add_element(pos,element);
				break;
			}
		case 3:
			{
				c.remove_front();
				break;
			}
		case 4:
			{
				int pos;
		    	cout<<"\nEnter the position to remove the element: ";
				cin>>pos;
				c.remove_element(pos);
				break;
			}
			case 5:
				{
					char element;
					cout<<"\nEnter the element to search in the list: ";
					cin>>element;
					c.search(element);
					break;
				}
			case 6:
				{
					int n;
					int count=1;
					char ele;
					cout<<"\nEnter How many elements you want to insert in the Second Linked list: ";
					cin>>n;
					cout<<"\nFor conactenation, Enter the elements for Second Linked list : ";
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
					cout<<"\nElements of the linked lists are: ";
					c.display();
					break;
				}
			case 8:
				{
					char ele;
					cout<<"\nEnter the element you want to add at the back of list : ";
					cin>>ele;
					c.add_end(ele);
					break;
				}
			case 9:
				{
					c.remove_end();
					break;
				}
			case 10:
				{
					char x,y;
					cout<<"\nEnter the element you want to insert : ";
					cin>>x;
					cout<<"\nEnter the element after which you want to enter "<<x<<"  : ";
					cin>>y;
					c.add_after_y(x,y);
					break;
				}
			case 11:
				{
					char x,y;
					cout<<"\nEnter the element you want to insert :";
					cin>>x;
					cout<<"\nEnter the element before which you want to enter "<<x<<"  :";
					cin>>y;
					c.add_before_y(x,y);
					break;
				}
			case 12:
				{
					c.reverse();
					break;
				}
			default:
					cout<<"\nWrong Choice";
				}
				cout<<"\nDo you want more opeartion to perform then press y or Y : ";
				cin>>ans;
			}while(ans=='y'||ans=='Y');
		break;
		}
		case 3:
				{
				do
	{
		cout<<"\nMENU:";
	cout<<"\n1.add_front()-add the at the beginning of the list";
	cout<<"\n2.add_element()-add element at given position";
	cout<<"\n3.remove_front()-remove an element from the front";
	cout<<"\n4.remove_element()-remove the element at i position from the list";
	cout<<"\n5.search()-search for the given element in the list";
	cout<<"\n6.concatenate()-concatenate two singly linked lists";
	cout<<"\n7.display()-display the elements of the list";
	cout<<"\n8.add_end()-to insert the element at the end of list";
	cout<<"\n9.remove_end()-to remove the element from the end of list";
	cout<<"\n10.add_after_y()- to Insert an element x after an element y in the singly linked list";
	cout<<"\n11.add_before_y()-to Insert an element x before an element y in the singly linked list";
	cout<<"\n12.reverse() - to reverse the singly linkrd list";
	cout<<"\nEnter Your Choice :";
	
	cin>>ch;
	switch(ch)
	{
		case 1:
			{
				float value;
				cout<<"\nEnter the element to insert in the list: ";
				cin>>value;
				f.add_front(value);
				break;
			}
		case 2:
			{
				int pos;
				float element;
				cout<<"\nEnter the position to enter the element:";
				cin>>pos;
				cout<<"\nNow, Enter the element at your given position:";
				cin>>element;
				f.add_element(pos,element);
				break;
			}
		case 3:
			{
				f.remove_front();
				break;
			}
		case 4:
			{
				int pos;
				cout<<"\nEnter the position to remove the element: ";
				cin>>pos;
				f.remove_element(pos);
				break;
			}
			case 5:
				{
					float element;
					cout<<"\nEnter the element to search in the list: ";
					cin>>element;
					f.search(element);
					break;
				}
			case 6:
				{
					int n;
					int count=1;
					float ele;
					cout<<"\nEnter How many elements you want to insert in the Second Linked list: ";
					cin>>n;
					cout<<"\nFor conactenation, Enter the elements for Second Linked list : ";
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
					cout<<"\nElements of the linked lists are : ";
					f.display();
					break;
				}
		   case 8:
				{
					float ele;
					cout<<"\nEnter the element you want to add at the back of list :";
					cin>>ele;
					f.add_end(ele);
					break;
				}
			case 9:
				{
					f.remove_end();
					break;
				}
			case 10:
				{
					float x,y;
					cout<<"\nEnter the element you want to insert :";
					cin>>x;
					cout<<"\nEnter the element after which you want to enter "<<x<<"  :";
					cin>>y;
					f.add_after_y(x,y);
					break;
				}
			case 11:
				{
					float x,y;
					cout<<"\nEnter the element you want to insert :";
					cin>>x;
					cout<<"\nEnter the element before which you want to enter "<<x<<"  : ";
					cin>>y;
					f.add_before_y(x,y);
					break;
				}
			case 12:
				{
					f.reverse();
					break;
				}
				
					default:
					cout<<"\nWrong Choice";
				}
				cout<<"\nDo you want more opeartion to perform then press y or Y : ";
				cin>>ans;
			}while(ans=='y'||ans=='Y');
		break;
		}
		getch();
		return 0;
	}
}

/*
OUTPUT

 Data types:
1.int
2.char
3.float
Enter your choice for same :2

MENU:
1.add_front()-add the at the beginning of the list
2.add_element()-add element at given position
3.remove_front()-remove an element from the front
4.remove_element()-remove the element at i position from the list
5.search()-search for the given element in the list
6.concatenate()-concatenate two singly linked lists
7.display()-display the elements of the list
8.add_end()-to insert the element at the end of list
9.remove_end()-to remove the element from the end of list
10.add_after_y()- to Insert an element x after an element y in the singly linked list
11.add_before_y()-to Insert an element x before an element y in the singly linked list
12.reverse() - to reverse the singly linkrd list
Enter Your Choice :8

Enter the element you want to add at the back of list : a

Do you want more opeartion to perform then press y or Y : y

MENU:
1.add_front()-add the at the beginning of the list
2.add_element()-add element at given position
3.remove_front()-remove an element from the front
4.remove_element()-remove the element at i position from the list
5.search()-search for the given element in the list
6.concatenate()-concatenate two singly linked lists
7.display()-display the elements of the list
8.add_end()-to insert the element at the end of list
9.remove_end()-to remove the element from the end of list
10.add_after_y()- to Insert an element x after an element y in the singly linked list
11.add_before_y()-to Insert an element x before an element y in the singly linked list
12.reverse() - to reverse the singly linkrd list
Enter Your Choice :8

Enter the element you want to add at the back of list : b

Do you want more opeartion to perform then press y or Y : y

MENU:
1.add_front()-add the at the beginning of the list
2.add_element()-add element at given position
3.remove_front()-remove an element from the front
4.remove_element()-remove the element at i position from the list
5.search()-search for the given element in the list
6.concatenate()-concatenate two singly linked lists
7.display()-display the elements of the list
8.add_end()-to insert the element at the end of list
9.remove_end()-to remove the element from the end of list
10.add_after_y()- to Insert an element x after an element y in the singly linked list
11.add_before_y()-to Insert an element x before an element y in the singly linked list
12.reverse() - to reverse the singly linkrd list
Enter Your Choice :7

Elements of the linked lists are:   a  b

Do you want more opeartion to perform then press y or Y : y

MENU:
1.add_front()-add the at the beginning of the list
2.add_element()-add element at given position
3.remove_front()-remove an element from the front
4.remove_element()-remove the element at i position from the list
5.search()-search for the given element in the list
6.concatenate()-concatenate two singly linked lists
7.display()-display the elements of the list
8.add_end()-to insert the element at the end of list
9.remove_end()-to remove the element from the end of list
10.add_after_y()- to Insert an element x after an element y in the singly linked list
11.add_before_y()-to Insert an element x before an element y in the singly linked list
12.reverse() - to reverse the singly linkrd list
Enter Your Choice :1

Enter the element to insert in the list: c

Do you want more opeartion to perform then press y or Y : y

MENU:
1.add_front()-add the at the beginning of the list
2.add_element()-add element at given position
3.remove_front()-remove an element from the front
4.remove_element()-remove the element at i position from the list
5.search()-search for the given element in the list
6.concatenate()-concatenate two singly linked lists
7.display()-display the elements of the list
8.add_end()-to insert the element at the end of list
9.remove_end()-to remove the element from the end of list
10.add_after_y()- to Insert an element x after an element y in the singly linked list
11.add_before_y()-to Insert an element x before an element y in the singly linked list
12.reverse() - to reverse the singly linkrd list
Enter Your Choice :7

Elements of the linked lists are:   c  a  b

Do you want more opeartion to perform then press y or Y : y

MENU:
1.add_front()-add the at the beginning of the list
2.add_element()-add element at given position
3.remove_front()-remove an element from the front
4.remove_element()-remove the element at i position from the list
5.search()-search for the given element in the list
6.concatenate()-concatenate two singly linked lists
7.display()-display the elements of the list
8.add_end()-to insert the element at the end of list
9.remove_end()-to remove the element from the end of list
10.add_after_y()- to Insert an element x after an element y in the singly linked list
11.add_before_y()-to Insert an element x before an element y in the singly linked list
12.reverse() - to reverse the singly linkrd list
Enter Your Choice :9

Do you want more opeartion to perform then press y or Y : y

MENU:
1.add_front()-add the at the beginning of the list
2.add_element()-add element at given position
3.remove_front()-remove an element from the front
4.remove_element()-remove the element at i position from the list
5.search()-search for the given element in the list
6.concatenate()-concatenate two singly linked lists
7.display()-display the elements of the list
8.add_end()-to insert the element at the end of list
9.remove_end()-to remove the element from the end of list
10.add_after_y()- to Insert an element x after an element y in the singly linked list
11.add_before_y()-to Insert an element x before an element y in the singly linked list
12.reverse() - to reverse the singly linkrd list
Enter Your Choice :7

Elements of the linked lists are:   c  a

Do you want more opeartion to perform then press y or Y : y

MENU:
1.add_front()-add the at the beginning of the list
2.add_element()-add element at given position
3.remove_front()-remove an element from the front
4.remove_element()-remove the element at i position from the list
5.search()-search for the given element in the list
6.concatenate()-concatenate two singly linked lists
7.display()-display the elements of the list
8.add_end()-to insert the element at the end of list
9.remove_end()-to remove the element from the end of list
10.add_after_y()- to Insert an element x after an element y in the singly linked list
11.add_before_y()-to Insert an element x before an element y in the singly linked list
12.reverse() - to reverse the singly linkrd list
Enter Your Choice :10

Enter the element you want to insert : t

Enter the element after which you want to enter t  : a

Do you want more opeartion to perform then press y or Y : y

MENU:
1.add_front()-add the at the beginning of the list
2.add_element()-add element at given position
3.remove_front()-remove an element from the front
4.remove_element()-remove the element at i position from the list
5.search()-search for the given element in the list
6.concatenate()-concatenate two singly linked lists
7.display()-display the elements of the list
8.add_end()-to insert the element at the end of list
9.remove_end()-to remove the element from the end of list
10.add_after_y()- to Insert an element x after an element y in the singly linked list
11.add_before_y()-to Insert an element x before an element y in the singly linked list
12.reverse() - to reverse the singly linkrd list
Enter Your Choice :7

Elements of the linked lists are:   c  a  t

Do you want more opeartion to perform then press y or Y : y

MENU:
1.add_front()-add the at the beginning of the list
2.add_element()-add element at given position
3.remove_front()-remove an element from the front
4.remove_element()-remove the element at i position from the list
5.search()-search for the given element in the list
6.concatenate()-concatenate two singly linked lists
7.display()-display the elements of the list
8.add_end()-to insert the element at the end of list
9.remove_end()-to remove the element from the end of list
10.add_after_y()- to Insert an element x after an element y in the singly linked list
11.add_before_y()-to Insert an element x before an element y in the singly linked list
12.reverse() - to reverse the singly linkrd list
Enter Your Choice :11

Enter the element you want to insert :b

Enter the element before which you want to enter b  :a

Do you want more opeartion to perform then press y or Y : y

MENU:
1.add_front()-add the at the beginning of the list
2.add_element()-add element at given position
3.remove_front()-remove an element from the front
4.remove_element()-remove the element at i position from the list
5.search()-search for the given element in the list
6.concatenate()-concatenate two singly linked lists
7.display()-display the elements of the list
8.add_end()-to insert the element at the end of list
9.remove_end()-to remove the element from the end of list
10.add_after_y()- to Insert an element x after an element y in the singly linked list
11.add_before_y()-to Insert an element x before an element y in the singly linked list
12.reverse() - to reverse the singly linkrd list
Enter Your Choice :7

Elements of the linked lists are:   c  b  a  t

Do you want more opeartion to perform then press y or Y : y

MENU:
1.add_front()-add the at the beginning of the list
2.add_element()-add element at given position
3.remove_front()-remove an element from the front
4.remove_element()-remove the element at i position from the list
5.search()-search for the given element in the list
6.concatenate()-concatenate two singly linked lists
7.display()-display the elements of the list
8.add_end()-to insert the element at the end of list
9.remove_end()-to remove the element from the end of list
10.add_after_y()- to Insert an element x after an element y in the singly linked list
11.add_before_y()-to Insert an element x before an element y in the singly linked list
12.reverse() - to reverse the singly linkrd list
Enter Your Choice :12

Do you want more opeartion to perform then press y or Y : y

MENU:
1.add_front()-add the at the beginning of the list
2.add_element()-add element at given position
3.remove_front()-remove an element from the front
4.remove_element()-remove the element at i position from the list
5.search()-search for the given element in the list
6.concatenate()-concatenate two singly linked lists
7.display()-display the elements of the list
8.add_end()-to insert the element at the end of list
9.remove_end()-to remove the element from the end of list
10.add_after_y()- to Insert an element x after an element y in the singly linked list
11.add_before_y()-to Insert an element x before an element y in the singly linked list
12.reverse() - to reverse the singly linkrd list
Enter Your Choice :7

Elements of the linked lists are:   t  a  b  c

Do you want more opeartion to perform then press y or Y :
*/

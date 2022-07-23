//completed
//implementing the doubly linked list
#include<iostream>
#include<conio.h>
using namespace std;

template<class type>
class node
{
	public:
	type data;
	node<type> *next;
	node<type> *prev;
};
template<class type>
class Doublylinkedlist
{
	int n;
      public:
      	Doublylinkedlist();
	  void insertathead(const type&);
	  void insertati(int,const type&);
	  void insertatback(const type&);
	  void removefront();
	  void removefromi(int);
	  void removeback();
	  node<type>* searchx(const type&);
	  void concatenate(Doublylinkedlist<type>,Doublylinkedlist<type>,int);
	  void insertxaftery(const type&,const type&);
	  void middle();
	  void reverse();
	  void display();
	  private:
	  class  node<type> *header; 	
	   
};
//constructor
template<class type>
Doublylinkedlist<type>::Doublylinkedlist()
{
	n=0; //keep the trak of number of elements in the list
	header=new node<type>;
	header=NULL;
}
//insert at the beginning of the list
template<class type>
void Doublylinkedlist<type>::insertathead(const type& element)
{
	 class node<type> *v=new node<type>;
//if no element is there means inserting the first node
	if(header==NULL)
	{
   v->data=element;
   v->next=NULL;
   v->prev=NULL;
   header=v;
   n++;
   }
//insert when there are more than one element in the list
   else
   {
   	v->data=element;
   	v->prev=NULL;
   	v->next=header;
   	header->prev=v;
   	header=v;
   	n++;
   }
}
//insert an element at the given position say i
template<class type>
void Doublylinkedlist<type>::insertati(int i,const type& element)
{
		node<type> *v=new node<type>;
	v->data=element;
	node<type> *temp=header;
//if list is empty
	if(header==NULL)
	{
		cout<<"\n\nDoubly linked list is empty";
	}
//if elements are there in the list
	else
	{
   int count=1;
//insert at the position greater than 1 and till the last position of the list
   if((i<=n) && (i>1))
   {
   while(count<i-1)
   {
   	  temp=temp->next;
   	  count++;
   }
   v->next=temp->next;
   v->prev=temp;
   temp->next->prev=v;	
   temp->next=v;
   n++;
  }
//inserting the element at the 1st position  i.e. at the head of the list 
  else if(i==1)
  {
  	v->prev=NULL;
  	v->next=temp;
  	temp->prev=v;
  	header=v;
  	n++;
  }
//if the given position is larger than the size of list
    else 
  {
  	cout<<"\n\nSize of doubly linked list exceed.";
  }
   }
}
//insert the element at the back of the list
template<class type>
void Doublylinkedlist<type>::insertatback(const type& element)
{
	node<type> *v=new node<type>;
	v->data=element;
	v->next=NULL;
//when list is empty
//if the very first element is added at the back of the list
	if (header==NULL)
	{
		v->prev=NULL;
		header=v;
		n++;
	}
//when list contain more than 1 elements then adding at the back of the list
	else
	{
	node<type> *temp=header;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	v->prev=temp;
	temp->next=v;
	n++;
   }
}
//remove the element from the very beginning of the list
template<class type>
void Doublylinkedlist<type>::removefront()
{
//if the lsit is empty
	if(header==NULL)
	{
		cout<<"\n\nDoubly Linked List is empty.";
	}
//if the list has only one element
	else if(n==1)
	{
		node<type> * old=NULL;
		old=header;
		header=NULL;
		delete old;
		n--;
	}
//delete from head of the list when there are more than 1 elements in the list
	else
	{
	node<type> * old=NULL;
	old=header;
	header=old->next;
	header->prev=NULL;
	delete old;
	n--;
  }
}
//remove the element from the given position
template<class type>
void Doublylinkedlist<type>::removefromi(int i)
{
	node<type> *temp=header;
	node<type> *old=NULL;
	int count=1;
//if the list is empty
	if(header==NULL)
	{
		cout<<"\n\nDoubly Linked List is empty.";
	}
	else
	{
//delete when position is between greater than 1 and n-1(the node before the last node)
		if(i>1 && i<n)
		{
	   while(count<i-1)
	   {
	      temp=temp->next;
		  count++;	
	   }
	   old=temp->next;
	   old->prev->next=old->next;
	   old->next->prev=old->prev;
	   delete old;
	   n--;
     }
//when the given position is greater than the size of list
     else if(i>n)
     {
     		cout<<"\n\nSize of doubly linked list exceed.";
	 }
//when only one element is present in the list
	  else if(n==1)
	 {
	 	temp=header;
	 	header=NULL;
	 	delete temp;
	 	n--;
	 }
//when the given position to delete is last position i.e. the deleting the last node
	 else if(i==n)
	 {
	 	node<type> *temp=header;
	 	while(temp->next!=NULL)
	 	{
	 		temp=temp->next;
		 }
		 old=temp;
		 old->prev->next=NULL;
		 delete old;
		 n--;
	 }
//deleting when position is very first i.e from the head of the list
     else
     {
    node<type> *temp=header;
    temp->next->prev=NULL;
    header=temp->next;
    delete temp;
	n--;
	 }
	}
}
//deleting from the back of the back of the list
template<class type>
void Doublylinkedlist<type>::removeback()
{
	node<type> *temp=header;
	node<type> * old=NULL;
//when the list is empty
	if(header==NULL)
	{
		cout<<"\n\nDoubly Linked List is empty.";
	}
//when only one element present in the list
	else if(n==1)
	{
		old=header;
		header=NULL;
		delete old;
		n--;
	}
//delete when more than one elements are present in the list
	else
	{
	 while(temp->next!=NULL)
	 {
	 	temp=temp->next;
	 }
	 old=temp;
	 old->prev->next=NULL;
	 delete old;
	n--;
  }
}
//search for the given element in the list
template<class type>
node<type>* Doublylinkedlist<type>::searchx(const type& element)
{
	node<type> *temp=header;
	int count=1;
//when the list is empty
	if(header==NULL)
	{
		cout<<"\n\nDoubly Linked List is empty.";
	}
//searching the given element	
	else
	{
//traverse through the list to search the element
	while(temp!=NULL)
	{
//if element is found
	  if(temp->data==element)
	  {
	  	cout<<"\n\nElement "<<element<<" found at the "<<count<<" position";
	  	return temp;
	  	break;
	 }
//if not found then keep traversing
	 else
	 {	
	 temp=temp->next;
	 count++;
    }
	}
//if the element is not found
   if(temp==NULL)
   {
   	temp=NULL;
   	return temp;
   	cout<<"\n\nElement "<<element<<" not found in the list";
	   }	
	}
}
//concatenate two doubly linked lists
template<class type>
void Doublylinkedlist<type>::concatenate(Doublylinkedlist<type> L1,Doublylinkedlist<type> L2,int m)
{
	node<type> *head1=L1.header;
	node<type> *head2=L2.header;
//if first list is empty
	if(head1==NULL)
	{
      cout<<"\n\nThe first list is empty.";
	}
//if second list is empty
	 if(head2==NULL)
	{
		cout<<"\n\nThe second list is empty.";
	}
	//concatenating
	else 
	{
	while(head1->next!=NULL)
	{
		head1=head1->next;
	}
	head2->prev=head1;
	head1->next=head2;
		n+=m;
   }
}
//insert an element x after y
template<class type>
void Doublylinkedlist<type>::insertxaftery(const type& x,const type&y)
{
	node<type> *temp=header;
	node<type> *v=new node<type>;
	v->data=x;
	//when the list is empty
	if(header==NULL)
	{
		cout<<"\n\nDoubly Linked List is empty.";
	}
	else
	{
		while(temp!=NULL)
		{
//when y is found
			if(temp->data==y)
			{
	//if the element x is added at the end i.e the value y exist at the end
				if(temp->next==NULL)
				{
				v->prev=temp;
				v->next=NULL;
				temp->next=v;
				n++;
				break;	
				}
	//adding element x after y other than last node
				else
				{
			v->prev=temp;
			v->next=temp->next;
			temp->next->prev=v;
		    temp->next=v;
			n++;	
		    break;
		     }
			}
//traversing the list until y is found
			else
			{
			temp=temp->next;
		    }
		}
//if y is not found
	  if(temp==NULL)
	  {
	  	cout<<"\n\nElement "<<y<<" not found in the list.";
	  }
	}
}
//finding the middle element of the list
template<class type>
void Doublylinkedlist<type>::middle()
{
	int p=0;
	node<type> *temp=header;
// if list is empty
	if(header==NULL)
	cout<<"\n\nDoubly linked list is empty.";
//if only one node is present in the list
   if(n==1)
   {
   	cout<<"\n\nSince only one node is present in the list\nThere is no middle element in the list";
   }
//if only two nodes are present in the list
   else if(n==2)
   {
   	cout<<"\n\nSince only two nodes are present in the list\nThere is no middle element in the list";
   }
// if number of nodes are odd there will be only one middle element
	else if(n%2==1)
	{
	int m=(n/2)+1;	
	while(p<m)
	{
		temp=temp->next;
		p++;
	}
	cout<<"\n\nThe middle of the list is:- "<<temp->prev->data;
	}
//if the number of nodes are even in the list there will be two middle elements
	else if(n%2==0)
	{
		int m=n/2;
			while(p<m)
	{
		temp=temp->next;
		p++;
	}
	cout<<"\n\nSince the number of nodes in the list are even there will be two middle elements.";
	cout<<"\nThe middle of the lists are:- "<<temp->prev->data<<"  "<<temp->data;
	}
}
//reversing the doubly linked list using an additional list
 template<class type>
void Doublylinkedlist<type>::reverse()
{
	Doublylinkedlist<type>k;
	node<type> *newhead=NULL;
	node<type> *curr=header;
	node<type> *next=NULL; 
	// if list is empty
	if(header==NULL)
	cout<<"\n\nDoubly Linked List is empty.";
	//if only one node is present in the list
	else if(n==1)
	cout<<"\n\nNo reversing can take place.Only one node is present in the list.";
	//else reversing the list
	else
	{
	while(curr!=NULL)
	{
		next=curr->next;
		k.insertathead(curr->data);
		curr=next;
		}
	header=curr;	
	//nDisplaying the reverse linked list
	cout<<"\n\nAfter reversing the linked list the new reverse doubly linked list is:- ";
	k.display();
	}
}
//display the contents of the doubly linked list
template<class type>
void Doublylinkedlist<type>::display()
{
	if(header==NULL)
	{
		cout<<"\n\nDoubly Linked List is empty.\nNo element to display";
	}
	else
	{
	node<type> *temp=header;
	while(temp->next!=NULL)
	{
		cout<<temp->data<<"  ";
		temp=temp->next;
	}
	cout<<temp->data<<"  ";
  }
}

int main()
{
	 Doublylinkedlist<int> i;
	 Doublylinkedlist<int> i2;
	 Doublylinkedlist<char> c;
     Doublylinkedlist<char> c2;	 
     Doublylinkedlist<float> f;
	 Doublylinkedlist<float> f2;	 	 
	int choice,choose;
	char ans;
	cout<<"\nEnter your data type:-\n1.int\n2.char\n3.float ";
	cout<<"\n\nEnter your data type:- "; 
	cin>>choose;
	switch(choose)
	{
		case 1:
			{
			do
			{
				cout<<"\n\nEnter your choice:- \n1.insertathead()-add to the front of the list\n2.insertati()-insert the element at the i position\n3.insertatback()-insert the element at the back of the list.\n4.removefront()-remove the element from the beginning of the list.\n5.removefromi()-remove the element from the user given position.\n6.removeback()-remove the element from the back of the list.\n7.searchx()-to search for the given element in the list.\n8.concatenate()-concatenate two doubly linked lists.\n9.insertxaftery()-insert an element x after y.\n10.middle()-to find the middle of the list.\n11.reverse()-revesing the doubly linked list using an additional linked list.\n12.display()-display the elements of the list";
				cout<<"\n\nYour choice please:- ";
				cin>>choice;
				switch(choice)
				{
					case 1:
						{
							int ele;
							cout<<"\n\nEnter the element you want to enter at the front of the list:- ";
							cin>>ele;
							i.insertathead(ele);
							break;
						}
					case 2:
						{
							int pos,ele;
							cout<<"\n\nEnter the position at which you want to enter:- ";
							cin>>pos;
							cout<<"\n\nEnter the element you want to enter:- ";
							cin>>ele;
						    i.insertati(pos,ele);
						    break;
						}
					case 3:
						{
							int ele;
							cout<<"\n\nEnter the element you want to enter at the back the list:- ";
							cin>>ele;
							i.insertatback(ele);
							break;
						}
					case 4:
						{
							i.removefront();
							break;
						}
					case 5:
						{
						int pos;
						cout<<"\nEnter the position from which you want to delete the element:- ";
						cin>>pos;	
						i.removefromi(pos);
						break;
						}
					case 6:
						{
							i.removeback();
							break;
						}
					case 7:
						{
							int ele;
							cout<<"\n\nEnter the element you want to search in the list:- ";
							cin>>ele;
							node<int> *u=i.searchx(ele);
							cout<<"\n\nPointer of the search element is:- "<<u;
							break;
						}
					case 8:
						{
							int n,k=0,ele;
							cout<<"\n\nEnter how many elements you want to add in the second list:- ";
							cin>>n;
							if(n>1)
							cout<<"\n\nEnter the elements of the second list:- ";
							while(k<n)
							{
								cin>>ele;
								i2.insertatback(ele);
								k++;
							}
							cout<<"\n\nThe elements of the first lists are:- ";
							i.display();
							cout<<"\n\nThe elements of the second lists are:- ";
							i2.display();
							i.concatenate(i,i2,n);
							break;
						}
					case 9:
						{
							int x,y;
							cout<<"\n\nEnter the element to insert in the list:- ";
							cin>>x;
							cout<<"\n\nEnter the element after which you want to add "<<x<<" :- ";
							cin>>y;
							i.insertxaftery(x,y);
							break;
						}
						case 10:
							{
								i.middle();
								break;
							}
						case 11:
							{
								i.reverse();
								break;
							}
					case 12:
						{
							cout<<"\n\nElements of doubly linked list are:- ";
							i.display();
							break;
						}
					default:
						cout<<"\nWrong choice please reenter your choice:- ";
				}
				cout<<"\n\nDo you want more operation to perform on the list then press y:- ";
				cin>>ans;
			}while(ans=='y');
			break;
		}
				case 2:
					{
			do
			{
				cout<<"\n\nEnter your choice:- \n1.insertathead()-add to the front of the list\n2.insertati()-insert the element at the i position\n3.insertatback()-insert the element at the back of the list.\n4.removefront()-remove the element from the beginning of the list.\n5.removefromi()-remove the element from the user given position.\n6.removeback()-remove the element from the back of the list.\n7.searchx()-to search for the given element in the list.\n8.concatenate()-concatenate two doubly linked lists.\n9.insertxaftery()-insert an element x after y.\n10.middle()-to find the middle of the list..\n11.reverse()-revesing the doubly linked list using an additional linked list.\n12.display()-display the elements of the list";
				cout<<"\n\nYour choice please:- ";
				cin>>choice;
				switch(choice)
				{
					case 1:
						{
							char ele;
							cout<<"\n\nEnter the element you want to enter at the front of the list:- ";
							cin>>ele;
							c.insertathead(ele);
							break;
						}
					case 2:
						{
							int pos;
							char ele;
							cout<<"\n\nEnter the position at which you want to enter:- ";
							cin>>pos;
							cout<<"\n\nEnter the element you want to enter:- ";
							cin>>ele;
						    c.insertati(pos,ele);
						    break;
						}
					case 3:
						{
							char ele;
							cout<<"\n\nEnter the element you want to enter at the back the list:- ";
							cin>>ele;
							c.insertatback(ele);
							break;
						}
					case 4:
						{
							c.removefront();
							break;
						}
					case 5:
						{
						int pos;
						cout<<"\nEnter the position from which you want to delete the element:- ";
						cin>>pos;	
						c.removefromi(pos);
						break;
						}
					case 6:
						{
							c.removeback();
							break;
						}
					case 7:
						{
							char ele;
							cout<<"\n\nEnter the element you want to search in the list:- ";
							cin>>ele;
							node<char> *u=c.searchx(ele);
							cout<<"\n\nPointer of the search element is:- "<<u;
							break;
						}
					case 8:
						{
							int n,k=0;
							char ele;
							cout<<"\n\nEnter how many elements you want to add in the second list:- ";
							cin>>n;
							if(n>1)
							cout<<"\n\nEnter the elements of the second list:- ";
							while(k<n)
							{
								cin>>ele;
								c2.insertatback(ele);
								k++;
							}
							cout<<"\n\nThe elements of the first lists are:- ";
							c.display();
							cout<<"\n\nThe elements of the second lists are:- ";
							c2.display();
							c.concatenate(c,c2,n);
							break;
						}
					case 9:
						{
							char x,y;
							cout<<"\n\nEnter the element to insert in the list:- ";
							cin>>x;
							cout<<"\n\nEnter the element after which you want to add "<<x<<" :- ";
							cin>>y;
							c.insertxaftery(x,y);
							break;
						}
						case 10:
							{
								c.middle();
								break;
							}
						case 11:
							{
								c.reverse();
								break;
							}
					case 12:
						{
							cout<<"\n\nElements of doubly linked list are:- ";
							c.display();
							break;
						}
					default:
						cout<<"\nWrong choice please reenter your choice:- ";
				}
				cout<<"\n\nDo you want more operation to perform on the list then press y:- ";
				cin>>ans;
			}while(ans=='y');
			break;
		}
		case 3:
					{
			do
			{
				cout<<"\n\nEnter your choice:- \n1.insertathead()-add to the front of the list\n2.insertati()-insert the element at the i position\n3.insertatback()-insert the element at the back of the list.\n4.removefront()-remove the element from the beginning of the list.\n5.removefromi()-remove the element from the user given position.\n6.removeback()-remove the element from the back of the list.\n7.searchx()-to search for the given element in the list.\n8.concatenate()-concatenate two doubly linked lists.\n9.insertxaftery()-insert an element x after y.\n10.middle()-to find the middle of the list.\n11.reverse()-reversing the doubly linked list using an additional list.\n12.display()-display the elements of the list";
				cout<<"\n\nYour choice please:- ";
				cin>>choice;
				switch(choice)
				{
					case 1:
						{
							float ele;
							cout<<"\n\nEnter the element you want to enter at the front of the list:- ";
							cin>>ele;
							f.insertathead(ele);
							break;
						}
					case 2:
						{
							int pos;
							float ele;
							cout<<"\n\nEnter the position at which you want to enter:- ";
							cin>>pos;
							cout<<"\n\nEnter the element you want to enter:- ";
							cin>>ele;
						    f.insertati(pos,ele);
						    break;
						}
					case 3:
						{
							float ele;
							cout<<"\n\nEnter the element you want to enter at the back the list:- ";
							cin>>ele;
							f.insertatback(ele);
							break;
						}
					case 4:
						{
							f.removefront();
							break;
						}
					case 5:
						{
						int pos;
						cout<<"\nEnter the position from which you want to delete the element:- ";
						cin>>pos;	
						f.removefromi(pos);
						break;
						}
					case 6:
						{
							f.removeback();
							break;
						}
					case 7:
						{
							float ele;
							cout<<"\n\nEnter the element you want to search in the list:- ";
							cin>>ele;
							node<float> *u=f.searchx(ele);
							cout<<"\n\nPointer of the search element is:- "<<u;
							break;
						}
					case 8:
						{
							int n,k=0;
							float ele;
							cout<<"\n\nEnter how many elements you want to add in the second list:- ";
							cin>>n;
							if(n>1)
							cout<<"\n\nEnter the elements of the second list:- ";
							while(k<n)
							{
								cin>>ele;
								c2.insertatback(ele);
								k++;
							}
							cout<<"\n\nThe elements of the first lists are:- ";
							f.display();
							cout<<"\n\nThe elements of the second lists are:- ";
							f2.display();
							f.concatenate(f,f2,n);
							break;
						}
					case 9:
						{
							float x,y;
							cout<<"\n\nEnter the element to insert in the list:- ";
							cin>>x;
							cout<<"\n\nEnter the element after which you want to add "<<x<<" :- ";
							cin>>y;
							f.insertxaftery(x,y);
							break;
						}
						case 10:
							{
								f.middle();
								break;
							}
						case 11:
							{
								f.reverse();
								break;
							}
					case 12:
						{
							cout<<"\n\nElements of doubly linked list are:- ";
							f.display();
							break;
						}
					default:
						cout<<"\nWrong choice please reenter your choice:- ";
				}
				cout<<"\n\nDo you want more operation to perform on the list then press y:- ";
				cin>>ans;
			}while(ans=='y');
			break;
		}
		default:
			cout<<"\n\nWrong data type entered.";
	}
	getch();
	return 0;
}

/* OUTPUT
Enter your data type:-
1.int
2.char
3.float

Enter your data type:- 2


Enter your choice:-
1.insertathead()-add to the front of the list
2.insertati()-insert the element at the i position
3.insertatback()-insert the element at the back of the list.
4.removefront()-remove the element from the beginning of the list.
5.removefromi()-remove the element from the user given position.
6.removeback()-remove the element from the back of the list.
7.searchx()-to search for the given element in the list.
8.concatenate()-concatenate two doubly linked lists.
9.insertxaftery()-insert an element x after y.
10.middle()-to find the middle of the list.
11.display()-display the elements of the list

Your choice please:- 1


Enter the element you want to enter at the front of the list:- s


Do you want more operation to perform on the list then press y:- y


Enter your choice:-
1.insertathead()-add to the front of the list
2.insertati()-insert the element at the i position
3.insertatback()-insert the element at the back of the list.
4.removefront()-remove the element from the beginning of the list.
5.removefromi()-remove the element from the user given position.
6.removeback()-remove the element from the back of the list.
7.searchx()-to search for the given element in the list.
8.concatenate()-concatenate two doubly linked lists.
9.insertxaftery()-insert an element x after y.
10.middle()-to find the middle of the list.
11.display()-display the elements of the list

Your choice please:- 3


Enter the element you want to enter at the back the list:- h


Do you want more operation to perform on the list then press y:- y


Enter your choice:-
1.insertathead()-add to the front of the list
2.insertati()-insert the element at the i position
3.insertatback()-insert the element at the back of the list.
4.removefront()-remove the element from the beginning of the list.
5.removefromi()-remove the element from the user given position.
6.removeback()-remove the element from the back of the list.
7.searchx()-to search for the given element in the list.
8.concatenate()-concatenate two doubly linked lists.
9.insertxaftery()-insert an element x after y.
10.middle()-to find the middle of the list.
11.display()-display the elements of the list

Your choice please:- 3


Enter the element you want to enter at the back the list:- g


Do you want more operation to perform on the list then press y:- y


Enter your choice:-
1.insertathead()-add to the front of the list
2.insertati()-insert the element at the i position
3.insertatback()-insert the element at the back of the list.
4.removefront()-remove the element from the beginning of the list.
5.removefromi()-remove the element from the user given position.
6.removeback()-remove the element from the back of the list.
7.searchx()-to search for the given element in the list.
8.concatenate()-concatenate two doubly linked lists.
9.insertxaftery()-insert an element x after y.
10.middle()-to find the middle of the list.
11.display()-display the elements of the list

Your choice please:- 11


Elements of doubly linked list are:- s  h  g

Do you want more operation to perform on the list then press y:- y


Enter your choice:-
1.insertathead()-add to the front of the list
2.insertati()-insert the element at the i position
3.insertatback()-insert the element at the back of the list.
4.removefront()-remove the element from the beginning of the list.
5.removefromi()-remove the element from the user given position.
6.removeback()-remove the element from the back of the list.
7.searchx()-to search for the given element in the list.
8.concatenate()-concatenate two doubly linked lists.
9.insertxaftery()-insert an element x after y.
10.middle()-to find the middle of the list.
11.display()-display the elements of the list

Your choice please:- 2


Enter the position at which you want to enter:- 3


Enter the element you want to enter:- a


Do you want more operation to perform on the list then press y:- y


Enter your choice:-
1.insertathead()-add to the front of the list
2.insertati()-insert the element at the i position
3.insertatback()-insert the element at the back of the list.
4.removefront()-remove the element from the beginning of the list.
5.removefromi()-remove the element from the user given position.
6.removeback()-remove the element from the back of the list.
7.searchx()-to search for the given element in the list.
8.concatenate()-concatenate two doubly linked lists.
9.insertxaftery()-insert an element x after y.
10.middle()-to find the middle of the list.
11.display()-display the elements of the list

Your choice please:- 11


Elements of doubly linked list are:- s  h  a  g

Do you want more operation to perform on the list then press y:- y


Enter your choice:-
1.insertathead()-add to the front of the list
2.insertati()-insert the element at the i position
3.insertatback()-insert the element at the back of the list.
4.removefront()-remove the element from the beginning of the list.
5.removefromi()-remove the element from the user given position.
6.removeback()-remove the element from the back of the list.
7.searchx()-to search for the given element in the list.
8.concatenate()-concatenate two doubly linked lists.
9.insertxaftery()-insert an element x after y.
10.middle()-to find the middle of the list.
11.display()-display the elements of the list

Your choice please:- 8


Enter how many elements you want to add in the second list:- 2


Enter the elements of the second list:- u
n


The elements of the first lists are:- s  h  a  g

The elements of the second lists are:- u  n

Do you want more operation to perform on the list then press y:- y


Enter your choice:-
1.insertathead()-add to the front of the list
2.insertati()-insert the element at the i position
3.insertatback()-insert the element at the back of the list.
4.removefront()-remove the element from the beginning of the list.
5.removefromi()-remove the element from the user given position.
6.removeback()-remove the element from the back of the list.
7.searchx()-to search for the given element in the list.
8.concatenate()-concatenate two doubly linked lists.
9.insertxaftery()-insert an element x after y.
10.middle()-to find the middle of the list.
11.display()-display the elements of the list

Your choice please:- 11


Elements of doubly linked list are:- s  h  a  g  u  n

Do you want more operation to perform on the list then press y:- y


Enter your choice:-
1.insertathead()-add to the front of the list
2.insertati()-insert the element at the i position
3.insertatback()-insert the element at the back of the list.
4.removefront()-remove the element from the beginning of the list.
5.removefromi()-remove the element from the user given position.
6.removeback()-remove the element from the back of the list.
7.searchx()-to search for the given element in the list.
8.concatenate()-concatenate two doubly linked lists.
9.insertxaftery()-insert an element x after y.
10.middle()-to find the middle of the list.
11.display()-display the elements of the list

Your choice please:- 7


Enter the element you want to search in the list:- g


Element g found at the 4 position

Pointer of the search element is:- 0xba3c20

Do you want more operation to perform on the list then press y:- y


Enter your choice:-
1.insertathead()-add to the front of the list
2.insertati()-insert the element at the i position
3.insertatback()-insert the element at the back of the list.
4.removefront()-remove the element from the beginning of the list.
5.removefromi()-remove the element from the user given position.
6.removeback()-remove the element from the back of the list.
7.searchx()-to search for the given element in the list.
8.concatenate()-concatenate two doubly linked lists.
9.insertxaftery()-insert an element x after y.
10.middle()-to find the middle of the list.
11.display()-display the elements of the list

Your choice please:- 10


Since the number of nodes in the list are even there will be two middle elements.
The middle of the lists are:- a  g

Do you want more operation to perform on the list then press y:- y


Enter your choice:-
1.insertathead()-add to the front of the list
2.insertati()-insert the element at the i position
3.insertatback()-insert the element at the back of the list.
4.removefront()-remove the element from the beginning of the list.
5.removefromi()-remove the element from the user given position.
6.removeback()-remove the element from the back of the list.
7.searchx()-to search for the given element in the list.
8.concatenate()-concatenate two doubly linked lists.
9.insertxaftery()-insert an element x after y.
10.middle()-to find the middle of the list.
11.display()-display the elements of the list

Your choice please:- 4


Do you want more operation to perform on the list then press y:- y


Enter your choice:-
1.insertathead()-add to the front of the list
2.insertati()-insert the element at the i position
3.insertatback()-insert the element at the back of the list.
4.removefront()-remove the element from the beginning of the list.
5.removefromi()-remove the element from the user given position.
6.removeback()-remove the element from the back of the list.
7.searchx()-to search for the given element in the list.
8.concatenate()-concatenate two doubly linked lists.
9.insertxaftery()-insert an element x after y.
10.middle()-to find the middle of the list.
11.display()-display the elements of the list

Your choice please:- 11


Elements of doubly linked list are:- h  a  g  u  n

Do you want more operation to perform on the list then press y:- y


Enter your choice:-
1.insertathead()-add to the front of the list
2.insertati()-insert the element at the i position
3.insertatback()-insert the element at the back of the list.
4.removefront()-remove the element from the beginning of the list.
5.removefromi()-remove the element from the user given position.
6.removeback()-remove the element from the back of the list.
7.searchx()-to search for the given element in the list.
8.concatenate()-concatenate two doubly linked lists.
9.insertxaftery()-insert an element x after y.
10.middle()-to find the middle of the list.
11.display()-display the elements of the list

Your choice please:- 2


Enter the position at which you want to enter:- 1


Enter the element you want to enter:- s


Do you want more operation to perform on the list then press y:- y


Enter your choice:-
1.insertathead()-add to the front of the list
2.insertati()-insert the element at the i position
3.insertatback()-insert the element at the back of the list.
4.removefront()-remove the element from the beginning of the list.
5.removefromi()-remove the element from the user given position.
6.removeback()-remove the element from the back of the list.
7.searchx()-to search for the given element in the list.
8.concatenate()-concatenate two doubly linked lists.
9.insertxaftery()-insert an element x after y.
10.middle()-to find the middle of the list.
11.display()-display the elements of the list

Your choice please:- 11


Elements of doubly linked list are:- s  h  a  g  u  n

Do you want more operation to perform on the list then press y:- y


Enter your choice:-
1.insertathead()-add to the front of the list
2.insertati()-insert the element at the i position
3.insertatback()-insert the element at the back of the list.
4.removefront()-remove the element from the beginning of the list.
5.removefromi()-remove the element from the user given position.
6.removeback()-remove the element from the back of the list.
7.searchx()-to search for the given element in the list.
8.concatenate()-concatenate two doubly linked lists.
9.insertxaftery()-insert an element x after y.
10.middle()-to find the middle of the list.
11.display()-display the elements of the list

Your choice please:- 5

Enter the position from which you want to delete the element:- 6


Do you want more operation to perform on the list then press y:- y


Enter your choice:-
1.insertathead()-add to the front of the list
2.insertati()-insert the element at the i position
3.insertatback()-insert the element at the back of the list.
4.removefront()-remove the element from the beginning of the list.
5.removefromi()-remove the element from the user given position.
6.removeback()-remove the element from the back of the list.
7.searchx()-to search for the given element in the list.
8.concatenate()-concatenate two doubly linked lists.
9.insertxaftery()-insert an element x after y.
10.middle()-to find the middle of the list.
11.display()-display the elements of the list

Your choice please:- 11


Elements of doubly linked list are:- s  h  a  g  u

Do you want more operation to perform on the list then press y:- y


Enter your choice:-
1.insertathead()-add to the front of the list
2.insertati()-insert the element at the i position
3.insertatback()-insert the element at the back of the list.
4.removefront()-remove the element from the beginning of the list.
5.removefromi()-remove the element from the user given position.
6.removeback()-remove the element from the back of the list.
7.searchx()-to search for the given element in the list.
8.concatenate()-concatenate two doubly linked lists.
9.insertxaftery()-insert an element x after y.
10.middle()-to find the middle of the list.
11.display()-display the elements of the list

Your choice please:- 3


Enter the element you want to enter at the back the list:- n

Enter your choice:-
1.insertathead()-add to the front of the list
2.insertati()-insert the element at the i position
3.insertatback()-insert the element at the back of the list.
4.removefront()-remove the element from the beginning of the list.
5.removefromi()-remove the element from the user given position.
6.removeback()-remove the element from the back of the list.
7.searchx()-to search for the given element in the list.
8.concatenate()-concatenate two doubly linked lists.
9.insertxaftery()-insert an element x after y.
10.middle()-to find the middle of the list..
11.reverse()-revesing the doubly linked list using an additional linked list.
12.display()-display the elements of the list

Your choice please:- 12


Elements of doubly linked list are:- s  h  a  g  u  n

Do you want more operation to perform on the list then press y:- y


Enter your choice:-
1.insertathead()-add to the front of the list
2.insertati()-insert the element at the i position
3.insertatback()-insert the element at the back of the list.
4.removefront()-remove the element from the beginning of the list.
5.removefromi()-remove the element from the user given position.
6.removeback()-remove the element from the back of the list.
7.searchx()-to search for the given element in the list.
8.concatenate()-concatenate two doubly linked lists.
9.insertxaftery()-insert an element x after y.
10.middle()-to find the middle of the list..
11.reverse()-revesing the doubly linked list using an additional linked list.
12.display()-display the elements of the list

Your choice please:- 11


After reversing the linked list the new reverse doubly linked list is:- n  u  g  a  h  s


*/

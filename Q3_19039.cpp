#include<iostream>
#include<conio.h>
using namespace std;

template<typename T>
class Node
{
	public:
		T data;
		Node<T> *next;
		Node(T data)
		{
			this->data = data;
			next = NULL;
		}
};




template<typename T>
class singly_LL
{
	Node<T> *head;
	Node<T> *head2;
	int size;
	
	public:
		singly_LL();
		void addFront(const T&);
		void addBetween(const T&, int);
		
		T removeFront();
		T removeBetween(int);
		
		void concatenate();
		int search(T);
		
		bool isEmpty();
		
		
	
};


template<typename T>
bool singly_LL<T>::isEmpty()
{
	return size==0;
}

template<typename T>
singly_LL<T>::singly_LL()
{
	head = NULL;
	size = 0;
	head2 = NULL;
	
}

template<typename T>
void singly_LL<T>::addFront(const T& ele)
{
	
	Node<T> *newN = new Node<T>(ele);
	head = newN;
	newN->next = NULL;
	size++;
}

template<typename T>
void singly_LL<T>::addBetween(const T& ele, int pos )
{	

	if(isEmpty())
	{
		addFront( ele);
	}
	Node<T> *newN = new Node<T>(ele);
	Node<T> *temp = head;
	
	for(int i=1;i<pos-1;i++)
	{	
		temp = temp->next;
	}
	newN->next = temp->next;
	temp->next = newN;
	size++;
	//cout<<size;
}

template<typename T>
T singly_LL<T>::removeFront()
{
	if(isEmpty())
	{
		return 0;
	}
	
	Node<T> *temp = head;
	head = temp->next;
	delete temp;
	size--;
	
}

template<typename T>
T singly_LL<T>::removeBetween(int pos)
{	
	Node<T> *old;
	Node<T> *temp = head;
	
	if(pos==1)
	{
		removeFront();
	}
	else if(isEmpty())
	{
		return 0;
	
	}
	else
	{
		
	for(int i=1;i<pos-1;i++)
	{	
		temp = temp->next;
	}
		old=temp;
	temp->next=old->next;
	delete old;
	size--;
	}
}

template<typename T>
int singly_LL<T>::search(T x) 
{
	int i=1;
	if(isEmpty())
	{
		return 0;
	}
	
	Node<T> *temp = head;
	while(temp->next!=NULL)
	{	
		if(temp->data == x)
		{
			return i;
			break;
		}
		temp= temp->next;
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



int main()
{
	singly_LL<int> s;
	singly_LL<char> c;
	singly_LL<float> f;
	
	
	
	
	
	
	
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
				s.addFront(value);
				break;
			}
		case 2:
			{
				int pos,element;
				cout<<"\nEnter the position at which you enter the element:- ";
				cin>>pos;
				cout<<"\nEnter the element you want to enter at given position:- ";
				cin>>element;
				s.addBetween(element, pos);
				break;
			}
		case 3:
			{
				s.removeFront();
				break;
			}
		case 4:
			{
				int pos;
				cout<<"\nEnter the position from which you want to remove the element:- ";
				cin>>pos;
				s.removeBetween(pos);
				break;
			}
			case 5:
				{
					int element;
					cout<<"\nEnter the element you want to search in the list:- ";
					cin>>element;
					s.search(element);
					break;
				}
		/*	case 6:
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
					s.input(ele);
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
				*/
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
				c.addFront(value);
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
				c.addBetween(element, pos);
				break;
			}
		case 3:
			{
				c.removeFront();
				break;
			}
		case 4:
			{
				int pos;
				cout<<"\nEnter the position from which you want to remove the element:- ";
				cin>>pos;
				c.removeBetween(pos);
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
			/*case 6:
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
				}*/
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
				f.addFront(value);
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
				f.addBetween(element, pos);
				break;
			}
		case 3:
			{
				f.removeFront();
				break;
			}
		case 4:
			{
				int pos;
				cout<<"\nEnter the position from which you want to remove the element:- ";
				cin>>pos;
				f.removeBetween(pos);
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
		/*	case 6:
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
				}*/
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
	
	s.addFront(10);
	s.search(10);
	
	s.addBetween(20,2);
	s.search(20);
	
	
	s.addBetween(30,3);
	s.search(30);
	s.addBetween(40,4);
	s.search(40);
	s.search(30);
	
	s.removeBetween(2);
	s.search(20);
	
	
	


	
	getch();
	return 0;
	*/

	
	
	
	
	

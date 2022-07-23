//implementation of Queue using a Circular Linked list
#include<iostream>
#include<conio.h>
#include"Circularlist_19007.cpp"
using namespace std;

template<class type>
class Linkedqueue
{
	circularlinkedlist<type> C;
	int n;
    public:
	Linkedqueue();
	int size() const;
	bool empty() const;
	const type& front();
	void enqueue(type&);
	void dequeue();	
	void display();
};
//constructor
template<class type>
Linkedqueue<type>::Linkedqueue()
{
	n=0;
}
//return the number of elements in the queue
template<class type>
int Linkedqueue<type>::size() const
{
	return n;
}
//tell if the queue is empty or not
template<class type>
bool Linkedqueue<type>::empty() const
{
	return n==0;
}
//return the front of the queue
template<class type>
const type& Linkedqueue<type>::front() 
{
	if(empty())
	{
	cout<<"\n\nQueue is empty.";
	return C.Front();
    }
	else
	{
		return C.Front();
	}
}
//add an element at the rear of the queue
template<class type>
void Linkedqueue<type>::enqueue(type& x)
{
	C.back(x);
	n++;
}
//deleting the element from the front of the queue
template<class type>
void Linkedqueue<type>::dequeue()
{
	if(n==0)
	cout<<"\n\nQueue is empty,\nNo element to delete";
	else
	{
		C.removefront();
		n--;
	}
}
//display the elements of the queue
template<class type>
void Linkedqueue<type>::display()
{
	if (n==0)
	cout<<"\n\nQueue is empty";
	else
	C.display();
}
int main()
{
	int ch,choose;
	char ans;
	cout<<"\nData Type are:-\n1.int\n2.char\n3.float";
	cout<<"\n\nYour Choice:- ";
	cin>>choose;
	switch(choose)
	{
		
		case 1:
			{
				Linkedqueue<int> q;
				do
				{
				cout<<"\n\nOperations on queue are:- \n1.size()-return the number of elements in the queue.\n2.empty()-tell if the queue is empty or not\n3.front()-return the front of the queue\n4.enqueue()-add an element at the rear end\n5.dequeue()-delete the element from the front of the queue\n6.display()-display the elements of the queue";
				cout<<"\n\nYour choice please:- ";
				cin>>ch;
				switch(ch)
				{
					case 1:
						{
						int k;
						k=q.size();
						cout<<"\n\nNumber of elements in the queue are:- "<<k;
						break;	
						}
					case 2:
						{
							int l=q.empty();
							if(l)
							cout<<"\nQueue is empty.";
							else
							cout<<"\n\nQueue is not empty.";
							break;
						}
					case 3:
						{
							int k=q.front();						 
							cout<<"\n\nThe front of the queue is:- "<<k;
							break;
						}
					case 4:
						{
							int x;
					         cout<<"\n\nEnter the element you want to add at the rear of the queue:- ";
					         cin>>x;
					         q.enqueue(x);
					         break;
					         
						}
					case 5:
						{
							q.dequeue();
							break;
						}
					case 6:
						{
							q.display();
							break;
						}
			      default:
			         cout<<"\nWrong choice.Re-enter your choice";
				}
			cout<<"\n\nDo you want more operation to perform on queue press y:- ";
			cin>>ans;
		}while(ans=='y');
		break;
		}
			case 2:
			{
				Linkedqueue<char> c;
				do
				{
				cout<<"\n\nOperations on queue are:- \n1.size()-return the number of elements in the queue.\n2.empty()-tell if the queue is empty or not\n3.front()-return the front of the queue\n4.enqueue()-add an element at the rear end\n5.dequeue()-delete the element from the front of the queue\n6.display()-display the elements of the queue";
				cout<<"\n\nYour choice please:- ";
				cin>>ch;
				switch(ch)
				{
					case 1:
						{
						int k;
						k=c.size();
						cout<<"\n\nNumber of elements in the queue are:- "<<k;
						break;	
						}
					case 2:
						{
							int l=c.empty();
							if(l)
							cout<<"\nQueue is empty.";
							else
							cout<<"\n\nQueue is not empty.";
							break;
						}
					case 3:
						{
							char k=c.front();						 
							cout<<"\n\nThe front of the queue is:- "<<k;
							break;
						}
					case 4:
						{
							char x;
					         cout<<"\n\nEnter the element you want to add at the rear of the queue:- ";
					         cin>>x;
					         c.enqueue(x);
					         break;
					         
						}
					case 5:
						{
							c.dequeue();
							break;
						}
					case 6:
						{
							c.display();
							break;
						}
			      default:
			         cout<<"\nWrong choice.Re-enter your choice";
				}
			cout<<"\n\nDo you want more operation to perform on queue press y:- ";
			cin>>ans;
		}while(ans=='y');
		break;
		}
			case 3:
			{
				Linkedqueue<float> f;
				do
				{
				cout<<"\n\nOperations on queue are:- \n1.size()-return the number of elements in the queue.\n2.empty()-tell if the queue is empty or not\n3.front()-return the front of the queue\n4.enqueue()-add an element at the rear end\n5.dequeue()-delete the element from the front of the queue\n6.display()-display the elements of the queue";
				cout<<"\n\nYour choice please:- ";
				cin>>ch;
				switch(ch)
				{
					case 1:
						{
						int k;
						k=f.size();
						cout<<"\n\nNumber of elements in the queue are:- "<<k;
						break;	
						}
					case 2:
						{
							int l=f.empty();
							if(l)
							cout<<"\nQueue is empty.";
							else
							cout<<"\n\nQueue is not empty.";
							break;
						}
					case 3:
						{
							float k=f.front();						 
							cout<<"\n\nThe front of the queue is:- "<<k;
							break;
						}
					case 4:
						{
							float x;
					         cout<<"\n\nEnter the element you want to add at the rear of the queue:- ";
					         cin>>x;
					         f.enqueue(x);
					         break;
					         
						}
					case 5:
						{
							f.dequeue();
							break;
						}
					case 6:
						{
							f.display();
							break;
						}
			      default:
			         cout<<"\nWrong choice.Re-enter your choice";
				}
			cout<<"\n\nDo you want more operation to perform on queue press y:- ";
			cin>>ans;
		}while(ans=='y');
		break;
		}
	       default:
			cout<<"\nWrong choice.Re-enter your choice";
	}
	getch();
	return 0;
}
/*Data Type are:-
1.int
2.char
3.float

Your Choice:- 1


Operations on queue are:-
1.size()-return the number of elements in the queue.
2.empty()-tell if the queue is empty or not
3.front()-return the front of the queue
4.enqueue()-add an element at the rear end
5.dequeue()-delete the element from the front of the queue
6.display()-display the elements of the queue

Your choice please:- 1


Number of elements in the queue are:- 0

Do you want more operation to perform on queue press y:- y


Operations on queue are:-
1.size()-return the number of elements in the queue.
2.empty()-tell if the queue is empty or not
3.front()-return the front of the queue
4.enqueue()-add an element at the rear end
5.dequeue()-delete the element from the front of the queue
6.display()-display the elements of the queue

Your choice please:- 4


Enter the element you want to add at the rear of the queue:- 5


Do you want more operation to perform on queue press y:- y


Operations on queue are:-
1.size()-return the number of elements in the queue.
2.empty()-tell if the queue is empty or not
3.front()-return the front of the queue
4.enqueue()-add an element at the rear end
5.dequeue()-delete the element from the front of the queue
6.display()-display the elements of the queue

Your choice please:- 3


The front of the queue is:- 5

Do you want more operation to perform on queue press y:- y


Operations on queue are:-
1.size()-return the number of elements in the queue.
2.empty()-tell if the queue is empty or not
3.front()-return the front of the queue
4.enqueue()-add an element at the rear end
5.dequeue()-delete the element from the front of the queue
6.display()-display the elements of the queue

Your choice please:- 4


Enter the element you want to add at the rear of the queue:- 6


Do you want more operation to perform on queue press y:- y


Operations on queue are:-
1.size()-return the number of elements in the queue.
2.empty()-tell if the queue is empty or not
3.front()-return the front of the queue
4.enqueue()-add an element at the rear end
5.dequeue()-delete the element from the front of the queue
6.display()-display the elements of the queue

Your choice please:- 4


Enter the element you want to add at the rear of the queue:- 7


Do you want more operation to perform on queue press y:- y


Operations on queue are:-
1.size()-return the number of elements in the queue.
2.empty()-tell if the queue is empty or not
3.front()-return the front of the queue
4.enqueue()-add an element at the rear end
5.dequeue()-delete the element from the front of the queue
6.display()-display the elements of the queue

Your choice please:- 8

Wrong choice.Re-enter your choice

Do you want more operation to perform on queue press y:- y


Operations on queue are:-
1.size()-return the number of elements in the queue.
2.empty()-tell if the queue is empty or not
3.front()-return the front of the queue
4.enqueue()-add an element at the rear end
5.dequeue()-delete the element from the front of the queue
6.display()-display the elements of the queue

Your choice please:- 6

Elements present are:-  5 6 7

Do you want more operation to perform on queue press y:- y


Operations on queue are:-
1.size()-return the number of elements in the queue.
2.empty()-tell if the queue is empty or not
3.front()-return the front of the queue
4.enqueue()-add an element at the rear end
5.dequeue()-delete the element from the front of the queue
6.display()-display the elements of the queue

Your choice please:- 3


The front of the queue is:- 5

Do you want more operation to perform on queue press y:- y


Operations on queue are:-
1.size()-return the number of elements in the queue.
2.empty()-tell if the queue is empty or not
3.front()-return the front of the queue
4.enqueue()-add an element at the rear end
5.dequeue()-delete the element from the front of the queue
6.display()-display the elements of the queue

Your choice please:- 1


Number of elements in the queue are:- 3

Do you want more operation to perform on queue press y:- y


Operations on queue are:-
1.size()-return the number of elements in the queue.
2.empty()-tell if the queue is empty or not
3.front()-return the front of the queue
4.enqueue()-add an element at the rear end
5.dequeue()-delete the element from the front of the queue
6.display()-display the elements of the queue

Your choice please:- 5


Do you want more operation to perform on queue press y:- y


Operations on queue are:-
1.size()-return the number of elements in the queue.
2.empty()-tell if the queue is empty or not
3.front()-return the front of the queue
4.enqueue()-add an element at the rear end
5.dequeue()-delete the element from the front of the queue
6.display()-display the elements of the queue

Your choice please:- 6

Elements present are:-  6 7

Do you want more operation to perform on queue press y:- y


Operations on queue are:-
1.size()-return the number of elements in the queue.
2.empty()-tell if the queue is empty or not
3.front()-return the front of the queue
4.enqueue()-add an element at the rear end
5.dequeue()-delete the element from the front of the queue
6.display()-display the elements of the queue

Your choice please:- 3


The front of the queue is:- 6

Do you want more operation to perform on queue press y:- y


Operations on queue are:-
1.size()-return the number of elements in the queue.
2.empty()-tell if the queue is empty or not
3.front()-return the front of the queue
4.enqueue()-add an element at the rear end
5.dequeue()-delete the element from the front of the queue
6.display()-display the elements of the queue

Your choice please:- 5


Do you want more operation to perform on queue press y:- y


Operations on queue are:-
1.size()-return the number of elements in the queue.
2.empty()-tell if the queue is empty or not
3.front()-return the front of the queue
4.enqueue()-add an element at the rear end
5.dequeue()-delete the element from the front of the queue
6.display()-display the elements of the queue

Your choice please:- 6

Elements present are:-  7

Do you want more operation to perform on queue press y:- y


Operations on queue are:-
1.size()-return the number of elements in the queue.
2.empty()-tell if the queue is empty or not
3.front()-return the front of the queue
4.enqueue()-add an element at the rear end
5.dequeue()-delete the element from the front of the queue
6.display()-display the elements of the queue

Your choice please:- 1


Number of elements in the queue are:- 1

Do you want more operation to perform on queue press y:- y


Operations on queue are:-
1.size()-return the number of elements in the queue.
2.empty()-tell if the queue is empty or not
3.front()-return the front of the queue
4.enqueue()-add an element at the rear end
5.dequeue()-delete the element from the front of the queue
6.display()-display the elements of the queue

Your choice please:- 5


Do you want more operation to perform on queue press y:- y


Operations on queue are:-
1.size()-return the number of elements in the queue.
2.empty()-tell if the queue is empty or not
3.front()-return the front of the queue
4.enqueue()-add an element at the rear end
5.dequeue()-delete the element from the front of the queue
6.display()-display the elements of the queue

Your choice please:- 6


Queue is empty

Do you want more operation to perform on queue press y:- y


Operations on queue are:-
1.size()-return the number of elements in the queue.
2.empty()-tell if the queue is empty or not
3.front()-return the front of the queue
4.enqueue()-add an element at the rear end
5.dequeue()-delete the element from the front of the queue
6.display()-display the elements of the queue

Your choice please:- 5


Queue is empty,
No element to delete

Do you want more operation to perform on queue press y:-

*/

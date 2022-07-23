#include<iostream>
#include<conio.h>
#include"DLL_19007.cpp"
using namespace std;

//exception class when dequeue is empty
class Queueempty:public exception
{
    public:
	char *what()
	{
	return "\nDouble Ended Queue is Empty ";	
	}	
};
template<class type>
class LinkedDequeue
{
	Doublylinkedlist<type> D;
	int n;
	public:
	LinkedDequeue()
	{
		n=0;
	}
	int size() const;
	bool empty() const;
	void front();
	void  back();
	void insertFront(const type&);
	void insertBack(const type&);
	void Output();
	void removeFront();
	void removeBack();
};
//return the number of elements in dequeue
template<class type>
int LinkedDequeue<type>::size() const
{
	return n;
}
//tell if dequeue is empty or not
template<class type>
bool LinkedDequeue<type>::empty() const
{
	return n==0;
}
//return the element at the front of the dequeue
template<class type>
void LinkedDequeue<type>::front()
{
	try
	{
	if(empty())
	throw Queueempty();
    }
    catch(Queueempty w)
    {
    	cout<<w.what()<<"\nSo there is no front of the dequeue at present"<<endl;
	}
	if(!empty())
	 cout<<"\n\nFront of the dequeue is:- "<<D.Front();
}
//return the element at the back  of the dequeue
template<class type>
void LinkedDequeue<type>::back()
{
	 try
	{
	if(empty())
	throw Queueempty();
    }
    catch(Queueempty w)
    {
    	cout<<w.what()<<"\nSo there is no back element  of the dequeue at present"<<endl;
	}
	if(!empty())
   cout<<"\n\nBack of the dequeue is:- "<<D.Back();
}
//insert element at the front of the dequeue
template<class type>
void LinkedDequeue<type>::insertFront(const type& value)
{
	D.insertathead(value);
	n++;
}
//insert element at the back of the dequeue
template<class type>
void LinkedDequeue<type>::insertBack(const type& value)
{
	D.insertatback(value);
	n++;
}
//remove the front element from the dequeue
template<class type>
void LinkedDequeue<type>::removeFront()
{
	 try
	{
	if(empty())
	throw Queueempty();
    }
    catch(Queueempty w)
    {
    	cout<<w.what()<<"\nSo there no element to delete"<<endl;
	}
	if(!empty())
    {
    	D.removefront();
    	n--;
	}
}
//remove the back element from the dequeue
template<class type>
void LinkedDequeue<type>::removeBack()
{
	 try
	{
	if(empty())
	throw Queueempty();
    }
    catch(Queueempty w)
    {
    	cout<<w.what()<<"\nSo there are no elements to delete"<<endl;
	}
	if(!empty())
    {
    	D.removeback();
    	n--;
	}
}
//display the elements of the dequeue
template<class type>
void LinkedDequeue<type>::Output()
{
	if(n==0)
	cout<<"\n\nDOuble ended queue is empty";
	else
	{
	cout<<"\n\nElements of the dequeue are:- ";
	D.display();
    }
}
int main()
{
	int choice,ch;
	char ans;
	cout<<"\nData Types are:- \n1.int\n2.char\n3.float";
	cout<<"\n\nYour Data Type please:- ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			{
				LinkedDequeue<int> i;
				do
				{
					cout<<"\n\nOperations on Double ended queue are:- \n1.size()-return number of elements in dequeue.\n2.empty()-tell if double ended queue is empty or not\n3.front()-return the front element of the dequeue\n4.back()-return the back element of the dequeue\n5.insertFront()-insert element ath the front of the dequeue\n6.insertBack()-insert element ath the back of the dequeue\n7.Output()-display the elements of the dequeue\n8.removeFront()-remove the front element from the dequeue\n9.removeBack()-remove the back element from the dequeue";
					cout<<"\n\nYour choice please:- ";
					cin>>ch;
					switch(ch)
					{
						case 1:
							{
								int k=i.size();
								cout<<"\n\nNumber of elements in double ended queue are:- "<<k;
								break;
							}
						case 2:
							{
								int k=i.empty();
								if(k)
								cout<<"\n\nDouble Ended Queue is empty.";
								else
								cout<<"\n\nDouble ended queue is not empty.";
								break;
							}
						case 3:
							{
								i.front();
								break;
							}
						case 4:
							{
								i.back();
								break;
							}
						case 5:
							{
								int value;
								cout<<"\n\nEnter the value you want to insert at the front of the dequeue:- ";
								cin>>value;
								i.insertFront(value);
								break;
							}
						case 6:
							{
								int value;
								cout<<"\n\nEnter the value you want to insert at the back of the dequeue:- ";
								cin>>value;
								i.insertBack(value);
								break;
							}
						case 7:
							{
								i.Output();
								break;
							}
						case 8:
							{
								i.removeFront();
								break;
							}
						case 9:
							{
								i.removeBack();
							}
					}
					cout<<"\n\nDo you want more opeartion to perform press y:- ";
					cin>>ans;
				}while(ans=='y');
				break;
			}
	case 2:
			{
				LinkedDequeue<char> c;
				do
				{
					cout<<"\n\nOperations on Double ended queue are:- \n1.size()-return number of elements in dequeue.\n2.empty()-tell if double ended queue is empty or not\n3.front()-return the front element of the dequeue\n4.back()-return the back element of the dequeue\n5.insertFront()-insert element ath the front of the dequeue\n6.insertBack()-insert element ath the back of the dequeue\n7.Output()-display the elements of the dequeue\n8.removeFront()-remove the front element from the dequeue\n9.removeBack()-remove the back element from the dequeue";
					cout<<"\n\nYour choice please:- ";
					cin>>ch;
					switch(ch)
					{
						case 1:
							{
								int k=c.size();
								cout<<"\n\nNumber of elements in double ended queue are:- "<<k;
								break;
							}
						case 2:
							{
								int k=c.empty();
								if(k)
								cout<<"\n\nDouble Ended Queue is empty.";
								else
								cout<<"\n\nDouble ended queue is not empty.";
								break;
							}
						case 3:
							{
								c.front();
								break;
							}
						case 4:
							{
								c.back();
								break;
							}
						case 5:
							{
								char value;
								cout<<"\n\nEnter the value you want to insert at the front of the dequeue:- ";
								cin>>value;
								c.insertFront(value);
								break;
							}
						case 6:
							{
								char value;
								cout<<"\n\nEnter the value you want to insert at the back of the dequeue:- ";
								cin>>value;
								c.insertBack(value);
								break;
							}
						case 7:
							{
								c.Output();
								break;
							}
						case 8:
							{
								c.removeFront();
								break;
							}
						case 9:
							{
								c.removeBack();
							}
					}
					cout<<"\n\nDo you want more opeartion to perform press y:- ";
					cin>>ans;
				}while(ans=='y');
				break;
			}
			case 3:
			{
				LinkedDequeue<float> f;
				do
				{
					cout<<"\n\nOperations on Double ended queue are:- \n1.size()-return number of elements in dequeue.\n2.empty()-tell if double ended queue is empty or not\n3.front()-return the front element of the dequeue\n4.back()-return the back element of the dequeue\n5.insertFront()-insert element ath the front of the dequeue\n6.insertBack()-insert element ath the back of the dequeue\n7.Output()-display the elements of the dequeue\n8.removeFront()-remove the front element from the dequeue\n9.removeBack()-remove the back element from the dequeue";
					cout<<"\n\nYour choice please:- ";
					cin>>ch;
					switch(ch)
					{
						case 1:
							{
								int k=f.size();
								cout<<"\n\nNumber of elements in double ended queue are:- "<<k;
								break;
							}
						case 2:
							{
								int k=f.empty();
								if(k)
								cout<<"\n\nDouble Ended Queue is empty.";
								else
								cout<<"\n\nDouble ended queue is not empty.";
								break;
							}
						case 3:
							{
								f.front();
								break;
							}
						case 4:
							{
								f.back();
								break;
							}
						case 5:
							{
								float value;
								cout<<"\n\nEnter the value you want to insert at the front of the dequeue:- ";
								cin>>value;
								f.insertFront(value);
								break;
							}
						case 6:
							{
								float value;
								cout<<"\n\nEnter the value you want to insert at the back of the dequeue:- ";
								cin>>value;
								f.insertBack(value);
								break;
							}
						case 7:
							{
								f.Output();
								break;
							}
						case 8:
							{
								f.removeFront();
								break;
							}
						case 9:
							{
								f.removeBack();
								break;
							}
					}
					cout<<"\n\nDo you want more opeartion to perform press y:- ";
					cin>>ans;
				}while(ans=='y');
				break;
			}
		default:
			cout<<"\n\nWrong Data type entered.";
	}
}

/*OUTPUT
Data Types are:-
1.int
2.char
3.float

Your Data Type please:- 1


Operations on Double ended queue are:-
1.size()-return number of elements in dequeue.
2.empty()-tell if double ended queue is empty or not
3.front()-return the front element of the dequeue
4.back()-return the back element of the dequeue
5.insertFront()-insert element ath the front of the dequeue
6.insertBack()-insert element ath the back of the dequeue
7.Output()-display the elements of the dequeue
8.removeFront()-remove the front element from the dequeue
9.removeBack()-remove the back element from the dequeue

Your choice please:- 5


Enter the value you want to insert at the front of the dequeue:- 3


Do you want more opeartion to perform press y:- y


Operations on Double ended queue are:-
1.size()-return number of elements in dequeue.
2.empty()-tell if double ended queue is empty or not
3.front()-return the front element of the dequeue
4.back()-return the back element of the dequeue
5.insertFront()-insert element ath the front of the dequeue
6.insertBack()-insert element ath the back of the dequeue
7.Output()-display the elements of the dequeue
8.removeFront()-remove the front element from the dequeue
9.removeBack()-remove the back element from the dequeue

Your choice please:- 5


Enter the value you want to insert at the front of the dequeue:- 4


Do you want more opeartion to perform press y:- y


Operations on Double ended queue are:-
1.size()-return number of elements in dequeue.
2.empty()-tell if double ended queue is empty or not
3.front()-return the front element of the dequeue
4.back()-return the back element of the dequeue
5.insertFront()-insert element ath the front of the dequeue
6.insertBack()-insert element ath the back of the dequeue
7.Output()-display the elements of the dequeue
8.removeFront()-remove the front element from the dequeue
9.removeBack()-remove the back element from the dequeue

Your choice please:- 7


Elements of the dequeue are:- 4  3

Do you want more opeartion to perform press y:- y


Operations on Double ended queue are:-
1.size()-return number of elements in dequeue.
2.empty()-tell if double ended queue is empty or not
3.front()-return the front element of the dequeue
4.back()-return the back element of the dequeue
5.insertFront()-insert element ath the front of the dequeue
6.insertBack()-insert element ath the back of the dequeue
7.Output()-display the elements of the dequeue
8.removeFront()-remove the front element from the dequeue
9.removeBack()-remove the back element from the dequeue

Your choice please:- 6


Enter the value you want to insert at the back of the dequeue:- 9


Do you want more opeartion to perform press y:- y


Operations on Double ended queue are:-
1.size()-return number of elements in dequeue.
2.empty()-tell if double ended queue is empty or not
3.front()-return the front element of the dequeue
4.back()-return the back element of the dequeue
5.insertFront()-insert element ath the front of the dequeue
6.insertBack()-insert element ath the back of the dequeue
7.Output()-display the elements of the dequeue
8.removeFront()-remove the front element from the dequeue
9.removeBack()-remove the back element from the dequeue

Your choice please:- 7


Elements of the dequeue are:- 4  3  9

Do you want more opeartion to perform press y:- y


Operations on Double ended queue are:-
1.size()-return number of elements in dequeue.
2.empty()-tell if double ended queue is empty or not
3.front()-return the front element of the dequeue
4.back()-return the back element of the dequeue
5.insertFront()-insert element ath the front of the dequeue
6.insertBack()-insert element ath the back of the dequeue
7.Output()-display the elements of the dequeue
8.removeFront()-remove the front element from the dequeue
9.removeBack()-remove the back element from the dequeue

Your choice please:- 6


Enter the value you want to insert at the back of the dequeue:- 10


Do you want more opeartion to perform press y:- y


Operations on Double ended queue are:-
1.size()-return number of elements in dequeue.
2.empty()-tell if double ended queue is empty or not
3.front()-return the front element of the dequeue
4.back()-return the back element of the dequeue
5.insertFront()-insert element ath the front of the dequeue
6.insertBack()-insert element ath the back of the dequeue
7.Output()-display the elements of the dequeue
8.removeFront()-remove the front element from the dequeue
9.removeBack()-remove the back element from the dequeue

Your choice please:- 7


Elements of the dequeue are:- 4  3  9  10

Do you want more opeartion to perform press y:- y


Operations on Double ended queue are:-
1.size()-return number of elements in dequeue.
2.empty()-tell if double ended queue is empty or not
3.front()-return the front element of the dequeue
4.back()-return the back element of the dequeue
5.insertFront()-insert element ath the front of the dequeue
6.insertBack()-insert element ath the back of the dequeue
7.Output()-display the elements of the dequeue
8.removeFront()-remove the front element from the dequeue
9.removeBack()-remove the back element from the dequeue

Your choice please:- 3


Front of the dequeue is:- 4

Do you want more opeartion to perform press y:- y


Operations on Double ended queue are:-
1.size()-return number of elements in dequeue.
2.empty()-tell if double ended queue is empty or not
3.front()-return the front element of the dequeue
4.back()-return the back element of the dequeue
5.insertFront()-insert element ath the front of the dequeue
6.insertBack()-insert element ath the back of the dequeue
7.Output()-display the elements of the dequeue
8.removeFront()-remove the front element from the dequeue
9.removeBack()-remove the back element from the dequeue

Your choice please:- 4


Back of the dequeue is:- 10

Do you want more opeartion to perform press y:- y


Operations on Double ended queue are:-
1.size()-return number of elements in dequeue.
2.empty()-tell if double ended queue is empty or not
3.front()-return the front element of the dequeue
4.back()-return the back element of the dequeue
5.insertFront()-insert element ath the front of the dequeue
6.insertBack()-insert element ath the back of the dequeue
7.Output()-display the elements of the dequeue
8.removeFront()-remove the front element from the dequeue
9.removeBack()-remove the back element from the dequeue

Your choice please:- 1


Number of elements in double ended queue are:- 4

Do you want more opeartion to perform press y:- y


Operations on Double ended queue are:-
1.size()-return number of elements in dequeue.
2.empty()-tell if double ended queue is empty or not
3.front()-return the front element of the dequeue
4.back()-return the back element of the dequeue
5.insertFront()-insert element ath the front of the dequeue
6.insertBack()-insert element ath the back of the dequeue
7.Output()-display the elements of the dequeue
8.removeFront()-remove the front element from the dequeue
9.removeBack()-remove the back element from the dequeue

Your choice please:- 8


Do you want more opeartion to perform press y:- y


Operations on Double ended queue are:-
1.size()-return number of elements in dequeue.
2.empty()-tell if double ended queue is empty or not
3.front()-return the front element of the dequeue
4.back()-return the back element of the dequeue
5.insertFront()-insert element ath the front of the dequeue
6.insertBack()-insert element ath the back of the dequeue
7.Output()-display the elements of the dequeue
8.removeFront()-remove the front element from the dequeue
9.removeBack()-remove the back element from the dequeue

Your choice please:- 7


Elements of the dequeue are:- 3  9  10

Do you want more opeartion to perform press y:- y


Operations on Double ended queue are:-
1.size()-return number of elements in dequeue.
2.empty()-tell if double ended queue is empty or not
3.front()-return the front element of the dequeue
4.back()-return the back element of the dequeue
5.insertFront()-insert element ath the front of the dequeue
6.insertBack()-insert element ath the back of the dequeue
7.Output()-display the elements of the dequeue
8.removeFront()-remove the front element from the dequeue
9.removeBack()-remove the back element from the dequeue

Your choice please:- 9


Do you want more opeartion to perform press y:- y


Operations on Double ended queue are:-
1.size()-return number of elements in dequeue.
2.empty()-tell if double ended queue is empty or not
3.front()-return the front element of the dequeue
4.back()-return the back element of the dequeue
5.insertFront()-insert element ath the front of the dequeue
6.insertBack()-insert element ath the back of the dequeue
7.Output()-display the elements of the dequeue
8.removeFront()-remove the front element from the dequeue
9.removeBack()-remove the back element from the dequeue

Your choice please:- 7


Elements of the dequeue are:- 3  9

Do you want more opeartion to perform press y:- y


Operations on Double ended queue are:-
1.size()-return number of elements in dequeue.
2.empty()-tell if double ended queue is empty or not
3.front()-return the front element of the dequeue
4.back()-return the back element of the dequeue
5.insertFront()-insert element ath the front of the dequeue
6.insertBack()-insert element ath the back of the dequeue
7.Output()-display the elements of the dequeue
8.removeFront()-remove the front element from the dequeue
9.removeBack()-remove the back element from the dequeue

Your choice please:- 1


Number of elements in double ended queue are:- 2

Do you want more opeartion to perform press y:- y


Operations on Double ended queue are:-
1.size()-return number of elements in dequeue.
2.empty()-tell if double ended queue is empty or not
3.front()-return the front element of the dequeue
4.back()-return the back element of the dequeue
5.insertFront()-insert element ath the front of the dequeue
6.insertBack()-insert element ath the back of the dequeue
7.Output()-display the elements of the dequeue
8.removeFront()-remove the front element from the dequeue
9.removeBack()-remove the back element from the dequeue

Your choice please:- 3


Front of the dequeue is:- 3

Do you want more opeartion to perform press y:- y


Operations on Double ended queue are:-
1.size()-return number of elements in dequeue.
2.empty()-tell if double ended queue is empty or not
3.front()-return the front element of the dequeue
4.back()-return the back element of the dequeue
5.insertFront()-insert element ath the front of the dequeue
6.insertBack()-insert element ath the back of the dequeue
7.Output()-display the elements of the dequeue
8.removeFront()-remove the front element from the dequeue
9.removeBack()-remove the back element from the dequeue

Your choice please:- 4


Back of the dequeue is:- 9

Do you want more opeartion to perform press y:- y


Operations on Double ended queue are:-
1.size()-return number of elements in dequeue.
2.empty()-tell if double ended queue is empty or not
3.front()-return the front element of the dequeue
4.back()-return the back element of the dequeue
5.insertFront()-insert element ath the front of the dequeue
6.insertBack()-insert element ath the back of the dequeue
7.Output()-display the elements of the dequeue
8.removeFront()-remove the front element from the dequeue
9.removeBack()-remove the back element from the dequeue

Your choice please:- 9


Do you want more opeartion to perform press y:- y


Operations on Double ended queue are:-
1.size()-return number of elements in dequeue.
2.empty()-tell if double ended queue is empty or not
3.front()-return the front element of the dequeue
4.back()-return the back element of the dequeue
5.insertFront()-insert element ath the front of the dequeue
6.insertBack()-insert element ath the back of the dequeue
7.Output()-display the elements of the dequeue
8.removeFront()-remove the front element from the dequeue
9.removeBack()-remove the back element from the dequeue

Your choice please:- 7


Elements of the dequeue are:- 3

Do you want more opeartion to perform press y:- y


Operations on Double ended queue are:-
1.size()-return number of elements in dequeue.
2.empty()-tell if double ended queue is empty or not
3.front()-return the front element of the dequeue
4.back()-return the back element of the dequeue
5.insertFront()-insert element ath the front of the dequeue
6.insertBack()-insert element ath the back of the dequeue
7.Output()-display the elements of the dequeue
8.removeFront()-remove the front element from the dequeue
9.removeBack()-remove the back element from the dequeue

Your choice please:- 9


Do you want more opeartion to perform press y:- y


Operations on Double ended queue are:-
1.size()-return number of elements in dequeue.
2.empty()-tell if double ended queue is empty or not
3.front()-return the front element of the dequeue
4.back()-return the back element of the dequeue
5.insertFront()-insert element ath the front of the dequeue
6.insertBack()-insert element ath the back of the dequeue
7.Output()-display the elements of the dequeue
8.removeFront()-remove the front element from the dequeue
9.removeBack()-remove the back element from the dequeue

Your choice please:- 7


DOuble ended queue is empty

Do you want more opeartion to perform press y:- y


Operations on Double ended queue are:-
1.size()-return number of elements in dequeue.
2.empty()-tell if double ended queue is empty or not
3.front()-return the front element of the dequeue
4.back()-return the back element of the dequeue
5.insertFront()-insert element ath the front of the dequeue
6.insertBack()-insert element ath the back of the dequeue
7.Output()-display the elements of the dequeue
8.removeFront()-remove the front element from the dequeue
9.removeBack()-remove the back element from the dequeue

Your choice please:- 9

Double Ended Queue is Empty
So there are no elements to delete


Do you want more opeartion to perform press y:-


*/

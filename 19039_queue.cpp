//implementation of queue using linear array representation
#include<iostream>
#include<conio.h>
#include<exception>
using namespace std;
//exception class when queue is empty
class Queueempty:public exception
{
    public:
	char *what()
	{
	return "\nQueue is Empty ";	
	}	
};
//exception class when queue is full
class Queuefull:public exception
{
    public:
	char *what()
	{
	return "\nQueue is Full ";	
	}	
};
//Queue class
template<class type>
class Queue
{
    	type *ar,n,f,r,size;
    	public:
    		Queue();
    		~Queue();
    		void input();
    		bool empty() const;
    		int Size() const;
    		const type& front();
    		void enqueue(const type element);
    		void display();
    		void dequeue();
};
//constructor
template<class type>
Queue<type>::Queue()
{
    f=-1;
	r=-1;
	n=0;
}
//destructor
template<class type>
Queue<type>::~Queue()
{
	delete []ar;
}
//taking the size of queue
template<class type>
void Queue<type>::input()
{
	cout<<"\nEnter the size of Queue:- ";
	cin>>size;
	ar=new int[size];
}
//check if queue is empty or not
template<class type>
bool Queue<type>::empty() const
{
   return f<0;
}
//return the number of elements of queue
template<class type>
int Queue<type>::Size() const
{
	return n;
}
//return the front of queue
template<class type>
const type& Queue<type>::front()
{
	try
	{
	if(empty())
	throw Queueempty();
    }
    catch(Queueempty w)
    {
    	cout<<w.what()<<"\nSo there is no front of the queue at present"<<endl;
	}
	if(!empty())
	cout<<"\nFront of the queue is:- "<<ar[f];
}
//add element at the rear of the queue
template<class type>
void Queue<type>::enqueue(const type element)
{
    try
	{
	  if(Size()==size)
	  throw Queuefull();
	 else if(f==-1 && r==-1)
	{
	f++;
	r++;
	n++;
	ar[r]=element; 
   }
	else
	{
	r++; 
	n++;
	ar[r]=element;	
	}
  }
	catch(Queuefull w)
	{
		cout<<w.what()<<"\nNo more element can be added in the queue\n ";
	}
}
//delete element from the rear of the queue
template<class type>
void Queue<type>::dequeue()
{
	try
	{
	if(empty())
	throw Queueempty();
	cout<<"\nDeleted element from the queue is:- "<<ar[f];
	if(f==r)
	{
		f=-1;
		r=-1;
		n=0;
	}
	else
	{
	   f++;
	   n--;	
	}
    }
    catch(Queueempty w)
    {
    	cout<<w.what()<<"\nNo element present for deletion.\n";
	}
}
//display the content of the queue
template<class type>
void Queue<type>::display()
{
	try
	{
		if(f==-1)
		throw Queueempty();
	else
	{
	cout<<"\nElements of the queue are:- ";
	for(int i=f;i<=r;i++)
	cout<<" "<<ar[i];
    }
   }
   catch(Queueempty w)
   {
   	cout<<w.what()<<"\nSo no element to display";
   }
}
int main()
{
	int ch;
	char ans;
	Queue<int> q;
	q.input();
	do
	{
		cout<<"\nEnter your choice\n1.empty()-return true if queue is empty.\n2.Size()-return the number of elements in the queue.\n3.front()-return the front element of queue\n4.enqueue()-add the element at the rear of the queue\n5.display()-display the elements of the queue\n6.dequeue()-delete the element from the rear of queue."; 
		cout<<"\nYour choice please:- ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				 {
				 	if(q.empty())
				 	cout<<"\n Queue is empty."<<endl;
				 	else
				 	cout<<"\n Queue is non-empty."<<endl;
				 	break;
			    }
			case 2:
				{
					cout<<"\nNumber of elements in the queue is:- "<<q.Size()<<endl;
					break;
				}
			case 3:
				{
					q.front();
					cout<<endl;
					break;
				}
			case 4:
				{
					int val;
					cout<<"\nEnter the element you want to add in the queue:- ";
					cin>>val;
					q.enqueue(val);
					break;
				}
			case 5:
				{
					q.display();
					cout<<endl;
					break;
				}
			case 6:
				{
					q.dequeue();
					break;
				}
			default:
				cout<<"\nWrong Choice. Please reenter your choice"<<endl;
		}
		cout<<"\nDo you want more operations to perfom press y:- ";
		cin>>ans;
	}while(ans=='y');
	getch();
	return 0;
}

/*
OUTPUT
Enter the size of Queue:- 4

Enter your choice
1.empty()-return true if queue is empty.
2.Size()-return the number of elements in the queue.
3.front()-return the front element of queue
4.enqueue()-add the element at the rear of the queue
5.display()-display the elements of the queue
6.dequeue()-delete the element from the rear of queue.
Your choice please:- 4

Enter the element you want to add in the queue:- 6

Do you want more operations to perfom press y:- y

Enter your choice
1.empty()-return true if queue is empty.
2.Size()-return the number of elements in the queue.
3.front()-return the front element of queue
4.enqueue()-add the element at the rear of the queue
5.display()-display the elements of the queue
6.dequeue()-delete the element from the rear of queue.
Your choice please:- 4

Enter the element you want to add in the queue:- 8

Do you want more operations to perfom press y:- y

Enter your choice
1.empty()-return true if queue is empty.
2.Size()-return the number of elements in the queue.
3.front()-return the front element of queue
4.enqueue()-add the element at the rear of the queue
5.display()-display the elements of the queue
6.dequeue()-delete the element from the rear of queue.
Your choice please:- 4

Enter the element you want to add in the queue:- 9

Do you want more operations to perfom press y:- y

Enter your choice
1.empty()-return true if queue is empty.
2.Size()-return the number of elements in the queue.
3.front()-return the front element of queue
4.enqueue()-add the element at the rear of the queue
5.display()-display the elements of the queue
6.dequeue()-delete the element from the rear of queue.
Your choice please:- 4

Enter the element you want to add in the queue:- 1

Do you want more operations to perfom press y:- y

Enter your choice
1.empty()-return true if queue is empty.
2.Size()-return the number of elements in the queue.
3.front()-return the front element of queue
4.enqueue()-add the element at the rear of the queue
5.display()-display the elements of the queue
6.dequeue()-delete the element from the rear of queue.
Your choice please:- 4

Enter the element you want to add in the queue:- 6

Queue is Full
No more element can be added in the queue

Do you want more operations to perfom press y:- y

Enter your choice
1.empty()-return true if queue is empty.
2.Size()-return the number of elements in the queue.
3.front()-return the front element of queue
4.enqueue()-add the element at the rear of the queue
5.display()-display the elements of the queue
6.dequeue()-delete the element from the rear of queue.
Your choice please:- 5

Elements of the queue are:-  6 8 9 1

Do you want more operations to perfom press y:- y

Enter your choice
1.empty()-return true if queue is empty.
2.Size()-return the number of elements in the queue.
3.front()-return the front element of queue
4.enqueue()-add the element at the rear of the queue
5.display()-display the elements of the queue
6.dequeue()-delete the element from the rear of queue.
Your choice please:- 2

Number of elements in the queue is:- 4

Do you want more operations to perfom press y:- y

Enter your choice
1.empty()-return true if queue is empty.
2.Size()-return the number of elements in the queue.
3.front()-return the front element of queue
4.enqueue()-add the element at the rear of the queue
5.display()-display the elements of the queue
6.dequeue()-delete the element from the rear of queue.
Your choice please:- 3

Front of the queue is:- 6

Do you want more operations to perfom press y:- y

Enter your choice
1.empty()-return true if queue is empty.
2.Size()-return the number of elements in the queue.
3.front()-return the front element of queue
4.enqueue()-add the element at the rear of the queue
5.display()-display the elements of the queue
6.dequeue()-delete the element from the rear of queue.
Your choice please:- 6

Deleted element from the queue is:- 6
Do you want more operations to perfom press y:- y

Enter your choice
1.empty()-return true if queue is empty.
2.Size()-return the number of elements in the queue.
3.front()-return the front element of queue
4.enqueue()-add the element at the rear of the queue
5.display()-display the elements of the queue
6.dequeue()-delete the element from the rear of queue.
Your choice please:- 6

Deleted element from the queue is:- 8
Do you want more operations to perfom press y:- y

Enter your choice
1.empty()-return true if queue is empty.
2.Size()-return the number of elements in the queue.
3.front()-return the front element of queue
4.enqueue()-add the element at the rear of the queue
5.display()-display the elements of the queue
6.dequeue()-delete the element from the rear of queue.
Your choice please:- 5

Elements of the queue are:-  9 1

Do you want more operations to perfom press y:- y

Enter your choice
1.empty()-return true if queue is empty.
2.Size()-return the number of elements in the queue.
3.front()-return the front element of queue
4.enqueue()-add the element at the rear of the queue
5.display()-display the elements of the queue
6.dequeue()-delete the element from the rear of queue.
Your choice please:- 6

Deleted element from the queue is:- 9
Do you want more operations to perfom press y:-
y

Enter your choice
1.empty()-return true if queue is empty.
2.Size()-return the number of elements in the queue.
3.front()-return the front element of queue
4.enqueue()-add the element at the rear of the queue
5.display()-display the elements of the queue
6.dequeue()-delete the element from the rear of queue.
Your choice please:- 6

Deleted element from the queue is:- 1
Do you want more operations to perfom press y:- y

Enter your choice
1.empty()-return true if queue is empty.
2.Size()-return the number of elements in the queue.
3.front()-return the front element of queue
4.enqueue()-add the element at the rear of the queue
5.display()-display the elements of the queue
6.dequeue()-delete the element from the rear of queue.
Your choice please:- 6

Queue is Empty
No element present for deletion.

Do you want more operations to perfom press y:-

*/

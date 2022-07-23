//program to implement circular queue
#include<iostream>
#include<conio.h>
#include<exception>
using namespace std;
//throw exception when Circular queue is empty
class CirQueueempty:public exception
{
    public:
	char *what()
	{
	return "\nCircular Queue is Empty ";	
	}	
};
//throw exception when Circular queue is full
class CirQueuefull:public exception
{
    public:
	char *what()
	{
	return "\nCircular Queue is Full ";	
	}	
};
//Circular Queue class
template<class type>
class CircularQueue
{
    	type *ar,n,f,r,size;
    	public:
    		CircularQueue();
    		~CircularQueue();
    		void input();
    		bool empty() const;
    		int Size() const;
    		const type& front();
    		void enqueue(const type element);
    		void display();
    		void dequeue();
};
//Constructor
template<class type>
CircularQueue<type>::CircularQueue()
{
    f=0;
	r=0;
	n=0;
}
//destructor
template<class type>
CircularQueue<type>::~CircularQueue()
{
	delete []ar;
}
//taking the size of circularqueue
template<class type>
void CircularQueue<type>::input()
{
	cout<<"\nEnter the size of Circular Queue:- ";
	cin>>size;
	ar=new int[size];
}
//if circular queue is empty or not
template<class type>
bool CircularQueue<type>::empty() const
{
   return n==0;
}
//return the number of elements in the circular queue
template<class type>
int CircularQueue<type>::Size() const
{
	return n;
}
//give the front of the circular queue
template<class type>
const type& CircularQueue<type>::front()
{
	try
	{
	if(empty())
	throw CirQueueempty();
    }
    catch(CirQueueempty w)
    {
    	cout<<w.what()<<"\nSo there is no front of the Circular queue at present"<<endl;
	}
	if(!empty())
	cout<<"\nFront of the queue is:- "<<ar[f];
}
//put element at the rear of the circular queue
template<class type>
void CircularQueue<type>::enqueue(const type element)
{
    try
	{
	  if(Size()==size)
	  throw CirQueuefull();
	else
	{
	ar[r]=	element;
	r=(r+1)%size; 
	n++;	
	}
  }
	catch(CirQueuefull w)
	{
		cout<<w.what()<<"\nNo more element can be added in the Circular queue\n ";
	}
}
//delete the element from the front of the circular queue
template<class type>
void CircularQueue<type>::dequeue()
{
	try
	{
	if(empty())
	throw CirQueueempty();
	else
	{
	   cout<<"\nDeleted element from the Circular queue is:- "<<ar[f]; 
	   f=(f+1)%size;
	   n=n-1;
	}
    }
    catch(CirQueueempty w)
    {
    	cout<<w.what()<<"\nNo element present for deletion.\n";
	}
}
//display the content of circular queue
template<class type>
void CircularQueue<type>::display()
{
	try
	{
		if(n==0)
		throw CirQueueempty();
	else
	{
	cout<<"\nElements of the Circular queue are:- ";
    if(r>f)
    {
    	for(int i=f;i<r;i++)
    	cout<<"\n"<<ar[i];
	}
	if(r<=f)
	{
		for(int i=f;i<size;i++)
    	cout<<"\n"<<ar[i];
    	for(int i=0;i<r;i++)
    	cout<<"\n"<<ar[i];
	}
    }
   }
   catch(CirQueueempty w)
   {
   	cout<<w.what()<<"\nSo no element to display";
   }
}
int main()
{
	int ch;
	char ans;
	CircularQueue<int> q;
	q.input();
	do
	{
		cout<<"\nEnter your choice\n1.empty()-return true if Circular queue is empty.\n2.Size()-return the number of elements in the Circular queue.\n3.front()-return the front element of Circular queue\n4.enqueue()-add the element at the rear of the Circular queue\n5.display()-display the elements of the Circular queue\n6.dequeue()-delete the element from the rear of Circular queue."; 
		cout<<"\nYour choice please:- ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				 {
				 	if(q.empty())
				 	cout<<"\n Circular Queue is empty."<<endl;
				 	else
				 	cout<<"\n Circular Queue is non-empty."<<endl;
				 	break;
			    }
			case 2:
				{
					cout<<"\nNumber of elements in the Circular queue is:- "<<q.Size()<<endl;
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
					cout<<"\nEnter the element you want to add in the Circular queue:- ";
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
Enter the size of Circular Queue:- 4

Enter your choice
1.empty()-return true if Circular queue is empty.
2.Size()-return the number of elements in the Circular queue.
3.front()-return the front element of Circular queue
4.enqueue()-add the element at the rear of the Circular queue
5.display()-display the elements of the Circular queue
6.dequeue()-delete the element from the rear of Circular queue.
Your choice please:- 4

Enter the element you want to add in the Circular queue:- 5

Do you want more operations to perfom press y:- y

Enter your choice
1.empty()-return true if Circular queue is empty.
2.Size()-return the number of elements in the Circular queue.
3.front()-return the front element of Circular queue
4.enqueue()-add the element at the rear of the Circular queue
5.display()-display the elements of the Circular queue
6.dequeue()-delete the element from the rear of Circular queue.
Your choice please:- 4

Enter the element you want to add in the Circular queue:- 6

Do you want more operations to perfom press y:- y

Enter your choice
1.empty()-return true if Circular queue is empty.
2.Size()-return the number of elements in the Circular queue.
3.front()-return the front element of Circular queue
4.enqueue()-add the element at the rear of the Circular queue
5.display()-display the elements of the Circular queue
6.dequeue()-delete the element from the rear of Circular queue.
Your choice please:- 4

Enter the element you want to add in the Circular queue:- 7

Do you want more operations to perfom press y:- y

Enter your choice
1.empty()-return true if Circular queue is empty.
2.Size()-return the number of elements in the Circular queue.
3.front()-return the front element of Circular queue
4.enqueue()-add the element at the rear of the Circular queue
5.display()-display the elements of the Circular queue
6.dequeue()-delete the element from the rear of Circular queue.
Your choice please:- 4

Enter the element you want to add in the Circular queue:- 8

Do you want more operations to perfom press y:- y

Enter your choice
1.empty()-return true if Circular queue is empty.
2.Size()-return the number of elements in the Circular queue.
3.front()-return the front element of Circular queue
4.enqueue()-add the element at the rear of the Circular queue
5.display()-display the elements of the Circular queue
6.dequeue()-delete the element from the rear of Circular queue.
Your choice please:- 5

Elements of the Circular queue are:-
5
6
7
8

Do you want more operations to perfom press y:- y

Enter your choice
1.empty()-return true if Circular queue is empty.
2.Size()-return the number of elements in the Circular queue.
3.front()-return the front element of Circular queue
4.enqueue()-add the element at the rear of the Circular queue
5.display()-display the elements of the Circular queue
6.dequeue()-delete the element from the rear of Circular queue.
Your choice please:- 4

Enter the element you want to add in the Circular queue:- 9

Circular Queue is Full
No more element can be added in the Circular queue

Do you want more operations to perfom press y:- y

Enter your choice
1.empty()-return true if Circular queue is empty.
2.Size()-return the number of elements in the Circular queue.
3.front()-return the front element of Circular queue
4.enqueue()-add the element at the rear of the Circular queue
5.display()-display the elements of the Circular queue
6.dequeue()-delete the element from the rear of Circular queue.
Your choice please:- 6

Deleted element from the Circular queue is:- 5
Do you want more operations to perfom press y:- y

Enter your choice
1.empty()-return true if Circular queue is empty.
2.Size()-return the number of elements in the Circular queue.
3.front()-return the front element of Circular queue
4.enqueue()-add the element at the rear of the Circular queue
5.display()-display the elements of the Circular queue
6.dequeue()-delete the element from the rear of Circular queue.
Your choice please:- 6

Deleted element from the Circular queue is:- 6
Do you want more operations to perfom press y:- y

Enter your choice
1.empty()-return true if Circular queue is empty.
2.Size()-return the number of elements in the Circular queue.
3.front()-return the front element of Circular queue
4.enqueue()-add the element at the rear of the Circular queue
5.display()-display the elements of the Circular queue
6.dequeue()-delete the element from the rear of Circular queue.
Your choice please:- 3

Front of the queue is:- 7

Do you want more operations to perfom press y:- y

Enter your choice
1.empty()-return true if Circular queue is empty.
2.Size()-return the number of elements in the Circular queue.
3.front()-return the front element of Circular queue
4.enqueue()-add the element at the rear of the Circular queue
5.display()-display the elements of the Circular queue
6.dequeue()-delete the element from the rear of Circular queue.
Your choice please:- 5

Elements of the Circular queue are:-
7
8

Do you want more operations to perfom press y:- y

Enter your choice
1.empty()-return true if Circular queue is empty.
2.Size()-return the number of elements in the Circular queue.
3.front()-return the front element of Circular queue
4.enqueue()-add the element at the rear of the Circular queue
5.display()-display the elements of the Circular queue
6.dequeue()-delete the element from the rear of Circular queue.
Your choice please:- 4

Enter the element you want to add in the Circular queue:- 9

Do you want more operations to perfom press y:- y

Enter your choice
1.empty()-return true if Circular queue is empty.
2.Size()-return the number of elements in the Circular queue.
3.front()-return the front element of Circular queue
4.enqueue()-add the element at the rear of the Circular queue
5.display()-display the elements of the Circular queue
6.dequeue()-delete the element from the rear of Circular queue.
Your choice please:- 5

Elements of the Circular queue are:-
7
8
9

Do you want more operations to perfom press y:- y

Enter your choice
1.empty()-return true if Circular queue is empty.
2.Size()-return the number of elements in the Circular queue.
3.front()-return the front element of Circular queue
4.enqueue()-add the element at the rear of the Circular queue
5.display()-display the elements of the Circular queue
6.dequeue()-delete the element from the rear of Circular queue.
Your choice please:- 4

Enter the element you want to add in the Circular queue:- 10

Do you want more operations to perfom press y:- y

Enter your choice
1.empty()-return true if Circular queue is empty.
2.Size()-return the number of elements in the Circular queue.
3.front()-return the front element of Circular queue
4.enqueue()-add the element at the rear of the Circular queue
5.display()-display the elements of the Circular queue
6.dequeue()-delete the element from the rear of Circular queue.
Your choice please:- 4

Enter the element you want to add in the Circular queue:- 11

Circular Queue is Full
No more element can be added in the Circular queue

Do you want more operations to perfom press y:- y

Enter your choice
1.empty()-return true if Circular queue is empty.
2.Size()-return the number of elements in the Circular queue.
3.front()-return the front element of Circular queue
4.enqueue()-add the element at the rear of the Circular queue
5.display()-display the elements of the Circular queue
6.dequeue()-delete the element from the rear of Circular queue.
Your choice please:- 5

Elements of the Circular queue are:-
7
8
9
10

Do you want more operations to perfom press y:- y

Enter your choice
1.empty()-return true if Circular queue is empty.
2.Size()-return the number of elements in the Circular queue.
3.front()-return the front element of Circular queue
4.enqueue()-add the element at the rear of the Circular queue
5.display()-display the elements of the Circular queue
6.dequeue()-delete the element from the rear of Circular queue.
Your choice please:- 3

Front of the queue is:- 7

Do you want more operations to perfom press y:- y

Enter your choice
1.empty()-return true if Circular queue is empty.
2.Size()-return the number of elements in the Circular queue.
3.front()-return the front element of Circular queue
4.enqueue()-add the element at the rear of the Circular queue
5.display()-display the elements of the Circular queue
6.dequeue()-delete the element from the rear of Circular queue.
Your choice please:- 6

Deleted element from the Circular queue is:- 7
Do you want more operations to perfom press y:- y

Enter your choice
1.empty()-return true if Circular queue is empty.
2.Size()-return the number of elements in the Circular queue.
3.front()-return the front element of Circular queue
4.enqueue()-add the element at the rear of the Circular queue
5.display()-display the elements of the Circular queue
6.dequeue()-delete the element from the rear of Circular queue.
Your choice please:- 5

Elements of the Circular queue are:-
8
9
10

Do you want more operations to perfom press y:- y

Enter your choice
1.empty()-return true if Circular queue is empty.
2.Size()-return the number of elements in the Circular queue.
3.front()-return the front element of Circular queue
4.enqueue()-add the element at the rear of the Circular queue
5.display()-display the elements of the Circular queue
6.dequeue()-delete the element from the rear of Circular queue.
Your choice please:- 3

Front of the queue is:- 8

Do you want more operations to perfom press y:- y

Enter your choice
1.empty()-return true if Circular queue is empty.
2.Size()-return the number of elements in the Circular queue.
3.front()-return the front element of Circular queue
4.enqueue()-add the element at the rear of the Circular queue
5.display()-display the elements of the Circular queue
6.dequeue()-delete the element from the rear of Circular queue.
Your choice please:- 6

Deleted element from the Circular queue is:- 8
Do you want more operations to perfom press y:- y

Enter your choice
1.empty()-return true if Circular queue is empty.
2.Size()-return the number of elements in the Circular queue.
3.front()-return the front element of Circular queue
4.enqueue()-add the element at the rear of the Circular queue
5.display()-display the elements of the Circular queue
6.dequeue()-delete the element from the rear of Circular queue.
Your choice please:- 5

Elements of the Circular queue are:-
9
10

Do you want more operations to perfom press y:- y

Enter your choice
1.empty()-return true if Circular queue is empty.
2.Size()-return the number of elements in the Circular queue.
3.front()-return the front element of Circular queue
4.enqueue()-add the element at the rear of the Circular queue
5.display()-display the elements of the Circular queue
6.dequeue()-delete the element from the rear of Circular queue.
Your choice please:- 3

Front of the queue is:- 9

Do you want more operations to perfom press y:- y

Enter your choice
1.empty()-return true if Circular queue is empty.
2.Size()-return the number of elements in the Circular queue.
3.front()-return the front element of Circular queue
4.enqueue()-add the element at the rear of the Circular queue
5.display()-display the elements of the Circular queue
6.dequeue()-delete the element from the rear of Circular queue.
Your choice please:- 4

Enter the element you want to add in the Circular queue:- 11

Do you want more operations to perfom press y:- y

Enter your choice
1.empty()-return true if Circular queue is empty.
2.Size()-return the number of elements in the Circular queue.
3.front()-return the front element of Circular queue
4.enqueue()-add the element at the rear of the Circular queue
5.display()-display the elements of the Circular queue
6.dequeue()-delete the element from the rear of Circular queue.
Your choice please:- 5

Elements of the Circular queue are:-
9
10
11

Do you want more operations to perfom press y:- y

Enter your choice
1.empty()-return true if Circular queue is empty.
2.Size()-return the number of elements in the Circular queue.
3.front()-return the front element of Circular queue
4.enqueue()-add the element at the rear of the Circular queue
5.display()-display the elements of the Circular queue
6.dequeue()-delete the element from the rear of Circular queue.
Your choice please:- 4

Enter the element you want to add in the Circular queue:- 12

Do you want more operations to perfom press y:- y

Enter your choice
1.empty()-return true if Circular queue is empty.
2.Size()-return the number of elements in the Circular queue.
3.front()-return the front element of Circular queue
4.enqueue()-add the element at the rear of the Circular queue
5.display()-display the elements of the Circular queue
6.dequeue()-delete the element from the rear of Circular queue.
Your choice please:- 5

Elements of the Circular queue are:-
9
10
11
12

Do you want more operations to perfom press y:- y

Enter your choice
1.empty()-return true if Circular queue is empty.
2.Size()-return the number of elements in the Circular queue.
3.front()-return the front element of Circular queue
4.enqueue()-add the element at the rear of the Circular queue
5.display()-display the elements of the Circular queue
6.dequeue()-delete the element from the rear of Circular queue.
Your choice please:- 1

 Circular Queue is non-empty.

Do you want more operations to perfom press y:- y

Enter your choice
1.empty()-return true if Circular queue is empty.
2.Size()-return the number of elements in the Circular queue.
3.front()-return the front element of Circular queue
4.enqueue()-add the element at the rear of the Circular queue
5.display()-display the elements of the Circular queue
6.dequeue()-delete the element from the rear of Circular queue.
Your choice please:- 2

Number of elements in the Circular queue is:- 4

Do you want more operations to perfom press y:- y

Enter your choice
1.empty()-return true if Circular queue is empty.
2.Size()-return the number of elements in the Circular queue.
3.front()-return the front element of Circular queue
4.enqueue()-add the element at the rear of the Circular queue
5.display()-display the elements of the Circular queue
6.dequeue()-delete the element from the rear of Circular queue.
Your choice please:- 3

Front of the queue is:- 9

Do you want more operations to perfom press y:-


*/


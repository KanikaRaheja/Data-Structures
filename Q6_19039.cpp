//Implementation of stack using array representation
#include<iostream>
#include<conio.h>
#include<exception>
using namespace std;
//throw exception if stack is empty
class Stackempty:public exception
{
	public:
		char *what()
		{
			cout<<"\nStack is empty. ";
		}
};
//throw exception if stack is full
class Stackfull:public exception
{
	public:
		char *what()
		{
			cout<< "\nStack is full.";
		}
};
//Stack Class
template<class type>
class Stack
{
    type *ar,top,cap;
	public:
    Stack()
	{
	top=-1;
	}	
	void input();
	int size() const;
	bool empty() const;
	const type& Top();
	void push(const type& element);
	void pop(); 
	void display();
};
//Take the size of stack as input
template<class type>
void Stack<type>::input()
{
	cout<<"\nEnter the size of stack:- ";
	cin>>cap;
	ar=new int[cap];
}
//return the number of elements in the stack
template<class type>
int Stack<type>::size() const
{
	return top+1;
}
//check if the stack is empty or not
template<class type>
bool Stack<type>::empty() const
{
	return (top<0);
	 
}
//return the top element of stack otherwise throw exception if stack is empty
template<class type>
const type& Stack<type>::Top()
{
  	try
	{
	if(empty())
	{
	 Stackempty w;
	 throw w;
    }
    }
    catch(Stackempty w)
    {
    	cout<<" "<<w.what()<<"\nSo there is no top";
	}
	if(!empty())
 cout<<"\nTop element of Stack is:- "<<ar[top];
 
}
//push the  element in the  stack otherwise throw exception if stack is full
template<class type>
void Stack<type>::push(const type& element)
{
	try
	{
	if(size()==cap)
	{
	Stackfull x;
	throw x;	 
	}
    }
    catch(Stackfull x)
    {
    cout<<" "<<x.what()<<"\nSo no more element can be push in stack";
    }
	if(size()!=cap)
	{
	ar[++top]=element;
    }
}
// delete the top element of stack otherwise throw exception if stack is empty
template<class type>
void Stack<type>::pop()  
{
	try
	{
	if(empty())
	{
	 Stackempty w;
	 throw w;
    }
    }
     catch(Stackempty w)
    {
    	cout<<" "<<w.what();
	}
	 if(!empty())
	{
	cout<<"\nDeleted element from the stack is:- "<<ar[top];
    --top;
    }
}
//dispalys the elements of stack
template<class type>
void Stack<type>::display()
{
	for(int i=0;i<=top;i++)
	cout<<" "<<ar[i];
}
int main()
{
	Stack<int> s;
 	int ch;
	char ans;
	s.input();
		do
	{
	cout<<"\nEnter your choice\n1.size()-return the number of elements in the stack\n2.empty()-tell if stack is empty or not\n3.Top()-display the top most element of stack\n4.push()-push the element in the stack\n5.dispaly()-it display the elements of the stack\n6.pop()-delete the element from the top";
	cout<<"\nYour Choice:- ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			{
			int N=s.size();
			cout<<"\nNumber of elements in the stack is:- "<<N;
			break;
		   }
		case 2:
			{
		     if(!s.empty())
		     cout<<"\nStack is not empty";
		     else
		     cout<<"\nStack is empty";
			break;
		   }
		case 3:
			{
				int value;
				s.Top();
				break;
			}
		case 4:
			{
			int value;	
			cout<<"\nEnter the element you want to push in the stack:-";
        	cin>>value;
			s.push(value);
			break; 
		    }
		case 5:
			{
				cout<<"\nThe elements in the stack are:- ";
				s.display();
				break;
			}
		case 6:
			{
				s.pop();
				break;
			}
		default:
		cout<<"\n Wrong Choice Please Reenter your choice";
	}
	cout<<"\n\nDo You want operations to perform press y:- ";
	cin>>ans;
   }while(ans=='y'); 
	getch();
	return 0;
}
/*
OUTPUT
Enter the size of stack:- 5

Enter your choice
1.size()-return the number of elements in the stack
2.empty()-tell if stack is empty or not
3.Top()-display the top most element of stack
4.push()-push the element in the stack
5.dispaly()-it display the elements of the stack
6.pop()-delete the element from the top
Your Choice:- 1

Number of elements in the stack is:- 0

Do You want operations to perform press y:- y

Enter your choice
1.size()-return the number of elements in the stack
2.empty()-tell if stack is empty or not
3.Top()-display the top most element of stack
4.push()-push the element in the stack
5.dispaly()-it display the elements of the stack
6.pop()-delete the element from the top
Your Choice:- 4

Enter the element you want to push in the stack:-10


Do You want operations to perform press y:- y

Enter your choice
1.size()-return the number of elements in the stack
2.empty()-tell if stack is empty or not
3.Top()-display the top most element of stack
4.push()-push the element in the stack
5.dispaly()-it display the elements of the stack
6.pop()-delete the element from the top
Your Choice:- 1

Number of elements in the stack is:- 1

Do You want operations to perform press y:- y

Enter your choice
1.size()-return the number of elements in the stack
2.empty()-tell if stack is empty or not
3.Top()-display the top most element of stack
4.push()-push the element in the stack
5.dispaly()-it display the elements of the stack
6.pop()-delete the element from the top
Your Choice:- 4

Enter the element you want to push in the stack:-34


Do You want operations to perform press y:- y

Enter your choice
1.size()-return the number of elements in the stack
2.empty()-tell if stack is empty or not
3.Top()-display the top most element of stack
4.push()-push the element in the stack
5.dispaly()-it display the elements of the stack
6.pop()-delete the element from the top
Your Choice:- 5

The elements in the stack are:-  10 34

Do You want operations to perform press y:- y

Enter your choice
1.size()-return the number of elements in the stack
2.empty()-tell if stack is empty or not
3.Top()-display the top most element of stack
4.push()-push the element in the stack
5.dispaly()-it display the elements of the stack
6.pop()-delete the element from the top
Your Choice:- 4

Enter the element you want to push in the stack:-55


Do You want operations to perform press y:- y

Enter your choice
1.size()-return the number of elements in the stack
2.empty()-tell if stack is empty or not
3.Top()-display the top most element of stack
4.push()-push the element in the stack
5.dispaly()-it display the elements of the stack
6.pop()-delete the element from the top
Your Choice:- 4

Enter the element you want to push in the stack:-7


Do You want operations to perform press y:- y

Enter your choice
1.size()-return the number of elements in the stack
2.empty()-tell if stack is empty or not
3.Top()-display the top most element of stack
4.push()-push the element in the stack
5.dispaly()-it display the elements of the stack
6.pop()-delete the element from the top
Your Choice:- 1

Number of elements in the stack is:- 4

Do You want operations to perform press y:- y

Enter your choice
1.size()-return the number of elements in the stack
2.empty()-tell if stack is empty or not
3.Top()-display the top most element of stack
4.push()-push the element in the stack
5.dispaly()-it display the elements of the stack
6.pop()-delete the element from the top
Your Choice:- 4

Enter the element you want to push in the stack:-65


Do You want operations to perform press y:- y

Enter your choice
1.size()-return the number of elements in the stack
2.empty()-tell if stack is empty or not
3.Top()-display the top most element of stack
4.push()-push the element in the stack
5.dispaly()-it display the elements of the stack
6.pop()-delete the element from the top
Your Choice:- 1

Number of elements in the stack is:- 5

Do You want operations to perform press y:- y

Enter your choice
1.size()-return the number of elements in the stack
2.empty()-tell if stack is empty or not
3.Top()-display the top most element of stack
4.push()-push the element in the stack
5.dispaly()-it display the elements of the stack
6.pop()-delete the element from the top
Your Choice:- 2

Stack is not empty

Do You want operations to perform press y:- y

Enter your choice
1.size()-return the number of elements in the stack
2.empty()-tell if stack is empty or not
3.Top()-display the top most element of stack
4.push()-push the element in the stack
5.dispaly()-it display the elements of the stack
6.pop()-delete the element from the top
Your Choice:- 3

Top element of Stack is:- 65

Do You want operations to perform press y:- y

Enter your choice
1.size()-return the number of elements in the stack
2.empty()-tell if stack is empty or not
3.Top()-display the top most element of stack
4.push()-push the element in the stack
5.dispaly()-it display the elements of the stack
6.pop()-delete the element from the top
Your Choice:- 5

The elements in the stack are:-  10 34 55 7 65

Do You want operations to perform press y:- y

Enter your choice
1.size()-return the number of elements in the stack
2.empty()-tell if stack is empty or not
3.Top()-display the top most element of stack
4.push()-push the element in the stack
5.dispaly()-it display the elements of the stack
6.pop()-delete the element from the top
Your Choice:- 4

Enter the element you want to push in the stack:-6

Stack is full.
No  more element can be push in the stack  + I

Do You want operations to perform press y:- y

Enter your choice
1.size()-return the number of elements in the stack
2.empty()-tell if stack is empty or not
3.Top()-display the top most element of stack
4.push()-push the element in the stack
5.dispaly()-it display the elements of the stack
6.pop()-delete the element from the top
Your Choice:- 6

Deleted element from the stack is:- 65

Do You want operations to perform press y:- y

Enter your choice
1.size()-return the number of elements in the stack
2.empty()-tell if stack is empty or not
3.Top()-display the top most element of stack
4.push()-push the element in the stack
5.dispaly()-it display the elements of the stack
6.pop()-delete the element from the top
Your Choice:- 5

The elements in the stack are:-  10 34 55 7

Do You want operations to perform press y:- y

Enter your choice
1.size()-return the number of elements in the stack
2.empty()-tell if stack is empty or not
3.Top()-display the top most element of stack
4.push()-push the element in the stack
5.dispaly()-it display the elements of the stack
6.pop()-delete the element from the top
Your Choice:- 6

Deleted element from the stack is:- 7

Do You want operations to perform press y:- y

Enter your choice
1.size()-return the number of elements in the stack
2.empty()-tell if stack is empty or not
3.Top()-display the top most element of stack
4.push()-push the element in the stack
5.dispaly()-it display the elements of the stack
6.pop()-delete the element from the top
Your Choice:- 5

The elements in the stack are:-  10 34 55

Do You want operations to perform press y:-

*/

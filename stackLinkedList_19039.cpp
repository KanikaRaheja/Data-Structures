//implementing stack using linked list
#include<iostream>
#include<conio.h>
#include"SinglyLinkedList.cpp"
using namespace std;

//Stack Linked List Class
template<class type>
class StackLinkedList
{
    int n;
    LinkedList<type> S;
	public:
    StackLinkedList();
	int size() const; 
	bool empty() const;
	const type& Top();
	void push(const type& element);
	void pop(); 
	void display();
	
};
//constructor
template<class type>
StackLinkedList<type>::StackLinkedList()
{
	n=0;
}
//return number of elements in the stack
template<class type>
int StackLinkedList<type>::size() const
{
	return n;
}
//check if  the stack is empty
template<class type>
bool StackLinkedList<type>::empty() const
{
	return n==0;
}
//return the top of the stack
template<class type>
const type& StackLinkedList<type>::Top()
{
	if(empty())
	{
	cout<<"\n\nStack is Empty.\nNo Top of the Stack";
   }
	else
	{
		return S.front();
	}
}
//push the element in the stack
template<class type>
void StackLinkedList<type>::push(const type& element)
{
	S.addfront(element);
	n++;
}
//pop the element from the stack
template<class type>
void StackLinkedList<type>::pop()
{
	if(empty())
	cout<<"\n\nStack is empty";
	else
	{
		S.removefront();
		n--;
	}
	
}
//display the elements of the stack
template<class type>
void StackLinkedList<type>::display()
{
	S.display();
}
int main()
{
 	int ch,choose;
	char ans;
	cout<<"\nChoice for data type:- \n1.int\n2.char\n3.float";
	cout<<"\nEnter the data type:- ";
	cin>>choose;
	switch(choose)
	{
		case 1:
			{
				StackLinkedList<int> s;
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
				cout<<" "<<s.empty();
		     if(!s.empty())
		     cout<<"\nStack is not empty";
		     else
		     cout<<"\nStack is empty";
			break;
		   }
		case 3:
			{
				int value;
				cout<<"\n\nTop of the stack is:- "<<s.Top();
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
   break;
}
     case 2:
			{
				StackLinkedList<char> c;
		do
	{
	cout<<"\nEnter your choice\n1.size()-return the number of elements in the stack\n2.empty()-tell if stack is empty or not\n3.Top()-display the top most element of stack\n4.push()-push the element in the stack\n5.dispaly()-it display the elements of the stack\n6.pop()-delete the element from the top";
	cout<<"\nYour Choice:- ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			{
			int N=c.size();
			cout<<"\nNumber of elements in the stack is:- "<<N;
			break;
		   }
		case 2:
			{
				cout<<" "<<c.empty();
		     if(!c.empty())
		     cout<<"\nStack is not empty";
		     else
		     cout<<"\nStack is empty";
			break;
		   }
		case 3:
			{
				char value;
				cout<<"\n\nTop of the stack is:- "<<c.Top();
				break;
			}
		case 4:
			{
			char value;	
			cout<<"\nEnter the element you want to push in the stack:-";
        	cin>>value;
			c.push(value);
			break; 
		    }
		case 5:
			{
				cout<<"\nThe elements in the stack are:- ";
				c.display();
				break;
			}
		case 6:
			{
				c.pop();
				break;
			}
		default:
		cout<<"\n Wrong Choice Please Reenter your choice";
	}
	cout<<"\n\nDo You want operations to perform press y:- ";
	cin>>ans;
   }while(ans=='y'); 
   break;
}
    case 3:
			{
				StackLinkedList<float> f;
		do
	{
	cout<<"\nEnter your choice\n1.size()-return the number of elements in the stack\n2.empty()-tell if stack is empty or not\n3.Top()-display the top most element of stack\n4.push()-push the element in the stack\n5.dispaly()-it display the elements of the stack\n6.pop()-delete the element from the top";
	cout<<"\nYour Choice:- ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			{
			int N=f.size();
			cout<<"\nNumber of elements in the stack is:- "<<N;
			break;
		   }
		case 2:
			{
				cout<<" "<<f.empty();
		     if(!f.empty())
		     cout<<"\nStack is not empty";
		     else
		     cout<<"\nStack is empty";
			break;
		   }
		case 3:
			{
				float value;
				cout<<"\n\nTop of the stack is:- "<<f.Top();
				break;
			}
		case 4:
			{
			float value;	
			cout<<"\nEnter the element you want to push in the stack:-";
        	cin>>value;
			f.push(value);
			break; 
		    }
		case 5:
			{
				cout<<"\nThe elements in the stack are:- ";
				f.display();
				break;
			}
		case 6:
			{
				f.pop();
				break;
			}
		default:
		cout<<"\n Wrong Choice Please Reenter your choice";
	}
	cout<<"\n\nDo You want operations to perform press y:- ";
	cin>>ans;
   }while(ans=='y'); 
   break;
}
    default:
    	cout<<"\n\nWrong Data Type Enter:- ";
}
	getch();
	return 0;
}
/*OUTPUT
Choice for data type:-
1.int
2.char
3.float
Enter the data type:- 2

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
Your Choice:- 2
 1
Stack is empty

Do You want operations to perform press y:- y

Enter your choice
1.size()-return the number of elements in the stack
2.empty()-tell if stack is empty or not
3.Top()-display the top most element of stack
4.push()-push the element in the stack
5.dispaly()-it display the elements of the stack
6.pop()-delete the element from the top
Your Choice:- 3


Stack is Empty.
No Top of the Stack

Top of the stack is:- 

Do You want operations to perform press y:- y

Enter your choice
1.size()-return the number of elements in the stack
2.empty()-tell if stack is empty or not
3.Top()-display the top most element of stack
4.push()-push the element in the stack
5.dispaly()-it display the elements of the stack
6.pop()-delete the element from the top
Your Choice:- 4

Enter the element you want to push in the stack:-s


Do You want operations to perform press y:- y

Enter your choice
1.size()-return the number of elements in the stack
2.empty()-tell if stack is empty or not
3.Top()-display the top most element of stack
4.push()-push the element in the stack
5.dispaly()-it display the elements of the stack
6.pop()-delete the element from the top
Your Choice:- 5

The elements in the stack are:-   s


Do You want operations to perform press y:- y

Enter your choice
1.size()-return the number of elements in the stack
2.empty()-tell if stack is empty or not
3.Top()-display the top most element of stack
4.push()-push the element in the stack
5.dispaly()-it display the elements of the stack
6.pop()-delete the element from the top
Your Choice:- 4

Enter the element you want to push in the stack:-a


Do You want operations to perform press y:- y

Enter your choice
1.size()-return the number of elements in the stack
2.empty()-tell if stack is empty or not
3.Top()-display the top most element of stack
4.push()-push the element in the stack
5.dispaly()-it display the elements of the stack
6.pop()-delete the element from the top
Your Choice:- 5

The elements in the stack are:-   a  s


Do You want operations to perform press y:- y

Enter your choice
1.size()-return the number of elements in the stack
2.empty()-tell if stack is empty or not
3.Top()-display the top most element of stack
4.push()-push the element in the stack
5.dispaly()-it display the elements of the stack
6.pop()-delete the element from the top
Your Choice:- 3


Top of the stack is:- a

Do You want operations to perform press y:- y

Enter your choice
1.size()-return the number of elements in the stack
2.empty()-tell if stack is empty or not
3.Top()-display the top most element of stack
4.push()-push the element in the stack
5.dispaly()-it display the elements of the stack
6.pop()-delete the element from the top
Your Choice:- 4

Enter the element you want to push in the stack:-g


Do You want operations to perform press y:- y

Enter your choice
1.size()-return the number of elements in the stack
2.empty()-tell if stack is empty or not
3.Top()-display the top most element of stack
4.push()-push the element in the stack
5.dispaly()-it display the elements of the stack
6.pop()-delete the element from the top
Your Choice:- 5

The elements in the stack are:-   g  a  s


Do You want operations to perform press y:- y

Enter your choice
1.size()-return the number of elements in the stack
2.empty()-tell if stack is empty or not
3.Top()-display the top most element of stack
4.push()-push the element in the stack
5.dispaly()-it display the elements of the stack
6.pop()-delete the element from the top
Your Choice:- 3


Top of the stack is:- g

Do You want operations to perform press y:- y

Enter your choice
1.size()-return the number of elements in the stack
2.empty()-tell if stack is empty or not
3.Top()-display the top most element of stack
4.push()-push the element in the stack
5.dispaly()-it display the elements of the stack
6.pop()-delete the element from the top
Your Choice:- 6


Do You want operations to perform press y:- y

Enter your choice
1.size()-return the number of elements in the stack
2.empty()-tell if stack is empty or not
3.Top()-display the top most element of stack
4.push()-push the element in the stack
5.dispaly()-it display the elements of the stack
6.pop()-delete the element from the top
Your Choice:- 5

The elements in the stack are:-   a  s


Do You want operations to perform press y:- y

Enter your choice
1.size()-return the number of elements in the stack
2.empty()-tell if stack is empty or not
3.Top()-display the top most element of stack
4.push()-push the element in the stack
5.dispaly()-it display the elements of the stack
6.pop()-delete the element from the top
Your Choice:- 6


Do You want operations to perform press y:- y

Enter your choice
1.size()-return the number of elements in the stack
2.empty()-tell if stack is empty or not
3.Top()-display the top most element of stack
4.push()-push the element in the stack
5.dispaly()-it display the elements of the stack
6.pop()-delete the element from the top
Your Choice:- 6


Do You want operations to perform press y:- y

Enter your choice
1.size()-return the number of elements in the stack
2.empty()-tell if stack is empty or not
3.Top()-display the top most element of stack
4.push()-push the element in the stack
5.dispaly()-it display the elements of the stack
6.pop()-delete the element from the top
Your Choice:- 5

The elements in the stack are:-

No element to display



Do You want operations to perform press y:- y

Enter your choice
1.size()-return the number of elements in the stack
2.empty()-tell if stack is empty or not
3.Top()-display the top most element of stack
4.push()-push the element in the stack
5.dispaly()-it display the elements of the stack
6.pop()-delete the element from the top
Your Choice:- 6


Stack is empty

Do You want operations to perform press y:-
*/


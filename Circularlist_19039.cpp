//implementing circular linked list
#include<iostream>
#include<conio.h>
using namespace std;
//Cnode class
template<class type>
class Cnode
{
	public:
    	type data;
    	Cnode *next;
};
//circular linked list class
template<class type>
class circularlinkedlist
{
	int n;
	Cnode<type> *Cursor;
	public:
		circularlinkedlist();
		void front(type&);
		void display();
		void insertxaftery(type&,type&);
		void back(type&);
		void removefront();
		void removeback();
		type& Front();
		Cnode<type>* searchx(type&);
		void concatenate(circularlinkedlist<type>,circularlinkedlist<type>);
		void removex(type&);
};
//constructor
template<class type>
circularlinkedlist<type>::circularlinkedlist()
{
	n=0;
	Cursor=NULL;
}
template<class type>
type& circularlinkedlist<type>::Front()
{
	if(Cursor==NULL)
	cout<<"\nNO front because it is empty.";
	else
	return Cursor->next->data;
}
//function to add element at the front of the circular linked list
template<class type>
void circularlinkedlist<type>::front(type &ele)
{
	Cnode<type> *v=new Cnode<type>;
	v->data=ele;
	//if list is empty
	if(Cursor==NULL)
	{
		v->next=v;
		Cursor=v;
		n++;
	}
	//if nodes are present in the list
	else
	{
		v->next=Cursor->next;
		Cursor->next=v;
		n++;
	}
}
//function to add x after y
template<class type>
void circularlinkedlist<type>::insertxaftery(type &x,type &y)
{
	//if list is empty
	if(Cursor==NULL)
	{
		cout<<"\n\nList is Empty.";
	}
	else
	{
	Cnode<type> *temp=Cursor->next;
	Cnode<type> *v=new Cnode<type>;
	v->data=x;
	//traverse through the list until y is found
		while(temp!=Cursor)
		{
		//if y is found
		   if(temp->data==y)	
		   {
		   	v->next=temp->next;
		   	temp->next=v;
		   	n++;
		   	break;
		   }
		   else
		   {
		   	temp=temp->next;
		   }
		}
	//if we have to add x after cursor
		if(Cursor->data==y)
		{
		v->next=Cursor->next;
		 Cursor->next=v;
		 Cursor=v;
		 n++;
		}
	//if y not exist in the list
		else if(temp==Cursor && temp->data!=y)
		{
			cout<<"\n\nElement "<<y<<" not exist in the list.";
		}
		
	}
}
//function to add to the back of the list
template<class type>
void circularlinkedlist<type>::back(type &element)
{
	Cnode<type> *v=new Cnode<type>;
	v->data=element;
	//if list is empty
	if(Cursor==NULL)
	{
		v->next=v;
		Cursor=v;
		n++;
	}
	//if nodes are present
	else
	{
		v->next=Cursor->next;
	    Cursor->next=v;	
	    Cursor=v;
	    n++;
	}
}
//function to remove from the front of the list
template<class type>
void circularlinkedlist<type>::removefront()
{
	//if list is empty
	if(Cursor==NULL)
	{
		cout<<"\n\nList is Empty.";
	}
	//if nodes are present in the list
	else
	{
    Cnode<type> *old=Cursor->next;
    if(old==Cursor)
    {
    Cursor=NULL;
    n=0;
    }
    else
    {
	Cursor->next=old->next;
	delete old;
	n--;
    }
    }	
}	
//function to remove from the back of the list
template<class type>
void circularlinkedlist<type>::removeback()
{
	//if list is empty
	if(Cursor==NULL)
	{
		cout<<"\n\nList is Empty.";
	}
	//if nodes are present in the list
	else
	{
		Cnode<type> *old=Cursor->next;
	    Cnode<type> *temp=NULL;	
	    if(old==Cursor)
	    {
	    	Cursor=NULL;
	    	n=0;
		}
		else
		{
		while(old!=Cursor)
		{
			temp=old;
			old=old->next;
		}
		temp->next=Cursor->next;
		Cursor=temp;
		delete old;
		n--;
	}
	}
}
//function to seacrch x and return its pointer
template<class type>
Cnode<type>* circularlinkedlist<type>::searchx(type &x)
{
    //if list is empty
	if(Cursor==NULL)
	{
		cout<<"\n\nList is empty.\nNo element to display";
	}
   //if nodes are present
   else
   {
   		Cnode<type> *temp=Cursor->next;
   		while(temp!=Cursor)
   		{
   		   if(temp->data==x)
			  {
			  	return temp;
			  	break;
			  }
			  else
			  {
			    temp=temp->next;	
			  } 	
		}
		if(Cursor->data==x)
		return Cursor;
		else if(temp==Cursor && Cursor->data!=x)
		{
		temp=NULL;
		cout<<"\n\nElement "<<x<<" not present in the list";
		return temp;
        }
   }
}
//function to concatenate two circular linked list
template<class type>
void circularlinkedlist<type>::concatenate(circularlinkedlist<type> L1,circularlinkedlist<type> L2)
{
	if(L1.Cursor==NULL)
	{
		cout<<"\n\nFirst is list";
	}
	else
	{
	 Cnode<type>* temp1=L1.Cursor->next;
	 Cnode<type>* temp2=L2.Cursor->next;
	 L1.Cursor->next=L2.Cursor->next;
	 L2.Cursor->next=temp1;
}
}
//function to remove x from the list
template<class type>
void circularlinkedlist<type>::removex(type &x)
{
	//if list is empty
	if(Cursor==NULL)
	{
		cout<<"\n\nList is empty.";
	}
 
	else
	{
			Cnode<type> *temp=Cursor->next;
			Cnode<type> *ptr=temp;
		//if only one node is present and we have to delete that node
		  if(n==1 && Cursor->data==x)
        {
        	Cursor=NULL;
        	n--;
		}
		//if nodes present are more than 1
		else if(n>1)
		{
		//if we have to delete first node after Cursor
		if(temp->data==x)
		{
			Cursor->next=temp->next;
			delete temp;
			n--;
		}
	//if we have to delete node other than first node
		else
		{
			ptr=temp;
			temp=temp->next;
		while(temp!=Cursor)
		{
		//if node x is found
			if(temp->data==x)
			{
				ptr->next=temp->next;
				delete temp;
				n--;
				break;
			}
		// if not x then traverse the list
			else
			{
					ptr=temp;
				temp=temp->next;
			}
		}
	}    
	}
	//if the node to be deleted is Cursor
		if (temp==Cursor && Cursor->data==x)
		{
			ptr->next=Cursor->next;
			delete temp;
			Cursor=ptr;
			n--;
		}	
	//if element x not present in the list
		else if(temp==Cursor && Cursor->data!=x)
		{
		cout<<"\n\nElement "<<x<<" not present in the list";
        }
}
}
template<class type>
void circularlinkedlist<type>::display()
{
	//if list is empty
	if(Cursor==NULL)
	{
		cout<<"\n\nNo element to display";
	}
   //if nodes are present
	else
	{
	Cnode<type> *temp=Cursor->next;
	cout<<"\nElements present are:- ";
	while(temp!=Cursor)
	{
		cout<<" "<<temp->data;
		temp=temp->next;
	}
	cout<<" "<<temp->data;
    }
}

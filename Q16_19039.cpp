//program to sort the user entered array
#include<iostream>
#include<conio.h>
using namespace std;
template<class type>
//sort array
class sort
{
	type temp;
	type *ar;
	int size;
	public:
		void input();
		void bsorting();
		void isorting();
		void ssorting();
		void display();
};
//function to take the input from the user
template<class type>
void sort<type> :: input()
{
	cout<<"\n Enter the size of array";
	cin>>size;
	ar=new type[size];
	cout<<"\n Enter the elements of array";
	for(int i=0;i<size;i++)
	cin>>ar[i];
}
//function to sort the array through bubble sort
template<class type>
void sort<type> :: bsorting()
{
	for(int i=0;i<size;i++)
	{
		for (int j=0;j<size-1;j++)
		{ 
		    if(ar[j]>ar[j+1])
		    {
		    	temp=ar[j];
		    	ar[j]=ar[j+1];
		    	ar[j+1]=temp;
			}
		}
		
	}
	display();
}
//function to sort the array using insertion sort
template<class type>
void sort<type> :: isorting()
{
	for(int i=1;i<size;i++)
	{
		temp=ar[i];
		int j=i;
		while(j>0 && ar[j-1]>temp)
		{
			ar[j]=ar[j-1];
			j--;
		}
		ar[j]=temp;
	}
	display();
}
//function to sort the array using selection sort
template<class type>
void sort<type> :: ssorting()
{
	for(int i=0;i<size-1;i++)
	{
		int min=ar[i];
		int loc=i;
		for(int j=i+1;j<size;j++)
		{
			if(min>ar[j])
			{
			min=ar[j];
			loc=j;
		    }
		}
			temp=ar[i];
			ar[i]=ar[loc];
			ar[loc]=temp;
	}
	 display();
}
//function to display the array after sorting
template<class type>
void sort<type> :: display()
{
	cout<<"\n After sorting array is ";
	for(int i=0;i<size;i++)
	cout<<"\n "<<ar[i];
}
//main function
int main()
{
	int ch,choice,choose;
	char ans;
	do
	{
		cout<<"\n Which type of data you want to sort \n1.int \n2.float \n3.char";
	    cin>>ch;
	    switch(ch)
	    {
	    	case 1:
	    	     sort<int> b;
	    	     b.input();
	    	     cout<<"Enter the type of sort \n1.Bubble sort \n2.insertion sort \n3.selection sort";
	    	     cin>>choose;
	    	       switch(choose)
	    	       {
	    	       	    case 1:
	    	       	    	b.bsorting();
	    	       	    	break;
	    	       	    case 2:
	    	       	    	b.isorting();
	    	       	    	break;
	    	       	    case 3:
	    	       	    	b.ssorting();
	    	       	    	break;
					}
					break;
	    	case 2:
	    		sort<float> c;
	    		c.input();
	    	     cout<<"Enter the type of sort \n1.Bubble sort \n2.insertion sort\n 3.selection sort";
	    	     cin>>choose;
	    	       switch(choose)
	    	       {
	    	       	    case 1:
	    	       	    	c.bsorting();
	    	       	    	break;
	    	       	    case 2:
	    	       	    	c.isorting();
	    	       	    	break;
	    	       	    case 3:
	    	       	    	c.isorting();
	    	       	    	break;
				   }
				   break;
	    	case 3:
	    		sort<char> d;
	    		d.input();
	    	     cout<<"Enter the type of sort \n1.Bubble sort \n2.insertion sort \n3.selection sort";
	    	     cin>>choose;
	    	       switch(choose)
	    	       {
	    	       	    case 1:
	    	       	    	d.bsorting();
	    	       	    	break;
	    	       	    case 2:
	    	       	    	d.isorting();
	    	       	    	break;
	    	       	    case 3:
	    	       	    	d.isorting();
	    	       	    	break;
				   }
				   break;
	    	default:
	    		cout<<"\n Wrong choice";
		}
		cout<<"\n Do you want more array to sort";
		cin>>ans;
	}while(ans=='y');
	getch();
	return 0;
}

/* Output
 
  Which type of data you want to sort
1.int
2.float
3.char1

 Enter the size of array4

 Enter the elements of array7
5
8
1
Enter the type of sort
1.Bubble sort
2.insertion sort
3.selection sort2

 After sorting array is
 1
 5
 7
 8
 Do you want more array to sorty

 Which type of data you want to sort
1.int
2.float
3.char2

 Enter the size of array4

 Enter the elements of array2.9
5.7
5.6
1.0
Enter the type of sort
1.Bubble sort
2.insertion sort
 3.selection sort3

 After sorting array is
 1
 2.9
 5.6
 5.7
 Do you want more array to sort
 */

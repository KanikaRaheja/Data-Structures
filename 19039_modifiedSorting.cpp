//program to sort the user entered array through modified sorting
#include<iostream>
#include<conio.h>
using namespace std;
template<class type>
//sort array
class sort
{
	type temp,noc,nom;
	type *ar;
	int size;
	public:
		sort()
		{
		 int n=0;
		}
		void input();
		void modifiedbubble();
		void modifiedinsert();
		void modifiedselection();
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
//function to sort the array through modified bubble sort
template<class type>
void sort<type> :: modifiedbubble()
{
	noc=0;
	nom=0;
	for(int i=0;i<size;i++)
	{
		for (int j=0;j<size-1-i;j++,noc++)
		{ 
		    if(ar[j]>ar[j+1])
		    {
		    	temp=ar[j];
		    	ar[j]=ar[j+1];
		    	ar[j+1]=temp;
		    	nom++;
			}
		}
	}
	display();
	cout<<"\nTotal number of comparision in bubble sort is:-"<<noc;
	cout<<"\nTotal number of movements in bubble sort is:-"<<3*nom;
}
//function to sort the array using modified insertion sort
template<class type>
void sort<type> :: modifiedinsert()
{
	noc=0;
	nom=0;
	int j;
	for(int i=1;i<size;i++)
	{
		temp=ar[i];
		nom++;
		for(j=i;j>0 && ++noc && temp<ar[j-1];j--)
		{
			ar[j]=ar[j-1];
			nom++;
		}
		ar[j]=temp;
		nom++;
	}
		display();
	cout<<"\nTotal number of comparision in insertion sort is:-"<<noc;
	cout<<"\nTotal number of movements in insertion sort is:-"<<nom;
}
//function to sort the array using modified selection sort
template<class type>
void sort<type> :: modifiedselection()
{
	noc=0;
	nom=0;
	for(int i=0;i<size-1;i++)
	{
		int loc=i;
		for(int j=i+1;j<size;j++,noc++)
		{
			if(ar[loc]>ar[j])
			loc=j;
		}
		if(loc!=i)
		{
			temp=ar[i];
			ar[i]=ar[loc];
			ar[loc]=temp;
			nom++;
		}
	}
	 display();
	cout<<"\nTotal number of comparision in selection sort is:-"<<noc;
	cout<<"\nTotal number of movements in selection sort is:-"<<3*nom;
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
	sort<int> a;
	int choice,choose;
	char ans;	
	do
	{
		 cout<<"\nEnter your choice\n1.Modified Bubble Sort\n2.Modified Insertion Sort\n3.Modified Selection Sort";
		 cin>>choice;
		 switch(choice)
		 {
		 	case 1:
		 		a.input();
		 		a.modifiedbubble();
		 		break;
		 	case 2:
				a.input();
		 		a.modifiedinsert();
		 		break;
		 	case 3:
			 	a.input();
		 		a.modifiedselection();
		 		break;
		 	default:
		 	    cout<<"\nWrong Choice Enter with in range of 1 to 3";
		 }
		cout<<"\n Do you want more array to sort";
		cin>>ans;
	}while(ans=='y');
	getch();
	return 0;
}

/*
OUTPUT
Enter your choice
1.Modified Bubble Sort
2.Modified Insertion Sort
3.Modified Selection Sort1

 Enter the size of array5

 Enter the elements of array10
9
6
5
3

 After sorting array is
 3
 5
 6
 9
 10
Total number of comparision in bubble sort is:-10
Total number of movements in bubble sort is:-30
 Do you want more array to sort y

Enter your choice
1.Modified Bubble Sort
2.Modified Insertion Sort
3.Modified Selection Sort
2

 Enter the size of array 5

 Enter the elements of array1
2
3
4
5

 After sorting array is
 1
 2
 3
 4
 5
Total number of comparision in insertion sort is:-4
Total number of movements in insertion sort is:-8
 Do you want more array to sort y

Enter your choice
1.Modified Bubble Sort
2.Modified Insertion Sort
3.Modified Selection Sort
3

 Enter the size of array 5

 Enter the elements of array3
7
9
10
12

 After sorting array is
 3
 7
 9
 10
 12
Total number of comparision in selection sort is:-10
Total number of movements in selection sort is:-0
 Do you want more array to sort
*/

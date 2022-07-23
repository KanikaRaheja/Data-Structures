#include<iostream>
#include<conio.h>
using namespace std;

int linear(int arr[], int size, int x)
{
	for (int i = 0; i<size; i++)
	{
		if ( arr[i]==x)
			return i;
			
		
		
	}
	return -1;
}

int binary(int arr[], int size, int x)
{	
	int start =0;
	int end = size-1;
	
	while(start<= end)
	{
		int mid = (start+end)/2;
		
		if(arr[mid] == x)
		{
		return mid;
		}
		else if(arr[mid]<x)
		{
			start = mid+1;
		
		}
		else
		{
			end = mid-1;
		}
	}
		
		return -1;

}

void getdata()
{
	int array[100];
	int no_of_elements;
	cout<<"enter the no. of elements"<<endl;
	cin>>no_of_elements;
	cout<<"enter the values"<<endl;
	for(int i=0;i<no_of_elements;i++)
	{
		cin>>array[i];
	}
	int no_to_be_searched;
	cout<<"enter no to be searched"<<endl;
	cin>>no_to_be_searched;
	
	cout<<"no searched at:";

}

int main()
{	
	getdata();
	cout<<"enter 1 if you wish to search linearly \n 2. if you wish to do a binary search \n";
	int choice;
	cin>>choice;
	
	
	switch(choice)
	{
		case 1: cout<<binary(array, no_of_elements, no_to_be_searched);
		break;
		case 2: cout<<linear(array, no_of_elements, no_to_be_searched);
		break;
		defaul:
			cout<<"wrong choice entered";
			
			
	}
	
	
	
	getch();
	return 0;
}

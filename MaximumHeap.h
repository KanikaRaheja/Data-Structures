#include<iostream>
#include<conio.h>

using namespace std;

class MaxHeap
{
	int *a;
	int capacity;
	int size;
	
	public:
			MaxHeap();
			void MaxHeapify(int);
			const bool empty()const;
			int parent(int);
			int left_child(int);
			int right_child(int);
			int extractMax();
			void increaseKey(int,int);
			int getMax();
			void deleteKey(int);
			void insertKey(int);
			void swap(int*,int*);
			void display();
};

MaxHeap::MaxHeap()
{
	size=0;
	capacity=INT_MAX;
	a=new int[size];
}


int MaxHeap::parent(int i)
{
	return (i-1)/2;
}

int MaxHeap::left_child(int i)
{
	return (2*i+1);
}

int MaxHeap::right_child(int i)
{
	return (2*i+2);
}

const bool MaxHeap::empty()const
{
	return size==0;
}
void MaxHeap::swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}


void MaxHeap::insertKey(int key)
{
	if(size==capacity)
	{
		cout<<"\n\nOverflow!!!";
		return;
	}
	
	size++;
	int i=size-1;
	a[i]=key;
	
	
	while(i!=0 && a[parent(i)]<a[i])
	{
		swap(&a[i],&a[parent(i)]);
		i=parent(i);
	}
}

void MaxHeap::increaseKey(int i, int new_val) 
{ 
	if(i>size-1)
	{
		cout<<"INVALID KEY!!!";
		return;
	}
    	if(new_val>a[i])
	{
	
    	a[i] = new_val; 
    	while (i != 0 && a[parent(i)] < a[i]) 
    	{ 
       	swap(&a[i], &a[parent(i)]); 
       	i = parent(i); 
    	}
	}
	else
	{
		a[i]=new_val;
		MaxHeapify(i);
	}
} 
 
 

int MaxHeap::extractMax()
{

		
	if(size==1)
	{
		size--;
		return a[0];
	}
	
	int root=a[0];
	a[0]=a[size-1];
	size--;
	MaxHeapify(0);
	
	return root; 
}

int MaxHeap::getMax()
{

	return a[0];
}

void MaxHeap::deleteKey(int i)
{
	increaseKey(i,INT_MAX);
	extractMax();
}


void MaxHeap::MaxHeapify(int i)
{
	int l=left_child(i);
	int r=right_child(i);
	int largest=i;
	
	if(l<size && a[l]>a[i])
		largest=l;
	if(r<size && a[r]>a[largest])
		largest=r;
	
	if(largest!=i)
	{
		swap(&a[i],&a[largest]);
		MaxHeapify(largest);
	}
}

void MaxHeap::display()
{
	
	for(int i=0;i<size;++i)
		cout<<a[i]<<"  ";
}


	

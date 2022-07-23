#include<iostream>
#include<conio.h>
using namespace std;

template<typename T>
class searching
{
	
	private:
		T *arr;
		T size;
		T x;
		
	public:
		void input();
		
		searching();
		~searching()
		{
			delete arr;
		}
		void sorting();
		T search(T *arr, T, T, T);
		void print() const;
	
	
	
};


template<typename T>
void searching<T>::input()
{
	cout<<"enter the size of the array"<<endl;
	cin>>size;
	arr = new T[size];													//array is declared dymamically		
	cout<<"enter the elements of the array"<<endl;
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
	}
}


template<typename T>
searching<T>::searching()
{
	
	
	
	
}

template<typename T>
void searching<T>::sorting()
{
	
	
	input();
	
	
	for(int k = 0;k<size-1;k++)
	{
		int min = arr[k];
		int min_index = k;
		for(int i=k+1;i<size;i++)
		{
			if(arr[i]<min)
			{
				min = arr[i];
				min_index = i;
			}
		
		}
		
		
		int temp = arr[k];
		arr[k] = arr[min_index];
		arr[min_index] = temp;
	}
	
	
	cout<<"enter the element you want to search"<<endl;
	cin>>x;
	int ss = search(arr, 0, size-1, x);
	cout<<ss;
	
}



template<typename T>
T searching<T>::search(T *arr, T lb, T ub, T x)
{
	
	
	
	
	
	if (ub >= lb) { 
        int mid = lb + (ub - lb) / 2; 
  
        // If the element is present at the middle 
        // itself 
        if (arr[mid] == x) 
            return mid; 
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (arr[mid] > x) 
            return search(arr, lb, mid - 1, x); 
  
        // Else the element can only be present 
        // in right subarray 
        return search(arr, mid + 1, ub, x); 
    } 
  
    // We reach here when element is not 
    // present in array 
    return -1;
	
	
/*	
	lb = 0;
	ub = size-1;
	mid = (lb+ub)/2;
	
	while(ub>=lb)
	{
		if(x == arr[mid])
		return mid+1;
		
		else if(x>arr[mid])
		{
			lb = mid+1;
			
		}
		else if(x<arr[mid])
		{
			ub = mid-1;
		}
		
	}
	return -1;
	
	*/
	
	
	
	
}
template<typename T>
void searching<T>::print() const
{
	
	
}






int main()
{
	
	
	searching<int> s;
	int size;
	//*arr = new int[size];
	
	
	s.sorting() ;
	
	
	
	
	return 0;
	getch();
}

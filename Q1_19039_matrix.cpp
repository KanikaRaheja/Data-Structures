/*
Q1: Write a menu-driven program to implement the following sparse matrices using 1-D array:
i) Diagonal Matrix
ii) Tri-diagonal Matrix
iii) Lower Triangular Matrix
iv) Upper Triangular Matrix
v) Symmetric Matrix
*/

#include<iostream>
#include<conio.h>

using namespace std;

template<class T>
class matrix
{
	private:
		T *element;
		T **a;
		int n;
		
	public:
			matrix();
			~matrix()
			{
				delete [] element;
			}
			//Digonal Matrix
			
				void digonal();
				void set_digonal(int,int, const T&);
				T get_digonal(int,int);	
				void show_diagonal();
			
			//Tridigonal Matrix
			
				void tridigonal();
				void set_tridigonal(int,int j,const T&);
				T get_tridigonal(int,int);
				void show_tridigonal();	
			
			//Lower Triangular Matrix
			
				void lowertri();
				void set_lowertri(int,int,const T&);
				T get_lowertri(int i,int j);
				void show_lowertri();
				
			// Upper Triangular Matrix
			
				void uppertri();
				void set_uppertri(int,int,const T&);
				T get_uppertri(int i,int j);
				void show_uppertri();
				
			//Symmetric Matrix
				
				void symm();
				void set_symm(int,int,const T&);
				T get_symm(int i,int j);
				void show_symm();	
};

template<class T>
matrix<T>::matrix()
{
	n=0;
}


// Digonal Matrix

 
template<class T>
void matrix<T>::digonal()
{	T val;
	
	cout<<"\nEnter the size of Rows:-";
	cin>>n;
	a =new T*[n];
	for(int i=0;i<n;++i)
	a[i]=new T[n];
	element=new T[n];
	cout<<"\nEnter the element of the array:- ";
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
		{
			if(i==j)
			{
			
			cout<<"\nEnter the element at  "<<"a["<<i<<"]["<<j<<"]"<<":-";
			cin>>a[i][j];
			val=a[i][j];
			set_digonal(i,j,val);
			}
			
		}
			cout<<"\n\nDiagonal Elements are:-";
			for(int i=0;i<n;++i)
			cout<<element[i]<<"  ";
}




template<class T>
T matrix<T>::get_digonal(int i,int j)
{
	if(i==j)
	return element[i];
	else
	return 0;
} 




template<class T>
void matrix<T>::set_digonal(int i,int j, const T& val)
{
	if(i<0||j<0||i>n||j>n)
		{
			cout<<"Index out of Bound";
			
		}
	if(i==j)
	element[i]=val;
	else 
	{
		if(val!=0)
		cout<<"Non-Digonal elements should be zero\n";
	}
}



template<class T>
void matrix<T>::show_diagonal()
{	T ele;
	cout<<"\n\n";
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			ele=get_digonal(i,j);
			cout<<ele<<" ";
		}
		cout<<endl;
	}
}


//Tridigonal Matrix


template<class T>
void matrix<T>::tridigonal()
{
	T val;
	cout<<"\nEnter the no of rows-";
	cin>>n;
	int s= 3*n-2;
	element=new T[s];
	a=new T*[n];
	for(int i=0;i<n;++i)
		a[i]=new T[n];
	//Input the 2 D array:-
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			{    if((i-j)==0||(i-j)==1||(i-j)==-1)
				{
				
						cout<<"\nEnter the element at  "<<"a["<<i<<"]["<<j<<"]"<<":-";
						cin>>a[i][j];
						val=a[i][j];
						set_tridigonal(i,j,val);			
				}	
			}
			
			cout<<"\n\nTri Diagonal Elements are:-";
			for(int i=0;i<s;++i)
			cout<<element[i]<<"  ";
}





template<class T>
void matrix<T>::set_tridigonal(int i,int j, const T& val)
{
		switch(i-j)
	{
		case 1 :   //Lower Diagonal
				element[i-1]=val;
				break;
				
		case 0 :   //Main diagonal 
				element[n+i-1]=val;
				break;
				
		case -1 :   //Upper Triangle
				element[2*n+i-1]=val;
				break;
				
		default:
					cout<<"Non-Tridigonal element must be zero\n";
	};
}




template<class T>
T matrix<T>::get_tridigonal(int i,int j)
{
		switch(i-j)
	{
		case 1 :   //Lower Diagonal
				 return element[i-1];
				 break;
				
		case 0 :   //Main diagonal 
				return element[n+i-1];
				break;
				
		case -1 :   //Upper Triangle
				return element[2*n+i-1];
				break;
				
		default:
					return 0;
	};
}



template<class T>
void matrix<T>::show_tridigonal()
{
	T val;
	cout<<"\n";
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			val=get_tridigonal(i,j);
			cout<<val<<" ";
		}
		cout<<endl;
	}
}


//Lower Triangular Matrix


template<class T>
void matrix<T>::lowertri()
{
		T val;
		int s;
	
	cout<<"\nEnter the size of Rows:-";
	cin>>n;
	s=((n*(n+1))/2);
	a =new T*[n];
	for(int i=0;i<n;++i)
	a[i]=new T[n];
	element=new T[s];
	cout<<"\nEnter the element of the array:- ";
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
		{
			if(i>=j)
			{
			
			cout<<"\nEnter the element at  "<<"a["<<i<<"]["<<j<<"]"<<":-";
			cin>>a[i][j];
			val=a[i][j];
			set_lowertri(i,j,val);
			}
			
		}
			cout<<"\n\nLower Triangluar Elements are:-";
			for(int i=0;i<s;++i)
			cout<<element[i]<<"  ";
}

template<class T>
void matrix<T>::set_lowertri(int i,int j,const T& val)
{
		if(i<0||j<0||i>n||j>n)
		{
			cout<<"Index out of Bound";
			
		}
		
		if(i>=j)
		{
			element[i*(i+1)/2+j]=val;
		}
		else
		 if(val!=0)
		 	cout<<"Non Lower Triangular element must be zero";
}

template<class T>
T matrix<T>::get_lowertri(int i,int j)
{
		if(i<0||j<0||i>n||j>n)
		{
			cout<<"Index out of Bound";
			
		}
		
		if(i>=j)
		{
			return element[i*(i+1)/2+j];
		}
		else
		 return 0;
}

template<class T>
void matrix<T>::show_lowertri()
{	T ele;
	cout<<"\n\n";
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			ele=get_lowertri(i,j);
			cout<<ele<<" ";
		}
		cout<<endl;
	}
}


//Upper Triangular Matrix


template<class T>
void matrix<T>::uppertri()
{
		T val;
		int s;
	
	cout<<"\nEnter the size of Rows:-";
	cin>>n;
	s=((n*(n+1))/2);
	a =new T*[n];
	for(int i=0;i<n;++i)
	a[i]=new T[n];
	element=new T[s];
	cout<<"\nEnter the element of the array:- ";
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
		{
			if(i<=j)
			{
			
			cout<<"\nEnter the element at  "<<"a["<<i<<"]["<<j<<"]"<<":-";
			cin>>a[i][j];
			val=a[i][j];
			set_uppertri(i,j,val);
			}
			
		}
			cout<<"\n\nUpper Triangluar Elements are:-";
			for(int i=0;i<s;++i)
			cout<<element[i]<<"  ";
}



template<class T>
void matrix<T>::set_uppertri(int i,int j,const T& val)
{
		if(i<0||j<0||i>n||j>n)
		{
			cout<<"Index out of Bound";
			
		}
		
		if(i<=j)
		{
			element[j+(i*n)-i*(i+1)/2]=val;
		}
		else
		 if(val!=0)
		 	cout<<"Non Lower Triangular element must be zero";
}



template<class T>
T matrix<T>::get_uppertri(int i,int j)
{
		if(i<0||j<0||i>n||j>n)
		{
			cout<<"Index out of Bound";
			
		}
		
		if(i<=j)
		{
			return 	element[j+(i*n)-i*(i+1)/2];
		}
		else
		 return 0;
}



template<class T>
void matrix<T>::show_uppertri()
{	T ele;
	cout<<"\n\n";
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			ele=get_uppertri(i,j);
			cout<<ele<<" ";
		}
		cout<<endl;
	}
}


//Symmetric Matrix


template<class T>
void matrix<T>::symm()
{
		T val;
		int s;
	
	cout<<"\nEnter the size of Rows:-";
	cin>>n;
	s=((n*(n+1))/2);
	a =new T*[n];
	for(int i=0;i<n;++i)
	a[i]=new T[n];
	element=new T[s];
	cout<<"\nEnter the element of the array:- ";
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
		{
			if(i>=j)
			{
			
			cout<<"\nEnter the element at  "<<"a["<<i<<"]["<<j<<"]"<<":-";
			cin>>a[i][j];
			val=a[i][j];
			set_symm(i,j,val);
			}
			
		}
			
}



template<class T>
void matrix<T>::set_symm(int i,int j,const T& val)
{
		if(i<0||j<0||i>n||j>n)
		{
			cout<<"Index out of Bound";
			
		}
		
		if(i>=j)
		{
			element[i*(i+1)/2+j]=val;
		}
		
}



template<class T>
T matrix<T>::get_symm(int i,int j)
{
		if(i<0||j<0||i>n||j>n)
		{
			cout<<"Index out of Bound";
			
		}
		
		if(i>=j)
		{
			return element[i*(i+1)/2+j];
		}
		else
			if(i<j)
		 return element[j*(j+1)/2+i];
}



template<class T>
void matrix<T>::show_symm()
{	T ele;
	cout<<"\n\n";
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			ele=get_symm(i,j);
			cout<<ele<<" ";
		}
		cout<<endl;
	}
}



int main()
{
	
	
	matrix<int>m;
	int choice;
	char ans;
	do
	{
	
	cout<<"\nINSTRUCTION TABLE";
	cout<<"\n1.DIGONAL MATRIX";
	cout<<"\n2.TRIDIGONAL MATRIX";
	cout<<"\n3.LOWER TRIANGULAR MATRIX";
	cout<<"\n4.UPPER TRIANGULAR MATRIX";
	cout<<"\n5.SYMMETRIC MATRIX";
	cout<<"\nEnter your choice:-";
	cin>>choice;
	switch(choice)
	{
		case 1:
					m.digonal();
					m.show_diagonal();
					break;
					
		case 2:
					m.tridigonal();
					m.show_tridigonal();
					break;
					
		case 3:
					m.lowertri();
					m.show_lowertri();
					break;
					
		case 4:
					m.uppertri();
					m.show_uppertri();
					break;
					
		case 5:
					m.symm();
					m.show_symm();
					break;
					
		default:
					cout<<"INVALID CHOICE!!!";
					
	}
		cout<<"\n Do you wish to continue?..press y";
		cin>>ans;
	}while(ans=='y');

getch();
return 0;
}



/*

INSTRUCTION TABLE
1.DIGONAL MATRIX
2.TRIDIGONAL MATRIX
3.LOWER TRIANGULAR MATRIX
4.UPPER TRIANGULAR MATRIX
5.SYMMETRIC MATRIX
Enter your choice:-1

Enter the size of Rows:-4

Enter the element of the array:-
Enter the element at  a[0][0]:-1

Enter the element at  a[1][1]:-2

Enter the element at  a[2][2]:-3

Enter the element at  a[3][3]:-4


Diagonal Elements are:-1  2  3  4

1 0 0 0
0 2 0 0
0 0 3 0
0 0 0 4

 Do you wish to continue?..press yy

INSTRUCTION TABLE
1.DIGONAL MATRIX
2.TRIDIGONAL MATRIX
3.LOWER TRIANGULAR MATRIX
4.UPPER TRIANGULAR MATRIX
5.SYMMETRIC MATRIX
Enter your choice:-2

Enter the no of rows-4

Enter the element at  a[0][0]:-1

Enter the element at  a[0][1]:-2

Enter the element at  a[1][0]:-3

Enter the element at  a[1][1]:-4

Enter the element at  a[1][2]:-5

Enter the element at  a[2][1]:-6

Enter the element at  a[2][2]:-7

Enter the element at  a[2][3]:-8

Enter the element at  a[3][2]:-9

Enter the element at  a[3][3]:-10


Tri Diagonal Elements are:-3  6  9  1  4  7  10  2  5  8
1 2 0 0
3 4 5 0
0 6 7 8
0 0 9 10

 Do you wish to continue?..press yy

INSTRUCTION TABLE
1.DIGONAL MATRIX
2.TRIDIGONAL MATRIX
3.LOWER TRIANGULAR MATRIX
4.UPPER TRIANGULAR MATRIX
5.SYMMETRIC MATRIX
Enter your choice:-3

Enter the size of Rows:-4

Enter the element of the array:-
Enter the element at  a[0][0]:-1

Enter the element at  a[1][0]:-2

Enter the element at  a[1][1]:-3

Enter the element at  a[2][0]:-4

Enter the element at  a[2][1]:-5

Enter the element at  a[2][2]:-6

Enter the element at  a[3][0]:-7

Enter the element at  a[3][1]:-8

Enter the element at  a[3][2]:-9

Enter the element at  a[3][3]:-10


Lower Triangluar Elements are:-1  2  3  4  5  6  7  8  9  10

1 0 0 0
2 3 0 0
4 5 6 0
7 8 9 10

 Do you wish to continue?..press yy

INSTRUCTION TABLE
1.DIGONAL MATRIX
2.TRIDIGONAL MATRIX
3.LOWER TRIANGULAR MATRIX
4.UPPER TRIANGULAR MATRIX
5.SYMMETRIC MATRIX
Enter your choice:-4

Enter the size of Rows:-4

Enter the element of the array:-
Enter the element at  a[0][0]:-1

Enter the element at  a[0][1]:-2

Enter the element at  a[0][2]:-3

Enter the element at  a[0][3]:-4

Enter the element at  a[1][1]:-5

Enter the element at  a[1][2]:-6

Enter the element at  a[1][3]:-7

Enter the element at  a[2][2]:-8

Enter the element at  a[2][3]:-9

Enter the element at  a[3][3]:-10


Upper Triangluar Elements are:-1  2  3  4  5  6  7  8  9  10

1 2 3 4
0 5 6 7
0 0 8 9
0 0 0 10

 Do you wish to continue?..press yy

INSTRUCTION TABLE
1.DIGONAL MATRIX
2.TRIDIGONAL MATRIX
3.LOWER TRIANGULAR MATRIX
4.UPPER TRIANGULAR MATRIX
5.SYMMETRIC MATRIX
Enter your choice:-5

Enter the size of Rows:-4

Enter the element of the array:-
Enter the element at  a[0][0]:-1

Enter the element at  a[1][0]:-2

Enter the element at  a[1][1]:-3

Enter the element at  a[2][0]:-4

Enter the element at  a[2][1]:-5

Enter the element at  a[2][2]:-6

Enter the element at  a[3][0]:-7

Enter the element at  a[3][1]:-8

Enter the element at  a[3][2]:-9

Enter the element at  a[3][3]:-10


1 2 4 7
2 3 5 8
4 5 6 9
7 8 9 10

 Do you wish to continue?..press y
*/

#include<iostream>
#include<conio.h>
using namespace std;

template<typename T>
class matrix
{	private:
	T **a, **b, **c, row, col;
	
	public:
		matrix();
		/*~matrix()
		{delete [] a;
		delete [] b;
		delete [] c;
		}
	*/
	
		void input();
		void display();
		T operator+(matrix mat);
		T operator-(matrix mat);
		void multiply(matrix mat);
		void operator = (matrix mat);
		
		
};

template<typename T>
matrix<T>::matrix()
{
	row = 0;
	col = 0;
}


template<typename T>
void matrix<T>::input()
{	
	cout<<"\nEnter the number of rows";
	cin>>row;
	cout<<"\nEnter the number of columns";
	cin>>col;
	
	a=new T*[col];
	for(int i=0;i<row;i++)
	a[i]=new T[col];
	cout<<"\nEnter the matrix";
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			cin>>a[i][j];
		}
	}
}


template<typename T>
void matrix<T>::display()
{
	cout<<"\n The matrix is"<<endl;

	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{	
			cout<<" "<<a[i][j];
		}
		cout<<endl;
	}
}

template<typename T>
T matrix<T>:: operator+(matrix mat)
{
	if((mat.row!=row)||(mat.col!=col))
	cout<<"\n matrix mismatch";
	
	else
	{
	c = new T*[col];	
	for(int i=0;i<row;i++)
	c[i]=new T[col];
	
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			c[i][j] = a[i][j] + mat.a[i][j];
		}
	}
	
		cout<<"After Addition matrix is "<<endl;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			cout<<" "<<c[i][j];
		}
		cout<<endl;
	}
	}
}




template<typename T>
T matrix<T>:: operator-(matrix mat)
{
	if((mat.row!=row)||(mat.col!=col))
	cout<<"\n matrix mismatch";
	
	else
	{
	c = new T*[col];	
	for(int i=0;i<row;i++)
	c[i]=new T[col];
	
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			c[i][j] = a[i][j] - mat.a[i][j];
		}
	}
	
		cout<<"After Addition matrix is "<<endl;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			cout<<" "<<c[i][j];
		}
		cout<<endl;
	}
	}
}




template<typename T>
void matrix<T>::multiply(matrix mat)
{
	if(col!=mat.row)
	cout<<"\nError!! column of first matrix must be equal to row of second matrix";
	else
	{
	c=new T*[mat.col];
	for(int i=0;i<row;i++)
	c[i]=new T[mat.col];
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<mat.col;j++)
		{
			c[i][j]=0;
		}
	}
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<mat.col;j++)
		{
			for(int k=0;k<col;k++)
			{
				c[i][j]+=a[i][k]*mat.a[k][j];
			}
		}
	}
	cout<<"\n After Multiplying matrices the result is "<<endl;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<mat.col;j++)
		{
			cout<<" "<<c[i][j];
		}
		cout<<endl;
	}
	
   }
	
}
template<typename T>
void matrix<T>::operator =(matrix mat)
{
	row=mat.row;
	col=mat.col;
	c=new T*[col];
	for(int i=0;i<row;i++)
	c[i]=new T[col];
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			a[i][j]=mat.a[i][j];
		}
	}
	cout<<"\n After assignment the first matrix result is"<<endl;
		for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
		 cout<<" "<<a[i][j];
		}
		cout<<endl;
	}
}





int main()
{	
matrix<int> m,n;
	int ch;
	char ans;
	do
	{
	 cout<<"\nEnter your choice \n1.Display the matrix\n2.Overload + operator\n3.Overload - operator\n4.Multiply two matrices\n5.Overload = operator";
	 cout<<"\nYour Choice:-";
	 cin>>ch;
	 switch(ch)
	 {
	 	case 1:
	 		m.input();
	 		m.display();
	 		break;
	 	case 2:
	 		m.input();
	 		n.input();
	 		cout<<"\n First Matrix:-"<<endl;
	 		m.display();
	 		cout<<"\n Second Matrix:-"<<endl;
	 		n.display();
	 		m+n;
	 		break;
	 	case 3:
	 		m.input();
	 		n.input();
	 		cout<<"\n First Matrix:-"<<endl;
	 		m.display();
	 		cout<<"\n Second Matrix:-"<<endl;
	 		n.display();
	 		m-n;
	 		break;
	 	case 4:
	 		m.input();
		    n.input();
		    cout<<"\n First Matrix:-"<<endl;
	 		m.display();
	 		cout<<"\n Second Matrix:-"<<endl;
	 		n.display();
			m.multiply(n);	 
			break;
		case 5:
			m.input();
			n.input();
			cout<<"\n First Matrix:-"<<endl;
	 		m.display();
	 		cout<<"\n Second Matrix:-"<<endl;
	 		n.display();
			m=n;
		}
		cout<<"\n Do you want more matrices to perform then press y:-";
		cin>>ans;
	}while(ans=='y');
	
getch();
return 0;
}

/*

Enter your choice
1.Display the matrix
2.Overload + operator
3.Overload - operator
4.Multiply two matrices
5.Overload + operator
Your Choice:-1

Enter the number of rows2

Enter the number of columns3

Enter the matrix1
2
3
4
5
6

 The matrix is
 1 2 3
 4 5 6

 Do you want more matrices to perform then press y:-y

Enter your choice
1.Display the matrix
2.Overload + operator
3.Overload - operator
4.Multiply two matrices
5.Overload + operator
Your Choice:-2

Enter the number of rows2

Enter the number of columns3

Enter the matrix1
2
3
4
5
6

Enter the number of rows2

Enter the number of columns3

Enter the matrix2
4
6
8
10
12

 First Matrix:-

 The matrix is
 1 2 3
 4 5 6

 Second Matrix:-

 The matrix is
 2 4 6
 8 10 12
After Addition matrix is
 3 6 9
 12 15 18

 Do you want more matrices to perform then press y:-y

Enter your choice
1.Display the matrix
2.Overload + operator
3.Overload - operator
4.Multiply two matrices
5.Overload + operator
Your Choice:-3

Enter the number of rows2

Enter the number of columns3

Enter the matrix2
4
3
5
6
4

Enter the number of rows2

Enter the number of columns3

Enter the matrix4
2
3
5
7
1

 First Matrix:-

 The matrix is
 2 4 3
 5 6 4

 Second Matrix:-

 The matrix is
 4 2 3
 5 7 1
After Addition matrix is
 -2 2 0
 0 -1 3

 Do you want more matrices to perform then press y:-y

Enter your choice
1.Display the matrix
2.Overload + operator
3.Overload - operator
4.Multiply two matrices
5.Overload + operator
Your Choice:-4

Enter the number of rows3

Enter the number of columns3

Enter the matrix1
2
3
4
5
6
7
8
9

Enter the number of rows3

Enter the number of columns3

Enter the matrix1
2
3
4
5
6
7
8
9

 First Matrix:-

 The matrix is
 1 2 3
 4 5 6
 7 8 9

 Second Matrix:-

 The matrix is
 1 2 3
 4 5 6
 7 8 9

 After Multiplying matrices the result is
 30 36 42
 66 81 96
 102 126 150

 Do you want more matrices to perform then press y:-y
 
 
 Enter your choice
1.Display the matrix
2.Overload + operator
3.Overload - operator
4.Multiply two matrices
5.Overload = operator
Your Choice:-5

Enter the number of rows2

Enter the number of columns3

Enter the matrix1
2
3
4
5
6

Enter the number of rows2

Enter the number of columns3

Enter the matrix1
2
3
4
5
6

 First Matrix:-

 The matrix is
 1 2 3
 4 5 6

 Second Matrix:-

 The matrix is
 1 2 3
 4 5 6

 After assignment the first matrix result is
 1 2 3
 4 5 6

 Do you want more matrices to perform then press y:-

 */

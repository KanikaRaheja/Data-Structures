#include<iostream>
#include<conio.h>

using namespace std;

class matrix
{public:
	void input(int r,int c, int **a)
	{
		cout << "Enter number of rows (between 1 and 100): ";
    cin >> r;

    cout << "Enter number of columns (between 1 and 100): ";
    cin >> c;

    cout << endl << "Enter elements of 1st matrix: " << endl;
	
	for(int i = 0; i < r; ++i)
       for(int j = 0; j < c; ++j)
       {
           cout << "Enter element a" << i + 1 << j + 1 << " : ";
           cin >> a[i][j];
       }

	}
	
	void display(int r, int c, int a[][100])
	{
	
	for(int i = 0; i < r; ++i)
      { for(int j = 0; j < c; ++j)
       {cout<<" ";
          cout<<a[i][j];
       }
       cout<<endl;
   }
	
	}
};
int main()
{int r, c, b[100][100], sum[100][100], i, j;
int **a = new int[100];
    
	matrix m;
	m.input(3,3, **a);
	m.display(3, 3, a);
	getch();
	return 0;
}















/*
using namespace std;
template<typename T>
class matrices
{
	
	private:
		T *element;
		T **a;
		int rows,cols;
		
	public:
			matrices(int rows, int cols);
			~matrices()
			{
				delete [] element;
			}
	
			
				void matrix_input();
				T addition();
				T subs();
				T multiply();
				void display();

};

template<class T>
matrices<T>::matrices(int rows, int cols)
{
	this->rows = rows;
	this->cols = cols;
}

template<class T>
void matrices<T>::matrix_input()
{	a = new T* [rows];
	cout<<"Enter your matrix elements: \n";
	for (int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
		cout<<"a["<<i<<"]["<<j<<"]: ";
        cin>>a[i][j];
		}
	}

}


template<class T>
void matrices<T>::display()
{
	
	for (int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			cout<<" ";
		cout<<"a["<<i<<"]["<<j<<"]: ";
        
		}
	}

}




int main()
{
	matrices<int> m(3,3);
	m.matrix_input();
	m.display();
	
}
*/


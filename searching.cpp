//searching
#include<iostream>
#include<conio.h>
using namespace std;
   template<class type>
//searching
    class search
    {
    	type size,n,ar[];
    	public:
    		int input();
    		int lsrch(type ar[],type size,type n);
    		int bisrch(type ar[],type size,type n);
    		int choice();
    		
	};
	  template<class type>
//function to take input from user
	  search<type> :: input()
	  {
	  	cout<<"Enter the size of array\n";
	  	cin>>size;
	  	cout<<"\nEnter the sorted array\n";
	  	for(int i=0;i<size;i++)
	  	cin>>ar[i];
	  	cout<<"\nEnter the element you want to search\n";
	  	cin>>n;
	  }
	   template<class type>
//function to find the user entered element through linear search
	   search<type> :: lsrch(type ar[],type size,type n)
	   {
	   	  type c=0;
	   	for(int i=0;i<size;i++)
	   	{
	   		if(ar[i]==n)
	   		{
	   			cout<<"\n "<<n<<" is at the "<<i<<" position";
	   			break;
			}
			c++;
		}
			if(c==size)
			cout<<"\n the element is not found";
	   }
			template<class type>
//function to find the user entered element through binary search
			search<type>::bisrch(type ar[],type size,type n)
			{
				type first=0;
				type last=size-1;
				type mid;
				type flag=0;
				while(first<=last)
				{
				 	mid=(first+last)/2;
					if(n>ar[mid])
					first=mid+1;

				else if(n<ar[mid])
					last=mid-1;
					else
					{
						flag=1;
					    first=last+1;
				   }
				   	 
                }
                if(flag)
                cout<<"\n"<<n<<" is present at "<<mid<<" in the array";
                else
				cout<<"\nElement is not present in the array";
			}
		template<class type>
//function to take the choice from the users 
	   search<type> :: choice()
	   {
	   	   char ans;
	   	   int ch;
	   	   do
	   	   {
	   	   cout<<"Enter your choice \n1.linear search \n2.Binary search\n";
	   	   cin>>ch;
	   	   input();
	   	   switch(ch)
	   	   {
	   	   	case 1:
	   	   	 lsrch(ar,size,n);
	   	   	 break;
	   	   	case 2:
	   	   	 bisrch(ar,size,n);
	   	   	 break;
	   	   	default:
	   	   		cout<<"\n Enter with in range 1 or 2";
		   }
		   cout<<"\n Do you want more array to be sorted then press y";
		   cin>>ans;
	     }while(ans=='y');
   }
	     int main()
	     {
	       search<int> s;
	       s.choice();
	   	   getch();
	   	   return 0;
	   }
	   
//OUTPUT OF THE CODE
/* 
Enter your choice
1.linear search
2.Binary search
1
Enter the size of array
7

Enter the sorted array
12
34
56
78
99
122
231

Enter the element you want to search
122

 122 is at the 5 position
 Do you want more array to be sorted then press yy
Enter your choice
1.linear search
2.Binary search
2
Enter the size of array
8

Enter the sorted array
2
5
47
83

92
154
155
201

Enter the element you want to search
154

154 is present at 5 in the array
 Do you want more array to be sorted then press y*/


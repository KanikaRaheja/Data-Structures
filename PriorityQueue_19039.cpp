#include<iostream>
#include<conio.h>
#include "MaximumHeap.h"

using namespace std;

class Pri_queue
{
	MaxHeap m;
	public:
		Pri_queue();
		void insert(int);
		int getPri_key();
		int deletePri_key();
		void delete_key(int);
		void change_pri(int,int);
		void display();
		
};

Pri_queue::Pri_queue():m(){}

void Pri_queue::insert(int e)
{
	m.insertKey(e);
}

int Pri_queue::getPri_key()
{
	return m.getMax();
}

int Pri_queue::deletePri_key()
{
	return m.extractMax();
}

void Pri_queue::delete_key(int i)
{
	m.deleteKey(i);
}

void Pri_queue::change_pri(int i,int y)
{
	m.increaseKey(i,y);
}


void Pri_queue::display()
{
	m.display();
}
int main()
{
	Pri_queue h;
		int choice,e;
		char ch;
		do
		{
		
			cout<<"\n\nImstruction Table";
			cout<<"\n1.Insert a key";
			cout<<"\n2.Delete a key";
			cout<<"\n3.Get the priority key";
			cout<<"\n4.Delete the priority key";
			cout<<"\n5.Change the Priority";
			cout<<"\n6.Display";
			cout<<"\n\nEnter your choice:-";
			cin>>choice;
			switch(choice)
			{
				case 1:
						do
						{
								cout<<"\n\nEnter the element:-";
								cin>>e;
								h.insert(e);
								cout<<"\nAdd more(Y/N):-";
								cin>>ch;
						}while(ch=='y'||ch=='Y');
						cout<<endl<<endl;
						break;
						
				case 2:
							cout<<"\n\nEnter the key to be deleted:-";
							cin>>e;
							h.delete_key(e);
							cout<<"\n\n";
							break;
					
				case 3:
					
							cout<<"\n\n"<<h.getPri_key()<<" is the maximum key\n\n";
							break;
							
				case 4:
							cout<<"\n\n"<<h.deletePri_key()<<" is deleted";
							break;
							
				case 5:
							cout<<"\n\nEnter the required key:-";
							cin>>e;
							int e1;
							cout<<"\nEnter the new value:-";
							cin>>e1;
							h.change_pri(e,e1);
							break;
							
				case 6:
							cout<<"\n\n";
							h.display();
							break;
							
				default:
							cout<<"\n\nINVALID CHOICE!!!!\n\n";
			};
			cout<<"\n\nDo you want to continue(Y/N):-";
			cin>>ch;
		}while(ch=='y'||ch=='Y');
	
getch();
return 0;	
}

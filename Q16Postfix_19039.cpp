//Program to evaluate a postfix expression using stacks.

#include<iostream>
#include<conio.h>
#include<string>
#include<stack>
#include<math.h>	
#include<stdlib.h>

using namespace std;

class Postfix
{
	string exp;		 
	public:
		PostfixEval()
		{
			exp='\0';
		}
		void getdata();			 
		bool isOperator(char);	 
		bool isDigit(char);	 
		int convertNum(char);	 
		
		float oper(int a,int b,char symbol); 
		float eval();		 
};

//taking input
void Postfix::getdata()
{
	cout<<"Enter the postfix expression:- ";
	cin>>exp;
}

//checking for the operator
bool Postfix::isOperator(char ch)
{
	if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
	return true;
	
	return false;
}

//checking for the opearnds 
bool Postfix::isDigit(char ch) 
{
	return (ch>='0' && ch<='9');
}

int Postfix::convertNum(char ch)
{
	int k = atoi(&ch);
	return k;
}

//performing the opeartions
float Postfix::oper(int a, int b, char symbol)
{
	switch(symbol)
	{
		case '+': return b+a;
		case '-': return b-a;
		case '*': return b*a;
		case '/': return b/a;
		case '^': return pow(b,a);	 
		default: cout<<"\nINVALID OPERATION!"; 
	}
}

//evaluating the expression
float Postfix::eval()
{
	int a,b;	
	stack<int> stackob;		 
	string::iterator i;
	for(i=exp.begin(); i!=exp.end(); i++)
	{
		if(isDigit(*i))
		{
			stackob.push(convertNum(*i));
		}
		else if(isOperator(*i))
		{
			a=stackob.top();
			stackob.pop();
			b=stackob.top();
			stackob.pop();
			stackob.push(oper(a,b,*i));
		}
	}
	return stackob.top();
}

int main()
{ 
	Postfix p;
	p.getdata();
	cout<<"\nAfter evluation result is:- "<<p.eval()<<endl;
	getch();
	return 0;
}

/*
OUTPUT
Enter the postfix expression:- 53+62/*35*+

After evluation result is:- 39
*/

#include<iostream>
#include<string>
#include<fstream>
#include "mytoolkit.h"
#define MAX 100
using namespace std;
ofstream outfile;
ifstream infile;
int prec(char ch)
{
	switch (ch)
	{
	case  '^':return 3;//level
	case  '*':
	case  '/':return 2;
	case  '+':
	case  '-':return 1;
	default:return -1;
	}
}
void write(string inp)
{
	outfile << inp;
}
void read()
{
	string reading;
	infile >> reading;
}
int main()
{
	stackLinkList<char> S;
	string infix,postfix;
	infile.open("text.txt", ios::in);
	outfile.open("text.txt", ios::app);
	int i = 0;
	char token;
	int ch;
	char temp;
	do
	{
		cout << "++++++++ Menu +++++++++++\n";
		cout << "1 ) Reading From File \n";
		cout << "2 ) Reading From Command Line\n";
		cout << "Enter Your Choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			infile >> infix;
			if (infix == "-1")
				cout << "File Not Find;n";
			break;
		case 2:
			cin.ignore(10, '\n');
			cout << "Enter infix Notation (Write on File ): ";
			getline(cin, infix);
			outfile << infix;
			break;
		default:
			cout << "Wrong Choice \n";
		}
	} while (ch != 1 || ch != 2);
	infile.close();
	while(infix[i]!='\0')
	{	token = infix[i];
		 if (token == '(')
			S.push(token);
		 else if (token == '+' || token == '-' || token == '*' || token == '/' || token == '^')
		{
			 if(S.isEmpty())
				S.push(token);
			 else
			 {
				 while ((!S.isEmpty()) && (prec(token)<=prec(S.peek())))
				 {
						 temp = S.pop();
						 postfix.append(1, temp);
				 }
				 S.push(token);
			 }
		}
		else if (token == ')')
		{
			while (S.peek()!= '(')
			{
				temp = S.pop();
				postfix.append(1, temp);
			}
			S.pop();//removing '(' from stack

		}
		else
			 postfix.append(1,token);
		 i++;
	}
	while (!S.isEmpty())//making stack empty
	{
		temp = S.pop();
		postfix.append(1, temp);
	}
	cout << " Infix to PostFix \n ";
	cout << "Before : " << infix << endl;
	cout << "After : " << postfix << endl;
	if (!S.isEmpty())
	{
		cout << "Your Stack is Not Empty Yet\n";
			system("pause");
	}
	system("pause");

}
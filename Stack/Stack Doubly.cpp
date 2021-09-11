#include<iostream>
#include "hamza.h"
using namespace std;
int main()
{
	stackD S;
	int ch, data;
	int res;
	do
	{
		system("cls");
		cout << "+++++++++++   MAIN  MENU  +++++++++++++\n\n";
		cout << "1 ) PUSH ON STACK\n\n";
		cout << "2 ) POP ON STACK\n\n";
		cout << "3 ) PEEK OFF STACK\n\n";
		cout << "4 ) EXIT\n\n";
		cout << "Enter Choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "Enter Data To Push on Stack : ";
			cin >> data;
			S.push(data);
			break;
		case 2:
			if (!S.isEmpty())
			{
				res = S.pop();
				cout << "Poped Data : " << res << endl;
				system("pause");
			}
			else
			{
				cout << "Stack is Empty\n";
				system("pause");
			}
			break;
		case 3:
			if (!S.isEmpty())
			{
				res = S.peek();
				cout << "Data on TOP of Stack : " << res << endl;
				system("pause");
			}
			else
			{
				cout << "Stack is Empty\n";
				system("pause");
			}
			break;
		case 4:
			exit(-1);
		default:
			cout << "You Enter the wrong choice \n\n";
			break;
		}
	} while (true);
	system("pause");
}
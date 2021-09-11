#include<iostream>
#include<string>
#include<cmath>
#include "mytoolkit.h"
#define MAX 100
using namespace std;
int main()
{
	stackLinkList<int> S;
	string postfix;
	int i = 0;
	char token;
	int op1, op2,opr,res;
	cout << "Enter Postfix Notation : ";
	getline(cin, postfix);
	while (postfix[i] != NULL)
	{
		token = postfix[i];
		if (token >= '0' && token <= '9')
		{
			opr = static_cast<int>(token)-'0';//-48 convert character from integer
			S.push(opr);
		}
		else 
		{
			op2 = S.pop();//2nd operand  
			op1 = S.pop();//1st operand
			switch (token)
			{
			case '^':
				res = pow(op1, op2);
				S.push(res);
				break;
			case '*':
				res = op1 * op2;
				S.push(res);
				break;
			case '/':
				res = op1 / op2;
				S.push(res);
				break;
			case '+':
				res = op1 + op2;
				S.push(res);
				break;
			case '-':
				res = op1 - op2;
				S.push(res);
				break;
			}
		}
		i++;
	}
	cout << "Result : " << S.pop() << endl;
	cout << S.isEmpty() << endl;
	system("pause");
}
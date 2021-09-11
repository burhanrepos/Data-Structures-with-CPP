#include<iostream>
#include<string>
#include<cmath>
#define MAX 100
using namespace std;
template<class T>
class stackLinkList//stack class with linkedlist
{
	template<class T>
	class node
	{
	public:
		T m;
		node<T> *next;
		node<T>() : m(0), next(NULL) {}
	};
	node<T> *head;
	node<T> *cur;
	node<T> *pre;
public:
	stackLinkList<T>() : head(NULL), cur(NULL), pre(NULL) {}
	void push(T data);
	T pop();
	bool isEmpty();
	T peek();
};
template<class T>
void stackLinkList<T>::push(T data)
{
	cur = new node<T>;
	cur->next = NULL;
	cur->m = data;
	if (head == NULL)
		head = pre = cur;
	else
	{
		pre->next = cur;
		pre = cur;
	}
}
template<class T>
T stackLinkList<T>::pop()
{
	cur = pre = head;
	while (cur)
	{
		if (cur->next == NULL)
		{
			int temp = cur->m;
			if (head == cur)
				head = NULL;
			else
				pre->next = NULL;
			delete cur;
			return temp;
		}
		pre = cur;
		cur = cur->next;
	}
}
template<class T>
bool stackLinkList<T>::isEmpty()
{
	if (head == NULL)
		return true;
	else
		return false;
}
template<class T>
T stackLinkList<T>::peek()
{
	if (head != NULL)
		return pre->m;
}
int prec(char ch);//Simple Methods without class
string infix_prefix(string infix);//Simple Methods without class
string infix_postfix(string infix);//Simple Methods without class
int evaluate_postfix(string post);//Simple Methods without class
int evaluate_prefix(string pre);//Simple Methods without class
int main()
{
	int i ;
	int op1, op2, opr, res,choice, length;
	string infix,postfix,tempstr,prefix;
	char token;
	char temp;
	do
	{
		cout << "++----------------++  Main Menu  ++-------------------++\n\n";
		cout << "1 ) Infix to PostFix\n\n";
		cout << "2 ) Infix to PreFix\n\n";
		cout << "3 ) Postfix Evaluation\n\n";
		cout << "4 ) Prefix Evaluation\n\n";
		cout << "5 ) Exit\n\n";
		cout << "Enter Choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1://infix to postfix
			cin.ignore(10, '\n');
			cout << "Enter infix Notation : ";
			getline(cin, infix);
			postfix = infix_postfix(infix);
			cout << "Postfix Notation : " << postfix << endl;
			break;
		case 2://infix to pREfix
			cin.ignore(10, '\n');
			cout << "Enter infix Notation : ";
			getline(cin, infix);
			prefix = infix_prefix(infix);
			cout << "Prefix Notation : " << prefix << endl;
			break;
		case 3://postfix evaluation
			cin.ignore(10, '\n');
			cout << "Enter Postfix Notation : ";
			getline(cin, postfix);
			res = evaluate_postfix(postfix);
			cout << "Result of Postfix Expression : " << res << endl;
			break;
		case 4://prefix evaluation
			cin.ignore(10, '\n');
			cout << "Enter Prefix Notation : ";
			getline(cin, prefix);
			res = evaluate_prefix(prefix);
			cout << "Result of Postfix Expression : " << res << endl;
			break;
		case 5://exit
			exit(-1);
		default:
			cout << "wrong choice ,enter again\n\n";
			break;
		}
	} while (true);
	system("pause");
}
int evaluate_postfix(string post)
{
	stackLinkList<int> E;
	char token;
	int op1, op2, opr, res;
	int i = 0;
	while (post[i] != NULL)
	{
		token = post[i];
		if (token >= '0' && token <= '9')
		{
			opr = static_cast<int>(token) - 48;//-48 convert character from integer
			E.push(opr);
		}
		else
		{
			op2 = E.pop();//2nd operand  
			op1 = E.pop();//1st operand
			switch (token)
			{
			case '^':
				res = pow(op1, op2);
				E.push(res);
				break;
			case '*':
				res = op1 * op2;
				E.push(res);
				break;
			case '/':
				res = op1 / op2;
				E.push(res);
				break;
			case '+':
				res = op1 + op2;
				E.push(res);
				break;
			case '-':
				res = op1 - op2;
				E.push(res);
				break;
			}
		}
		i++;
	}
	int temp = E.pop();
	return temp;
}
int evaluate_prefix(string pre)
{
	stackLinkList<int> E;
	char token;
	int op1, op2, opr, res;
	int i = pre.length();
	while (i >=0)
	{
		token = pre[i];
		if (token >= '0' && token <= '9')
		{
			opr = static_cast<int>(token) - 48;//-48 convert character from integer
			E.push(opr);
		}
		else
		{
			op1 = E.pop();//1st operand  
			op2 = E.pop();//2nd operand
			switch (token)
			{
			case '^':
				res = pow(op1, op2);
				E.push(res);
				break;
			case '*':
				res = op1 * op2;
				E.push(res);
				break;
			case '/':
				res = op1 / op2;
				E.push(res);
				break;
			case '+':
				res = op1 + op2;
				E.push(res);
				break;
			case '-':
				res = op1 - op2;
				E.push(res);
				break;
			}
		}
		i--;
	}
	int temp = E.pop();
	return temp;
}
string infix_prefix(string infix)
{
	stackLinkList<char> S;
	string prefix;
	int token, length;
	char temp;
	reverse(infix.begin(), infix.end());
	int i = 0;
	while (infix[i]!=NULL)
	{
		if (infix[i] == '(')
			infix[i] = ')';
		else if (infix[i] == ')')
			infix[i] = '(';
		i++;
	}
	prefix = infix_postfix(infix);
	reverse(prefix.begin(), prefix.end());
	return prefix;
}
string infix_postfix(string infix)
{
	stackLinkList<char> S;
	char token,temp;
	string postfix;
	int i = 0;
	while (infix[i] != '\0')
	{
		token = infix[i];
		if (token == '(')
			S.push(token);
		else if (token == '+' || token == '-' || token == '*' || token == '/' || token == '^')
		{
			if (S.isEmpty())
				S.push(token);
			else
			{
				while ((!S.isEmpty()) && (prec(token) <= prec(S.peek())))
				{
					temp = S.pop();
					postfix.append(1, temp);
				}
				S.push(token);
			}
		}
		else if (token == ')')
		{
			while (S.peek() != '(')
			{
				temp = S.pop();
				postfix.append(1, temp);
			}
			S.pop();//removing '(' from stack

		}
		else
			postfix.append(1, token);
		i++;
	}
	while (!S.isEmpty())//making stack empty
	{
		temp = S.pop();
		postfix.append(1, temp);
	}
	return postfix;
}
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
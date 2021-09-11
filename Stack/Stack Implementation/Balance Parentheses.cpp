#include<iostream>
#include<string>
using namespace std;
template<class T>
class stackLinkList
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
bool balance_parentheses(string str);
int main()
{
	string str;
	char ch;
	do
	{
		cout << "Enter Parantheses String : ";
		getline(cin, str);
		if (balance_parentheses(str))
			cout << "Balanced\n";
		else
			cout << "Not Balanced\n";
		cout << "Do you want to Enter Again ( Y : N ) : ";
		cin >> ch;
		cin.ignore(10, '\n');
	} while (toupper(ch) == 'Y');
	system("pause");
}
bool balance_parentheses(string str)
{
	stackLinkList<char> S;
	int i = 0;
	char token,temp;
	while (str[i] != NULL)
	{
		token = str[i];
		if (token == '{' || token == '[' || token == '(')//simply push when left parenth accurs
			S.push(token);
		else if (S.isEmpty())//this condition is true when you enter right parenth in start
			return false;
		else
		{
			switch (token)
			{
			case ')':
				temp = S.peek();
				S.pop();//removing top value from stack before checking that it's a true case
				if (temp == '{' || temp == '[')
					return false;
				break;
			case ']':
				temp = S.peek();
				S.pop();//removing top value from stack before checking that it's a true case
				if (temp == '{' || temp == '(')
					return false;
				break;
			case '}':
				temp = S.peek();
				S.pop();//removing top value from stack before checking that it's a true case
				if (temp == '[' || temp == '(')
					return false;
				break;
			}
		}
		i++;
	}
	return S.isEmpty();//if any of return donot run so then it's balance paranthese ,,,and S.empty return true;
}
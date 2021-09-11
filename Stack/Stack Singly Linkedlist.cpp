#include<iostream>
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
		node<T>():m(0),next(NULL){}
	};
	node<T> *head;
	node<T> *cur;
	node<T> *pre;
public:
	stackLinkList<T>():head(NULL),cur(NULL),pre(NULL){}
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
			int temp= cur->m;
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
int main()
{
	stackLinkList<int> S;
	int ch,data;
	int res;
	do
	{
		system("cls");
		cout << "+++++++++++   MAIN  MENU  +++++++++++++\n\n";
		cout << "1 ) PUSH ON STACK\n\n";
		cout << "2 ) POP FROM STACK\n\n";
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
				cout << "UnderFlow\n";
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
				cout << "UnderFlow\n";
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
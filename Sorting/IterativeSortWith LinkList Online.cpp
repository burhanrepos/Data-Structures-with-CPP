#include<iostream>
using namespace std;
template<class T>
class node
{
public:
	T data;
	node<T> *next;
	node<T>():next(NULL){}
};
template<class T>
class iterative_Sort
{
	node<T> *head, *pre, *cur, *nsNode,*temp;
public:
	iterative_Sort<T>():head(NULL),pre(NULL),cur(NULL),temp(NULL),nsNode(NULL){}
	void setter();
	void getter();
	void bubbleSort();
    void insertionSort();
	void selectionSort();
};
template<class T>
void iterative_Sort<T>::setter()
{
	char ch;
	head = cur = pre = NULL;
	do
	{
		nsNode = new node<T>;
		nsNode->next = NULL;
		cout << "Enter Data On Node : ";
		cin >> nsNode->data;
		if (head == NULL)
			head = pre = nsNode;
		else
		{
			pre->next = nsNode;
			pre = nsNode;
		}
		cout << "Have Another Data (YES : Y || No : N ) : ";
		cin >> ch;
	} while (ch == 'Y' || ch == 'y');
}
template<class T>
void iterative_Sort<T>::bubbleSort()
{
	bool flag;
	for (pre = head; pre != NULL; pre = pre->next)
	{
		flag = false;
		for (cur = head; cur->next != NULL; cur = cur->next)
		{
			if (cur->data > cur->next->data)
			{
				T temp = cur->data;
				cur->data = cur->next->data;
				cur->next->data = temp;
				flag = true;
			}
			if (!flag)
				break;
		}
	}
}
template<class T>
void iterative_Sort<T>::selectionSort()
{
	for (pre = head; pre != NULL; pre = pre->next)
	{
		temp = pre;
		for (cur = pre->next; cur != NULL; cur = cur->next)
			if (cur->data < temp->data)
				temp = cur;
		if (temp != pre)
		{
			T temp1 = pre->data;
			pre->data = temp->data;
			temp->data = temp1;
		}
	}
}
template<class T>
void iterative_Sort<T>::insertionSort()
{
	for (cur = head->next; cur != NULL; cur = cur->next)
	{
		temp = head;
		while (temp != cur )
		{
			if(cur->data < temp->data)
			swap(temp->data, cur->data);
			else
				temp = temp->next;
		}
		
	}
}
template<class T>
void iterative_Sort<T>::getter()
{
	pre = head;
	cout << "List Items Are \n";
	while (pre)
	{
		cout << pre->data << " \n";
		pre = pre->next;
	}
}
int main()
{
	iterative_Sort<int> S;
	int  ch;
	bool check = false;
	do
	{
		cout << "-____-____-  MENU -____-____-\n\n";
		cout << "1 ) Input In Array \n\n";
		cout << "2 ) Bubble Sort\n\n";
		cout << "3 ) Insertin Sort\n\n";
		cout << "4 ) Selection Sort\n\n";
		cout << "5 ) Display Array \n\n";
		cout << "6 ) EXIT\n\n";
		cout << "Enter Choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			S.setter();
			check = true;
			break;
		case 2:
			if (check)
				S.bubbleSort();
			else
				cout << "First Fill the Array \n\n";
			break;
		case 3:
			if (check)
				S.insertionSort();
			else
				cout << "First Fill the Array \n\n";
			break;
		case 4:
			if (check)
				S.selectionSort();
			else
				cout << "First Fill the Array \n\n";
			break;
		case 5:
			if (check)
				S.getter();
			else
				cout << "First Fill the Array \n\n";
			break;
		case 6:
			exit(-1);
		}
	} while (true);
}
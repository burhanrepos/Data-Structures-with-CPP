#include<iostream>
#include<String>
using namespace std;
template<class T>
class node
{
public:
	T m;
	node<T> *lptr;
	node<T> *rptr;
	node<T>() : lptr(NULL), rptr(NULL) {}
};
template<class T>
class DeQue
{
	node<T> *head;
	node<T> *pre;
	node<T> *cur;
	node<T> *tail;
	static int count;
public:
	DeQue<T>() : head(NULL), pre(NULL), cur(NULL), tail(NULL) {}
	void enQueuefront(T data);
	void enQueuerear(T data);
	T deQueuefront();
	T deQueuerear();
	void display();
	bool isEmpty();
	int Size();
	void MakeNULL();
};
template<class T>
int DeQue<T>::count = 0;
template<class T>
int DeQue<T>::Size()
{
	return count;
}
template<class T>
void DeQue<T>::MakeNULL()
{
	head = NULL;
	pre = NULL;
	cur = NULL;
	tail = NULL;
	count = 0;
}
template<class T>
void DeQue<T>::enQueuefront(T data)
{
	cur = new node<T>;
	cur->lptr = cur->rptr = NULL;
	cur->m = data;
	if (head == NULL)
		tail = head = pre = cur;
	else
	{
		cur->rptr = head;
		head->lptr = cur;
		head = cur;
	}
	count++;
}
template<class T>
void DeQue<T>::enQueuerear(T data)
{
	cur = new node<T>;
	cur->lptr = cur->rptr = NULL;
	cur->m = data;
	if (head == NULL)
		tail = head = pre = cur;
	else
	{
		cur->lptr = tail;
		tail->rptr = cur;
		tail = cur;
	}
	count++;
}
template<class T>
T DeQue<T>::deQueuefront()
{
	T temp = head->m;
	cur = head;
	if (head == tail)
	{
		delete cur;
		head = NULL;
		tail = NULL;
	}
	else
	{
		head = head->rptr;
		head->lptr = NULL;
		delete cur;
	}
	count--;
	return temp;
}
template<class T>
T DeQue<T>::deQueuerear()
{
	T temp = tail->m;
	cur = tail;
	if (head == tail)
	{
		delete cur;
		head = NULL;
		tail = NULL;
	}
	else
	{
		tail = tail->lptr;
		tail->rptr = NULL;
		delete cur;
	}
	count--;
	return temp;

}
template<class T>
bool DeQue<T>::isEmpty()
{
	if (head == NULL)
		return true;
	else
		return false;
}
template<class T>
void DeQue<T>::display()
{
	if (!isEmpty()) {
		node<T>* temp = head;
		cout << "Output : ";
		while (temp != NULL) {
			cout << temp->m << " ";
			temp = temp->rptr;
		}
		cout << endl;
		return;
	}
	cout << "List is Empty" << endl;
}
bool Palindrome(string str)
{
	DeQue<char> D;
	D.MakeNULL();
	int strLen = str.length();
	for (int i = 0; i < strLen; i++)
		D.enQueuerear(str[i]);
	bool check = true;
	while (D.Size() > 1 && check)
	{
		char first = D.deQueuefront();//first element
		char last = D.deQueuerear();//last element
		if (first != last)
			check = false;
	}
	return check;
}

int main()
{
	string str;
	int ch;
	do
	{
		cout << "_________ MAIN MENU _________\n";
		cout << "1 ) Palindrome \n";
		cout << "2 ) Exit \n";
		cout << "Enter Your Choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cin.ignore(10, '\n');
			cout << "Enter String For which you want to find Palindrome : ";
			getline(cin, str);
			if (Palindrome(str))
				cout << "Yes ,It's Palindrome \n";
			else
				cout << "No,It's not Palindrome \n";
			break;
		case 2:
			exit(-1);
		default:
			cout << "You Enter Wrong choice ,Plz Enter CorrectONe \n\n";
		}
	} while (true);
}

















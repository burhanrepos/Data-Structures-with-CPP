#include<iostream>
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
public:
	DeQue<T>(): head(NULL), pre(NULL), cur(NULL), tail(NULL){}
	void enQueuefront(T data); 
	void enQueuerear(T data);
	T deQueuefront();
	T deQueuerear();
	bool isEmpty();
	T getfront();
	T getrear();
};
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

int main()
{
	DeQue<int> Q;
	int data, ch;
	do
	{
		system("cls");
		cout << "-__-__-__-__-__-__-  MAIN MENU  -__-__-__-__-__-__-\n\n";
		cout << "1 ) ENQUEUE (insertion in Queue)\n\n";
		cout << "2 ) DEQUEUE (deletion in Queue)\n\n";
		cout << "3 ) EXIT\n\n";
		cout << "Enter CHoice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			do
			{
				cout << "***** SUB MENU ******\n";
				cout << "1 ) EnQueue From Front \n";
				cout << "2 ) EnQueue From Rear \n";
				cout << "3 ) EXIT\n\n";
				cout << "Enter CHoice : ";
				cin >> ch;
				switch (ch)
				{
				case 1:
					cout << "Enter Data : ";
					cin >> data;
					Q.enQueuefront(data);
					break;
				case 2:
					cout << "Enter Data : ";
					cin >> data;
					Q.enQueuerear(data);
					break;
				case 3:
					break;
				}
			} while (ch != 3);
			break;
		case 2:
			do
			{
				cout << "***** SUB MENU ******\n";
				cout << "1 ) DeQueue From Front \n";
				cout << "2 ) DeQueue From Rear \n";
				cout << "3 ) EXIT\n\n";
				cout << "Enter CHoice : ";
				cin >> ch;
				switch (ch)
				{
				case 1:
					if (!Q.isEmpty())
					{
						data = Q.deQueuefront();
						cout << "DEQUEUED From Front : " << data << endl;
						system("pause");
					}
					else
					{
						cout << "Queue UnderFlow\n";
						system("pause");
					}
					break;
				case 2:
					if (!Q.isEmpty())
					{
						data = Q.deQueuerear();
						cout << "DEQUEUED From Rear : " << data << endl;
						system("pause");
					}
					else
					{
						cout << "Queue UnderFlow\n";
						system("pause");
					}
					break;
				case 3:
					break;
				}
			} while (ch != 3);
			break;
		case 3:
			exit(-1);
		}
	} while (true);
}
			
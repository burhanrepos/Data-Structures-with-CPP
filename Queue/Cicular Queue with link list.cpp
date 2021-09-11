#include<iostream>
using namespace std;
template<class T>
class Queue
{
	template<class T>
	class node
	{
	public:
		T m;
		node<T> *next;
		node<T>() : m(0), next(NULL) {}
	};
	node<T> *front;
	node<T> *cur;
	node<T> *pre;
	node<T> *rear;
public:
	Queue<T>() : cur(NULL), front(NULL), pre(NULL),rear(NULL) {}
	void enQueue(T data);
	T deQueue();
	bool isEmpty();
};
template<class T>
void Queue<T>::enQueue(T data)
{
	cur = new node<T>;
	cur->next = NULL;
	cur->m = data;
	if (front == NULL)
		rear=front = pre = cur;
	else
	{
		rear = cur;
		pre->next = cur;
		pre = cur;
	}
	rear->next = front;
}
template<class T>
T Queue<T>::deQueue()
{
	T temp = front->m;
	pre = front;
	if (front == rear)
	{
		delete pre;
		front = NULL;
		rear = NULL;
	}
	else
	{
		front = front->next;
		rear->next = front;
		delete pre;
	}
	return temp;
}
template<class T>
bool Queue<T>::isEmpty()
{
	if (front == NULL)
		return true;
	else
		return false;
}
int main()
{
	Queue<int> Q;
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

			cout << "Enter Data : ";
			cin >> data;
			Q.enQueue(data);
			break;
		case 2:
			if (!Q.isEmpty())
			{
				data = Q.deQueue();
				cout << "DEQUEUED ELEMENT : " << data << endl;
				system("pause");
			}
			else
			{
				cout << "Queue UnderFlow\n";
				system("pause");
			}
			break;
		case 3:
			exit(-1);
		}
	} while (true);

}
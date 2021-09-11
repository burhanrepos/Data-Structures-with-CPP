#include<iostream>
using namespace std;
#define MAX 5
template<class T>
class Queue
{
	T l[MAX];
	int rear, front;
public:
	Queue<T>():rear(-1),front(-1){}
	void enQueue(T data);
	T deQueue();
	bool isEmpty();
	bool isFull();
	T peek();
};
template<class T>
void Queue<T>::enQueue(T data)
{

	if (rear < MAX - 1)
	{
		if (front == -1)
			front = 0;
		l[++rear] = data;
	}
}
template<class T>
T Queue<T>::deQueue()
{
	if (front < MAX )
	{
		int temp = l[front++];
		if (front == rear)
			front = -1;
		return temp;
	}
}
template<class T>
bool Queue<T>::isEmpty()
{
	if (front == -1)
		return true;
	else
		return false;
}
template<class T>
bool Queue<T>::isFull()
{
	if (rear == MAX-1)
		return true;
	else
		return false;
}
template<class T>
T Queue<T>::peek()
{
	if (rear >= 0 && rear < MAX)
		return l[rear];
	else
		cout << "Queue is Empty\n";
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
			if (!Q.isFull())
			{
				cout << "Enter Data : ";
				cin >> data;
				Q.enQueue(data);
			}
			else
			{
				cout << "Queue OverFlow\n";
				system("pause");
			}
			break;
		case 2:
				if(!Q.isEmpty())
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
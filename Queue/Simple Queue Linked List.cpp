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
	node<T> *front, *rear,*pre,*temp;
	static int count;
public:
	Queue<T>():front(NULL),rear(NULL),pre(NULL){}
	//Operation on Queue using Linkedlist
	void enQueue(T data);
	T deQueue();
	bool isEmpty();
	T peek();
	int size();
	void display();
};
template<class T>
int Queue<T>::count = 0;
template<class T>
void Queue<T>::enQueue(T data)
{
	rear = new node<T>;
	rear->next = NULL;
	rear->m = data;
	if (front == NULL)
		front = pre = rear;
	else
	{
		pre->next = rear;
		pre = rear;
	}
	count++;
}
template<class T>
T Queue<T>::deQueue()
{
	temp = front;
	T temp1 = front->m;		
	front = front->next;
	delete temp;
	count--;
	return temp1;
}
template<class T>
bool Queue<T>::isEmpty()
{
	if (front == NULL)
		return true;
	else
		return false;
}
template<class T>
T Queue<T>::peek()
{
	return front->m;
}
template<class T>
int Queue<T>::size()
{
	return count;
}
template<class T>
void Queue<T>::display()
{
	temp = front;
	while (temp)
	{
		cout << temp->m << "  ";
		temp = temp->next;
	}
	cout << endl;
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
		cout << "3 ) SIZE (elements in Queue)\n\n";
		cout << "4 ) PEEK (element on Front)\n\n";
		cout << "5 ) DISPLAY QUEUE\n\n";
		cout << "6 ) EXIT\n\n";
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
			if (!Q.isEmpty())
			{
				cout << "Size of Queue : " << Q.size() << " . \n";
				system("pause");
			}
			else
			{
				cout << "Queue UnderFlow\n";
				system("pause");
			}
			break;
		case 4:
			if (!Q.isEmpty())
			{
				cout << "Data on The Peak of Queue : " << Q.peek() << " .\n";
				system("pause");
			}
			else
			{
				cout << "Queue UnderFlow\n";
				system("pause");
			}
			break;
		case 5:
			if (!Q.isEmpty())
			{
				Q.display();
				system("pause");
			}
			else
			{
				cout << "Queue UnderFlow\n";
				system("pause");
			}
			break;
		case 6:
			exit(-1);
		}
	} while (true);

}
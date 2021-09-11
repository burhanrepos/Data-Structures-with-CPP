#include<iostream>
using namespace std;
template<class T>
class node
{
public:
	T adj_vertix;
	int weight;
	node<T>* link;
	node<T>* next;
};
template<class T>
class graphs_list
{
	node<T>* cur;
	node<T>* pre;
	node<T>* front;
public:
	graphs_list<T>():cur(NULL),pre(NULL),front(NULL){}
	void createList();
	void  display();
};
template<class T>
void graphs_list<T>::createList()
{
	char ch;
	int count = 1;
	node<T>* c1 = NULL;//for inner list
	node<T>* p1 = NULL;
	node<T>* f1 = NULL;
	do
	{
		cur = new node<T>;
		cout << "Enter Vertix : ";
		cin >>cur->adj_vertix;
		cur->next = cur->link = NULL;
		c1 = NULL;//for inner list
		p1 = NULL;
		f1 = NULL;
		do
		{
			c1 = new node<T>;
			c1->next = NULL;
			cout << "Enter adjecent Vertix : ";
			cin >> c1->adj_vertix;
			cout << "Enter Weight From Vertix " << cur->adj_vertix << " to " << c1->adj_vertix << " : ";
			cin >> c1->weight;
			if (f1 == NULL)
			{
				f1 = p1 = c1;
				cur->weight = c1->weight;
			}
			else
			{
				p1->next = c1;
				p1 = c1;
			}
			cout << "Do you Have Another Adjecent Vertix :(Y / N) ";
			cin >> ch;
			if (toupper(ch) == 'N')
				break;
		} while (true);
		if (front == NULL)
		{
			front = pre = cur;
			front->link = f1;
		}
		else
		{
			pre->next = cur;
			cur->link = f1;
			pre = cur;
		}
		cout << "Do you Have Another Vertix :(Y / N) ";
		cin >> ch;
		if (toupper(ch) == 'N')
			break;
	} while (true);
}
template<class T>
void graphs_list<T>::display()
{
	cur = pre = front;
	cout << endl;
	while (cur)
	{
		if (cur->link != NULL)
		{
			cout << cur->adj_vertix << "->" << cur->link->adj_vertix;
			pre = cur->link->next;
			while (pre)
			{
				cout << "->" << pre->adj_vertix << endl;
				pre = pre->next;
			}
			cout << endl << endl;
		}
		cur = cur->next;
	}
	cur =pre = front;
	cout << endl;
	while (cur)
	{
		cout << "For Vertix " << cur->adj_vertix << " All weights Are \n\n";
		if (cur->link != NULL)
		{
			cout << "Weight Between " << cur->adj_vertix << "->" << cur->link->adj_vertix << " : " << cur->weight << endl;
			pre = cur->link->next;
			while (pre)
			{
				cout << "Weight Between " << cur->adj_vertix << "->" << pre->adj_vertix << " : " << pre->weight << endl;
				pre = pre->next;
			}
			cout << endl << endl;
		}
			cur = cur->next;
	}

}
int main()
{
	graphs_list<int> g;
	int ch,count=0;
	do
	{
		cout << "____________________ MAIN MENU _________________\n\n";
		cout << "1 ) Create Graph (Using List of List)\n\n";
		cout << "2 ) Display Graph \n\n";
		cout << "3 ) Exit \n\n";
		cout << "Enter Choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			g.createList();
			count++;
			break;
		case 2:
			if (count != 0)
				g.display();
			else
				cout << "Graph Does not Exist\n\n";
			break;
		case 3:
			exit(-1);
		}
	} while (true);

}
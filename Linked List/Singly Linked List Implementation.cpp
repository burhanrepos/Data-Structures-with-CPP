#include<iostream>
using namespace std;
class singly
{
	class node
	{
	public:
		int m;
		node *next;
		node() :m(0), next(NULL) {}
	};
	node *cur;
	node *first;
	node *prev;
	node *newnode;
public:
	singly() :cur(NULL), first(NULL), prev(NULL), newnode(NULL) {}
	void setter();
	void getter();
	void insert();
	void delet();
};
void singly::setter()
{
	char ch;
	do
	{
		cur = new node;
		cur->next = NULL;
		cout << "Enter Data on Node : ";
		cin >> cur->m;
		if (first == NULL)
			first = prev = cur;
		else
		{
			prev->next = cur;
			prev = cur;
		}
		cout << "Do You have another Node :(Y FOr YES  AND N FOR NO  ) :";
		cin >> ch;
		if (ch == 'n' || ch == 'N')
			break;
	} while (ch == 'Y' || ch == 'y');

}
void singly::getter()
{
	cur = first;
	if (first == NULL)
		cout << "LIST is empty\n";
	else
		while (cur)
		{
			cout << cur->m << endl;
			cur = cur->next;
		}
}
void singly::insert()
{
	bool check = false;
	newnode = new node;
	newnode->next = NULL;
	cout << "Enter data to be inserted : ";
	cin >> newnode->m;
	if (first == NULL)
	{
		first = newnode;
		first->next = NULL;
	}
	else
	{
		if (first->m > newnode->m)
		{
			newnode->next = first;
			first = newnode;
			check = true;
		}
		else
		{
			prev = cur = first;
			while (cur)
			{
				if (newnode->m > cur->m)
				{
					prev = cur;
					cur = cur->next;
				}
				else
				{
					prev->next = newnode;
					newnode->next = cur;
					check = true;
					break;
				}
			}
		}
	}
	if (!check)
		prev->next = newnode;
}
void singly::delet()
{
	bool check = false;
	int delinfo;
	cout << "Enter Data to be Delete : ";
	cin >> delinfo;
	if (first->m == delinfo)
	{
		if (first->next = NULL)
			first = NULL;
		else
		{
			first = first->next;
			check = true;
		}
	}
	else
	{
		prev = cur = first;
		while (cur)
		{
			if (cur->m < delinfo)
			{
				prev = cur;
				cur = cur->next;
			}
			else
			{
				prev->next = cur->next;
				check = true;
				break;
			}

		}
	}
	if (!check)
		cout << "This Data is not exit\n";
}
int main()
{
	singly N;
	int ch, count = 0;
	do
	{
		cout << "++++++++++++  MAIN  MENU  ++++++++++++++\n\n";
		cout << "1 ) TO CREATE LIST\n\n";
		cout << "2 ) TO INSERT IN A LIST\n\n";
		cout << "3 ) TO DELETE FROM LIST\n\n";
		cout << "4 ) TO DISPLAY LIST\n\n";
		cout << "5 ) TO EXIT FROM PROGRAM\n\n";
		cout << "Enter choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1://input in list
			if (count == 0)
			{
				N.setter();
				count++;
			}
			else
				cout << "You have Already Created List\n\n";
			break;
		case 2:
			if(count>0)
				N.insert();
			else
				cout << "List is Empty ,You Can't insert in it.\n\n";
			break;
		case 3:
			if(count>0)
				N.delet();
			else
				cout << "List is Empty ,You Can't delete from it.\n\n";
			break;
		case 4:
			if(count>0)
				N.getter();
			else
				cout << "List is Empty ,You Can't Display Empty List.\n\n";
			break;
		case 5:
			exit(-1);
		}
	} while (true);
	system("Pause");
}
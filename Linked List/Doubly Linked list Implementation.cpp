#include<iostream>
using namespace std;
class doubly
{
	class node
	{
	public:
		int m;
		node *lptr, *rptr;
		node() :m(0), lptr(NULL), rptr(NULL) {}
	};
	node *cur;
	node *pre;
	node *head;
	node *tail;
	node *nsnode;
public:
	doubly() :cur(NULL), pre(NULL), head(NULL), tail(NULL), nsnode(NULL) {}
	void setter();
	void getter();
	void deletion();
	int searching();
	void insertion();
	void sorting();
};
void doubly::setter()
{
	char ch;
	do
	{
		cur = new node;
		cur->lptr = NULL;
		cur->rptr = NULL;
		cout << "Enter Data on NODE : ";
		cin >> cur->m;
		cout << "Do You Have Another \nEnter Y For Yes  AND  N For No : ";
		cin >> ch;
		if (head == NULL)
			head = pre = tail = cur;
		else
		{
			tail = cur;
			pre->rptr = cur;
			cur->lptr = pre;
			pre = cur;
		}
	} while (ch == 'y' || ch == 'Y');
}
void doubly::getter()
{
	int ch;
	do
	{
		cout << "++++++ Main Menu ++++++\n\n";
		cout << "1 ) Display in Forward Order \n";
		cout << "2 ) Display in Reverse Order \n";
		cout << "3 ) To Exit From Function";
		cout << "Enter Your Choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cur = head;
			while (cur)
			{
				cout << "Node Data : " << cur->m << endl;
				cur = cur->rptr;
			}
			break;
		case 2:
			cur = tail;
			while (cur)
			{
				cout << "Node Data : " << cur->m << endl;
				cur = cur->lptr;
			}
			break;
		case 3://exit
			break;
		}
		if (ch == 3)
			break;
	} while (true);
}
void doubly::deletion()
{
	int delinfo;
	bool check = false;
	if (head != NULL)
	{
		cout << "Enter Data for Deletion : ";
		cin >> delinfo;
		if (head->m == delinfo)
		{
			cur = head;
			head = head->rptr;
			head->lptr = NULL;
			delete cur;
			check = true;
		}
		else
		{
			cur = pre = head;
			while (cur)
			{
				if (cur->m == delinfo)
				{
					pre->rptr = cur->rptr;
					cur->rptr->lptr = pre;
					delete cur;
					check = true;
					break;
				}
				else
				{
					pre = cur;
					cur = cur->rptr;
				}
			}

		}
		if (!check)
			cout << delinfo << " is not found in the list \n";
	}
	else
		cout << "List is empty\n";
}
int doubly::searching()
{
	if (head != NULL)
	{
		int searchinfo, i = 0;
		cout << "Enter Data to be search : ";
		cin >> searchinfo;
		cur = head;
		while (cur)
		{
			i++;
			if (cur->m == searchinfo)
			{
				return i;
			}
			cur = cur->rptr;
		}
	}
	else
		cout << "list is empty\n";
	return 0;
}
void doubly::insertion()
{
	if (head != NULL)
	{
		nsnode = new node;
		nsnode->lptr = NULL;
		nsnode->rptr = NULL;
		cout << "Enter Data to Insert : ";
		cin >> nsnode->m;
		if (nsnode->m <= head->m)
		{
			nsnode->rptr = head;
			head->lptr = nsnode;
			head = nsnode;
		}
		else
		{
			cur = head;
			while ((cur != NULL) && (cur->m <= nsnode->m))
			{
				pre = cur;
				cur = cur->rptr;
			}
			if (cur != NULL)
			{
				pre->rptr = nsnode;
				nsnode->lptr = pre;
				nsnode->rptr = cur;
				cur->lptr = nsnode;
			}
			else
			{
				pre->rptr = nsnode;
				nsnode->lptr = pre;
				tail = nsnode;
			}
		}
	}
}
void doubly::sorting()
{
	pre = head;
	while (pre != NULL)
	{
		cur = pre->rptr;
		while (cur != NULL)
		{
			if (pre->m > cur->m)
			{
				int temp = cur->m;
				cur->m = pre->m;
				pre->m = temp;
			}
			cur = cur->rptr;
		}
		pre = pre->rptr;
	}
}
int main()
{
	doubly N;
	int ch, count = 0;
	do
	{
		cout << "++++++++++++  MAIN  MENU  ++++++++++++++\n\n";
		cout << "1 ) TO CREATE LIST\n\n";
		cout << "2 ) TO INSERT IN A LIST\n\n";
		cout << "3 ) TO DELETE FROM LIST\n\n";
		cout << "4 ) TO SEARCH IN A LIST\n\n";
		cout << "5 ) TO SORT THE LIST\n\n";
		cout << "6 ) TO DISPLAY LIST\n\n";
		cout << "7 ) TO EXIT FROM PROGRAM\n\n";
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
			if (count > 0)
				N.insertion();
			else
				cout << "List is Empty ,You Can't insert in it.\n\n";
			break;
		case 3:
			if (count > 0)
				N.deletion();
			else
				cout << "List is Empty ,You Can't delete from it.\n\n";
			break;
		case 4:
			if (count > 0)
			{ 
				int pos = N.searching();
				if (pos == 0)
					cout << "Search Not Found\n";
				else
					cout << "Search Found at position : " << pos << endl;
			}
			else
				cout << "List is Empty ,You Can't search in it.\n\n";
			break;
		case 5:
			if (count > 0)
				N.sorting();
			else
				cout << "List is Empty ,You Can't sorting in it.\n\n";
			break;
		case 6:
			if (count > 0)
				N.getter();
			else
				cout << "List is Empty ,You Can't Display Empty List.\n\n";
			break;
		case 7:
			exit(-1);
		}
	} while (true);
	system("pause");
}
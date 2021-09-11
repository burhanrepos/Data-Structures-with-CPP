#include<iostream>
using namespace std;
#define MAX 20
struct table
{
	int value;
	int index;
	table* next;
};
class Hash
{
	table hash_table[MAX];
public:
	Hash();//constructor
	void Map_hashTable(int monkey);
	void Display(int monkey);
	void Search(int monkey);
	void Insert(int& monkey);
};
Hash::Hash()
{
	for(int i=0;i<MAX;i++)
		hash_table[i].next = NULL;
	for (int i = 0; i < MAX; i++)
		hash_table[i].value = -9999;
	for (int i = 0; i < MAX; i++)
		hash_table[i].index = -9999;
}
void Hash::Map_hashTable(int monkey)
{
	int data;
	for (int i = 0; i < monkey; i++)
	{
		cout << "Enter Data for index "<<i<<" : ";
		cin >> data;
		if (hash_table[data%monkey].value == -9999)
		{
			hash_table[data%monkey].value = data;
			hash_table[data%monkey].index = data % monkey;
		}
		else
		{
			table *temp = hash_table[data%monkey].next;
			table *colission;
			colission = new table;
			colission->value = data;
			colission->next = NULL;
			if (temp != NULL)
			{
				while (temp->next)
					temp = temp->next;
				temp->next = colission;
			}
			else
				hash_table[data%monkey].next = colission;
		}
	}
}
void Hash::Display(int monkey)
{
	cout << "Indexes :\t  Keys  :\t Values" << endl;
	for (int i = 0; i < monkey; i++)
	{
		cout << i<<"\t:\t"<<hash_table[i].index << "\t:\t" << hash_table[i].value ;
		struct table *ptr;
		ptr = hash_table[i].next;

		while (ptr != NULL)
		{
			cout << "  ,  " <<ptr->value << "   ";
			ptr = ptr->next;
		}
		cout << endl;
	}
}
void Hash::Search(int monkey)
{
	int data;
	cout << "Enter the data for search :  ";
	cin >> data;
	if (hash_table[data%monkey].index = data % monkey)
	{
		if (hash_table[data%monkey].value == data)
			cout << "Element Find at postion " << data % monkey << endl;
		else
		{
			table *temp = hash_table[data%monkey].next;

			while (temp)
			{
				if (temp->value == data)
				{
					cout << "Element Find at postion " << data % monkey << endl;
					return;
				}
				temp = temp->next;
			}
		}
	}
	else
		cout << "Element doesn't exist ." << endl;
}
void Hash::Insert(int& monkey)
{
	int data;
	monkey++;
	cout << "Enter the Element to insert : ";
	cin >> data;
	if (hash_table[data%monkey].value == -9999)
	{ 
		hash_table[data%monkey].value = data;
		hash_table[data%monkey].index = data % monkey;
	}
	else
	{
		table *temp = hash_table[data%monkey].next;
		table *colission;
		colission = new table;
		colission->value = data;
		colission->next = NULL;
		if (temp != NULL)
		{
			while (temp->next)
				temp = temp->next;
			temp->next = colission;
		}
		else
			hash_table[data%monkey].next = colission;
	}
}
int main()
{
	Hash H;
	int n,ch,count;
	count = 0;
	do
	{
		cout << "++++++++++++++++ MAIN MENU +++++++++++++++\n";
		cout << "1 ) Map Data in Hash Table \n";
		cout << "2 ) Search Data in Hash Table \n";
		cout << "3 ) Insert Data in Hash Tabe (after Mapping First )\n";
		cout << "4 ) Display Hash Table \n";
		cout << "5 ) Exit\n";
		cout << "Enter Your Choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
				while (true)
				{
					cout << "Enter the size of table : ";
					cin >> n;
					if (n < MAX || n >= 0)
						break;
					else
						cout << "!Wrong Size ,Enter again\n";
				} 
				H.Map_hashTable(n);
				count++;
			break;
		case 2:
			if (count > 0)
			{
				H.Search(n);
			}
			else
				cout << "Map in The Hash Table First \n";
			break;
		case 3:
			if (count > 0)
			{
				H.Insert(n);
			}
			else
				cout << "Map in The Hash Table First \n";
			break;
		case 4:
			if (count > 0)
			{
				H.Display(n);
			}
			else
				cout << "Map in The Hash Table First \n";
			break;
		case 5:
			exit(-1);
		}
	} while (true);
}
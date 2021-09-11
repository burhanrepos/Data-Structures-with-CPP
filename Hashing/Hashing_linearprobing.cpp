#include<iostream>
using namespace std;
#define MAX 10
class Hash
{
	int H[MAX];
public:
	Hash(){}
	void Hash_Map(int data,int monkey);
	void search(int data, int monkey);
	void display(int monkey);
	void MakeEmpty();
};
void Hash::MakeEmpty()
{
	for (int i = 0; i < MAX; i++)
		H[i] = 0;
}
void Hash::Hash_Map(int data, int monkey)
{
	int position = data % monkey;
	if (H[position ] == 0)
		H[position] = data;
	else
		for (int i = (position + 1) % monkey; i != position; i = (i + 1) % monkey)
		{
			if (H[i] == 0)
			{
				H[i] = data;
				break;
			}
			if (i == position)
			{
				cout << "Out of Bound\n";
				break;
			}
		}
}
void Hash::display(int monkey)
{
	cout << "Index     :   Value  \n";
	for (int i = 0; i < monkey; i++)
		cout << "    " << i << "     :    " << H[i] << endl;
}
void Hash::search(int data, int monkey)
{
	int position = data % monkey;
	if (H[position] == data)
		cout << "The element found at index : " << position + 1 << endl;
	else
		for (int i = (position + 1) % monkey; i != position; i = (i + 1) % monkey)
		{
			if (H[i] == data)
			{
				cout << "The element found at index : " << i + 1 << endl;
				return;
			}
		}
	cout << "Element Not Found\n";
}
int main()
{
	Hash H;
	int n, data;
	int count = 0;
	int ch;
	do
	{
		cout << "-------------- MAIN MANU ---------\n";
		cout << "1 ) Map in Hashing Table \n";
		cout << "2 ) Search In Hash Table \n";
		cout << "3 ) Display Table \n";
		cout << "4 ) Exit \n";
		cout << "Enter Choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			H.MakeEmpty();
			while (true)
			{
				cout << "Enter No of Elements in Array :";
				cin >> n;
				if (n >= 1 && n <= 10)
					break;
			}
			for (int i = 0; i < n; i++)
			{
				cout << "Enter Data : ";
				cin >> data;
				H.Hash_Map(data, n);
			}
			count++;
			break;
		case 2:
			if (count > 0)
			{
				cout << "Enter Data to Search : ";
				cin >> data;
				H.search(data, n);
			}
			else
				cout << "First Fill the Hash Table \n";
			break;
		case 3:
			if (count > 0)
				H.display(n);
			else
				cout << "First Fill the Hash Table \n";
			break;
		case 4:
			exit(-1);
		}
	} while (true);
}
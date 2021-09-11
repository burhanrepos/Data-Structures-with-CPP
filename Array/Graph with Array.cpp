#include<iostream>
#include<iomanip>
using namespace std;
#define MAX 10
void setter(int adj_mat[][MAX], int monkey);
void getter(int adj_mat[][MAX], int monkey);
int main()
{
	int adj_mat[MAX][MAX];
	int n;
	cout << "Enter the Number of Vertices : ";
	cin >> n;
	setter(adj_mat, n);
	getter(adj_mat, n);
	system("pause");
}
void setter(int adj_mat[][MAX], int monkey)
{
	for (int i = 0; i < monkey; i++)
		for (int j = i; j < monkey; j++)
		{
			if (i != j)//becuase there is no loop
			{
				cout << "Enter 1 If the Vertex " << i + 1 << " is Adjecent to " << j + 1 << " , Otherwise 0 : ";
				cin >> adj_mat[i][j];
				adj_mat[j][i] = adj_mat[i][j];//because it is undirected graph  to both side direction is done in this statement
			}
			else
				adj_mat[i][j] = 0;
		}
}
void getter(int adj_mat[][MAX], int monkey)
{
	cout << "\n\n" << setw(4) << " ";
	for (int i = 0; i < monkey; i++)
	{
		cout << setw(4) << i + 1;
			if(i<monkey-1)
		    	cout << "  |";
	}
	cout << endl;
	cout << "____________________________\n";
	for (int i = 0; i < monkey; i++)
	{
		cout << setw(3) << i + 1 << " |";
		for (int j = 0; j < monkey; j++)
			cout << setw(4) << adj_mat[i][j]<<" |";
		cout << endl;
		cout << "____________________________\n";
	}
}

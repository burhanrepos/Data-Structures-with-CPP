#include<iostream>
using namespace std;
int main()
{
	int cmax, rmax, sum = 0;
	int *iptr = NULL;
	cout << "Enter No of Rows : ";
	cin >> rmax;
	cout << "Enter No of Columns : ";
	cin >> cmax;
	int** y = new int*[rmax];
	for (int i = 0; i < rmax; i++)
			y[i] = new int[cmax];
	for (int i = 0; i < rmax; i++)
		for (int j = 0; j < cmax; j++)
		{
			cout << "Enter Data " << i + 1 + j << " : ";
			cin>> y[i][j];
		}
	for (int i = 0; i < rmax; i++)
	{
		for (int j = 0; j < cmax; j++)
			sum = sum + y[i][j];
	}
	cout << "Sum = " << sum << endl;
	delete[] y;
	system("pause");
}
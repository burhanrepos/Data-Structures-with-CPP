#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
template<typename T>
class Sorting {
	vector<T> A;
public:
	void setter();
	void getter();
	void BubbleSort();
	void SelectionSort();
	void InsertionSort();
	void MergeSort(int p,int r);
	void Merge(int p, int q, int r);
	void QuickSort(int p,int r);
	int Partition(int p, int r);
	void swap(T &x, T &y);
	int getSize()
	{
		return A.size();
	}
	void clearData()
	{
		A.clear();
		A.shrink_to_fit();
	}
};
template<typename T>
void Sorting<T>::setter() {
	int n;
	T data;
	cout << "Enter Number of items : ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cout << "Enter Data in _ A[ " << i + 1 << " ] : ";
		cin >> data;
		A.push_back(data);
	}
}
template<typename T>
void Sorting<T>::getter() {
	cout << "Now Array is Sorting\n";
	for (int i = 0; i < A.size(); i++)
	{
		cout << "A[ " << i + 1 << " ] = " << A[i] << endl;
	}
}
template<typename T>
void Sorting<T>::BubbleSort()
{
	for (int i = 0; i < A.size() - 1; i++)
	{
		for (int j = 0; j < A.size()-1 - i; j++)
		{
			if (A[j] > A[j + 1])
			{
				swap(A[j], A[j + 1]);
			}
		}
	}
}
template<typename T>
void Sorting<T>::SelectionSort()
{
	int min;
	for (int i = 0; i < A.size(); i++)
	{
		min = i;
		for (int j = i + 1; j < A.size(); j++)
		{
			if (A[j] < A[min])
			{
				min = j;
			}
		}
		swap(A[i], A[min]);
	}
}
template<typename T>
void Sorting<T>::InsertionSort()
{
	T key;
	int j;
	for (int i = 1; i < A.size(); i++)
	{
		key = A[i];
		j = i - 1;
		while (j >= 0 && key < A[j])
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = key;
	}
}
template<typename T>
void Sorting<T>::MergeSort(int p,int r)
{
	int q;
	if (p < r)
	{
		q = floor((p + r) / 2);
		MergeSort(p, q);
		MergeSort(q + 1, r);
		Merge(p, q, r);
	}
}
template<typename T>
void Sorting<T>::Merge(int p,int q,int r)
{
	vector<T> L, R;
	int n1 = q - p + 1;
	int n2 = r - q;
	for (int i = p; i <= q; i++)
		L.push_back(A[i]);
	for (int j = q + 1; j <= r; j++)
		R.push_back(A[j]);
	int i, j, k;
	i = 0;
	j = 0;
	k = 0;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
			A[p++] = L[i++];
		else
			A[p++] = R[j++];
	}
	while (i < n1)
		A[p++] = L[i++];
	while (j < n2)
		A[p++] = R[j++];
}
template<typename T>
void Sorting<T>::QuickSort(int p, int r)
{
	if (p < r)
	{
		int q = Partition(p, r);
		QuickSort(p, q);
		QuickSort(q + 1, r);
	}
}
template<typename T>
int Sorting<T>::Partition(int p, int r)
{
	T x = A[p];
	int q = p;
	for (int s = p + 1; s <= r; s++)
	{
		if (A[s] < x)
		{
			q++;
			swap(A[q], A[s]);
		}
	}
	swap(A[p], A[q]);
	return q;
}
template<typename T>
void Sorting<T>::swap(T &x, T &y)
{
	T temp = std::move(x);
	x = std::move(y);
	y = std::move(temp);
}

int main()
{
	Sorting<int> SI;
	Sorting<double> SD;
	int ch;
	do 
	{
		system("cls");
		cout << " ------------( Main Menu )------------\n\n";
		cout << "1 ) Bubble Sort\n\n";
		cout << "2 ) Selection Sort\n\n";
		cout << "3 ) Insertion Sort\n\n";
		cout << "4 ) Merge Sort\n\n";
		cout << "5 ) Quick Sort\n\n";
		cout << "6 ) Exit\n\n";
		cout << "Enter Your Choice: ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			SI.setter();
			SI.BubbleSort();
			SI.getter();
			SI.clearData();
			system("pause");
			break;
		case 2:
			SD.setter();
			SD.SelectionSort();
			SD.getter();
			SD.clearData();
			system("pause");
			break;
		case 3:
			SI.setter();
			SI.InsertionSort();
			SI.getter();
			SI.clearData();
			system("pause");
			break;
		case 4:
			SI.setter();
			SI.MergeSort(0, SI.getSize()-1);
			SI.getter();
			SI.clearData();
			system("pause");
			break;
		case 5:
			SI.setter();
			SI.QuickSort(0, SI.getSize() - 1);
			SI.getter();
			SI.clearData();
			system("pause");
			break;
		case 6:
			exit(-1);
		default:
			cout << "Wrong Choice, Enter Again\n\n";
			system("pause");
		}
	} while (true);
}
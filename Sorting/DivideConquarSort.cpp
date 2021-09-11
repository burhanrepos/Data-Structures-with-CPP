#include<iostream>
#define MAX 20
using namespace std;
template<class T>
class D_C_Sorting
{
	T A[MAX];
public:
	D_C_Sorting<T>(){}
	void setter(int monkey);
	void mergeSort(int start,int end);
	void merge( int start,int mid,int end);
	void quickSort(int start, int end);
	int Partition( int start, int end);
	void heapSort(int monkey);
	void max_heapify(int monkey, int i);
	void getter(int monkey);
};
template<class T>
void D_C_Sorting<T>::setter(int monkey)
{
	for (int i = 0; i < monkey; i++)
	{
		cout << "Enter Elements No  " << i + 1 << " : ";
		cin >> A[i];
	}
}
template<class T>
void D_C_Sorting<T>::getter(int monkey)
{
	for (int i = 0; i < monkey; i++)
		cout << "Elements " << i + 1 << " : " << A[i] << endl;
}
template<class T>
void D_C_Sorting<T>::mergeSort(int start, int end)
{
	
	if (start < end)
	{
	int mid = (start + end) / 2;
		mergeSort(start, mid);
		mergeSort(mid+1 , end);
		merge(start, mid, end);
	}
}
template<class T>
void D_C_Sorting<T>::merge(int start, int mid, int end)
{
	int n1, n2;
	n1 = mid - start+1 ;
	n2 = end - mid;
	int *L = new int[n1];
	int *R = new int[n2];
	for (int i = start; i <= mid; i++)
		L[i - start] = A[i];
	for (int j = mid + 1; j <= end; j++)
		R[j - (mid + 1)] = A[j];
	int i, j, k;
	i = 0;
	j = 0;
	k = 0;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
			A[start++] = L[i++];
		else
			A[start++] = R[j++];
	}
	while(i < n1)
		A[start++] = L[i++];
	while (j < n2)
		A[start++] = R[j++];
}
template<class T>
void D_C_Sorting<T>::quickSort(int start, int end)
{
	if (start < end)
	{
		int pivot_index = Partition(start, end);
		quickSort(start, pivot_index - 1);
		quickSort(pivot_index + 1, end);
	}
}
template<class T>
int D_C_Sorting<T>::Partition( int start, int end)
{
	int pivot = A[start];
	int pivot_index = start;
	for (int i = start + 1; i <= end; i++)
		if (A[i] < pivot)
		{
			pivot_index++;
			swap(A[pivot_index], A[i]);
		}
	swap(A[start], A[pivot_index]);
	return pivot_index;
}
template<class T>
void D_C_Sorting<T>::heapSort(int monkey)
{
	for (int i = monkey / 2 - 1; i >= 0; i--)
		max_heapify(monkey, i);
	for (int j = monkey - 1; j > 0; j--)
	{
		swap(A[0], A[j]);
		max_heapify(j, 0);
	}
}
template<class T>
void D_C_Sorting<T>::max_heapify(int monkey,int i)
{
	int large = i;
	int left = 2 * i+1;
	int right = 2 * i + 2;
	if (left < monkey && A[left] > A[large])
		large = left;
	if (right < monkey && A[right] > A[large])
		large = right;
	if (large != i)
	{
		swap(A[i], A[large]);
		max_heapify(monkey, large);
	}
}
int main()
{
	D_C_Sorting<int> D;
	int ch, count,n;
	count = 0;
	do
	{
		cout << "-----------------   Divide_Conquar Sorting   ---------------------\n\n";
		cout << "1) Setter(Fill Array First )\n\n";
		cout << "2) MergeSort \n\n";
		cout << "3) QuickSort \n\n";
		cout << "4) HeapSort \n\n";
		cout << "5) Display \n\n";
		cout << "6) Exit \n\n";
		cout << "Enter Choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			do
			{
				cout << "Enter Number of Elements in Array : ";
				cin >> n;
				if (n < MAX)
					break;
			} while (true);
			D.setter(n);
			count++;
			break;
		case 2:
			if (count > 0)
				D.mergeSort(0, n-1);
			else
				cout << "Fill Array First \n";
			break;
		case 3:
			if (count > 0)
				D.quickSort(0, n - 1);
			else
				cout << "Fill Array First \n";
			break;
		case 4:
			if (count > 0)
				D.heapSort(n);
			else
				cout << "Fill Array First \n";
			break;
		case 5:
			if (count > 0)
				D.getter(n);
			else
				cout << "Fill Array First \n";
			break;
		case 6:
			exit(-1);
		}
	} while (true);
}

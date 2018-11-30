#include<iostream>
using namespace std;
void BinarySearch(char arr[], int size, int search)
{
	int lower = 0;
	int high = size - 1;
	int mid;
	int counter = 0;

	while (lower < size)
	{
		mid = lower + (high- lower) / 2;

		if (arr[mid] == search)
		{
			cout << "Angka ditemukan pada index " << mid << endl;
			break;
		}
		if (arr[lower] == search)
		{
			cout << "Angka ditemukan pada index " << lower << endl;
			break;
		}
		if (arr[high] == search)
		{
			cout << "Angka ditemukan pada index " << high << endl;
			break;
		}

		if (mid > size || mid < 0 || lower == high || lower == mid || high == mid)
		{
			cout << "not found \n";
			break;
		}

		if (search > arr[mid])
		{
			lower = mid + 1;
			//mid = lower + (upper - lower) / 2;
		}
		else if (search < arr[mid])
		{
			high = mid - 1;
			//mid = lower + (upper - lower) / 2;
		}

		cout << "loop - " << counter << endl;
		cout << "Upper : " << high << endl;
		cout << "lower : " << lower << endl;
		cout << "mid : " << mid << endl;
		cout << endl;
		counter++;
	}
}


int main()
{
int n, search;

	cout << "banyak array : ";
	cin >> n;

	int *arr = new int[n];
	//int arr[100];
	int upper = 0, lower = 0, mid;
    cout << endl << endl;
	cout << "nilai yang ingin di cari : ";
	cin >> search;
BinarySearch(arr, n, search);

}


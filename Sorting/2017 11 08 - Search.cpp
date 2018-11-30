#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<Windows.h>
#include<time.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<ctype.h>
#include<algorithm>
#include<vector>
#include<fstream>
#include<list>

using namespace std;

// A function to implement insertion sort
// arr[] is a array, n is array size
void InsertionSort(int arr[], int n)
{
	// Base case
	if (n <= 1)
	{
		return;
	}
	else
	{
		// Sort first n-1 elements
		InsertionSort(arr, n - 1);

		// Insert last element at its correct position
		// in sorted array.
		int last = arr[n - 1];
		int j = n - 2;

		while (j >= 0 && arr[j] > last)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = last;
	}
}

//arr = array
//size = ukuran array
//search = nilai yang dicari
void BinarySearch(int arr[], int size, int search)
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

void InterpolationSearch(int arr[], int size, int search)
{
	int lower = 0;
	int high = size - 1;
	int mid;
	int counter = 0;

	while (lower < size)
	{
		mid = lower + (((double)(high - lower) /
			(arr[high] - arr[lower]))*(search - arr[lower]));

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

		if (mid > size || mid < 0)
		{
			cout << "out of rangeb \n";
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
	srand(time(0));

	int n, search;

	cout << "banyak array : ";
	cin >> n;

	int *arr = new int[n];
	//int arr[100];
	int upper = 0, lower = 0, mid;

	//random isi
	for (int q = 0; q < n; q++)
	{
		//cin >> arr[q];

		int temp = rand() % n + 1;
		arr[q] = temp;
	}

	cout << "Upper " << upper << " \nLower " << lower << endl;

	//sort data
	InsertionSort(arr, n);

	//menampilkan isi array
	for (int q = 0; q < n; q++)
	{
		cout << arr[q] << " ";
	}

	cout << endl << endl;
	cout << "nilai yang ingin di cari : ";
	cin >> search;

	cout << endl;
	/*lower = 0;
	upper = n - 1;
	int counter = 0;*/

	BinarySearch(arr, n, search);
	//InterpolationSearch(arr, n, search);

	//while (true)
	//{
	//	mid = lower + (upper - lower) / 2;
//
 //		if (arr[mid] == search)
	//	{
	//		cout << "Angka ditemukan pada index " << mid << endl;
	//		break;
	//	}
	//	if (arr[lower] == search)
	//	{
	//		cout << "Angka ditemukan pada index " << lower << endl;
	//		break;
	//	}
	//	if (arr[upper] == search)
	//	{
	//		cout << "Angka ditemukan pada index " << upper << endl;
	//		break;
	//	}
	//	
	//	if (search > arr[mid])
	//	{
	//		lower = mid + 1;
	//		//mid = lower + (upper - lower) / 2;
	//	}
	//	else if (search < arr[mid])
	//	{
	//		upper = mid - 1;
	//		//mid = lower + (upper - lower) / 2;
	//	}
	//
	//	cout << "loop - " << counter << endl;
	//	cout << "Upper : " << upper << endl;
	//	cout << "lower : " << lower << endl;
	//	cout << "mid : " << mid << endl;
	//	cout << endl;
	//}

	//cout << "data not found ";

	//hapus arr pointer
	delete[] arr;
	getch();
	return 0;
}
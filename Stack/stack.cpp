#include <iostream>
#include <string>
using namespace std;

class Stack
{
private :
	char *data;
	int size;
public :
	Stack()
	{
		size = 0;
		data = new char[0];
	}
	void push(char _data)
	{
		char *temp;
		temp = new char[size];
		for (int i = 0 ; i < size ; i ++ )
		{
			temp[i] = data[i];
		}
		size ++;
		data = new char[size];
		for ( int i = 0 ; i < size - 1 ; i ++ )
		{
			data[i] = temp[i];
		}
		data[size-1] = _data;
	}
	char top()
	{
		return data[size-1];
	}
	void pop()
	{
		char *temp;
		temp = new char [size];
		for ( int i = 0 ; i < size ; i ++)
		{
			temp[i] = data[i];
		}
		size --;
		data = new char [size];
		for ( int i = 0 ; i < size ; i ++)
		{
			data[i] = temp[i];
		}
	}
	bool isEmpty()
	{
		if ( size <= 0 )
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void viewData()
	{
		for ( int i = 0 ; i < size ; i ++ )
		{
			cout << data[i] << " ";
		}
		cout << endl;
	}
};

void main()
{
	Stack stack;
	int banyak_kata, counter = 0;
	string kalimat;
	char *hasil;
	cout << "Input kalimat = " ;
	cin >> kalimat;
	cout << "Input banyak kata =  " ;
	cin >> banyak_kata;
	hasil = new char [kalimat.length()];
	int index_hasil = 0;
	for ( int i = 0 ; i < kalimat.length() ; i ++ )
	{
		counter ++;
		stack.push(kalimat[i]);
		if ( counter == banyak_kata || i == kalimat.length() - 1)
		{
			counter = 0;
			while ( stack.isEmpty() == false )
			{
				hasil[index_hasil] = stack.top();
				index_hasil ++;
				stack.pop();
			}
		}
	}
	cout << "Hasil = " ;
	for ( int i = 0 ; i < index_hasil ; i++)
	{
		cout << hasil[i];
	}
}
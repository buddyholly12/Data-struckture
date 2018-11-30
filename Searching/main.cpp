#include <iostream>
#include<stdio.h>
using namespace std;

class Data{
private:
char data[100];
int count;
char data1,data2,data3;
public:
    Data()
    {
        count=0;
    }
    char interpolating (char search, int hi, int low)
	{
		int index=0;
		for(int i=0;i<count;i++)
		{
			if(search==data[i])
			{
				index=i;
			}
		}

		if(index==0)
		{
			printf("huruf tidak ditemukan\n");
		}
		else
		{
			int mid = low + ((index - low)*(hi - low) / hi - low);
			printf("\nlow = %d\n", low);
			printf("high = %d\n", hi);
			printf("mid = %d\n", mid);
			if (search == data[low])
			{
				return low;
			}
			if (search == data[hi])
			{
				return hi;
			}
			if (search == data[mid])
			{
				return mid;
			}
			if (low >= hi)
			{
				return -1;
			}
			if (search < data[mid])
			{
				low = low + 1;
				mid = mid - 1;
			}
			else
			{
				low = low - 1;
				mid = mid + 1;
			}
			printf("low = %d\n", low);
			printf("high = %d\n", hi);
			printf("mid = %d\n", mid);
		}
	}

	char binary(char search, int hi, int low)
	{
		int mid = (low + hi) / 2;
		printf("\nlow = %d\n", low);
		printf("high = %d\n", hi);
		printf("mid = %d\n", mid);
		if (search == data[low])
		{
			return low;
		}
		if (search == data[hi])
		{
			return hi;
		}
		if (search == data[mid])
		{
			return mid;
		}
		if (low >= hi)
		{
			return -1;
		}
		if (search < data[mid])
		{
			low = low + 1;
			mid = mid - 1;
		}
		else
		{
			low = low - 1;
			mid = mid + 1;
		}
		printf("low = %d\n", low);
		printf("high = %d\n", hi);
		printf("mid = %d\n", mid);
	}
    void inputanData()
    {
        int N=0;
		cout<<"input Jumlah Array:"<<endl;
        cin>>N;
        count=N;
        for(int i=0;i<count;i++)
        {
            char temp;
			cout<<"Input Character:"<<endl;
			fflush(stdin);
			cin>>temp;
			data[i]=temp;

        }
    }
    int isi()
    {
        return count-1;
    }
    void sortingdata()
    {
        for (int i=0;i<=count-2;i++)
        {
            for (int j=0;j<=count-2-i;j++)
            {
                if(data[j]<data[j+1])
                {
                   data1=data[j] ;
                   data[j]=data[j+1];
                   data[j+1]=data1;
                }

            }
        }
    }
    void cetak()
    {
        for(int i=0;i<count;i++)
		{
		    cout<<data[i]<<endl;
		}
    }

};

int main()
{


    int loops=0;
    int chc;
    Data main;
    while(loops!=4)
    {
        cout<< "Menu"<<endl;
        cout<< "1.Input data"<<endl;
        cout<< "2.Binary search"<<endl;
        cout<< "3.search Data(interpolating search)"<<endl;
        cout<< "4.exit"<<endl;
        cin>>chc;
        if(chc==1)
        {
            main.inputanData();
            cout<<"Data yang diinput:"<<endl;
            main.cetak();
            main.sortingdata();
            cout<<"Data yang sudah disorting :"<<endl;
            main.cetak();
        }
		else if (chc==2)
		{
			char f=0;
			cout<<"search:\t";
			fflush(stdin);
			cin>>f;
			main.binary(f,main.isi(),0);
			cout<<f,main.binary(f,main.isi(),0);
		}
		else if(chc==3)
		{
			char f=0;
			cout<<"search\t";
			fflush(stdin);
			cin>>f;
			main.interpolating(f,main.isi(),0);
			cout<<f,main.interpolating(f,main.isi(),0);
		}
		else if(chc==4)
		{
			break;
		}

    }
  return 0;
}

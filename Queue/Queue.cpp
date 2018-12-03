#include<iostream>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
using namespace std;
class Queue
{
	private:
	int head, tail, *data;
public:
	Queue()
	{
		head = -1;
		tail = -1;
		data = NULL;
	}
	void enqueue(int dat)
	{
		if (isEmpty())
		{
			head=0;
		}
		tail++;
		int *temp = data;
		data = new int[tail + 1];
		for (int i = 0; i < tail; i++)
		{
			data[i] = temp[i];
		}
		delete[]temp;
		data[tail] = dat;
	}
	int dequeue()
	{
		if (!isEmpty())
		{
			int hapus = data[head];
			int *temp = data;
			data = new int[tail];
			for (int i = 1,j=0; i <= tail; j++,i++)
			{
				data[j] = temp[i];
			}
			delete[]temp;
			tail--;
			if (tail < 0)
			{
				head = -1;
			}
			return hapus;
		}
	}
	int isEmpty()
	{
		if (head == -1)
		{
			return 1;
		}
		return 0;
	}
	void View()
	{
		for (int i = 0; i <= tail; i++)
		{
			cout << data[i] << endl;
		}
	}
	int Tops()
	{
		if(!isEmpty())
		{
			return data[head];
		}
	}


};

void main()
{
	srand(time(NULL));
	Queue *q,antre;
	int x,ran;
	int chc=5;
	while(chc!=3)
	{
	cout<<"Menu"<<endl;
	cout<<"1.jumlah queue"<<endl;
	cout<<"2.keluarkan queue"<<endl;
	cin>>chc;
	if (chc==1)
	{
		cout<<"input jumlah que"<<endl;
		cin>>x;
		q=new Queue[x];
		for(int i=1;i<=100;i++)
		{
			ran=rand()%x;
			q[ran].enqueue(i);
			printf("Nomor urut %d masuk ke queue %d\n", i, ran+ 1);
		}
	}
	else 
	{
		int out,deq,found=0,idx;
		cout<<"input no yang keluar"<<endl;
		cin>>out;
		for(int i=0;i<out;i++)
		{
			q[i].View();
		}
		for(int i=0;i<out&&found==0;i++)
		{
			int head=q[i].Tops(),x=0;
			if(!q[i].isEmpty())
			{
				deq=q[i].dequeue();
			}
			if(deq==out)
			{
				cout<<"Queue=%d\t index=%d\t",i+1,idx;
				antre.enqueue(out);
				x=1;
			}
				while(q[i].Tops()!=head&& x==0)
				{
					if(deq==out)
					{
						cout<<"Queue=%d\t index=%d\t"<<i+1,idx;
						antre.enqueue(out);
						x=1;
					}
					else 
					{
						q[i].enqueue(deq);
						idx++;
					}
					deq=q[i].dequeue();
				}
				if(q[i].Tops()==head)
				{
					if(deq==out)
					{
						cout<<"Queue=%d\t index=%d\t"<<i+1,idx;
						antre.enqueue(out);
						x=1;
					}
					else 
						q[i].enqueue(deq);
				}
		}
			ran=rand()%10;
			if(ran==0)
			{
				ran=rand()%x;
				q[ran].enqueue(antre.dequeue());
			}
			for(int i=0;i<x;i++)
			{
				q[i].View();
			}
	}
	}
}
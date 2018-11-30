#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<math.h>
using namespace std;

void deret8 (int n, int m, int value = 1, int incrementVal = 0)
{
    // int value = 0;
    //int hasil;
    if(n == m)
    {
        value += incrementVal;
        cout << value << " ";
        return;
    }
    else if (n == 1)
    {
        // value += incrementVal;
       deret8(n + 1, m, value - 1, incrementVal + 5);
       cout << value << " ";
    }
    else
    {
        value += incrementVal;
        deret8(n + 1, m, value, incrementVal + 5);
        cout << value << " ";
    }
}

int main()
{

int n,m;
n = 1;
 printf("Input data : ");
 scanf("%d", &m);
 deret8(n, m);
 getch();
    return 0;
}

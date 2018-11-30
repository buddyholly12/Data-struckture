#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<math.h>
using namespace std;

void deret (int n,int m, int value = 0)
{
    // int value = 0;
    //int hasil;
    if(n == m)
    {
        value = pow(2, n) - 1;
        cout << value << " ";
        return;
    }
    else
    {
        value = pow(2, n) - 1;
        cout << value << " ";
        deret(n + 1, m, value);
    }
}

int main()
{
int n,m;
n = 1;
 printf("Input data : ");
 scanf("%d", &m);
 deret(n, m);
 getch();
    return 0;
}

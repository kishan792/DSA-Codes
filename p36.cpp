#include<iostream>
using namespace std;

int main()
{
    int num = 20;

    int count = 0;
    while(num>0)
    {
        if(num&1==1)
        {
            count++;
        }
        num = num>>1;
    }

    printf("%d\n",count);
}
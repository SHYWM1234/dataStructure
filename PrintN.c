#include<stdio.h>
#include<stdlib.h>
//递归实现
void printN1(int n)
{
    int i;
    for(i=1; i<n; i++)
    {
        printf("%d\n", i);
    }
    return;
}
//循环实现
void printN2(int i)
{
    if(i != 0)
    {
        printN2(i-1);
        printf("%d\n", i);
    }
    return;
}
int main()
{
    int i;
    printN2(100000);
    system("pause");
    return 0;
}
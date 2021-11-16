#include<iostream>
using namespace std;
int fibor(int n)
{
    if(n==1)
    {
        return 0;
    }
    else if(n==2)
    {
        return 1;
    }
    return fibor(n-1)+fibor(n-2);
}
int fiboi(int n)
{
    int a=0,b=1,c,i;
    if(n==1)
    {
        return a;
    }
    else if(n==2)
    {
        return b;
    }
    for(i=0;i<n-2;i++)
    {
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}
int main()
{
    int n,r;
    cin>>n;
    r=fibor(n);
    cout<<r;
    return 0;
}
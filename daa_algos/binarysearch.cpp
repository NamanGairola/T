#include<iostream>
using namespace std;
int binarys(int arr[],int l,int r,int k)
{
    int m;
    while(l<=r)
    {
        m=(l+r)/2;
        if(k==arr[m])
        {
            return m;
        }
        else if(k<arr[m])
        {
            r=m-1;
        }
        else
        {
            l=m+1;
        }
    }
    return -1;
}
int binaryr(int arr[],int l,int r,int k)
{
    if(l<=r)
    {
        int m=(l+r)/2;
        if(k==arr[m])
        {
            return m;
        }
        else if(k<arr[m])
        {
            return binaryr(arr,l,m-1,k);
        }
        else
        {
            return binaryr(arr,m+1,r,k);
        }
    }
    return -1;
}
int main()
{
    int n,i,k,p;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cin>>k;
    p=binaryr(arr,0,n-1,k);
    if(p==-1)
    {
        cout<<"no. is not present";
    }
    else
    {
        cout<<"present at index : "<<p;
    }
    return 0;
}
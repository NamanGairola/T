#include<iostream>
using namespace std;
void heapify(int arr[],int n,int i);
void buildheap(int arr[],int n)
{
    int i;
    for(i=n/2;i>=0;i--)
    {
        heapify(arr,n,i);
    }
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
void heapify(int arr[],int n,int i)
{
    int c1=i*2+1,c2=i*2+2,m=i,t;
    if(c1<n && arr[c1]>arr[m])
    {
        m=c1;
    }
    if(c2<n && arr[c2]>arr[m])
    {
        m=c2;
    }
    if(m!=i)
    {
        t=arr[m];
        arr[m]=arr[i];
        arr[i]=t;
        heapify(arr,n,m);
    }
}
void extractmax(int arr[],int n)
{
    int temp;
    temp=arr[0];
    arr[0]=arr[n-1];
    arr[n-1]=temp;
    heapify(arr,n-1,0);
}
void heapsort(int arr[],int n)
{
    buildheap(arr,n);
    int i;
    for(i=n;i>0;i--)
    {
        extractmax(arr,i);
    }
}
int main()
{
    int n,i;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    heapsort(arr,n);
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
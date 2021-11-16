#include<iostream>
using namespace std;
void selectionsort(int arr[],int n)
{
    int i,j,t;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                t=arr[i];
                arr[i]=arr[j];
                arr[j]=t;
            }
        }
    }
}
void bubblesort(int arr[],int n)
{
    int i,j,t;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }
        }
    }
}
void insertionsort(int arr[],int n)
{
    int i,j,k;
    for(i=1;i<n;i++)
    {
        k=arr[i];
        for(j=i;j>0 && k<arr[j-1];j--)
        {
            arr[j]=arr[j-1];
        }
        arr[j]=k;
    }
}
void merge(int arr[],int l,int r,int m);
void mergesort(int arr[],int l,int r)
{
    int m;
    if(l<r)
    {
        m=(l+r)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merge(arr,l,r,m);
    }
}
void merge(int arr[],int l,int r,int m)
{
    int c1=m-l+1,c2=r-m,i=0,j=0,k=l;
    int al[c1],ar[c2];
    for(i=0;i<c1;i++)
    {
        al[i]=arr[k];
        k++;
    }
    for(j=0;j<c2;j++)
    {
        ar[j]=arr[k];
        k++;
    }
    i=0;
    j=0;
    k=l;
    while(i<c1 && j<c2)
    {
        if(al[i]<ar[j])
        {
            arr[k]=al[i];
            i++;
            k++;
        }
        else
        {
            arr[k]=ar[j];
            j++;
            k++;
        }
    }
    while(i<c1)
    {
        arr[k]=al[i];
        i++;
        k++;
    }
    while(j<c2)
    {
        arr[k]=ar[j];
        j++;
        k++;
    }
}
int quick(int arr[],int l,int r);
void quicksort(int arr[],int l,int r)
{
    int p;
    if(l<r)
    {
        p=quick(arr,l,r);
        quicksort(arr,l,p-1);
        quicksort(arr,p+1,r);
    }
}
int quick(int arr[],int l,int r)
{
    int i=l-1,j,t;
    for(j=l;j<r;j++)
    {
        if(arr[j]<arr[r])
        {
            i++;
            t=arr[i];
            arr[i]=arr[j];
            arr[j]=t;
        }
    }
    i++;
    t=arr[i];
    arr[i]=arr[r];
    arr[r]=t;
    return i;
}
void heapify(int arr[],int n,int p);
void buildheap(int arr[],int n)
{
    int i;
    for(i=n/2;i>=0;i--)
    {
        heapify(arr,n,i);
    }
}
void heapify(int arr[],int n,int p)
{
    int c1=p*2+1,c2=p*2+2,m=p,t;
    if(c1<n && arr[c1]>arr[m])
    {
        m=c1;
    }
    if(c2<n && arr[c2]>arr[m])
    {
        m=c2;
    }
    if(m!=p)
    {
        t=arr[p];
        arr[p]=arr[m];
        arr[m]=t;
        heapify(arr,n,m);
    }
}
void extractmax(int arr[],int n)
{
    int t;
    t=arr[0];
    arr[0]=arr[n-1];
    arr[n-1]=t;
    heapify(arr,n-1,0);
}
void heapsort(int arr[],int n)
{
    int i;
    buildheap(arr,n);
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
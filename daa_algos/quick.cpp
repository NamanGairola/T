#include <iostream>
using namespace std;
int quick(int arr[], int l, int m);
void quicksort(int arr[],int l,int r)
{
    if(l<r)
    {
        int p;
        p=quick(arr,l,r);
        quicksort(arr,l,p-1);
        quicksort(arr,p+1,r);
    }
}
int quick(int arr[], int l,int r)
{
	int i=l-1,j=l,temp;
    for(;j<=r-1;j++)
    {
        if(arr[j]<arr[r])
        {
            i++;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    i++;
    temp=arr[i];
    arr[i]=arr[r];
    arr[r]=temp;
    return i;
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
    quicksort(arr,0,n-1);
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}

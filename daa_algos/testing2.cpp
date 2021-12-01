#include<iostream>
using namespace std;
void insertionsort(int arr[],int n)
{
	int i,j,key;
	for(i=1;i<n;i++)
	{
		key=arr[i];
		for(j=i;key<arr[j-1]&&j>0 ;j--)
		{
			arr[j]=arr[j-1];
		}
		arr[j]=key;
	}
}
void merge(int arr[],int l,int r,int m);
void mergesort(int arr[],int l,int r)
{
	if(l<r)
	{
		int m=(l+r)/2;
		mergesort(arr,l,m);
		mergesort(arr,m+1,r);
		merge(arr,l,r,m);
	}
}
void merge(int arr[],int l,int r,int m)
{
	int l1=m-l+1,l2=r-m,i,j=0,k=0;
	int L[l1],R[l2];
	i=l;
	for(j=0;j<l1;j++)
	{
		L[j]=arr[i];
		i++;
	}
	for(j=0;j<l2;j++)
	{
		R[j]=arr[i];
		i++;
	}
	i=0;
	j=0;
	k=l;
	while(i<l1&&j<l2)
	{
		if(L[i]<R[j])
		{
			arr[k]=L[i];
			i++;
			k++;
		}
		else
		{
			arr[k]=R[j];
			j++;
			k++;
		}
	}
	while(i<l1)
	{
		arr[k]=L[i];
		i++;
		k++;
	}
	while(j<l2)
	{
		arr[k]=R[j];
		j++;
		k++;
	}
}
int quick(int arr[],int l,int r);
void quicksort(int arr[],int l,int r)
{
	if(l<r)
	{
		int p=quick(arr,l,r);
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
int main()
{
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	mergesort(arr,0,n-1);
	for(i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
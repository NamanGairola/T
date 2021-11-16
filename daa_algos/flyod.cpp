#include<iostream>
using namespace std;
int main()
{
    int v,e,i,j,k,w;
    cin>>v>>e;
    int arr[v][v];
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            arr[i][j]=INT_MAX;
        }
    }
    for(i=0;i<e;i++)
    {
        cin>>j>>k>>w;
        arr[j][k]=w;
        arr[k][j]=w;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                if(arr[i][j]>arr[i][k]+arr[k][j])
                {
                    arr[i][j]=arr[i][k]+arr[k][j];
                }
            }
        }
    }
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
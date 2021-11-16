#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int knapsackr(int w[],int v[],int n,int k)
{
    if(n==0 || k==0)
    {
        return 0;
    }
    if(k<w[n-1])
    {
        return knapsackr(w,v,n-1,k);
    }
    else
    {
        return max(knapsackr(w,v,n-1,k),v[n-1]+knapsackr(w,v,n-1,k-v[n-1]));
    }
}
int knapsacki(int w[],int v[],int n,int k)
{
    int arr[n+1][n+1];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0 || j==0)
            {
                arr[i][j]=0;
            }
            if(w[i-1]<k)
            {
                arr[i][j]=arr[i-1][j];
            }
            else
            {
                arr[i][j]=max(arr[i-1][j],p[i-1]+arr[i][j-w[i-1]]);
            }
        }
    }
    return arr[n][n]
}
int main()
{
    int n,i,wt,va,pro;
    cin>>n;
    int w[n],v[n];
    for(i=0;i<n;i++)
    {
        cin>>wt>>va;
        w[i]=wt;
        v[i]=va;
    }
    pro=
    cout<<pro;
    return 0;
}
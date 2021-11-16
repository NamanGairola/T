#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int lcsr(string x,string y,int m,int n)
{
    if(m==0 || n==0)
    {
        return 0;
    }
    else if(x[m-1]==y[n-1])
    {
        return 1+lcsr(x,y,m-1,n-1);
    }
    else
    {
        return max(lcsr(x,y,m-1,n),lcsr(x,y,m,n-1));
    }
}
int lcsi(string x,string y,int m,int n)
{
    int i,j;
    int arr[m+1][n+1];
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0 || j==0)
            {
                arr[i][j]=0;
            }
            else if(x[i-1]==y[j-1])
            {
                arr[i][j]=1+arr[i-1][j-1];
            }
            else
            {
                arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
            }
        }
    }
    return arr[m][n];
}
int main()
{
    string x,y;
    cin>>x>>y;
    int n=lcsi(x,y,x.length(),y.length());
    cout<<n;
    return 0;
}
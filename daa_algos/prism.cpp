#include<iostream>
using namespace std;
void prism(int g[],int v)
{
    int p[v],mst[v],w[v],i,we,m;
    for(i=0;i<v;i++)
    {
        p[0]=-1;
        mst[i]=0;
        w[i]=INT_MAX;
    }
    w[0]=0;
    for(i=0;i<v-1;i++)
    {
        we=INT_MAX;
        for(j=0;j<v;j++)
        {
            if(mst[j]==0 && we>w[j])
            {
                m=j;
            }
        }
        mst[m]=1;
        for(j=0;j<v;j++)
        {
            if(mst[j]==0 && g[m][j]<w[j])
            {
                w[j]=g[m][j];
                p[j]=m;
            }
        }
    }
}
int main()
{
    int v,e,i,j,w;
    int arr[v][v];
    cin>>v>>e;
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
    prism(arr,v);
    return 0;
}
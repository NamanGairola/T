#include<iostream>
using namespace std;
int find(int u,int p[])
{
    if(p[u]<0)
    {
        return p[u];
    }
    return find(p[u],p);
}
int unions(int u,int v,int p[])
{
    int pu=find(u,p),pv=find(u,v);
    if(pu!=pv)
    {
        if(p[pu]<p[pv])
        {
            p[pu]=p[pu]+p[pv];
            p[pv]=pu;
        }
        else
        {
            p[pv]=p[pv]+p[pu];
            p[pu]=pv;
        }
    }
}
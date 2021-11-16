#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef vector<pair<int,pair<int,int>>> viii;
int find(int u,int p[])
{
    if(p[u]<0)
    {
        return u;
    }
    return find(p[u],p);
}
void unions(int u,int v,int p[])
{
    if(find(u,p)!=find(v,p))
    {
        if(p[u]<p[v])
        {
            p[u]=p[u]+p[v];
            p[v]=u;
        }
        else
        {
            p[v]=p[v]+p[u];
            p[u]=v;
        }
    }
}
viii krushugals(int v,viii g)
{
    viii r;
    int p[v],i,s,d;
    for(i=0;i<v;i++)
    {
        p[i]=-1;
    }
    sort(g.begin(),g.end());
    for(i=0;i<g.size();i++)
    {
        s=g[i].second.first,d=g[i].second.second;
        if(find(s,p)!=find(d,p))
        {
            unions(s,d,p);
            r.push_back(g[i]);
        }
    }
    return r;
}
int main()
{
    int v,e,i,w,s,d;
    cin>>v>>e;
    viii g,r;
    for(i=0;i<e;i++)
    {
        cin>>s>>d>>w;
        g.push_back(make_pair(w,make_pair(s,d)));
    }
    r=krushugals(v,g);
    w=0;
    for(i=0;i<r.size();i++)
    {
        cout<<r[i].second.first<<" "<<r[i].second.second<<"\n";
        w=w+r[i].first;
    }
    cout<<"weight is : "<<w;
    return 0;
}
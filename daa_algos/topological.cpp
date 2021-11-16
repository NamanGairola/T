#include<iostream>
#include<stack>
#include<vector>
using namespace std;
void topo(stack<int> &s,int vis[],vector<int> g[],int i)
{
    int j;
    vis[i]=1;
    for(j=0;j<g[i].size();j++)
    {
        if(vis[g[i][j]]==0)
        {
            topo(s,vis,g,g[i][j]);
        }
    }
    s.push(i);
}
void topologicalsort(int vis[],vector<int> g[],int n)
{
    stack<int> s;
    int i;
    for(i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            topo(s,vis,g,i);
        }
    }
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}
int main()
{
    int n,e,i,u,v;
    cin>>n;
    int vis[n]={0};
    vector<int> g[n];
    cin>>e;
    for(i=0;i<e;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
    }
    topologicalsort(vis,g,n);
    return 0;
}
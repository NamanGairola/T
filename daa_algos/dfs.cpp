#include<iostream>
#include<vector>
using namespace std;
void dfs(int s,vector<int> g[],int vis[])
{
    int i;
    vis[s]=1;
    cout<<s<<" ";
    for(i=0;i<g[s].size();i++)
    {
        if(vis[g[s][i]]==0)
        {
            dfs(g[s][i],g,vis);
        }
    }
}
int main()
{
    int n,e,u,v,i;
    cin>>n;
    vector<int> g[n];
    int vis[n]={0};
    cin>>e;
    for(i=0;i<e;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0,g,vis);
    return 0;
}
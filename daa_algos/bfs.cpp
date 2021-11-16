#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void bfs(int s,vector<int> g[],int vis[])
{
    queue<int> q;
    q.push(s);
    vis[s]=1;
    while(!q.empty())
    {
        int c=q.front(),i;
        q.pop();
        cout<<c<<" ";
        for(i=0;i<g[c].size();i++)
        {
            if(vis[g[c][i]]==0)
            {
                vis[g[c][i]]=1;
                q.push(g[c][i]);
            }
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
    bfs(0,g,vis);
    return 0;
}
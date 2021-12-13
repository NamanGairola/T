
//bfs
/*
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void bfs(int s,vector<int> g[],int v[])
{
	int i,j;
	queue<int> q;
	q.push(s);
	v[s]=1;
	while(!q.empty())
	{
		s=q.front();
		q.pop();
		cout<<s<<" ";
		for(i=0;i<g[s].size();i++)
		{
			if(v[g[s][i]]==0)
			{
				v[g[s][i]]=1;
				q.push(g[s][i]);
			}
		}
	}
}
int main()
{
	int n,e,i,s,d,v;
	cin>>v>>e;
	vector<int> g[v];
	for(i=0;i<e;i++)
	{
		cin>>s>>d;
		g[s].push_back(d);
	}
	int vis[v]={0};
	bfs(0,g,vis);
	return 0;
}
*/

//dfs

/*
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
	int s,d,e,v,i;
	cin>>v>>e;
	vector<int> g[v];
	for(i=0;i<e;i++)
	{
		cin>>s>>d;
		g[s].push_back(d);
	}
	int vis[v]={0};
	dfs(0,g,vis);
	return 0;
}
*/

//topological
/*
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
void topo(int s,vector<int> g[],int vis[],stack<int> &st)
{
	vis[s]=1;
	int i;
	for(i=0;i<g[s].size();i++)
	{
		if(vis[g[s][i]]==0)
		{
			topo(g[s][i],g,vis,st);
			st.push(g[s][i]);
		}
	}
}
void topological(vector<int> g[],int vis[],int v)
{
	stack<int> s;
	int i;
	for(i=0;i<v;i++)
	{
		if(vis[i]==0)
		{
			topo(i,g,vis,s);
			s.push(i);
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
	int v,e,s,d,i;
	cin>>v>>e;
	vector<int> g[v];
	for(i=0;i<e;i++)
	{
		cin>>s>>d;
		g[s].push_back(d);
	}
	int vis[v]={0};
	topological(g,vis,v);
	return 0;
}
*/

//krushkal's
/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef vector<pair<int,pair<int,int>>> viii;
int parent(int p[],int i)
{
	if(p[i]<0)
	{
		return i;
	}
	return parent(p,p[i]);
}
void unions(int p[],int s,int d)
{
	int ps=parent(p,s),pd=parent(p,d);
	if(ps!=pd)
	{
		if(p[ps]<p[pd])
		{
			p[ps]=p[ps]+p[pd];
			p[pd]=ps;
		}
		else
		{
			p[pd]=p[pd]+p[ps];
			p[ps]=pd;
		}
	}
}
viii krushkal(viii g,int p[])
{
	int s,d,w,i;
	viii res;
	for(i=0;i<g.size();i++)
	{
		s=g[i].second.first;
		d=g[i].second.second;
		if(parent(p,s)!=parent(p,d))
		{
			res.push_back(g[i]);
			unions(p,s,d);
		}
	}
	return res;
}
int main()
{
	int v,e,s,d,w,i;
	cin>>v>>e;
	viii g,res;
	for(i=0;i<e;i++)
	{
		cin>>s>>d>>w;
		g.push_back(make_pair(w,make_pair(s,d)));
	}
	sort(g.begin(),g.end());
	int p[v];
	for(i=0;i<v;i++)
	{
		p[i]=-1;
	}
	res=krushkal(g,p);
	cout<<"mst edges :\n";
	for(i=0;i<res.size();i++)
	{
		cout<<res[i].second.first<<" "<<res[i].second.second<<" "<<res[i].first<<"\n";
	}
}
*/

//prims
/*
#include<iostream>
#include<vector>
using namespace std;
void prims(int v,vector<vector<int>> g)
{
	int mst[v],p[v],w[v],i,j,m,mw;
	for(i=0;i<v;i++)
	{
		mst[i]=0;
		p[v]=-1;
		w[i]=INT_MAX;
	}
	w[0]=0;
	for(i=0;i<v;i++)
	{
		mw=INT_MAX;
		for(j=0;j<v;j++)
		{
			if(w[j]<mw && mst[j]==0)
			{
				mw=w[j];
				m=j;
			}
		}
		mst[m]=1;
		for(j=0;j<v;j++)
		{
			if(g[m][j]<INT_MAX && g[m][j]<w[j])
			{
				p[j]=m;
				w[j]=g[m][j];
			}
		}
	}
	cout<<"mst :\n";
	for(i=1;i<v;i++)
	{
		cout<<p[i]<<" "<<i<<" "<<w[i]<<'\n';
	}
}
int main()
{
	int v,e,s,d,w,i,j;
	cin>>v>>e;
	vector<vector<int>> arr(v,vector<int>(v,INT_MAX));
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			arr[i][j]=INT_MAX;
		}
	}
	for(i=0;i<e;i++)
	{
		cin>>s>>d>>w;
		arr[s][d]=w;
	}
	prims(v,arr);
	return 0;
}
*/

//dijkstra

/*
#include<iostream>
#include<vector>
using namespace std;
void dij(vector<vector<int>> g,int v)
{
	int mst[v],p[v],w[v],mw,m,i,j;
	for(i=0;i<v;i++)
	{
		mst[i]=0;
		p[i]=-1;
		w[i]=INT_MAX;
	}
	w[0]=0;
	for(i=0;i<v;i++)
	{
		mw=INT_MAX;
		for(j=0;j<v;j++)
		{
			if(mst[j]==0 && mw>w[j])
			{
				mw=w[j];
				m=j;
			}
		}
		mst[m]=1;
		for(j=0;j<v;j++)
		{
			if(g[m][j]!=INT_MAX && g[m][j]+w[m]<w[j])
			{
				w[j]=g[m][j]+w[m];
				p[j]=m;
			}
		}
	}
	cout<<"graph is :\n";
	for(i=1;i<v;i++)
	{
		cout<<p[i]<<" "<<i<<" "<<g[p[i]][i]<<" "<<w[i]<<'\n';
	}
}
int main()
{
	int v,e,s,d,w,i;
	cin>>v>>e;
	vector<vector<int>> g(v,vector<int>(v,INT_MAX));
	for(i=0;i<e;i++)
	{
		cin>>s>>d>>w;
		g[s][d]=w;
		g[d][s]=w;
	}
	dij(g,v);
	return 0;
}
*/

//bellman ford

/*
#include<iostream>
#include<vector>
using namespace std;
void bell(vector<vector<int>> g,int v)
{
	int p[v],w[v],i,j,k,check=0;
	for(i=0;i<v;i++)
	{
		p[i]=-1;
		w[i]=INT_MAX;
	}
	w[0]=0;
	for(i=0;i<v-1;i++)
	{
		for(j=0;j<v;j++)
		{
			if(w[j]<INT_MAX)
			{
				for(k=0;k<v;k++)
				{
					if(g[j][k]+w[j]<w[k] && g[j][k]!=INT_MAX)
					{
						w[k]=g[j][k]+w[j];
						p[k]=j;
					}
				}
			}
		}
	}
	for(j=0;j<v;j++)
	{
		if(w[j]<INT_MAX)
		{
			for(k=0;k<v;k++)
			{
				if(g[j][k]+w[j]<w[k] && g[j][k]!=INT_MAX)
				{
					w[k]=g[j][k]+w[j];
					p[k]=j;
					check=1;
				}
			}
		}
	}	
	if(check==1)
	{
		cout<<"Negative Cycle";
	}
	else
	{
		cout<<"graph:\n";
		for(i=1;i<v;i++)
		{
			cout<<p[i]<<" "<<i<<" "<<g[p[i]][i]<<" "<<w[i]<<'\n';
		}
	}
}
int main()
{
	int v,e,s,d,w,i;
	cin>>v>>e;
	vector<vector<int>> g(v,(vector<int>(v,INT_MAX)));
	for(i=0;i<e;i++)
	{
		cin>>s>>d>>w;
		g[s][d]=w;
	}
	bell(g,v);
	return 0;
}
*/

//floyd
/*
#include<iostream>
using namespace std;
int main()
{
	int v,i,j,k;
	cin>>v;
	int g[v][v];
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			cin>>g[i][j];
		}
	}
	for(k=0;k<v;k++)
	{
		for(i=0;i<v;i++)
		{
			for(j=0;j<v;j++)
			{
				if(g[i][k]+g[k][j]<g[i][j])
				{
					g[i][j]=g[i][k]+g[k][j];
				}
			}
		}
	}
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			cout<<g[i][j]<<" ";
		}
		cout<<'\n';
	}
	return 0;
}
*/
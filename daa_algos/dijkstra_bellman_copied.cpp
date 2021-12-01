#include<bits/stdc++.h>
using namespace std;

#define V 6		//No of vertices

int selectMinVertex(vector<int>& value,vector<bool>& processed)
{
	int minimum = INT_MAX;
	int vertex;
	for(int i=0;i<V;++i)
	{
		if(processed[i]==false && value[i]<minimum)
		{
			vertex = i;
			minimum = value[i];
		}
	}
	return vertex;
}

void dijkstra(int graph[V][V])
{
	int parent[V];		//Stores Shortest Path Structure
	vector<int> value(V,INT_MAX);	//Keeps shortest path values to each vertex from source
	vector<bool> processed(V,false);	//TRUE->Vertex is processed

	//Assuming start point as Node-0
	parent[0] = -1;	//Start node has no parent
	value[0] = 0;	//start node has value=0 to get picked 1st

	//Include (V-1) edges to cover all V-vertices
	for(int i=0;i<V-1;++i)
	{
		//Select best Vertex by applying greedy method
		int U = selectMinVertex(value,processed);
		processed[U] = true;	//Include new Vertex in shortest Path Graph

		//Relax adjacent vertices (not yet included in shortest path graph)
		for(int j=0;j<V;++j)
		{
			/* 3 conditions to relax:-
			      1.Edge is present from U to j.
			      2.Vertex j is not included in shortest path graph
			      3.Edge weight is smaller than current edge weight
			*/
			if(graph[U][j]!=0 && processed[j]==false && value[U]!=INT_MAX
			&& (value[U]+graph[U][j] < value[j]))
			{
				value[j] = value[U]+graph[U][j];
				parent[j] = U;
			}
		}
	}
	//Print Shortest Path Graph
	for(int i=1;i<V;++i)
		cout<<"U->V: "<<parent[i]<<"->"<<i<<"  wt = "<<graph[parent[i]][i]<<"\n";
}

int main()
{
	int graph[V][V] = { {0, 1, 4, 0, 0, 0},
						{1, 0, 4, 2, 7, 0},
						{4, 4, 0, 3, 5, 0},
						{0, 2, 3, 0, 4, 6},
						{0, 7, 5, 4, 0, 7},
						{0, 0, 0, 6, 7, 0} };

	dijkstra(graph);	
	return 0;
}

//TIME COMPLEXITY: O(V^2)
//TIME COMPLEXITY: (using Min-Heap + Adjacency_List): O(ElogV)


/////////////////////////////
///////////////////////////
//////////////////////////////
////////////////////////////////////////////


#include<bits/stdc++.h>
using namespace std;

struct edge{
	int src,dst,wt;
};
int V,E;

void bellmanFord(vector<edge>& Edges)
{
	int parent[V];		//Stores Shortest Path Structure
	int cost_parent[V];	//Cost of the node to parent edge weight
	vector<int> value(V,INT_MAX);	//Keeps shortest path values to each vertex from source
	
	//Assuming start point as Node-0
	parent[0] = -1;	//Start node has no parent
	value[0] = 0;	//start node has value=0 to get picked 1st

	//Include (V-1) edges to cover all V-vertices
	bool updated;
	for(int i=0;i<V-1;++i)
	{
		updated = false;
		for(int j=0;j<E;++j)
		{
			int U = Edges[j].src;
			int V = Edges[j].dst;
			int wt = Edges[j].wt;
			if(value[U]!=INT_MAX and value[U]+wt<value[V])
			{
				value[V] = value[U]+wt;
				parent[V] = U;
				cost_parent[V] = value[V];
				updated = true;
			}
		}
		if(updated==false)
			break;
	}
	//Now check by relaxing once more if we have a negative edge cycle
	for(int j=0;j<E and updated==true;++j)
		{
			int U = Edges[j].src;
			int V = Edges[j].dst;
			int wt = Edges[j].wt;
			if(value[U]!=INT_MAX and value[U]+wt<value[V])
			{
				cout<<"Graph has -VE edge cycle\n";
				return;
			}
		}
	//Print Shortest Path Graph
	for(int i=1;i<V;++i)
		cout<<"U->V: "<<parent[i]<<"->"<<i<<"  Cost to reach "<<parent[i]<<"from source 0 = "<<value[i]<<"\n";
}

int main()
{
	cin>>V>>E;	//Enter no of Vertices and Edges
	vector<edge> Edges(E);

	//Now input all E edges
	int src,dst,wt;
	for(int i=0;i<E;++i)
	{
		cin>>src>>dst>>wt;
		Edges[i].src = src;
		Edges[i].dst = dst;
		Edges[i].wt = wt;
	}

	bellmanFord(Edges);	
	return 0;
}

//TIME COMPLEXITY: O(V.E)
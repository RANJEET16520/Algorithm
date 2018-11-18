#include <bits/stdc++.h>
using namespace std;
#define pii pair< int, int >
#define ll long long int
#define clr(g,x)(memset(g,x,sizeof(g)))
#define pb push_back
#define mk make_pair
#define fst first
#define sec second
const ll inf = 1e18;
int main()
{
	// Total Nodes and Edges in the graph 
	int nodes,edges;
	cout<<"-----------Prims Algorithm------------\n";
	cout<<"Enter the number of nodes : ";
	cin>>nodes;
	cout<<"Enter the number of edges : ";
	cin>>edges;

	// Edge and their weight
	cout<<"Enter the edges in between nodes and their weights: \n";
	vector< pii >vect[nodes+1];
	for(int i=0; i<edges; i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		vect[x].pb(mk(w,y));
		vect[y].pb(mk(w,x));
	}

	// Visited nodes
	bool visited[nodes+1];
	clr(visited,false);
	// First node
	int cost = 0;
	int u=1,v;
	// Priority queue to extract minimum weightd edge
	priority_queue< pii, vector< pii >, greater< pii > >q;
	pii p;
	q.push(mk(0,u));

	while(!q.empty())
	{
		// Extract minimum weighted edge
		p = q.top();
		q.pop();
		u = p.sec;
		// Node visited or not?
		if(visited[u])
			continue;
		// If not then mark visited, add it to spanning tree and expand the node
		int wei = p.fst;
		cost += wei;
		visited[u]=true;
		// Expanding the node
		for(int i=0; i<vect[u].size(); i++)
		{
			v = vect[u][i].sec;
			if(!visited[v])
				q.push(vect[u][i]);
		}
	}
	// Minimum cost
	cout<<"Minimum cost : "<<cost<<endl;
	cout<<"-By\nRanjeet Walia\nRoll no: 16520\nCSE 4yr.\n3rd year, 5th sem\n";
	
}
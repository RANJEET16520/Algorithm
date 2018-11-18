#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define clr(g,x)(memset(g,x,sizeof(g)))
const ll inf = 1e18;
const ll siz = 20;
ll G[siz][siz];
int coloring_array[siz];
void next_value(int k,int mod,int n)
{	
	while(true)
	{
		// Assign the color
		coloring_array[k] = (coloring_array[k]+1)%(mod+1);
		if(coloring_array[k]==0)//No color is assigned
			return ;
		int i=0;
		for(i=0; i<n; i++)
		{
			if(G[k][i]==1 and coloring_array[i] == coloring_array[k])//Matching color with the adjeceincy node
				break;//If color is matched then don't assign that color to node.
		}
		if(i>n-1) //color is assigned
			return ;
		// cout<<coloring_array[k]<< " ";
	}
}

bool colorGraph(int k, int mod,int n)
{
	next_value(k,mod,n);
	// if no color assigned to graph then this color number is not possible for this graph
	if(coloring_array[k]==0)
		return false;
	// if Nodes are colored the return the answer
	if(k==n)
		return true;
	else
		colorGraph(k+1,mod,n); //Assigning color to next node 
}
int main()
{
	cout<<"------------Graph Coloring------------\n";
	clr(G,0);
	clr(coloring_array,0);
	cout<<"Enter the number of nodes : ";
	int nodes,edges;
	cin>>nodes;
	cout<<"Enter the number of edges : ";
	cin>>edges;
	cout<<"Enter the edge between nodes \n";
	for(int i=0; i<edges; i++)
	{
		int x,y;
		cin>>x>>y;
		G[x-1][y-1]=1;
		G[y-1][x-1]=1;
	}
	int ans=-1;
	for(int i=1; i<=10; i++)
	{
		// Increasing colors to assign to the nodes in graph
		if(colorGraph(0,i,nodes))
		{
			ans=i;
			break;
		}
		clr(coloring_array,0);
	}
	cout<<"Adjeciency Matrix is:\n";
	for(int i=0; i<nodes; i++)
	{
		for(int j=0; j<nodes; j++)
			cout<<G[i][j]<<" ";
		cout<<endl;
	}
	cout<<"Total Color Assigned are : "<<ans<<endl;
	cout<<"Color Assigned to Nodes are ::: ";

	for(int i=0; i<nodes; i++)
		cout<<i+1<<":"<<coloring_array[i]<<"  ";
	cout<<endl;
	cout<<"-By\nRanjeet Walia\nRoll no: 16520\nCSE 4yr.\n3rd year, 5th sem\n";
}
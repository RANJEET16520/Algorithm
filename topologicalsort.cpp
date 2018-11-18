#include <bits/stdc++.h>
using namespace std;
const int siz = 20;
vector< int >vect[siz];
bool visited[siz];
int finish_Time[siz];
int start_Time[siz];
int Time=0;
void dfs(int index)
{
	Time+=1;
	start_Time[index]=Time;

	for(int i=0; i<vect[index].size(); i++)
	{
		if(!visited[ vect[index][i] ]){
			visited[ vect[index][i] ]=true;
			dfs(vect[index][i]);
		}
	}
	Time+=1;
	finish_Time[index]=Time;
}
int main()
{
	for(int i=0; i<siz; i++){
		finish_Time[i]=0,start_Time[i]=0,visited[i]=false;
	}
	// Total Nodes and Edges in the graph 
	int nodes,edges;
	cout<<"-----------Topological Sort------------\n";
	cout<<"Enter the number of nodes : ";
	cin>>nodes;
	cout<<"Enter the number of edges : ";
	cin>>edges;
	// Edge and their weight
	cout<<"Enter the edges in between nodes\n";

	for(int i=0; i<edges; i++)
	{
		int x,y;
		cin>>x>>y;
		vect[x].push_back(y);
	}
	visited[1]=true;
	dfs(1);
	while(true)
	{
		int nhi=0;
		for(int i=1; i<=nodes; i++)
		{
			if(visited[i])
				nhi=1;
			else{
				visited[i]=true;
				dfs(i);
				nhi=0;
				break;
			}
		}
		if(nhi)
			break;
	}
	vector< pair< int, int > >vec;
	for(int i=1; i<nodes; i++)
		vec.push_back(make_pair(finish_Time[i],i));
	sort(vec.rbegin(), vec.rend());
	cout<<"Topological Sort : ";
	vector < pair< int, int > >::iterator itr;
	for(itr = vec.begin(); itr != vec.end(); itr++)
		cout<<itr->second<<" ";
	cout<<endl;
}
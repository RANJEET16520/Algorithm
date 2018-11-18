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
const ll siz = 20;
// Component used to visit the Graph
vector< int >straight_vect[siz];//Adjecency list
bool straight_visited[siz];//Visited Array
int straight_finish_time[siz];//Finish time array
int straight_start_Time[siz];//Start Time array

// Component used to visit the complament of Graph
vector< int >opposite_vect[siz];//Adjecency list for the complamnet of graph
bool opposite_visited[siz];//Visited Array for the complamnet of graph
int opposite_finish_time[siz];//Finish time array for the complamnet of graph
int opposite_start_Time[siz];//Start Time array for the complamnet of graph
int opposite_val[siz];//Storing the connected component value

int Time;
int nodes,edges;

// DFS for straight visit in the graph
void straight_dfs(int index)
{
	Time+=1;
	straight_start_Time[index]=Time;

	for(int i=0; i<straight_vect[index].size(); i++)
	{
		int y = straight_vect[index][i];
		if(!straight_visited[y]){
			straight_visited[y]=true;//Node is visited
			straight_dfs(y);
		}
	}
	Time+=1;
	straight_finish_time[index]=Time;
}
void straight_visit()
{
	clr(straight_finish_time,0);
	clr(straight_start_Time,0);
	clr(straight_visited,false);
	Time=0;
	straight_visited[1]=true;
	straight_dfs(1);
	// for(int i=1; i<=nodes; i++)
	// 	cout<<i<<":"<<straight_visited[i]<<" ";
	// To check wheather all nodes are visited in the graph
	while(true)
	{
		int nhi=0;
		for(int i=1; i<=nodes; i++)
		{
			if(straight_visited[i])
				nhi=1;
			else{ //If node is unvisited in the graph then apply DFS again in the Graph
				straight_visited[i]=true;
				straight_dfs(i);
				nhi=0;
				break;
			}
		}
		if(nhi)
			break;
	}
	cout<<"Straight-Visit\n";
	cout<<"Node\tStartTime\tFinishTime\n";
	// Printing the start-time and finish-time of the node
	for(int i=1; i<=nodes; i++)
		cout<<i<<"\t"<<straight_start_Time[i]<<"\t\t"<<straight_finish_time[i]<<endl;
	vector< pii >straight_vec;
	for(int i=1; i<nodes; i++)
		straight_vec.pb(mk(straight_finish_time[i],i));
	sort(straight_vec.rbegin(), straight_vec.rend());
	cout<<endl;
}

// DFS to visit the complament of the graph
void opposite_dfs(int index,int val)
{
	Time+=1;
	opposite_start_Time[index]=Time;
	opposite_val[index]=val;
	for(int i=0; i<opposite_vect[index].size(); i++)
	{
		int y = opposite_vect[index][i];
		if(!opposite_visited[y]){
			opposite_visited[y]=true;//Node is visited
			opposite_dfs(y, val);
		}
	}
	Time+=1;
	opposite_finish_time[index]=Time;
}
void opposite_visit(int mx)
{
	clr(opposite_finish_time,0);
	clr(opposite_start_Time,0);
	clr(opposite_visited,false);
	clr(opposite_val,0);
	int val=0;
	opposite_visited[mx]=true;
	Time=-2;
	opposite_dfs(mx,val);
	// for(int i=1; i<=nodes; i++)
	// 	cout<<i<<":"<<opposite_visited[i]<<" ";
	while(true)
	{
		int nhi=0;
		for(int i=1; i<=nodes; i++)
		{
			if(opposite_visited[i])
				nhi=1;
			else{
				opposite_visited[i]=true;
				val+=1;
				opposite_dfs(i,val);
				nhi=0;
				break;
			}
		}
		if(nhi)
			break;
	}

	cout<<"Opposite-Visit\n";
	cout<<"Node\tStartTime\tFinishTime\n";
	for(int i=1; i<=nodes; i++)
		cout<<i<<"\t"<<opposite_start_Time[i]<<"\t\t"<<opposite_finish_time[i]<<endl;
	vector< pii >opposite_vec;
	for(int i=1; i<nodes; i++)
		opposite_vec.pb(mk(opposite_finish_time[i],i));
	sort(opposite_vec.rbegin(), opposite_vec.rend());
}

void connented_componet()
{
	cout<<"Strongly connencted Components are : \n";
	vector< pii >vect;
	for(int i=1; i<=nodes; i++)
	{
		vect.pb(mk(opposite_val[i], i));
	}

	// Arranging the strongly connected componet
	sort(vect.begin(), vect.end());
	vector< vector<int> >V;
	vector< int >small_v;
	int preval=1;
	for(auto itr=vect.begin(); itr!=vect.end(); itr++)
	{
		if(preval == itr->fst){
			small_v.pb(itr->sec);
			preval=itr->fst;
		}
		else{
			preval = itr->fst;
			V.pb(small_v);
			small_v.clear();
			small_v.pb(itr->sec);
		}
	}
	V.pb(small_v);

	for(int i=0; i<V.size(); i++)
	{
		cout<<i+1<<" Strongly Connented nodes are : ";
		for(int j=0; j<V[i].size(); j++)
			cout<<V[i][j]<<" ";
		cout<<endl;
	}
}
int main()
{
	// Total Nodes and Edges in the graph 
	
	cout<<"-----------Strongly Connented Component------------\n";
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
		// G of garph
		straight_vect[x].pb(y);
		// G' (complament) of the graph
		opposite_vect[y].pb(x);
	}
	// Straight Visit to graph
	straight_visit();
	
	int mx=0,mx_f_time=0;
	for(int i=1; i<=nodes; i++){
		if(mx_f_time > straight_finish_time[i]){
			mx=i;
			mx_f_time = straight_finish_time[i];
		}
	}
	// Opposite visit to Graph
	opposite_visit(mx);
	connented_componet();
	cout<<"\n-By\nRanjeet Walia\nRoll no: 16520\nCSE 4yr.\n3rd year, 5th sem\n";
}
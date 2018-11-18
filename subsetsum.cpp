#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define clr(g,x)(memset(g,x,sizeof(g)))
const ll inf = 1e18;

bool promising(int WeightSoFar, int total, int sum, int index, int array[])
{
	if((WeightSoFar + total >= sum) and (WeightSoFar==sum or WeightSoFar+array[index]<=sum))
		return true;
	return false;
}

void subset_sum(int array[], int index, int siz, int sum, int WeightSoFar, int total, bool vect[])
{
	// Promising node
	if(promising(WeightSoFar,total,sum,index,array))
	{
		if(WeightSoFar==sum)
		{
			cout<<"Subset is : ";
			for(int i=0; i<siz; i++)
				if(vect[i])
					cout<<array[i]<<" ";
			cout<<endl;
		}
		else
		{
			// Including current weight
			vect[index]=true;
			subset_sum(array, index+1, siz, sum, WeightSoFar+array[index], total-array[index],vect);
			// Excluding curremt weight
			vect[index]=false;
			subset_sum(array, index+1, siz, sum, WeightSoFar, total-array[index],vect);
		}
	}
}

int main()
{
	cout<<"--------Subset Sum Algorithm--------\n";
	int n;
	cout<<"Enter the size of set : ";
	cin>>n;

	int a[n];
	cout<<"Enter the number : ";
	for(int i=0; i<n; i++)
		cin>>a[i];
	
	cout<<"Enter the sum : ";
	int sum;
	cin>>sum;
	
	bool vect[n];
	clr(vect, false);
	
	int total = 0;
	for(int i=0; i<n; i++)
		total += a[i];
	
	subset_sum(a,0,n,sum,0,total,vect);
	cout<<"-By\nRanjeet Walia\nRoll no: 16520\nCSE 4yr.\n3rd year, 5th sem\n";
	return 0;
}
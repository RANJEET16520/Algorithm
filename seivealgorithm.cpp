#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define clr(g,x)(memset(g,x,sizeof(g)))
const ll inf = 1e8;
int main()
{
	ll n= inf;
	vector<char>vect(n+1,true);
	vect[0]=vect[1]=false;
	for(ll i=2; i<=n; i++)
	{
		if(vect[i] and i*i<=n)
		{
			for(ll j=i*i; j<=n; j+=i)
				vect[j]=false;
		}
	}
	ll cnt=0;
	for(ll i=0; i<=n; i++)
		if(vect[i])
			cout<<i<<" ", cnt++;

	cout<<"\n\n"<<cnt<<"\n";
}
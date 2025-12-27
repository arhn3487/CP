#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";


void solve()
{
	ll n,k,cost=0;cin>>n>>k;
	vector<array<ll,2>> graph[k+1];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int a;cin>>a;
			//debug(a);
			graph[a].push_back({i,j});

		}
	}

	for(int i=2;i<=k;i++)
	{
		ll tmp=INT_MAX;
		for(auto [i1,j1] : graph[i])
		{
			for(auto [i2,j2]: graph[i-1])
			{
				tmp=min(tmp,abs(i2-i1)+abs(j2-j1));
			}
		}

		cost+=tmp;
	}

	//debug(graph);

	cout<<cost<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t=1;
	cin>>t;

	for(int i=1;i<=t;i++)
	{
		//cout<<"Case "<<i<<": ";
		solve();
	}
}
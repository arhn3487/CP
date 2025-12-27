#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}
const int N=1e6+7;

vector<ll> spf(N);
vector<ll> prime;

void spf_gen() {
    for(int i = 1; i < N; i++) spf[i] = i;

    for(int i = 2; i < N; i++) {
        if(spf[i] == i) { 
            for(int j = i*2; j < N; j += i) {
                if(spf[j] == j) spf[j] = i;
            }
        }
    }

    for(int i=2;i<N;i++)
    {
        if(spf[i]==i) prime.push_back(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    spf_gen();

    int t;
    cin>>t;
    ll k;
    ll sz=prime.size()+1;
    vector<ll> presum(sz+1);
    partial_sum(prime.begin(),prime.end(),presum.begin()+1);


    while(t--)
    {
        cin>>k;
        
        ll nop=lower_bound(prime.begin(),prime.end(),spf[k])-prime.begin();
        ll ans=presum[nop+1]*k;
        cout<<ans<<endl;
    }
}
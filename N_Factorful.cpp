#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

const int N=1e6+3;
vector<int> is_prime(N,0);
vector<int> cnt[11];

void seive()
{
    for(int i=2;i<N;i++)
        if(is_prime[i]==0)
            for(int j=i;j<N;j+=i)
                is_prime[j]++;

    for(int i=1;i<N;i++)
        if(is_prime[i]<11)
            cnt[is_prime[i]].push_back(i);
}           

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    seive();

    int t;
    cin>>t;

    while(t--)
    {
        int n,a,b;
        cin>>a>>b>>n;
        int x=lower_bound(cnt[n].begin(),cnt[n].end(),a)-cnt[n].begin();
        int y=upper_bound(cnt[n].begin(),cnt[n].end(),b)-cnt[n].begin();

        cout<<(y-x)<<endl;
    }
}
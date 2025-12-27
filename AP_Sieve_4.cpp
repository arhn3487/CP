#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

const int N=1e5+7;
vector<bool> is_prime(N,true);

void sieve()
{
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i*i<N;i++)
        for(int j=i*i;j<N;j+=i)
            is_prime[j]=false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,cnt=0,total=0;
    cin>>n;
    vector<int> v(n+2,0);
    set<int> st;

    sieve();

    if(n==1) cout<<1<<endl<<1<<endl;
    else if(n==2) cout<<1<<endl<<"\n1 1"<<endl;
    else{
        cout<<2<<endl;
        for(int i=2;i<=n+1;i++)
        {
            if(is_prime[i]) cout<<1<<" ";
            else cout<<2<<" ";
        }
    }

    
}
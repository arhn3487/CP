#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const int N=1e6+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

vector<bool> is_prime(N,true);

void seive()
{
    is_prime[0]=is_prime[1]=false;   
    for(int i=2;i*i<N;i++)
        if(is_prime[i])
            for(int j=i*i;j<N;j+=i)
                is_prime[j]=false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    seive();

    int n,m=1;
    cin>>n;
    while(m*n+1<N && is_prime[m*n+1])
    {
        m++;
    }

    cout<<m<<endl;
}
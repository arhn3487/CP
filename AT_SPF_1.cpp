#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
const int N=1e7+3;
int dx[]={1,0,-1,0,1,1,-1,-1};
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int spf[N];

void Spf()
{
    for(int i=2;i<=N;i++) spf[i]=i;
    
    for(int i=2;i*i<N;i++)
        if(spf[i]==i)
            for(int j=i*i;j<N;j+=i)
                if(spf[j]==j) spf[j]=i;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Spf();
    int n;

    while(cin>>n)
    {
        cout<<1;
        while(n>1)
        {
            cout<<" x "<<spf[n];
            n/=spf[n];
        }
        cout<<"\n";
    }
}
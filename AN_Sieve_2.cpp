#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

const int mx=1e8+3;
//const int mx=80;
bool isPrime[mx];
vector<int> p;

void seive()
{
    for(int i=2;i<mx;i++) isPrime[i]=true;

    for(int i=2;i*i<mx;i++)
        if(isPrime[i])
            for(int j=i*i;j<mx;j+=i)
                isPrime[j]=false;

    for(int i=2;i<mx;i++)
    {
        if(isPrime[i]) p.push_back(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    seive();

    int sz=p.size();

    for(int i=0;i<sz;i+=100)
    {
        cout<<p[i]<<"\n";
    }
}

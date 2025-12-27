#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

const int N=1e7+3;
vector<int> is_prime(N,true);
vector<int> v;

void  seive()
{
    is_prime[0]=is_prime[1]=false;

    for(int i=2;i*i<N;i++)
        if(is_prime[i])
            for(int j=i*i;j<N;j+=i)
                is_prime[j]=false;
    
}

void find()
{
    for(int i=1;i<N;i++)
    {
        int tmp=i*i*i*i;
        if(tmp>N) break;
        for(int j=1;j<N;j++)
        {
            int tmp2=j*j;
            if(tmp+tmp2>=N) break;

            if(is_prime[tmp+tmp2])
            {
                v.push_back(tmp+tmp2);
                is_prime[tmp+tmp2]=false;
            }
        }
    }

    sort(v.begin(),v.end());
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    seive();
    find();

    int t;
    t=1;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        //for(int i=0;i<10;i++) cout<<v[i]<<endl;
        cout<<upper_bound(v.begin(),v.end(),n)-v.begin()<<endl;
    }
}
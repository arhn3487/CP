#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

const int N=1e6+3;
vector<bool> is_prime(N,true);

void seive()
{
    is_prime[0]=is_prime[1]=false;

    for(int i=2;i*i<N;i++)
    {
        if(is_prime[i])
        {
            for(int j=i*i;j<N;j+=i)
                is_prime[j]=false;
        }
    }
}

vector<int> arr[7];
vector<int> afraidnum;

void afraid_gen()
{
    arr[0].push_back(0);
    int power=1;
    for(int i=1;i<7;i++)
    {
        for(int j=1;j<10;j++)
        {
            for(auto it : arr[i-1])
            {
                int tmp=j*power+it;
                if(is_prime[tmp])
                {
                    arr[i].push_back(tmp);
                    afraidnum.push_back(tmp);
                }
            }
        }
        power*=10;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    seive();
    afraid_gen();

    int t;
    t=1;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        cout<<upper_bound(afraidnum.begin(),afraidnum.end(),n)-afraidnum.begin()<<endl;
    }
}
#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

const int N=1e7+3;
vector<ll> spf(N);
vector<ll> cnt1(N),cnt2(N);

void spf_gen() {
    for(int i = 1; i < N; i++) spf[i] = i;

    for(int i = 2; i < N; i++) {
        if(spf[i] == i) { 
            for(int j = i*2; j < N; j += i) {
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    spf_gen();

    int n,m;
    cin>>n>>m;
    vector<ll> a(n),b(m);

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        int tmp=a[i];

        while(tmp>1)
        {
            cnt1[spf[tmp]]++;
            tmp/=spf[tmp];
        }
    }

    for(int i=0;i<m;i++)
    {
        cin>>b[i];
        int tmp=b[i];

        while(tmp>1)
        {
            cnt2[spf[tmp]]++;
            tmp/=spf[tmp];
        }
    }

    cout<<n<<" "<<m<<endl;

    for(int i=0;i<n;i++)
    {
        ll num=1;

        while(a[i]>1)
        {
            if(cnt2[spf[a[i]]]>0)
            {
                cnt2[spf[a[i]]]--;
            }
            else num*=spf[a[i]];

            a[i]/=spf[a[i]];
        }

        cout<<num<<" ";
    }
    cout<<endl;
    for(int i=0;i<m;i++)
    {
        ll num=1;

        while(b[i]>1)
        {
            if(cnt1[spf[b[i]]]>0)
            {
                cnt1[spf[b[i]]]--;
            }
            else num*=spf[b[i]];

            b[i]/=spf[b[i]];
        }

        cout<<num<<" ";
    }
}
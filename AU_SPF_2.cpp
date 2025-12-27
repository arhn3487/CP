#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
const int N=1e7+3;
int dx[]={1,0,-1,0,1,1,-1,-1};
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int stf[N];
bool p[N];
vector<int> prime;

void Stf()
{
    for(int i=1;i<N;i++) stf[i]=i;

    for(int i=2;i*i<=N;i++)
        if(stf[i]==i)
            for(int j=i*i;j<N;j+=i)
                if(stf[j]==j)
                    stf[j]=i;
}

void seive()
{
    for(int i=1;i<N;i++) p[i]=true;

    for(int i=2;i*i<N;i++)
    {
        if(p[i])
        {
            //prime.push_back(i);
            for(int j=i*i;j<N;j+=i) p[j]=false;
        }       
    }

    for(int i=2;i<N;i++)
    {
        if(p[i]) prime.push_back(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Stf();
    seive();
    int t;
    t=1;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];

        //for(int i=0;i<n;i++) cin>>arr[i];
        set<int> st;

        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            while(arr[i]%stf[arr[i]==0])
            {
                st.insert(stf[arr[i]]);
                arr[i]/=stf[arr[i]];
            }
            if(arr[i]>1) st.insert(arr[i]);
        }

        int l = prime.size();

        for(int i=0;i<prime.size();i++)
        {
            if(st.find(prime[i])==st.end())
            {
                cout<<prime[i]<<endl;
                break;
            }
        }
    }
}
#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n,k,a,k2,dui_bar_first=0,dui_bar_second=0;
        cin>>n>>k;
        k*=2;
        k2=k;
        int first[n+1]={0},second[n+1]={0};

        for(int i=0;i<n;i++)
        {
            cin>>a;
            first[a]++;
            if(first[a]==2) dui_bar_first++;
        }
        for(int i=0;i<n;i++)
        {
            cin>>a;
            second[a]++;
            if(second[a]==2) dui_bar_second++;
        }

        // for(int i=1;i<=n;i++) cout<<first[i]<<" ";
        // cout<<endl;
        // for(int i=1;i<=n;i++) cout<<second[i]<<" ";
        // cout<<endl;

        for(int i=1;i<=n && dui_bar_first && k>1;i++)
        {
            if(first[i]==2)
            {
                k-=2;
                dui_bar_first--;
                first[i]=0;
                cout<<i<<" "<<i<<" ";
            }
        }
        for(int i=1;i<=n&& k;i++)
        {
            if(first[i]==1)
            {
                k--;
                //dui_bar_first--;
                first[i]=0;
                cout<<i<<" ";
            }
        }
        cout<<endl;
        for(int i=1;i<=n && dui_bar_second && k2>1;i++)
        {
            if(second[i]==2)
            {
                k2-=2;
                dui_bar_second--;
                second[i]=0;
                cout<<i<<" "<<i<<" ";
            }
        }
        for(int i=1;i<=n && k2;i++)
        {
            if(second[i]==1)
            {
                k2--;
                //dui_bar_first--;
                first[i]=0;
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }
}
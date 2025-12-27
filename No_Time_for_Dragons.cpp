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

    int n;
    cin>>n;

    vector<pair<int,int>> v(n);

    for(int i=0;i<n;i++)
    {
        cin>>v[i].first>>v[i].second;
    }


    sort(v.begin(),v.end(),[](pair<int,int>a,pair<int,int>b)
    {
        return a.first-a.second>b.first-b.second;
    });

    ll sum=0;
    ll beche_ase=0;

    for(int i=0;i<n;i++)
    {
        if(beche_ase<v[i].first)
        {
            sum+=v[i].first-beche_ase;
            beche_ase=v[i].first-v[i].second;
            continue;
        }
        beche_ase-=v[i].second;
    }

    cout<<sum<<endl;
}
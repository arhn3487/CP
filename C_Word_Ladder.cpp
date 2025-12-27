#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a,b;
    cin>>a>>b;
    int l=a.size();
    //vector<int> arr(n);
    vector<string> v;
    int c=0;

    for(int i=0;i<l;i++)
    {
        if(a[i]!=b[i] && a[i]>b[i])
        {
            //string s=a;
            a[i]=b[i];
            //cout<<a<<endl;
            v.push_back(a);

        }
    }
    for(int i=l-1;i>=0;i--)
    {
        if(a[i]!=b[i])
        {
            //string s=a;
            a[i]=b[i];
            //cout<<a<<endl;
            v.push_back(a);

        }
    }

    //sort(v.begin(),v.end());

    cout<<v.size()<<endl;

    for(int i=0;i<v.size();i++) cout<<v[i]<<endl;
}
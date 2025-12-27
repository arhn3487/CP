#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,c=0;
    cin>>n>>m;

    set<string> p,e;
    string s;

    for(int i=0;i<n;i++)
    {
        cin>>s;
        p.insert(s);
    }
    for(int i=0;i<m;i++)
    {
        cin>>s;
        if(p.find(s)!=p.end()) c++;
        e.insert(s);
    }

    int p_b=n-c+c%2;
    int e_b=m-c;

    if(p_b>e_b) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
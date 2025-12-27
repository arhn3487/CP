#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        string s,p,n="",m="";
        cin>>s>>p;
        cout<<p[0];
        cout<<s[1]<<s[2]<<" ";
        cout<<s[0]<<p[1]<<p[2]<<endl;

        //cout<<n<<" "<<m<<endl;
    }
}
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    t=1;
    cin>>t;

    while(t--)
    {
        string s;
        cin>>s;

        int l = s.length();
        bool flag=false;

        if(s[l-1]=='9' || s[0]!='1') 
        {
            cout<<"NO"<<endl;
            continue;
        }

        for(int i=0;i<l-1;i++)
        {
            if(s[i]=='0')
            {
                flag=true;
            }
        }

        if(flag) cout<<"NO"<<endl;
        else cout<<"YES\n";
    }
}
#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

string txt,pat="1100"; 
int n,m,cnt=0;

bool valid(int x)
{
    if(txt[x]=='0')
    {
        if(x-3>=0 && txt[x-1]=='0' && txt[x-2]=='1' && txt[x-3]=='1') return true;
        else if(x-2>=0 && x+1<n && txt[x-1]=='1' && txt[x-2]=='1' && txt[x+1]=='0') return true;
        return false;
    }
    else
    {
        if(x+3<n && txt[x+1]=='1' && txt[x+2]=='0' && txt[x+3]=='0') return true;
        else if(x+2<n && x-1>=0 && txt[x+1]=='0' && txt[x+2]=='0' && txt[x-1]=='1') return true;
        return false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        cnt=0;
        cin>>txt;
        n=txt.length();

        for(int i=0;i<n;i++)
        {
            if(i+3<n && txt[i]=='1' && txt[i+1]=='1' && txt[i+2]=='0' && txt[i+3]=='0')
            {
                cnt++;
                i+=3;
            }
        }

        int q,ind;
        char val;
        cin>>q;
        
        while(q--)
        {
            cin>>ind>>val;
            ind--;

            if(valid(ind)) cnt--;
            txt[ind]=val;
            //cout<<txt<<'\n';
            if(valid(ind)) cnt++;

            if(cnt<1) cout<<"NO\n";
            else cout<<"YES\n";
        }
    }
}
#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

vector<int> lps;
int m;
string str;

void lps_cal()
{
    lps[0]=0;
    int i=1,len=0;

    while(i<m)
    {
        if(str[i]==str[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len==0)
            {
                lps[i]=0;
                i++;
            }
            else len=lps[len-1];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>str;
    m=str.length();
    lps.assign(m,0);
    lps_cal();

    //cout<<str.length()<<endl;
    //for(auto x : lps) cout<<x<<" ";
    if(lps[m-1]*2>m)
    {
        cout<<"YES\n"<<str.substr(0,lps[m-1])<<endl;
    }
    else cout<<"NO\n";
}
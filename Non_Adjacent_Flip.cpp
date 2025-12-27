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
        int n,change=0;
        string str;
        cin>>n>>str;
        vector<int> v;
        //int have_to_change=0;
        //cout<<"arafat\n";
        for(int i=0;i<n;i++)
        {
            if(str[i]=='1') 
            {
                change++;
                v.push_back(i);
                //v.push_back(i+1);
            }
        }

        //cout<<change<<endl;
        if(change%2) cout<<-1<<endl;
        else if(change>2 || change==0) cout<<change/2<<endl;
        else 
        {
            bool f=false;
            for(int i=0;i<n-1;i++)
            {
                if(str[i]=='1' && str[i+1]=='1')
                {
                    f=true;
                    break;
                }
            }
            if(str=="0110") cout<<3<<endl;
            else if(!f && n==3) cout<<1<<endl;
            else if(n==3) cout<<-1<<endl;
            else if(!f) cout<<1<<endl;
            else 
            {
                if(str[0]=='1' && str[1]=='1') cout<<2<<"\n";
                else if(str[n-1]=='1' && str[n-2]=='1') cout<<2<<"\n";
                else cout<<3<<endl;
            }
        }
    }
}
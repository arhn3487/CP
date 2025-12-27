#include<bits/stdc++.h>
#include "D:/debug.h"
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

    int t;
    t=1;
    cin>>t;

    while(t--)
    {
        int n,cnt=0,j=0;
        string str;
        cin>>n>>str;

        stack<pair<char,int>> st;
        
        for(int i=0;i<n;i++)
        {
            char ch = str[i];
            if(!st.empty() && (st.top().first=='('|| st.top().first=='_') && (ch ==')' || ch=='_'))
            {
                cnt+=i-st.top().second;
                st.pop();
                j=i;
                //cout<<j<<" "<<cnt<<endl;
            }
            else st.push({ch,i});
        }

        cout<<cnt<<endl;
    }
}
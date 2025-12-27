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

    int n,a,tgt=0,cnt=0;
    cin>>n;
    n*=2;
    stack<int> st;
    
    while(n--)
    {
        string str;
        cin>>str;

        if(str=="add") 
        {
            cin>>a;
            st.push(a);
        }
        else 
        {
            tgt++;
            if(st.empty())
                continue;
            if(st.top()==tgt)
                st.pop();
            else
            {
                while(!st.empty()) st.pop();
                cnt++;
            }
            
        }
    }

    cout<<cnt<<endl;
}
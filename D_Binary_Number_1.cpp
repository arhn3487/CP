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

    string str;
    cin>>str;

    str='0'+str;
    int op=0;

    while(str!="0" && str!="01")
    {
        if(str.back()=='0')str.pop_back();
        else if(str.back()=='1')
        {
            int ind=str.length();
            ind--;

            while(ind>=0 && str[ind]!='0') ind--;
            
            if (ind < 0) break;
            
            for(int i=ind;i<str.size();i++)
            {
                if(str[i]=='0') str[i]='1';
                else str[i]='0';
            }
        }
        op++;
        
        //cout<<str<<endl;
    }

    cout<<op<<endl;
}
#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

vector<int> v;

void rec(string str,int ind)
{
    if(ind==str.length()) return;
    //cout<<str<<" "<<ind<<endl;
    
    if(str[ind]=='?')
    {
        for(int i=0;i<10;i++)
        {
            string s=str;
            char ch=i-0+'0';
            s[ind]=ch;
            if(ind!=s.length()-1)rec(s,ind+1);
            else v.push_back(stoi(s));
        }
    }
    else rec(str,ind+1);
    if(ind==str.length()-1) v.push_back(stoi(str));
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
        string s;
        cin>>s;
        bool flag=true;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='?') flag=false;
        }

        //cout<<s<<endl;

        if(flag) cout<<s<<endl;
        else 
        {
            if(s.length()==1)
            {
                cout<<7<<endl;
                continue;
            }
            v.clear();
            rec(s,0);
            int one=0,num=INT_MIN;
            
            //sort(v.begin(),v.end());

            //for(auto x : v) cout<<x<<" ";
            //cout<<endl;

            for(auto x : v)
            {
                int set_bit=0;
                for(int i=0;i<=32;i++)
                {
                    if((x>>i)&1) set_bit++;
                }
                if(set_bit>=one)
                {
                    one=set_bit;
                    num=x;
                }
            }

            cout<<num<<endl;
        }
    }
}
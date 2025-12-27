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
        string s1,s2;
        cin>>s1>>s2;
        int a=s1.length(),b=s2.length(),i=0,j=0;

        while(i<a && j<b)
        {
            if(s1[i]==s2[j]) 
            {
                j++;
                //continue;
            }
            else if(s1[i]=='?')
            {
                s1[i]=s2[j];
                j++;
            }

            i++;
            //j++;
        }

        if(a==1 && s1[0]!='?' && s1!=s2) cout<<"NO\n";
        else if(j==b) 
        {
            cout<<"YES\n";
            for(auto ch : s1)
            {
                if(ch=='?') cout<<'a';
                else cout<<ch;
            }
            cout<<endl;
        }
        else cout<<"NO\n";
    }
}
#include<bits/stdc++.h>
#include "D:/debug.h"
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}
int n;
string s;
int t;

void find()
{
    int ans=INT_MAX;
    for(int i=0;i<n-1;i++)
    {
        int num=(s[i]-'0')*10+(s[i+1]-'0'),sum=0;
        if(num==0) 
        {
            cout<<0<<endl;
            //cout<<"x"<<endl;
            return;
        }

        for(int j=0;j<i;j++)
        {
            int p=s[j]-'0';
            if(p==0)
            {
                cout<<0<<endl;
                return;
            }
            else if(p>=2) sum+=p;
            //
        }
        for(int j=i+2;j<n;j++)
        {
            int p=s[j]-'0';
            if(p==0)
            {
                cout<<0<<endl;
                //cout<<"y"<<endl;
                return;
            }
            else if(p>=2) sum+=p;
        }
        
        //if(sum==0) ans=min(num,ans);
        int last;
        if(num==1) last=max(sum,num);
        else
        {
            last=sum+num;
        }
        ans=min(last,ans);
        //cout<<sum<<" "<<num<<" "<<ans<<endl;
    }

    //cout<<t<<"arafat"<<endl;
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    t=1;
    cin>>t;

    while(t--)
    {
        cin>>n;
        cin>>s;
        if(n<=2) 
        {
            cout<<(s[0]-'0')*10+s[1]-'0'<<endl;
            continue;
        }
        find();
    }
}
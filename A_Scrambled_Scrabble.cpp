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
    int l=str.length(),v=0,c=0,y=0,n=0,g=0,ans=0;

    for(int i=0;i<l;i++)
    {
        if(str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U') v++;
        else if(str[i]=='N') n++;
        else if(str[i]=='G') g++;
        else c++;
    }

    int ng=n+g;

    cout<<ng<<" "<<c<<" "<<" "<<v<<endl;

    while(ng>1 && v)
    {
        ng-=2;
        v--;
        ans+=5;
    }
    while(ng>1 && y)
    {
        ng-=2;
        y--;
        ans+=5;
    }

    if(ng==1 && c>=1 && v)
    {
        ng=0;
        c--;
        ans+=4;
    }
    if(ng==1 && c>=1 && y)
    {
        ng=0;
        c--;
        y--;
        ans+=4;
    }  

    c+=2*ng;

    while(c>1 && v)
    {
        c-=2;
        v--;
        ans+=3;
    }
    while(c>1 && y)
    {
        c-=2;
        y--;
        ans+=3;
    }

    cout<<ans<<'\n';
}
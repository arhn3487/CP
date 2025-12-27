#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,a,b,c,mx=0;
    cin>>n>>a>>b>>c;
    
    for(int x=0;x<=4000;x++)
    {
        for(int y=0;y<=4000;y++)
        {
            int zc=n-(a*x+b*y);
            if(zc<0) break;
            else
            {
                
                double d = zc*1.0/c;
                if(d==(int)d)
                {
                    //cout<<x<<" "<<y<<" "<<d<<" "<<zc<<endl;
                    int e=x+y+d;
                    if(mx<e) mx=e;
                }
            }
        }
    }
    cout<<mx<<endl;
}
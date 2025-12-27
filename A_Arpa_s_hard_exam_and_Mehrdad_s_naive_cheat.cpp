#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin>>n;
    int a=1,b=0,c=0,d=0;
    if(n==0) {cout<<1<<endl;return 0 ;}

    for(ll i=1;i<n;i++)
    {
        if(a){b=1,a=0;}
        else if(b){c=1;b=0;}
        else if(c){d=1;c=0;}
        else{d=0;a=1;}
    }
    if(a) cout<<8<<endl;
    else if(b) cout<<4<<endl;
    else if(c) cout<<2<<endl;
    else cout<<6<<endl;
}
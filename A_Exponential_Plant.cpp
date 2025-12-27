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
    ll i=0,h=0;

    while(h<=n)
    {
        //if(i==0)h=0;
        h+=1<<i;
        //cout<<h<<"k"<<endl;
        i++;
    } 
    cout<<i<<endl;
}
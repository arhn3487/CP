#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        ll l,r,k;
        cin>>l>>r>>k;

        ll odd = ((r+1)/2-l/2);
        if(r==1) cout<<"NO"<<endl;
        else if(l==r) cout<<"YES"<<endl;
        else if(odd<=k) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }
}
//3 4 5
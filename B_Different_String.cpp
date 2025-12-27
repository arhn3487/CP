#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        string s,p,a;
        cin>>s;
        a=s;
        next_permutation(s.begin(),s.end());
        p=s;
        
        if(a==p) cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            cout<<p<<endl;
        }
    }
}
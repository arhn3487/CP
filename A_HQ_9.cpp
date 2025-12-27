#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    int f=0;
    cin>>s;
    int l=s.length();

    for(int i=0;i<l;i++)
    {
        if(s[i]=='H' || s[i]=='Q' || s[i]=='9' ) f=1;
    }

    if(f) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
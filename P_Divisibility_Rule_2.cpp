#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;

bool is_palindrome(ll n)
{
    string s = to_string(n);
    ll l=s.length();
    if(l%2) return false;
    for(ll i=0,j=l-1;i<l/2;i++,j--)
    {
        if(s[i]!=s[j]) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin>>n;

    for(ll i=2;i<=n;i++)
    {
        if(n%i==0)
        {
            if(is_palindrome(i)) 
            {
                cout<<i<<endl;
                return 0;
            }
        }
    }
}
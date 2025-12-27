#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
ll res=0;

ll recursion(ll q)
{
    if(q==1) return res;
    if(q%2==0)
    {
        q/=2;
        res++;
        recursion(q);
    }
    else if(q%3==0)
    {
        q=((2*q)/3);
        res++;
        recursion(q);
    }
    else if(q%5==0)
    {
        q=((4*q)/5);
        res++;
        recursion(q);
    }
    else 
    {
        res=-1;
        return res;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        res=0;
        ll q;
        cin>>q;
        ll res=recursion(q);

        cout<<res<<endl;
    }
}
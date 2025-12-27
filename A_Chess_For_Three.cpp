#include<bits/stdc++.h>
#include "D:/debug.h"
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    t=1;
    cin>>t;

    while(t--)
    {
        priority_queue<int> pq;
        int a,cnt=0;
        cin>>a;
        if(a>0)pq.push(a);
        cin>>a;
        if(a>0)pq.push(a);
        cin>>a;
        if(a>0)pq.push(a);

        while(pq.size()>1)
        {
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            //cout<<a<<" "<<b<<endl;

            a--;
            b--;
            cnt++;

            if(a>0)pq.push(a);
            if(b>0)pq.push(b);

            //cout<<a<<" "<<b<<endl;
        }

        if(pq.empty()) cout<<cnt<<endl;
        else if(pq.top()%2) cout<<-1<<endl;
        else cout<<cnt<<endl;
    }
}
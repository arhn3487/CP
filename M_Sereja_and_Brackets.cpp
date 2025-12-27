#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

vector<array<int,3>> seg;
string str;

void build(int start,int end,int node)
{
    if(start==end)
    {
        seg[node]={str[start]=='(' ? 1 : 0,0,str[start]==')' ? 1 : 0};
        return;
    }
    int mid=(start+end)/2;
    build(start,mid,2*node);
    build(mid+1,end,2*node+1);

    int open = seg[2*node][0];
    int closed=seg[2*node+1][2];
    int matched=min(open,closed);

    seg[node]={
        seg[2*node][0]+seg[2*node+1][0]-matched,
        seg[2*node][1]+seg[2*node+1][1]+matched,
        seg[2*node][2]+seg[2*node+1][2]-matched
    };
}

array<int,3> query(int left,int right,int node,int l,int r)
{
    if(l>right || r<left) return {0,0,0};
    if(left>=l && r>=right) return seg[node]; //left l r right

    int mid=(left+right)/2;
    array<int,3>x =query(left,mid,2*node,l,r);
    array<int,3>y =query(mid+1,right,2*node+1,l,r);

    int open_left = x[0],closed_right=y[2],matched=min(open_left,closed_right);

    return {
        x[0]+y[0]-matched,
        x[1]+y[1]+matched,
        x[2]+y[2]-matched
    };
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>str;
    int n=str.length();
    str='0'+str;

    seg.resize(4*n);

    build(1,n,1);
    //for(auto x : seg) cout<<x[1]<<" ";

    int q;
    cin>>q;

    while(q--)
    {
        int l,r;
        cin>>l>>r;

        cout<<2*query(1,n,1,l,r)[1]<<endl;
    }
}
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node{
    ll cnt0=0,cnt1=0,inv=0;
    bool lazy=0;
};

const int NMAX=200005;
Node seg[4*NMAX];
string s;
int n,q;

void merge(Node &p,const Node &L,const Node &R){
    p.cnt0=L.cnt0+R.cnt0;
    p.cnt1=L.cnt1+R.cnt1;
    p.inv=L.inv+R.inv+L.cnt1*R.cnt0;
}

void apply_toggle(Node &x){
    swap(x.cnt0,x.cnt1);
    x.inv=x.cnt0*x.cnt1 - x.inv;
    x.lazy^=1;
}

void push(int node,int l,int r){
    if(!seg[node].lazy)return;
    int mid=(l+r)/2;
    apply_toggle(seg[node*2]);
    apply_toggle(seg[node*2+1]);
    seg[node].lazy=0;
}

void build(int node,int l,int r){
    if(l==r){
        if(s[l-1]=='0') seg[node].cnt0=1;
        else seg[node].cnt1=1;
        seg[node].inv=0;
        return;
    }
    int mid=(l+r)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    merge(seg[node],seg[node*2],seg[node*2+1]);
}

void update(int node,int l,int r,int ql,int qr){
    if(qr<l||ql>r)return;
    if(ql<=l&&r<=qr){
        apply_toggle(seg[node]);
        return;
    }
    push(node,l,r);
    int mid=(l+r)/2;
    update(node*2,l,mid,ql,qr);
    update(node*2+1,mid+1,r,ql,qr);
    merge(seg[node],seg[node*2],seg[node*2+1]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;
    cin>>s;
    build(1,1,n);
    cin>>q;
    while(q--){
        int l,r;cin>>l>>r;
        update(1,1,n,l,r);
        cout<<seg[1].inv<<"\n";
    }
}

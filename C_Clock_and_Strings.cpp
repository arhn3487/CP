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
        int a,b,c,d,w,x,y,z;
        cin>>a>>b>>c>>d;
        //wxzy
        w=min(a,b);
        x=max(a,b);
        y=min(c,d);
        z=max(c,d);

        if(y<w && w<x && x<z && z>y) cout<<"NO"<<endl;
        else if(w<y && y<z &&z<x && x>w) cout<<"NO"<<endl;
        else if(w<x && x<y && y<z && z>w) cout<<"NO"<<endl;
        else if(y<z && z<w && w<x && x>y) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}
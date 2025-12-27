#include<bits/stdc++.h>
using namespace std;


#define ll long long
const ll N =1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll f1,f2,n;
    cin>>f1>>f2>>n;
        
    if(n%6==1) cout<<(f1%N+N)%N<<endl;
    else if(n%6==2) cout<<(f2%N+N)%N<<endl;
    else if(n%6==3) cout<<((f2-f1)%N+N)%N<<endl;
    else if(n%6==4) cout<<((-1*f1)%N+N)%N<<endl;
    else if(n%6==5) cout<<((-1*f2)%N+N)%N<<endl;
    else cout<<((f1-f2)%N+N)%N<<endl;
}
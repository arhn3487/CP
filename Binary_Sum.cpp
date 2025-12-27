#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
    int n,k;
    cin>>n>>k;
    
    //int l=(n+1)/2;
    
        if(2*k+1==n || 2*k-1==n || 2*k==n) cout<<"YES\n";
        else cout<<"NO\n";
	}
}

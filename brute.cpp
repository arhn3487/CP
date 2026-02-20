#include <bits/stdc++.h>
using namespace std;
int a[300000];
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int T,n,i,ans;
	for(cin>>T;T>0;T--)
	{
		cin>>n;
		for(i=0;i<n;i++)cin>>a[i];
		ans=0;
		for(i=1;i<n;i++)
		{
			if(a[i]==a[i-1]||a[i]+a[i-1]==7)
			{
				i++;
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
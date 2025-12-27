#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int M=1e9+7;
const int N=100001;

int arr[N];
int dp[102][N]; // dp[ind][rem]

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>arr[i];

    // Base case
    dp[n][0]=1;
    for(int rem=1; rem<=k; rem++) dp[n][rem]=0;

    // Bottom-up filling
    for(int ind=n-1; ind>=0; ind--) {
        for(int rem=0; rem<=k; rem++) {
            ll ans=0;
            for(int i=0; i<=arr[ind] && i<=rem; i++) {
                ans += dp[ind+1][rem-i];
                if(ans>=M) ans-=M;
            }
            dp[ind][rem]=ans;
        }
    }

    cout << dp[0][k] << "\n";
}

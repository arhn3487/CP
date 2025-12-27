#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    string S,T;
    cin>>n>>m>>S>>T;

    vector<vector<ll>> dp1(n+1, vector<ll>(m+1,0));
    vector<vector<ll>> dp2(n+1, vector<ll>(m+1,0));

    for(int i=0;i<=n;i++) dp1[i][0]=dp2[i][0]=1; // empty T

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp1[i][j]=dp1[i-1][j];
            if(S[i-1]==T[j-1])
                dp1[i][j]=(dp1[i][j]+dp1[i-1][j-1])%MOD;

            dp2[i][j]=dp2[i-1][j];
            if(S[i-1]==T[j-1]){
                dp2[i][j]=(dp2[i][j]+dp2[i-1][j-1])%MOD;
            } else {
                dp2[i][j]=(dp2[i][j]+dp1[i-1][j-1])%MOD; // modify S[i-1] to T[j-1]
            }
            // if we modify S[i-1] to any *other* letter (not T[j-1])
            dp2[i][j]=(dp2[i][j]+25LL*dp1[i-1][j-1])%MOD;
        }
    }

    cout<<(dp1[n][m]+dp2[n][m])%MOD<<"\n";
}

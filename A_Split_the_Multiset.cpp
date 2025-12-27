#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        int n, k;
        cin >> n >> k;

        if (n == 1) {
            cout << 0 << endl;
        } else {
            cout << (n - 2) / (k - 1) + 1 << endl;
        }
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void solve() 
{
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
 
	if(a > c && b > d && a > d && b > c) cout << "4" << endl;
	else if(((a > c && b >= d) || (a >= c && b > d)) && ((a > d && b >= c) || (a >= d && b > c))) cout << "4" << endl;
	else if((a > c && b >= d) || (a >= c && b > d) || (a > d && b >= c) || (a >= d && b > c)) cout << "2" << endl;
	else cout << "0" << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}

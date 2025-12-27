#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define INF(t) numeric_limits<t>::max()

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		vector<int> a(n);
		for(auto &x : a) cin >> x;
		sort(a.begin(), a.end());

		ll ans = 0;
		for(int i = 0; i < n-2; i++) {
			for(int j = i+1; j < n-1; j++) {
				auto it = lower_bound(a.begin()+j+1, a.end(), a[i]+a[j]);
				int end = it - (a.begin()+j+1);
				if(end == 0) continue;
				// now search in range [j+1, j+end] for third val
				// such that ai+aj+ak > a(n-1)
				// ak > a(n-1) - ai - aj
				it = upper_bound(a.begin()+j+1, a.begin()+j+end+1, a[n-1]-a[i]-a[j]);
				ans += (a.begin()+j+end+1) - it;
			}
		}

		cout << ans << "\n";
	}

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

const double pi = acos(-1.0);
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	// cout << setprecision(0) << fixed;
	double a, p; cin >> a >> p;
	cout << a / pi << '\n' << 2 * p*a / pi << '\n';
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; vector<int> v(n); for (int &i : v) cin >> i;
		v.push_back(1440);
		int cnt = v[0] / 120;
		for (int i = 0; i < n; i++) {
			cnt += (v[i + 1] - v[i]) / 120;
		}

		cout << (cnt > 1 ? "YES" : "NO") << endl;
	}
	return 0;
}

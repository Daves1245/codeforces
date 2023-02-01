#include <bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		map<int, int> m;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			m[x]++;
		}

		int ans = 0;
		for (auto [a, cnt] : m) {
			if (a != k - a) {
				int x = min(m[a], m[k - a]);
				ans += x;
				m[a] -= x;
				m[k - a] -= x;
			} else if (m[a] >= 2) {
				int x = m[a] / 2;
				ans += x;
				m[a] -= x;
			}
		}

		cout << ans << endl;
	}
	return 0;
}

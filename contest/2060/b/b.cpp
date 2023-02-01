#include <bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vector<pair<int, vector<int>>> cows(n);

		int idx = 0;
		for (auto &[i, v] : cows) {
			i = idx++;
			v = vector<int>(m);
			for (int &j : v) cin >> j;
			sort(cows[i].second.begin(), cows[i].second.end());
		}

		sort(cows.begin(), cows.end(),
				[](auto &a, auto &b){
				return a.second[0] < b.second[0];
				}
		    );

		int f = 1;
		for (int i = 0; i < n; i++) {
			f &= cows[i].second[0] == i;
		}

		if (!f) {
			cout << -1 << endl;
			continue;
		}

		for (int i = 0; i < n && f; i++){
			auto &deck = cows[i].second;
			for (int j = 1; j < m; j++){
				if (deck[j] != deck[j - 1] + n) {
					f = 0;
					break;
				}
			}
		}

		if (!f) {
			cout << -1 << endl;
			continue;
		}

		for (auto &[i, v] : cows) {
			cout << i + 1 << " \n"[i == n - 1];
		}
	}

	return 0;
}


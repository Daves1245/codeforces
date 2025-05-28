#include <bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> v(2 * n); for (int &i : v) cin >> i;
		sort(v.begin(), v.end());
		vector<int> ans;
		int sum = 0;
		for (int i = 0; i < n - 1; i++) {
			sum += abs(v[i] - v[i + 1]);
		}
		for (int i = n; i < 2 * n - 1; i++) {
			sum += abs(v[i] - v[i + 1]);
		}
		cout << sum << endl;
	}
	return 0;
}

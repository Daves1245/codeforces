#include <bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	while (t--) {
		int l, r; cin >> l >> r;
		cout << r - l + (l == r && l == 1) << endl;
	}
	return 0;
}

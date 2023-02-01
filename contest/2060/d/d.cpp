#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n);
	for (int &i : v) cin >> i;

	int cur = v[0];
        bool f = 1;
        for (int i = 1; i < n; i++) {
            if (cur > v[i]) {
                f = 0;
                break;
            }
            v[i] -=  cur;
            cur = v[i];
        }
        cout << (f ? "YES" : "NO") << endl;
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, m, q; cin >> n >> m >> q;
        vector<int> a(n), b(m); for (int &i : a) cin >> i; for (int &i : b) cin >> i;
        vector<int> seen(n + 1, 0);
        int f = 1;
        int cnt = 0;
        for (int i = 0; i < m && f; i++) {
            if (!seen[b[i]]) {
                if (cnt >= n || b[i] != a[cnt]) {
                    f = 0;
                    break;
                }
                seen[b[i]] = true;
                cnt++;
            }
        }
        cout << (f ? "ya" : "tidak") << endl;
    }
    return 0;
}

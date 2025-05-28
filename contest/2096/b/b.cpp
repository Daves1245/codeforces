#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<ll> l(n), r(n), v(n), w(n);
        for (ll &i : l) cin >> i;
        for (ll &i : r) cin >> i;
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            v[i] = max(l[i], r[i]);
            w[i] = min(l[i], r[i]);
            sum += v[i];
        }
        sort(w.begin(), w.end(), greater<ll>());
        for (int i = 0; i < k - 1 && i < n; ++i) sum += w[i];
        cout << sum + 1 << '\n';
    }

    return 0;
}

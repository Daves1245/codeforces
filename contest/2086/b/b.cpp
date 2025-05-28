#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; ll x; cin >> n >> k >> x;
        vector<int> v(n); for (int &i : v) cin >> i;
        vector<ll> ps(n + 1, 0);
        for (int i = 0; i < n; i++) ps[i + 1] = ps[i] + v[i];
        ll sum = ps[n - 1] + v[n - 1];
        if (k * sum < x) {
            cout << 0 << endl;
            continue;
        }
        ll ans = 0;
        auto contribution = [&](ll val) {
            int l = 0, r = n, m;
            while (l < r) {
                m = (l + r) / 2;
                if (ps[m] <= val) l = m + 1;
                else r = m;
            }
            return l;
        };
        for (ll i = 0; i < k; i++) {
            ll start = (k * sum - x) - i * sum;
            if (start < 0) break;
            ans += contribution(start);
        }

        cout << ans << endl;
    }
    return 0;
}

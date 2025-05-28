#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<ll> a(n); for (ll &i : a) cin >> i;
        vector<pair<ll, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({a[i], i});
        }

        sort(v.begin(), v.end(), [](const auto& p1, const auto& p2) {
            return p1.first > p2.first;
        });

        ll c = 0;
        for (int i = 0; i < k + 1; i++) {
            c += v[i].first;
        }

        ll s = 0;
        bool l = false, r = false;
        for (int i = 0; i < k; i++) {
            s += v[i].first;
            if (v[i].second == 0) l = true;
            if (v[i].second == n - 1) r = true;
        }

        ll a_res = 0;
        if (l && r) {
            a_res = c;
        } else if (l) {
            a_res = s + a[n - 1];
        } else if (r) {
            a_res = s + a[0];
        } else {
            a_res = s + max(a[0], a[n - 1]);
        }

        ll b_res = -1;
        if (n - 2 >= k) {
            vector<ll> in;
            for (int i = 1; i < n - 1; i++) {
                in.push_back(a[i]);
            }

            sort(in.rbegin(), in.rend());

            ll s2 = 0;
            for (int i = 0; i < k; i++) {
                s2 += in[i];
            }

            b_res = s2 + max(a[0], a[n - 1]);
        }

        cout << max({a_res, b_res, c}) << endl;
    }

    return 0;
}

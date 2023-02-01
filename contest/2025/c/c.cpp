#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        map<int, int> cnt;
        vector<int> v(n); for (int &i : v) cin >> i, cnt[i]++;
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());

        n = v.size();
        vector<int> g(n);
        int group = 0;
        for (int i = 0; i < n; i++) {
            // only uniques here. if we're not one more, we're a different group
            // we can only pick the max val within one group
            if (i && (v[i] != v[i - 1] + 1)) {
                group++;
            }
            g[i] = group;
        }

        /*
        cout << endl;
        for (int i : v) cout << i << " "; cout << endl;
        for (int i : v) cout << cnt[i] << " "; cout << endl;
        cout << endl;
        */
        int sum = 0;
        int ma = 0;
        for (int i = 0; i < n; i++) {
            if (i && (g[i] != g[i - 1])) sum = 0;
            sum += cnt[v[i]];
            if ((i >= k) && (g[i] == g[i - k])) sum -= cnt[v[i - k]];
            ma = max(ma, sum);
        }

        cout << ma << endl;
    }
    return 0;
}


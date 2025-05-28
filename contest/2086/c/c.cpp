#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> p(n), d(n);
        for (int &i : p) cin >> i;
        for (int &i : d) cin >> i;
        vector<int> cc(n, -1), size;
        int id = 0;
        for (int i = 0; i < n; i++) {
            if (cc[i] != -1) continue;
            int cur = i, len = 0;
            while (cc[cur] == -1) {
                cc[cur] = id;
                len++;
                cur = p[cur] - 1;
            }
            size.push_back(len);
            id++;
        }
        vector<int> seen(id, 0);
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            int cur = d[i] - 1, cycle = cc[cur];
            if (!seen[cycle]) {
                seen[cycle] = 1;
                ans += size[cycle];
            }
            cout << ans << " ";
        }
        cout << endl;
    }

    return 0;
}

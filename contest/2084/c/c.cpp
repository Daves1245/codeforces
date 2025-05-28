#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n), b(n), inv(n + 1);
        for (int &i : a) cin >> i;
        for (int &i : b) cin >> i;

        for (int i = 1; i <= n; i++) {
          inv[b[i - 1]] = i;
        }

        vector<int> c(n + 1);
        for (int i = 1; i <= n; i++) c[i] = inv[a[i-1]];

        int valid = 1;
        int fixed = 0;
        for (int i = 1; i <= n; i++){
            if (c[c[i]] != i) { valid = 0; break; }
            if (c[i] == i) fixed++;
        }
        if (!valid || (n % 2 == 0 && fixed > 0) || (n % 2 == 1 && fixed != 1)) {
            cout << -1 << "\n";
            continue;
        }

        vector<int> used(n + 1, 0);
        vector<ii> pairs;
        int idx = -1;
        for (int i = 1; i <= n; i++){
            if (used[i]) continue;
            if (c[i] == i) { idx = i; used[i] = 1; }
            else {
                int j = c[i];
                if (!used[j]) {
                    pairs.push_back({min(i,j), max(i,j)});
                    used[i] = used[j] = 1;
                }
            }
        }

        vector<int> target(n, 0);
        int l = 0, r = n-1;
        for (auto pr : pairs) {
            target[l++] = pr.first;
            target[r--] = pr.second;
        }
        if (n & 1) target[l] = idx;

        vector<int> pos(n + 1), cur(n + 1);
        for (int i = 1; i <= n; i++) cur[i] = pos[i] = i;
        vector<ii> buildback;
        for (int i = 1; i <= n; i++) {
            if (cur[i] == target[i-1]) continue;
            int dest = pos[target[i-1]];
            swap(cur[i], cur[dest]);
            pos[cur[i]] = i;
            pos[cur[dest]] = dest;
            buildback.push_back({i, dest});
        }

        if (buildback.size() > n) {
            cout << -1 << endl;
        } else {
            cout << buildback.size() << endl;
            for(auto &p : buildback)
                cout << p.first << " " << p.second << endl;
        }
    }
    return 0;
}

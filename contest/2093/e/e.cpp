#include <iostream>
#include <vector>
#include <set>
using namespace std;
int mex(vector<int> &v) {
    set<int> s(v.begin(), v.end());
    int m = 0;
    while (s.count(m++));
    return m;
}
int main() {
  int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> v(n); for (int &i : v) cin >> i;
        int l = 0, r = mex(v), ans = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            auto check = [&](int m) -> int {
              int cnt = 0;
              vector<int> seen(m, 0);
              int needed = m;
              for (int num : v) {
                if (num < m && !seen[num]) {
                  seen[num] = 1;
                  needed--;
                }
                if (!needed) {
                  cnt++;
                  seen.assign(m, 0);
                  needed = m;
                }
                if (cnt >= k)
                  return 1;
              }
              return (cnt >= k);
            };
            if (check(m)) {
              ans = m;
              l = m + 1;
            } else {
              r = m - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}


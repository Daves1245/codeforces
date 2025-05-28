#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    vector<int> v(n * m);
    for (int &i : v) cin >> i;
    sort(v.begin(), v.end());
    if (n > m) swap(n, m);
    if (n == 1) {
      cout << (m - 1) * (v[n * m - 1] - v[0]) << '\n';
    } else {
      long long ans1 = (n * m - 1) * (v[n * m - 1]) - v[0] * (n * (m - 1)) - v[1] * (n - 1);
      long long ans2 = v[n * m - 1] * (n * (m - 1)) + v[n * m - 2] * (n - 1) - v[0] * (n * m - 1);
      cout << max(ans1, ans2) << '\n';
    }
  }
  return 0;
}

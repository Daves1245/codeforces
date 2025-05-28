#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll INF = (ll)1e15;
ll dp(vector<ll>& cost, vector<int>& mask) {
  int n = cost.size();
  vector<ll> prev = {0, cost[0]};
  vector<ll> cur(2, INF);
  for (int i = 0; i < n - 1; i++) {
    cur[0] = cur[1] = INF;
    int cur_mask = mask[i];
    for (int j = 0; j < 2; j++) {
      if (prev[j] >= INF) continue;
      for(int k = 0; k < 2; k++) {
        int diff = j - k;
        int bit = (diff == -1 ? 0 : (!diff ? 1 : 2));
        if (cur_mask & (1 << bit)) continue;
        ll c = prev[j] + (k ? cost[i + 1] : 0);
        cur[k] = min(cur[k], c);
      }
    }
    prev = cur;
  }
  return min(cur[0], cur[1]);
}
int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<vector<ll>> h(n, vector<ll>(n));
    for (auto &i : h) for (ll &j : i) cin >> j;
    vector<ll> r(n), c(n); for (ll &i : r) cin >> i; for (ll &i : c) cin >> i;
    vector<int> row_mask(n - 1, 0);
    for (int i = 0; i + 1 < n; i++) {
      int mask = 0;
      for (int j = 0; j < n; j++) {
        ll d = h[i + 1][j] - h[i][j];
        if (d == -1) mask |= 1 << 0;
        else if (d == 0) mask |= 1 << 1;
        else if (d == 1) mask |= 1 << 2;
      }
      row_mask[i] = mask;
    }
    vector<int> col_mask(n - 1, 0);
    for (int j = 0; j + 1 < n; j++) {
      int mask = 0;
      for (int i = 0; i < n; i++) {
        ll d = h[i][j + 1] - h[i][j];
        if (d == -1) mask |= 1 << 0;
        else if (d == 0) mask |= 1 << 1;
        else if (d == 1) mask |= 1 << 2;
      }
      col_mask[j] = mask;
    }
    ll row = dp(r, row_mask), col = dp(c, col_mask);
    cout << (row >= INF || col >= INF ? -1 : row + col) << endl;
  }
  return 0;
}

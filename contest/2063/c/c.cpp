#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<vi> adj(n);
    vector<pair<int, int>> deg(n);
    for (int i = 0; i < n; i++) {
      deg[i] = {0, i};
    }
    for (int i = 0; i < n - 1; i++) {
      int u, v; cin >> u >> v; u--, v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
      deg[u].first++;
      deg[v].first++;
    }

    int ans = 1;
    auto [d, i] = *max_element(deg.begin(), deg.end());
    ans += d - 1;
    deg[i] = {-1, INT_MIN};
    for (int u : adj[i]) {
      deg[u].first--;
    }
    auto [d2, j] = *max_element(deg.begin(), deg.end());
    ans += d2 - 1;
    cout << ans << endl;
  }
  return 0;
}

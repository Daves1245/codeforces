#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<vector<int>> g(n, vector<int>(n, 0));
    int cx = n / 2, cy = n / 2;
    if (!(n & 1)) cx--, cy--;
    int dx[] = { 0, 1, 0, -1 };
    int dy[] = { 1, 0, -1, 0 };
    int x = cx, y = cy, val = 0, steps = 1;
    g[x][y] = val++;
    while (val < n * n) {
      for (int d = 0; d < 4; ++d) {
        for (int i = 0; i < steps; i++) {
          x += dx[d];
          y += dy[d];
          if (x >= 0 && x < n && y >= 0 && y < n) {
            g[x][y] = val++;
          }
        }
        if (d == 1 || d == 3) {
          steps++;
        }
      }
    }
    for (auto &row : g) {
      for (int v : row) cout << v << ' '; cout << endl;
    }
  }
  return 0;
}

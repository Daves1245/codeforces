#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
int main() {
  string ret = "CCC";
  vector<string> g(3); for (auto &s : g) cin >> s;
  for (int r1 = 0; r1 < 3; r1++) {
    for (int c1 = 0; c1 < 3; c1++) {
      for (int r2 = 0; r2 < 3; r2++) {
        for (int c2 = 0; c2 < 3; c2++) {
          if (r2 == r1 && c2 == c1) continue;
          for (int r3 = 0; r3 < 3; r3++) {
            for (int c3 = 0; c3 < 3; c3++) {
              if ((r3 == r1 && c3 == c1) || (r3 == r2 && c3 == c2)) continue;
              if (abs(r1 - r2) > 1 || abs(c1 - c2) > 1) continue;
              if (abs(r2 - r3) > 1 || abs(c2 - c3) > 1) continue;

              ret = min(ret, string({g[r1][c1], g[r2][c2], g[r3][c3]}));
            }
          }
        }
      }
    }
  }
  cout << ret << endl;
  return 0;
}

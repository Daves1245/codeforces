#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n; vector<int> v(n); for (int &i : v) cin >> i;
  auto dp = [&](auto &&self, int i, int j) -> int {
    if (i == n) return !(j % 360);
    else return self(self, i + 1, j + v[i]) || self(self, i + 1, j - v[i]);
    return 0;
  };
  cout << (dp(dp, 0, 0) ? "YES" : "NO") << endl;
  return 0;
}

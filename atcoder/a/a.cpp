#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  vector<int> v(n); for (int &i : v) cin >> i;
  vector<int> dp(n, INT_MAX);
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    if (i + 1 < n) {
      dp[i + 1] = min(dp[i + 1], dp[i] + abs(v[i + 1] - v[i]));
    }
    if (i + 2 < n) {
      dp[i + 2] = min(dp[i + 2], dp[i] + abs(v[i + 2] - v[i]));
    }
  }

  cout << dp[n - 1] << endl;
  return 0;
}

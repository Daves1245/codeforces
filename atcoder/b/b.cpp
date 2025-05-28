#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k; cin >> n >> k;
  vector<int> v(n); for (int &i : v) cin >> i;
  vector<int> dp(n, INT_MAX);
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= k; j++) {
      if (i + j < n) {
        dp[i + j] = min(dp[i + j], dp[i] + abs(v[i] - v[i + j]));
      }
    }
  }
  cout << dp[n - 1] << endl;
  return 0;
}

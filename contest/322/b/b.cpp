#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c; cin >> a >> b >> c;
  int ans = 0;
  for (int i = 0; i < 3; i++) {
    int cnt = min({i, a, b, c});
    ans = max(ans, cnt + (a - cnt) / 3 + (b - cnt) / 3 + (c - cnt) / 3);
  }

  cout << ans << endl;
  return 0;
}

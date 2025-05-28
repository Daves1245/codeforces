#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      ll x, y;
      cin >> x >> y;
      if (((x + y) & 1) == 0) {
        sum++;
      } else {
        sum--;
      }
    }
    if (sum == 1) {
      cout << 0 << " " << 0 << endl;
    } else {
      cout << 0 << " " << 1 << endl;
    }
  }
  return 0;
}

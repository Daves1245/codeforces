#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    if (n & 1) {
      for (int i = 1; i <= n; i++) {
        if (2 * i <= n) {
          cout << 2 * i << " ";
        } else {
          cout << 2 * i - n << " ";
        }
      }
      cout << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}

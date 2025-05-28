#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    if (!(n & 1)) {
      cout << -1 << endl;
    } else {
      cout << n << " 2 1 ";
      for (int i = 3; i < n; i++) {
        cout << i << " ";
      }
      cout << endl;
    }
  }
  return 0;
}

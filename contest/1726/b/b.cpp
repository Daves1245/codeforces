#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;

    if (n > m) {
      cout << "No" << endl;
      continue;
    }

    if (n & 1) {
      cout << "Yes" << endl;
      for (int i = 0; i < n - 1; i++) cout << "1 ";
      cout << m - (n - 1) << endl;
    } else {
      if ((m - (n - 2)) & 1) {
        cout << "No" << endl;
        continue;
      }
      cout << "Yes" << endl;
      for (int i = 0; i < n - 2; i++) cout << "1 ";
      int tmp = (m - (n - 2)) / 2;
      cout << tmp << " " << tmp << endl;
    }
  }
  return 0;
}

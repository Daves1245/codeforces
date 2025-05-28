#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int l = 1, r = n * n;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if ((i + j) & 1) {
          cout << r-- << " ";
        } else {
          cout << l++ << " ";
        }
      }
      cout << endl;
    }
  }
  return 0;
}

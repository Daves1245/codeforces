#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    for (int i = n; i >= n / 2; i--) {
      cout << i << " ";
    }
    for (int i = 1; i < n / 2; i += 2) {
      cout << i << " " << n / 2 - i << " ";
    }
    cout << endl;
  }
  return 0;
}

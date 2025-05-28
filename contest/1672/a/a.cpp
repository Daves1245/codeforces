#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> v(n); for (int &i : v) cin >> i;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += v[i] - 1;
    }
    cout << (sum & 1 ? "errorgorn" : "maomao90") << endl;
  }
  return 0;
}

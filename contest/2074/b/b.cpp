#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> v(n); for (int &i : v) cin >> i;
    cout << accumulate(v.begin(), v.end(), 0LL) - (n - 1) << endl;
  }
  return 0;
}

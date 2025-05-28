#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> v(n); for (int &i : v) cin >> i;
    sort(v.begin(), v.end());
    long sum = accumulate(v.begin(), v.end(), 0L);
    int cur = 1;
    int save = 0;
    for (int i = 0; i < n - 1; i++) {

    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n; vector<int> v(n); for (int &i : v) cin >> i;
    ll sum = 0;
    int ma = 0;
    int cnt = 0;
    for (int i : v) {
      sum += i;
      ma = max(ma, i);
      cnt += sum - ma == ma;
    }
    cout << cnt << endl;
  }
  return 0;
}

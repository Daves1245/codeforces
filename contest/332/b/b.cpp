#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int n, k; cin >> n >> k;
  vector<int> v(n); for (int &i : v) cin >> i;
  vector<ll> ps(n + 1, 0); for (int i = 0; i < n; i++) ps[i + 1] = ps[i] + v[i];
  vector<ll> maxpre(n + 1, 0);
  for (int i = k; i < n - k; i++) {
    maxpre[i] =
  }
  return 0;
}

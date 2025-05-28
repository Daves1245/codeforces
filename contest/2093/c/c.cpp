#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int isprime(ll n) {
  if (n < 2) return 0;
  if (n == 2) return 1;
  if (!(n & 1)) return 0;
  for (ll i = 3; i * i <= n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
int main() {
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    if (k == 1) {
      cout << (isprime(n) ? "YES" : "NO") << endl;
    } else if (n == 1) {
      string s = to_string(n);
      string res = "";
      for (int i = 0; i < k; i++) res += s;
      ll v = stoll(res);
      cout << (isprime(v) ? "YES" : "NO") << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll M = 1e9 + 7;

ll fact(ll n) {
  if (n == 0) return 1;
  return (n * fact(n - 1)) % M;
}

int main() {
  int t; cin >> t;
  while (t--) {
    ll n; cin >> n;

    ll f = fact(n);
    f = (f * n) % M;
    f = (f * (n - 1)) % M;
    cout << f << endl;
  }
  return 0;
}

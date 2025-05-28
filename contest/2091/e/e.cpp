#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> isprime(1e6, 1);
vector<ll> primes;
void init() {
  isprime[0] = isprime[1] = 0;
  for (int i = 2; i < isprime.size(); i++) {
    if (isprime[i]) {
      primes.push_back(i);
      for (int j = 2 * i; j < isprime.size(); j += i) {
        isprime[j] = 0;
      }
    }
  }
}
int main() {
  int t; cin >> t;
  init();
  while (t--) {
    int n; cin >> n;
    ll cnt = 0;
    for (ll p : primes) {
      if (p > n) break;
      cnt += n / p;
    }
    cout << cnt << endl;
  }
  return 0;
}

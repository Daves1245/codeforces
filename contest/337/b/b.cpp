#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d; cin >> a >> b >> c >> d;
  int p, q;
  if (a * d <= b * c) {
    p = c * b - a * d;
    q = c * b;
  } else if (a * d > b * c) {
    p = a * d - b * c;
    q = a * d;
  }
  int x = gcd(p, q);
  p /= x;
  q /= x;
  cout << p << "/" << q << endl;
  return 0;
}

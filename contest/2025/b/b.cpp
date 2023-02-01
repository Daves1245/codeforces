#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll M = 1e9 + 7;
ll mpow(ll b, int p) {
    if (!p) return 1;
    ll ret = mpow(b, p / 2);
    ret = (ret * ret) % M;
    if (p & 1) ret = (ret * b) % M;
    return ret;
}
int main() {
    int t; cin >> t;
    vector<int> n(t), k(t);
    for (int &i : n) cin >> i;
    for (int &i : k) cin >> i;
    for (int i : k) cout << mpow(2, i) << endl;
    return 0;
}

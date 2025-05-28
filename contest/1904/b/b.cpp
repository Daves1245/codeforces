#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n); for (int &i : v) cin >> i;
        vector<int> ps(n + 1, 0); for (int i = 0; i < n; i++) ps[i + 1] = ps[i] + v[i];
        sort(v.begin(), v.end());
        for (int i = n - 1; i >= 0; i--) {

        }
    }
    return 0;
}

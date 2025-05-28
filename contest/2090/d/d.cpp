#include <bits/stdc++.h>
using namespace std;
vector<int> isprime(1e5, 1);
void init() {
    isprime[1] = 0;
    for (int i = 2; i * i < isprime.size(); i++) {
        if (!isprime[i]) continue;
        for (int j = i * i; j < isprime.size(); j += i) {
            isprime[j] = 0;
        }
    }
}

int main() {
    init();
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v;
        int pi = 1;

        for (int i = 1; i <= 2 * n / 3; i++) {
            if (isprime[i]) pi = i;
        }
        int l = pi - 1, r = pi + 1;
        v.push_back(pi);

        while (l >= 1 && r <= n) {
            v.push_back(r++);
            v.push_back(l--);
        }

        for (int i = 1; i <= l; i++) v.push_back(i);
        for (int i = r; i <= n; i++) v.push_back(i);
        for (int i : v) cout << i << " "; cout << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        string a, b; cin >> a >> b;
        int i = 0;
        while (i < (int) min(a.size(), b.size())) {
            if (a[i] != b[i]) break;
            i++;
        }

        cout << a.size() + b.size() - i + (i > 0) << endl;
    }

    return 0;
}

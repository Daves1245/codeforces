#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        int n; cin >> n; vector<int> v(n); for (int &i : v) cin >> i;
        int f = false;
        for (int i = 0; i <= n; i++) {
            int liars = 0;
            for (int j = 0; j < n; j++) {
                if (v[j] > i) {
                    liars++;
                }
            }

            if (liars == i) {
                cout << i << endl;
                f = true;
                break;
            }
        }

        if (!f) {
            cout << -1 << endl;
        }
    }
    return 0;
}

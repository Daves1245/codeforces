#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    std::cin >> n;

    std::vector<int> perm(n);
    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
    }

    int cnt = 0;
    do {
        bool valid = true;

        for (int i = 0; i < n - 1 && valid; i++) {
            for (int j = 0; j < n - 1 && valid; j++) {
                if (i != j && perm[j] % perm[i] == 0 && perm[j + 1] % perm[i + 1] == 0) {
                    valid = false;
                }
            }
        }

        if (valid) {
          cnt++;
        }

    } while (std::next_permutation(perm.begin(), perm.end()));

    cout << cnt << endl;

    return 0;
}

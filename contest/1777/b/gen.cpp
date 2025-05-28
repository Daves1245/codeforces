#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

// Function to count inversions in a permutation
int countInversions(const std::vector<int>& perm) {
    int invCount = 0;
    for (int i = 0; i < perm.size(); i++) {
        for (int j = i + 1; j < perm.size(); j++) {
            if (perm[i] > perm[j]) {
                invCount++;
            }
        }
    }
    return invCount;
}

int main() {
    int n;
    std::cin >> n;
    
    // Create a vector with numbers 1 to n
    std::vector<int> perm(n);
    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
    }

    ll sum = 0;

    // Process each permutation
    do {
        sum += countInversions(perm);
    } while (std::next_permutation(perm.begin(), perm.end()));

    cout << sum << endl;

    return 0;
}

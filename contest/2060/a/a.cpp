#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<pair<int, vector<ll>>> cows(n);
	vector<ll> allCards(n * m);

	int idx = 0;
	for (auto &[i, v] : cows) {
		i = idx++;
		v = vector<ll>(m);
		for (int j = 0; j < m; j++) {
			cin >> cows[i].second[j];
			allCards.push_back(cows[i].second[j]);
		}
		sort(cows[i].second.begin(), cows[i].second.end());
	}

	sort(allCards.begin(), allCards.end());

	sort(cows.begin(), cows.end(),
			[](auto &a, auto &b){
			return a.second[0] < b.second[0];
			}
	    );

	vector<ll> firstCards(n);
	for (int i = 0; i < n; i++) {
		firstCards[i] = cows[i].second[0];
	}
	sort(firstCards.begin(), firstCards.end());
	bool ok = true;
	// (A) Check if firstCards == allCards[0..n-1]
	for (int i = 0; i < n; i++) {
		if (firstCards[i] != allCards[i]) {
			ok = false;
			break;
		}
	}
	// (B) Check each cow's deck for consecutive differences >= n
	if (ok) {
		for (int i = 0; i < n && ok; i++){
			const auto &deck = cows[i].second;
			for (int j = 1; j < m; j++){
				if (deck[j] < deck[j - 1] + n) {
					ok = false;
					break;
				}
			}
		}
	}

	if (!ok) {
		cout << -1 << "\n";
		continue;
	}

	for(int i = 0; i < n; i++){
		cout << cows[i].first + 1 << (i+1 < n ? ' ' : '\n');
	}
    }

    return 0;
}


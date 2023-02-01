#include <bits/stdc++.h>
using namespace std;

class ufds {
	private:
	vector<int> p, rank;
public:
	ufds(int n) {
		p.assign(n + 1, 0); for (int i = 0; i < n; i++) p[i] = i;
		rank.assign(n + 1, 0);
	}

	int find(int i) { return (p[i] == i) ? i : (p[i] = find(p[i])); }

	void join(int i, int j) {
		if (find(i) == find(j)) return;
		int x = find(i), y = find(j);
		if (rank[x] > rank[y]) swap(x, y);
		p[x] = y;
		if (rank[x] == rank[y]) rank[y]++;
	}
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	while (t--){
		int n, m1, m2; cin >> n >> m1 >> m2;

		vector<pair<int,int>> fg(m1);
		for (auto &[u, v] : fg) cin >> u >> v;

		vector<pair<int,int>> gg(m2);
		for (auto &[u, v] : gg) cin >> u >> v;

		ufds g(n);
		for(auto &e : gg){
			g.join(e.first, e.second);
		}
		map<int, int> cid;
		vector<int> gcomps(n + 1, -1);
		int cidx = 0;
		for (int u = 1; u <= n; u++) {
			int p = g.find(u);
			if (!cid.count(p)) {
				cid[p] = cidx++;
			}
			gcomps[u] = cid[p];
		}
		int k = cidx;

		ufds f(n);
		int stranglers = 0;
		for (auto [u, v] : fg) {
			if (gcomps[u] != gcomps[v]) {
				stranglers++;
			} else {
				f.join(u,v);
			}
		}

		vector<set<int>> parents(k);

		for(int v = 1; v <= n; v++){
			int gp = gcomps[v];
			int fp = f.find(v);
			parents[gp].insert(fp);
		}

		int missing = 0;
		for (int c = 0; c < k; c++) {
			int cur = parents[c].size();
			missing += cur - 1;
		}

		cout << stranglers + missing << endl;
	}

	return 0;
}


#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()

struct val {
	int l;
	int r;
	int l_val;
	int r_val;
	int dist;
};

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (auto& x : a) cin >> x, --x;
	vector<vector<bool>> able(n, vector<bool>(n));
	for (int i = 0; i < n; ++i) {
		vector<int> us(n);
		int mn = a[i], mx = a[i];
		for (int j = i; j < n; ++j) {
			if (us[a[j]]) break;
			us[a[j]] = 1;
			mn = min(mn, a[j]), mx = max(mx, a[j]);
			if (mx - mn == j - i) able[mn][mx] = 1;
		}
	}

	for (int ans = n; ans > 0; --ans) {
		for (int i = 0; i + 2 * ans <= n; ++i) {
			if (able[i][i + ans - 1] && able[i + ans][i + 2 * ans - 1]) {
				cout << ans << '\n';
				return;
			}
		}
	}
	cout << "0\n";

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}
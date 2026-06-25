#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
	int n;
	cin >> n;

	vector<int> arr(n);

	int min_var = 20;
	int max_var = -1;
	for (int i= 0; i < n; i++) {
		int x;
		cin >> x;
		min_var = std::min(min_var, x);
		max_var = std::max(max_var, x);
	}

	cout << max_var - min_var + 1 << endl;
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
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	ll m = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] >= m) {
			m = a[i];
		} else {
			m += a[i];
		}
	}

	cout << m << endl;
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
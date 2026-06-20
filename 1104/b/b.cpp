#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
	int n;
	cin >> n;

	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >>a[i];
	}

	set<int> s;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		s.insert(x);
	}

	bool possible = true;
	for (int i = 0; i < n; i++) {
		auto it = s.lower_bound(a[i]);
		if (it == s.end()) {
			possible = false;
			break;
		}

		b[i] = *it;
		s.erase(it);
	}

	if (!possible) {
		cout << "-1" << endl;
		return;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (b[i] > b[j]) {
				ans++;
			}
		}
	}

	std:: cout << ans << endl;

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
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
	int n;
	cin >> n;

	int k;
	cin >> k;

	string s;
	cin >> s;

	bool possible = true;
	for (int i = 0; i < k; i += 1) {
		int c = 0;
		for (int j = i; j < n; j += k) {
			if (s[j] == '1') {
				c++;
			}
		}

		if (c % 2 == 1) {
			possible = false;
			break;
		}
	}

	if (possible) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
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
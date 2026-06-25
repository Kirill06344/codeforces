#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
	int n;
	cin >> n;

	string s;
	cin >> s;


	ll ans = 0;
	int cnt [3] = {1, 0, 0};
	int x = 0;
	int y = 0;
	char prev = '2';
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			x++;
		} else {
			x--;
		}

		x = ((x % 3) + 3) % 3;

		if (s[i] == prev) {
			y = 1;
		} else {
			y += 1;
		}

		prev = s[i];
		ans += (cnt[0] + cnt[1] + cnt[2]) - cnt[x];
		cnt[x] += 1;
		ans -= (y - 1) / 2;
	}

	cout << ans << endl;
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
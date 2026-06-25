#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
	int n, a;
	cin >> n;
	int min = 10000, amount = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		min = std::min(min, a);
		amount += min;
	}

	cout << amount << '\n';
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
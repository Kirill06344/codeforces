#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
    int a_s, b_s, x;
    cin >> a_s >> b_s >> x;

    int a = max(a_s, b_s);
    int b = min(a_s, b_s);
    int diff = a - b;

    if (diff <= 1) {
        cout << diff << endl;
        return;
    }

    if (a < x) {
        cout << 2 << endl;
        return;
    }


    int ans = diff;
    int divs = 0;
    while (a >= 1 || b >= 1) {
        int tmp_a = a;
        int tmp_b = b;
        a = max(tmp_a, tmp_b);
        b = min(tmp_a, tmp_b);

        a = a / x;
        divs += 1;

        ans = min(ans, abs(a - b) + divs);
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

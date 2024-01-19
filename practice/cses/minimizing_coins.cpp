#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define tc        \
    long long _t; \
    cin >> _t;    \
    while (_t--)
typedef long long ll;
#define int long long

// type name short forms
#define vvll vector<vector<long long>>
#define vll vector<long long>
#define pll pair<long long, long long>

#define loop(_k) for (int _q = 0; _q < _k; _q++)
long long _buf;
#define arrinp(_a, _n)                      \
    for (long long _l = 0; _l < _n; _l++) { \
        cin >> _buf;                        \
        _a.push_back(_buf);                 \
    }

ll dp[(ll)1e6 + 2];
ll done[(ll)1e6 + 2];

ll solve(ll x, vll& c) {
    if (x < 1) {
        return 1e10;
    }
    if (done[x]) {
        return dp[x];
    }
    ll ans = 1e10;
    for (int i = 0; i < c.size(); i++) {
        ans = min(solve(x - c[i], c), ans);
    }
    if (ans != 1e10) ans++;
    done[x] = 1;
    dp[x] = ans;
    return ans;
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, x;
    cin >> n >> x;

    vll c;
    arrinp(c, n);

    sort(c.begin(), c.end());

    for (int i = 0; i < x; i++) {
        done[n] = 0;
    }

    for (int i = 0; i < n; i++) {
        dp[c[i]] = 1;
        done[c[i]] = 1;
    }

    ll ans = solve(x, c);
    if (ans == 1e10) {
        cout << "-1\n";
    } else
        cout << ans << endl;
}
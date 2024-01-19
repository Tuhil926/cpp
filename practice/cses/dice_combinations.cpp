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

#define mod 1000000007

ll dp[(ll)1e6 + 2];
ll done[(ll)1e6 + 2];

ll solve(ll n) {
    if (n == 1) {
        return 1;
    } else if (n == 0) {
        return 0;
    }
    if (done[n]) {
        return dp[n];
    }
    ll ans = n <= 6;
    for (int i = 1; i < 7 && i < n; i++) {
        ans += solve(n - i);
        ans = ans % mod;
    }
    done[n] = 1;
    dp[n] = ans;
    return ans;
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        done[n] = 0;
    }

    cout << solve(n) << endl;
}
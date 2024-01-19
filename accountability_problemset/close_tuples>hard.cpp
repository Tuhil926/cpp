#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define TestCases \
    int _t;       \
    cin >> _t;    \
    for (int _i = 0; _i < _t; _i++)
typedef long long ll;
#define int long long
#define GetVector(_v, _n)             \
    for (int _i = 0; _i < _n; _i++) { \
        ll _temp;                     \
        cin >> _temp;                 \
        _v.push_back(_temp);          \
    }

#define Vec vector<ll>
#define mod (ll)(1e9 + 7)

ll fact_dp[(int)(2 * 1e5)];
ll done_dp[(int)(2 * 1e5)];

ll fact(ll n) {
    if (n == 0) {
        return 1;
    }
    if (done_dp[n]) {
        return fact_dp[n];
    }
    done_dp[n] = 1;
    fact_dp[n] = fact(n - 1) * n % mod;
    return fact_dp[n];
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m, k;

    for (int i = 0; i < (int)(2 * 1e5); i++) {
        done_dp[i] = 0;
    }

    TestCases {
        cin >> n >> m >> k;
        Vec a;
        GetVector(a, n);
        sort(a.begin(), a.end());
        ll i = 0, j = 0, tot = 0;
        for (; i < m; i++)
            ;
        i--;
        while (i < n) {
            if (i - j + 1 < m) {
                i++;
            } else if (a[i] - a[j] <= k) {
                if (i - j == m - 1) {
                    tot++;
                } else {
                    tot += i - j;
                }
                i++;
                tot %= mod;
            } else {
                j++;
            }
        }
    }
}
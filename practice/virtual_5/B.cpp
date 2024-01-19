#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define tc        \
    long long _t; \
    cin >> _t;    \
    while (_t--)
typedef long long ll;
#define int long long

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

#define mod 998244353

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll exists[(ll)1e5 + 1];
    ll roots[(ll)1e5 + 1];

    vll divr[(ll)1e5 + 1];

    for (ll i = 2; i * i <= 100000; i++) {
        for (ll j = i; j <= 100000; j += i) {
            divr[j].push_back(i);
        }
    }

    for (int i = 0; i < (ll)1e5 + 1; i++) {
        sort(divr[i].begin(), divr[i].end());
    }

    for (int i = 0; i < 1e5 + 1; i++) {
        roots[i] = (ll)sqrt(i);
    }
    tc {
        ll n;
        cin >> n;

        for (int i = 0; i < 1e5 + 1; i++) {
            exists[i] = -1;
        }
        vll s;
        arrinp(s, n);

        sort(s.begin(), s.end());

        for (int i = 0; i < n; i++) {
            exists[s[i]] = i;
        }

        vll dp(n, 1);

        for (int i = 1; i < n; i++) {
            for (int j = 0;
                 j < divr[s[i]].size() && divr[s[i]][j] * divr[s[i]][j] <= s[i];
                 j++) {
                ll dv = divr[s[i]][j];
                if (dv == 1) continue;
                ll other = s[i] / dv;
                ll ind1 = exists[dv];
                ll ind2 = exists[other];
                if (ind1 != -1 && ind2 != -1) {
                    dp[i] = (dp[i] + 1) % mod;
                }
            }
            // for (int j = 0; j < i; j++) {
            //     if (s[j] * s[j] > s[i]) {
            //         break;
            //     }
            //     if (s[i] % s[j] == 0) {
            //         // both individual
            //         ll other = s[i] / s[j];
            //         ll ind = exists[other];
            //         if (ind != -1) {
            //             dp[i] = (dp[i] + 1) % mod;
            //         }
            //     }
            // }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0;
                 j < divr[s[i]].size() && divr[s[i]][j] * divr[s[i]][j] <= s[i];
                 j++) {
                ll dv = divr[s[i]][j];
                if (dv == 1) continue;
                ll sqr = dv * dv;

                ll other = s[i] / dv;
                ll ind1 = exists[dv];
                ll ind2 = exists[other];
                if (ind1 != -1 && ind2 != -1) {
                    dp[i] = (dp[i] + 1) % mod;
                }
            }
            for (int j = 0; j < i; j++) {
                ll sqr = s[j] * s[j];
                if (sqr > s[i]) {
                    break;
                }
                if (dp[j] == 1) continue;
                if (s[i] % sqr == 0) {
                    ll other = s[i] / sqr;

                    ll ind = exists[other];

                    if (ind != -1) {
                        dp[i] = (dp[i] + dp[j] - 1) % mod;
                    }
                    if (sqr * sqr <= s[i]) {
                        ll rt = roots[other];
                        ll ind = exists[rt];
                        if (rt * rt == other && ind != -1 && dp[ind] != 1) {
                            dp[i] = (dp[i] + dp[j] * dp[ind]) % mod;
                        }
                    }
                }
            }
        }

        ll tot = 0;
        for (int i = 0; i < n; i++) {
            // cout << dp[i] << " ";
            tot += dp[i];
            tot = tot % mod;
        }

        cout << tot << endl;
    }
}
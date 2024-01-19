#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define TestCases \
    int _t;       \
    cin >> _t;    \
    for (int _i = 0; _i < _t; _i++)
typedef long long ll;
#define int long long
#define VecVec vector<vector<long long>>
#define Vec vector<long long>
#define Repeat(_k) for (int _q = 0; _q < _k; _q++)

ll dp[32];
ll done_dp[32];

ll pow_2(ll xi) {
    if (!xi) return 1;
    if (done_dp[xi]) return dp[xi];
    return 2 * pow_2(xi - 1);
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 32; i++) {
        done_dp[i] = 0;
    }

    TestCases {
        ll n, q;
        cin >> n >> q;
        Vec a, x;
        set<ll> x_set;
        ll buf;
        for (int i = 0; i < n; i++) {
            cin >> buf;
            a.push_back(buf);
        }
        for (int i = 0; i < q; i++) {
            cin >> buf;
            if (!x_set.count(buf)) {
                x.push_back(buf);
                x_set.insert(buf);
            }
        }
        for (int i = 0; i < x.size(); i++) {
            for (int j = 0; j < a.size(); j++) {
                if (a[j] % pow_2(x[i]) == 0) {
                    a[j] += pow_2(x[i] - 1);
                }
            }
        }
        for (int j = 0; j < a.size(); j++) {
            cout << a[j] << " ";
        }
        cout << endl;
    }
}
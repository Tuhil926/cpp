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

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    tc {
        ll n;
        cin >> n;
        vll a, b;
        arrinp(a, n);
        arrinp(b, n);

        vector<pll> res;
        for (int i = 0; i < n; i++) {
            res.push_back(make_pair(a[i] + b[i], a[i]));
        }

        sort(res.begin(), res.end());

        ll score = 0;

        for (int i = n - 1; i >= 0; i--) {
            if ((n - i) % 2) {
                score += res[i].second - 1;
            } else {
                score += res[i].second - res[i].first + 1;
            }
        }

        cout << score << endl;
    }
}
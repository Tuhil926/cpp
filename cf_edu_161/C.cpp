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
#define arrinp(_a, _n)                      \
    _a.resize(_n);                          \
    for (long long _l = 0; _l < _n; _l++) { \
        cin >> _a[_l];                      \
    }

#define debug(x) cerr << (#x) << " " << (x) << endl

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    tc {
        ll n;
        cin >> n;
        vll a;
        arrinp(a, n);
        vll pref_forw(n, 0), pref_back(n, 0);

        pref_forw[1] = 1;
        pref_back[n - 2] = 1;

        for (int i = 1; i < n - 1; i++) {
            if (a[i] - a[i - 1] > a[i + 1] - a[i]) {
                pref_forw[i + 1] = pref_forw[i] + 1;
            } else {
                pref_forw[i + 1] = pref_forw[i] + a[i + 1] - a[i];
            }

            if (a[n - i - 1] - a[n - i] < a[n - i - 2] - a[n - i - 1]) {
                pref_back[n - i - 2] = pref_back[n - i - 1] + 1;
            } else {
                pref_back[n - i - 2] =
                    pref_back[n - i - 1] - a[n - i - 2] + a[n - i - 1];
            }
        }

        // for (int i = 0; i < n; i++) {
        //     cout << pref_back[i] << " ";
        // }
        // cout << endl;

        ll m, x, y;
        cin >> m;
        loop(m) {
            cin >> x >> y;
            x--;
            y--;
            if (x < y) {
                cout << pref_forw[y] - pref_forw[x] << endl;
            } else {
                cout << pref_back[y] - pref_back[x] << endl;
            }
        }
    }
}
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

        sort(a.begin(), a.end());

        ll tot = 0;
        ll prev = a[n - 1];
        ll num = 1;
        for (int i = n - 2; i >= -1; i--) {
            if (i >= 0 && a[i] == prev) {
                num++;
            } else {
                tot += (num * (num - 1) * (num - 2)) / 6;
                tot += (num * (num - 1)) * (i + 1) / 2;
                num = 1;
                if (i >= 0) prev = a[i];
            }
        }
        cout << tot << endl;
    }
}
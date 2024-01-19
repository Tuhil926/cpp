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
        vll a;
        cin >> n;
        arrinp(a, n);

        set<ll> amt;
        amt.insert(0);

        ll tot = 0;
        ll yes = 0;

        for (int i = 0; i < n; i++) {
            if (i % 2)
                tot += a[i];
            else
                tot -= a[i];

            if (amt.count(tot)) {
                yes = 1;
                break;
            } else {
                amt.insert(tot);
            }
        }

        if (yes) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
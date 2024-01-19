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
        ll n, k;
        cin >> n >> k;

        vll b;
        arrinp(b, n);

        ll prod = 1;
        for (ll i = 0; i < n; i++) {
            prod *= b[i];
            if (prod > 2023) {
                break;
            }
        }

        if (2023 % prod == 0) {
            cout << "YES\n";
            for (ll i = 0; i < k - 1; i++) {
                cout << "1 ";
            }
            cout << 2023 / prod << endl;
        } else {
            cout << "NO\n";
        }
    }
}
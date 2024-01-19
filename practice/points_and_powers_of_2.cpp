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

    ll n;
    vll x;

    cin >> n;
    arrinp(x, n);

    ll a = x[0], b = 1e10, c = 1e10;
    ll done = 0;

    sort(x.begin(), x.end());
    for (int i = 0; i < n; i++) {
        for (int pow_2 = 1; pow_2 < 2e9; pow_2 *= 2) {
            if (binary_search(x.begin(), x.end(), x[i] + pow_2)) {
                a = x[i];
                b = x[i] + pow_2;
                done = 1;
                if (binary_search(x.begin(), x.end(), x[i] + pow_2 * 2)) {
                    c = x[i] + 2 * pow_2;
                    done = 2;
                    break;
                }
            }
        }
        if (done = 2) {
            break;
        }
    }

    if (b == 1e10) {
        cout << 1 << endl << x[0] << endl;
    } else if (c == 1e10) {
        cout << 2 << endl << a << " " << b << endl;
    } else {
        cout << 3 << endl << a << " " << b << " " << c << endl;
    }
}
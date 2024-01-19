#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define tc        \
    long long _t; \
    cin >> _t;    \
    while (_t--)
typedef long long ll;
#define int long long

#define mod 998244353

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

    ll two_pow[(ll)3e5 + 1];

    ll pow_2 = 1;

    for (int i = 0; i < 3e5 + 1; i++) {
        two_pow[i] = pow_2;
        pow_2 = (pow_2 * 2) % mod;
    }
    tc {
        ll n;
        cin >> n;
        vll p;
        arrinp(p, n);

        ll tot = 1;

        ll odd_start = 0;
        if (n > 1 && p[0] > p[1]) odd_start = 1;

        ll dec = odd_start;
        ll num = 1;

        vll stuff;

        for (int i = 1; i < n; i++) {
            if (dec) {
                if (p[i] > p[i + 1]) {
                    num++;
                } else {
                    stuff.push_back(num);
                    num = 1;
                    dec = 0;
                }
            } else {
                if (p[i] < p[i + 1]) {
                    num++;
                } else {
                    stuff.push_back(num);
                    num = 1;
                    dec = 1;
                }
            }
        }
        stuff.push_back(num);

        if (odd_start) {
            tot = (tot * two_pow[stuff[0]]) % mod;
            if (stuff.size() % 2 == 0) {
                tot = (tot * two_pow[stuff[stuff.size() - 1]]) % mod;
            }
        } else if (stuff.size() % 2 == 1) {
            tot = (tot * two_pow[stuff[stuff.size() - 1]]) % mod;
        }

        for (int i = odd_start; i < stuff.size() - 1; i += 2) {
            tot = (tot * (two_pow[stuff[i]] * two_pow[stuff[i + 1]] - 1)) % mod;
        }
        cout << tot << endl;
    }
}
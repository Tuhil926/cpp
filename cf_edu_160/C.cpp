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

    ll m;
    cin >> m;

    ll mul_set[30];
    ll two_pow[30];
    ll pow_2 = 1;
    for (int i = 0; i < 30; i++) {
        mul_set[i] = 0;
        two_pow[i] = pow_2;
        pow_2 *= 2;
    }

    ll choice, w;
    for (int i = 0; i < m; i++) {
        cin >> choice >> w;
        if (choice == 1) {
            mul_set[w]++;
        } else {
            for (int i = 29; i >= 0; i--) {
                if (!mul_set[i]) continue;
                ll num = w / two_pow[i];
                w -= min(num, mul_set[i]) * two_pow[i];
            }
            if (!w)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}
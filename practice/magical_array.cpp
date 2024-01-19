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
        ll n, m;
        cin >> n >> m;
        vll weights;
        for (int i = 0; i < n; i++) {
            vll c;
            arrinp(c, m);
            ll weight = 0;
            for (int i = 0; i < m; i++) {
                weight += c[i] * i;
            }
            weights.push_back(weight);
        }
        ll special = 0;
        ll other = 0;

        for (int i = 0; i < n; i++) {
            if (weights[i] > weights[special]) {
                other = special;
                special = i;
            } else if (weights[i] < weights[special]) {
                other = i;
            }
        }

        cout << special + 1 << " " << weights[special] - weights[other] << endl;
    }
}
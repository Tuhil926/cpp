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
    vll num_sub(201, 1);
    for (int i = 1; i < 201; i++) {
        num_sub[i] = num_sub[i - 1] * 2;
    }

    tc {
        ll X;
        cin >> X;
        vll out;
        for (int i = 1; i < 64; i++) {
                }
    }
}
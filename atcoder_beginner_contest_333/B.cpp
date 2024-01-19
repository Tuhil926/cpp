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

    string S, T;
    cin >> S >> T;
    char S1 = S[0], S2 = S[1];
    char T1 = T[0], T2 = T[1];

    if (min(abs(S1 - S2), 5 - abs(S1 - S2)) ==
        min(abs(T1 - T2), 5 - abs(T1 - T2))) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}
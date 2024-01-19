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
        cin >> n;
        string s, t;
        cin >> s >> t;
        if (s[0] != t[0] || s[n - 1] != t[n - 1]) {
            cout << "-1\n";
            continue;
        }
        vll invs, invt;

        char curr = s[0];
        for (int i = 1; i < n; i++) {
            if (s[i] != curr) {
                curr = s[i];
                invs.push_back(i);
            }
        }

        curr = t[0];
        for (int i = 1; i < n; i++) {
            if (t[i] != curr) {
                curr = t[i];
                invt.push_back(i);
            }
        }

        if (invs.size() != invt.size()) {
            cout << "-1\n";
            continue;
        }
        ll ops = 0;
        for (int i = 0; i < invs.size(); i++) {
            ops += abs(invs[i] - invt[i]);
        }
        cout << ops << endl;
    }
}
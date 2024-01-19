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
        vll rem;

        for (int i = 0; i < 26; i++) {
            rem.push_back(i + 1);
        }

        string s;
        cin >> s;
        // cout << (ll)'A' << endl;
        for (char c : s) {
            rem[c - 65]--;
        }

        ll count = 0;
        for (int i = 0; i < 26; i++) {
            if (rem[i] <= 0) count++;
        }

        cout << count << endl;
    }
}
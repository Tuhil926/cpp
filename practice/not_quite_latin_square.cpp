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
        string a, b, c;
        cin >> a >> b >> c;

        ll sum = 0;

        for (int i = 0; i < 3; i++) {
            if (a[i] != '?') {
                sum += a[i] - 'A' + 1;
            }
        }
        if (sum != 6) {
            cout << (char)(6 - sum - 1 + 'A') << endl;
            continue;
        }

        sum = 0;

        for (int i = 0; i < 3; i++) {
            if (b[i] != '?') {
                sum += b[i] - 'A' + 1;
            }
        }
        if (sum != 6) {
            cout << (char)(6 - sum - 1 + 'A') << endl;
            continue;
        }

        sum = 0;

        for (int i = 0; i < 3; i++) {
            if (c[i] != '?') {
                sum += c[i] - 'A' + 1;
            }
        }
        if (sum != 6) {
            cout << (char)(6 - sum - 1 + 'A') << endl;
            continue;
        }
    }
}
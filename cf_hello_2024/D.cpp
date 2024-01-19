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
        vll a;
        arrinp(a, n);
        ll yes = 1;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (a[i] - a[i + 1] > 1) {
                    yes = 0;
                    break;
                }
            } else if (i == n - 1) {
                if (a[i] - a[i - 1] > 1) {
                    // cout << i << endl;
                    yes = 0;
                    break;
                }
            } else if (a[i] - a[i - 1] > 1 && a[i] - a[i + 1] > 1) {
                yes = 0;
                break;
            }
        }
        sort(a.begin(), a.end());
        ll curr = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] - curr > 1) {
                yes = 0;
                break;
            }
            curr = a[i];
        }
        if (yes)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
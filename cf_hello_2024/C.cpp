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
        if (n <= 2) {
            cout << "0\n";
            continue;
        }

        ll x = 0;
        ll y = 0;
        ll count = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (x > y) {
                if (a[i] >= x) {
                    x = a[i];
                } else if (a[i] >= y) {
                    y = a[i];
                } else {
                    x = a[i];
                    count++;
                }
            } else {
                if (a[i] >= y) {
                    y = a[i];
                } else if (a[i] >= x) {
                    x = a[i];
                } else {
                    y = a[i];
                    count++;
                }
            }
        }
        // count -= 2;
        // if (x == 0 || y == 0) {
        //     count += 1;
        //     if (x == 0 && y == 0) count += 1;
        // }
        cout << count << endl;
    }
}
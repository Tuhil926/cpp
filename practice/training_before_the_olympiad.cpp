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
        vll a;
        cin >> n;
        arrinp(a, n);
        ll even = 0;
        ll odd = 0;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] % 2)
                odd++;
            else
                even++;
            sum += a[i];

            if (odd % 3 == 1 && i != 0)
                cout << sum - odd / 3 - 1 << " ";
            else
                cout << sum - odd / 3 << " ";
        }
        cout << endl;
    }
}
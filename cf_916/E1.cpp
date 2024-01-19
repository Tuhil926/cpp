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

ll score(vll a, vll b, ll turn) {
    ll max_score = -1e17;
    ll min_score = 1e17;
    ll exists = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] && b[i]) {
            exists = 1;
            ll prev;
            if (turn % 2) {
                a[i]--;
                prev = b[i];
                b[i] = 0;
                ll scr = score(a, b, turn + 1);
                if (scr > max_score) max_score = scr;
                a[i]++;
                b[i] = prev;
            } else {
                b[i]--;
                prev = a[i];
                a[i] = 0;
                ll scr = score(a, b, turn + 1);
                if (scr < min_score) min_score = scr;
                b[i]++;
                a[i] = prev;
            }
        }
    }
    if (!exists) {
        max_score = 0;
        for (int i = 0; i < a.size(); i++) {
            max_score += a[i] - b[i];
        }
        return max_score;
    }
    if (turn % 2)
        return max_score;
    else
        return min_score;
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    tc {
        ll n;
        cin >> n;
        vll a, b;
        arrinp(a, n);
        arrinp(b, n);

        cout << score(a, b, 1) << endl;
    }
}
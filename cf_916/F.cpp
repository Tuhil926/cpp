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

ll calc_heights(vll &p, vll &heights, ll ind) {
    if (ind == 0) {
        return 0;
    }
    if (heights[ind]) {
        return heights[ind];
    } else {
        ll ht = calc_heights(p, heights, p[ind] - 1);
        heights[ind] = ht + 1;
        return heights[ind];
    }
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    tc {
        ll n;
        cin >> n;
        vll p;
        p.push_back(0);
        arrinp(p, n - 1);

        vll heights(n, 0);
        for (int i = 0; i < n; i++) calc_heights(p, heights, i);

        vll heights_nums(n, 0);

        for (int i = 0; i < n; i++) {
            heights_nums[heights[i]]++;
        }

        ll tot = 0;
        for (int i = 0; i < n; i++) {
            tot += heights_nums[i] / 2;
        }

        cout << tot << endl;
    }
}
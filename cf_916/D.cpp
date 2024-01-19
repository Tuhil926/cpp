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

pll max_vec(vll &vec) {
    ll max_ = vec[0];
    ll ind = 0;
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] > max_) {
            max_ = vec[i];
            ind = i;
        }
    }

    return make_pair(max_, ind);
}

ll find_max(vll a, vll b, vll c) {
    pll a_mx = max_vec(a);
    ll tot = a_mx.first;
    b[a_mx.second] = 0;
    c[a_mx.second] = 0;

    pll b_mx = max_vec(b);
    tot += b_mx.first;
    c[b_mx.second] = 0;

    tot += max_vec(c).first;

    return tot;
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    tc {
        ll n;
        cin >> n;
        vll a, b, c;
        arrinp(a, n);
        arrinp(b, n);
        arrinp(c, n);

        ll maximum = 0;

        maximum = max(maximum, find_max(a, b, c));
        maximum = max(maximum, find_max(a, c, b));
        maximum = max(maximum, find_max(b, a, c));
        maximum = max(maximum, find_max(b, c, a));
        maximum = max(maximum, find_max(c, a, b));
        maximum = max(maximum, find_max(c, b, a));

        cout << maximum << endl;
    }
}
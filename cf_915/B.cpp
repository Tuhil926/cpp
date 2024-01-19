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

        vvll adj_list;

        for (int i = 0; i <= n; i++) {
            vll new_vec = vector<ll>();
            adj_list.push_back(new_vec);
        }

        for (int i = 0; i < n - 1; i++) {
            ll u, v;
            cin >> u >> v;

            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }

        ll tot = 0;

        ll num_junk = 0;

        for (int i = 1; i <= n; i++) {
            ll sz = adj_list[i].size();
            tot += (sz - sz / 2) - 1;

            if (sz % 2 && sz >= 3) {
                num_junk++;
            }
        }

        cout << tot + 1 - num_junk / 2 << endl;
    }
}
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

pll dfs(vvll &adj_list, ll i) {
    if (!adj_list[i].size()) return make_pair(1, 1);

    ll max1 = 0, max2 = 0;
    ll max_prod = 0;

    for (int j = 0; j < adj_list[i].size(); j++) {
        pll res = dfs(adj_list, adj_list[i][j]);
        if (res.first > max1) {
            max2 = max1;
            max1 = res.first;
        } else if (res.first > max2) {
            max2 = res.first;
        }

        if (res.second > max_prod) {
            max_prod = res.second;
        }
    }

    return (make_pair(max1, max(max_prod, max1 * max2)));
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    tc {
        ll n;
        cin >> n;
        vll a;
        vvll adj_list(n);
        for (int i = 1; i < n; i++) {
            ll j;
            cin >> j;
            j--;

            adj_list[j].push_back(i);
        }
        arrinp(a, n);

        cout << dfs(adj_list, 0).second << endl;
    }
}
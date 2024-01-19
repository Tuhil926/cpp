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
ll done[(ll)1e6];
ll subtree_size(vvll &adj_list, ll ind) {
    ll tot = 1;

    if (done[ind]) {
        return 0;
    }
    done[ind] = 1;

    for (int i = 0; i < adj_list[ind].size(); i++) {
        tot += subtree_size(adj_list, adj_list[ind][i]);
    }

    return tot;
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;

    for (int i = 0; i <= n; i++) {
        done[i] = 0;
    }
    done[1] = 1;

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

    ll max_size = 0;
    for (int i = 0; i < adj_list[1].size(); i++) {
        ll sz = subtree_size(adj_list, adj_list[1][i]);
        if (sz > max_size) {
            max_size = sz;
        }
    }

    cout << n - max_size << endl;
}
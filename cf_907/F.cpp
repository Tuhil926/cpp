#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define TestCases \
    int _t;       \
    cin >> _t;    \
    for (int _i = 0; _i < _t; _i++)
typedef long long ll;
#define int long long
#define VecVec vector<vector<long long>>
#define Vec vector<long long>
#define Repeat(_k) for (int _q = 0; _q < _k; _q++)

// ll add_stuff(VecVec* tree, Vec* adds, Vec* vals, ll i) {
//     (*vals)[i] += (*adds)[i];

//     for (int j = 1; j < (*tree)[i].size(); j++) {
//         // add_stuff()
//     }

//     (*adds)[i] = 0;
// }

ll val(VecVec* tree, Vec* adds, Vec* vals, ll i) {
    ll res = (*vals)[i] + (*adds)[i];
    while (i != 1) {
        i = (*tree)[i][0];
        res += (*adds)[i];
    }
    return res;
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    TestCases {
        VecVec tree;
        Vec adds;
        Vec vals;
        for (int i = 0; i < (int)(5 * 1e5 + 1); i++) {
            Vec v;
            tree.push_back(v);
            adds.push_back(0);
            vals.push_back(0);
        }
        ll sz = 1;
        ll q;
        cin >> q;

        ll ti, vi, xi;

        Repeat(q) {
            cin >> ti;
            cin >> vi;
            if (ti == 1) {
                tree[vi].push_back(sz + 1);
                tree[sz + 1].push_back(vi);
                sz++;
                ll ind = sz;
                while (ind != 1) {
                    ind = tree[ind][0];
                    vals[sz] -= adds[ind];
                }
            } else {
                cin >> xi;
                adds[vi] += xi;
            }
        }

        for (int i = 1; i <= sz; i++) {
            cout << val(&tree, &adds, &vals, i) << " ";
        }
        cout << endl;
    }
}
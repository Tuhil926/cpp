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

#include <random>

ll dp[(int)(2 * 1e5 + 1)];
ll done_dp[(int)(2 * 1e5 + 1)];

ll hashy(VecVec* tree, ll i, ll parent, ll hash_key, ll hash_key2, ll md) {
    if (done_dp[i]) {
        return dp[i];
    }
    ll val = 0;
    if ((*tree)[i].size() - 1 > 0) {
        for (int j = 0; j < (*tree)[i].size(); j++) {
            if ((*tree)[i][j] != parent)
                val += (hashy(tree, (*tree)[i][j], i, hash_key, hash_key2,
                              md + 11) *
                        hash_key) %
                       md;
            val %= md;
        }
        val *= hash_key2;
        val %= md;

        val *= (*tree)[i].size();
        val %= md;

        // cout << "hash of " << i << " " << val << endl;
        done_dp[i] = 1;
        dp[i] = val;
        return val;
    } else {
        // cout << "hash of " << i << " " << hash_key << endl;
        done_dp[i] = 1;
        dp[i] = hash_key;
        return hash_key;
    }
}

ll check_symmetry(VecVec* tree, ll i, ll parent) {
    ll md = (ll)1e9 + rand() + 1;
    ll hash_key = 0;
    while (!hash_key) {
        hash_key = (rand() * rand() + 1) % ((int)1e9);
    }
    ll hash_key2 = 0;
    while (!hash_key2) {
        hash_key2 = (rand() * rand() + 1) % ((int)1e9);
    }

    vector<pair<ll, ll>> childs;
    for (int j = 0; j < (*tree)[i].size(); j++) {
        if ((*tree)[i][j] != parent)
            childs.push_back(make_pair(
                hashy(tree, (*tree)[i][j], i, hash_key, hash_key2, md), j));
    }
    sort(childs.begin(), childs.end());

    // for (int j = 0; j < childs.size(); j++) {
    //     cout << childs[j].first << " ";
    // }
    // cout << endl;

    ll yes = 1;
    if (!childs.size()) return 1;
    if (childs.size() % 2 == 0) {
        for (int j = 0; j < childs.size() - 1; j += 2) {
            if (childs[j].first != childs[j + 1].first) {
                yes = 0;
                break;
            }
        }
    } else {
        ll num_bad = 0;
        ll to_check = childs.size() - 1;
        for (int j = 0; j < childs.size() - 1; j += 2) {
            if (childs[j].first != childs[j + 1].first) {
                if (!num_bad) {
                    num_bad++;
                    to_check = j;
                    j--;
                } else {
                    yes = 0;
                    break;
                }
            }
        }

        if (yes)
            yes *= check_symmetry(tree, (*tree)[i][childs[to_check].second], i);
    }
    return yes;
}

ll print_tree(VecVec* tree) {
    for (int i = 0; i < (*tree).size(); i++) {
        for (int j = 0; j < (*tree)[i].size(); j++) {
            cout << (*tree)[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    TestCases {
        ll n;
        cin >> n;

        for (int i = 0; i < n + 1; i++) {
            done_dp[i] = 0;
        }
        // if (_i == 8832 && n != 9) {
        //     cout << n << endl;
        // }
        VecVec tree;
        Repeat(n + 1) {
            Vec vect;
            tree.push_back(vect);
        }
        Repeat(n - 1) {
            ll u, v;
            cin >> u >> v;
            // if (_i == 407 && n != 4 && _q > 5) {
            //     cout << u << "-" << v << "-";
            // }
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        // print_tree(&tree);

        ll res = 0;
        int num = 22;
        Repeat(num) {
            res += check_symmetry(&tree, 1, 0);
            for (int i = 0; i < n + 1; i++) {
                done_dp[i] = 0;
            }
        }
        // cout << hashy(&tree, 1, 0, 3, 1, 10) << endl;
        if (res > num / 2) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
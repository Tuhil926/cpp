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

ll merge_sort(vll& arr, ll left, ll right) {
    if (left >= right) return 0;
    ll mid = (left + right) / 2;
    ll num_inv = 0;
    num_inv += merge_sort(arr, left, mid) + merge_sort(arr, mid + 1, right);
    ll start_1 = left;
    ll start_2 = mid + 1;
    vll merged;

    while (1) {
        if (start_1 <= mid && start_2 <= right) {
            if (arr[start_1] > arr[start_2]) {
                num_inv += mid + 1 - start_1;
                merged.push_back(arr[start_2]);
                start_2++;
            } else {
                merged.push_back(arr[start_1]);
                start_1++;
            }
        } else if (start_1 <= mid) {
            merged.push_back(arr[start_1]);
            start_1++;
        } else if (start_2 <= right) {
            merged.push_back(arr[start_2]);
            start_2++;
        } else
            break;
    }
    for (int i = left; i < right + 1; i++) {
        arr[i] = merged[i - left];
    }
    return num_inv;
}

ll num_inversions(vll vec) { return merge_sort(vec, 0, vec.size() - 1); }

#define qt QueryTree
class QueryTree {
   public:
    vll array;
    vll inp_arr;
    vll lazy;
    vll lazy_reset;

    // change this identity and func based on question. make sure that
    // func(a, identity) returns a.
    ll identity = 0;
    ll func(ll a, ll b) { return a + b; }
    ll identity_add = 0;
    ll func_add(ll a, ll b) { return a + b; }
    ll func_add_n(ll a, ll n) { return a * n; }

    QueryTree(vll inp_arr) {
        this->inp_arr = inp_arr;
        array = vll(inp_arr.size() * 4, identity);
        lazy = vll(inp_arr.size() * 4, identity);
        lazy_reset = vll(inp_arr.size() * 4, 0);
        this->build(1, 0, inp_arr.size() - 1);
    }

    ll build(ll node, ll n_l, ll n_r) {
        if (n_l == n_r) {
            array[node] = inp_arr[n_l];
        } else {
            ll m = (n_l + n_r) / 2;
            build(node * 2, n_l, m);
            build(node * 2 + 1, m + 1, n_r);
            array[node] = func(array[2 * node], array[2 * node + 1]);
        }
        return 0;
    }

    ll query(ll a, ll b) { return query_rec(1, 0, inp_arr.size() - 1, a, b); }

    ll update(ll a, ll b, ll val) {
        update_rec(1, 0, inp_arr.size() - 1, a, b, val);
        return 0;
    }

    ll reset(ll a, ll b) {
        reset_rec(1, 0, inp_arr.size() - 1, a, b);
        return 0;
    }

    ll query_rec(ll node, ll l, ll r, ll n_l, ll n_r) {
        if (l == n_l && r == n_r) {
            if (lazy_reset[node]) return func_add_n(lazy[node], r - l + 1);
            return func_add(array[node], func_add_n(lazy[node], r - l + 1));
        } else if (n_l > r || n_r < l) {
            return identity;
        } else {
            ll m = (l + r) / 2;
            propagate_update(node, r - l + 1);
            return func(
                query_rec(node * 2, l, m, n_l, min(m, n_r)),
                query_rec(node * 2 + 1, m + 1, r, max(m + 1, n_l), n_r));
        }
    }

    ll update_rec(ll node, ll l, ll r, ll n_l, ll n_r, ll val) {
        if (l == n_l && r == n_r) {
            lazy[node] = func_add(lazy[node], val);
            if (lazy_reset[node]) {
                propagate_update(node, r - l + 1);
                // return func_add_n(lazy[node], r - l + 1);
            }
            return func_add(array[node], func_add_n(lazy[node], r - l + 1));
        } else if (n_l > r || n_r < l) {
            return identity;
        } else {
            ll m = (l + r) / 2;
            propagate_update(node, r - l + 1);

            ll res = func(
                update_rec(node * 2, l, m, n_l, min(m, n_r), val),
                update_rec(node * 2 + 1, m + 1, r, max(m + 1, n_l), n_r, val));
            array[node] = res;
            return res;
        }
    }

    ll reset_rec(ll node, ll l, ll r, ll n_l, ll n_r) {
        if (l == n_l && r == n_r) {
            lazy_reset[node] = 1;
            lazy[node] = identity_add;

            return identity;
        } else if (n_l > r || n_r < l) {
            return identity;
        } else {
            ll m = (l + r) / 2;
            propagate_update(node, r - l + 1);

            ll res =
                func(reset_rec(node * 2, l, m, n_l, min(m, n_r)),
                     reset_rec(node * 2 + 1, m + 1, r, max(m + 1, n_l), n_r));
            array[node] = res;
            return res;
        }
    }

    ll propagate_update(ll node, ll range_size) {
        if (node >= inp_arr.size() * 2) return 0;
        if (lazy_reset[node]) {
            lazy[2 * node] = identity_add;
            lazy[2 * node + 1] = identity_add;
            array[node] = identity;
            // lazy[node] = identity_add;

            lazy_reset[2 * node] = 1;
            lazy_reset[2 * node + 1] = 1;
            lazy_reset[node] = 0;
            // return 0;
        }
        lazy[2 * node] = func_add(lazy[2 * node], lazy[node]);
        lazy[2 * node + 1] = func_add(lazy[2 * node + 1], lazy[node]);
        array[node] = func_add(array[node], func_add_n(lazy[node], range_size));
        lazy[node] = identity_add;

        cout << "Update propagated: " << array[node] << " " << node << endl;
        return 0;
    }
};

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vll inp_arr = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    QueryTree tree(inp_arr);

    cout << tree.query(0, 0) << endl;
    tree.update(0, 9, 2);
    tree.update(0, 0, 2);
    cout << tree.query(0, 0) << endl;
}
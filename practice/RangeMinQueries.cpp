#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define TestCases \
    long long _t; \
    cin >> _t;    \
    for (int _i = 0; _i < _t; _i++)
typedef long long ll;
#define int long long
#define VecVec vector<vector<long long>>
#define Vec vector<long long>
#define Repeat(_k) for (int _q = 0; _q < _k; _q++)
long long _buf;
#define ArrInp(_a, _n)                      \
    for (long long _l = 0; _l < _n; _l++) { \
        cin >> _buf;                        \
        _a.push_back(_buf);                 \
    }

ll merge_sort(Vec& arr, ll left, ll right) {
    if (left >= right) return 0;
    ll mid = (left + right) / 2;
    ll num_inv = 0;
    num_inv += merge_sort(arr, left, mid) + merge_sort(arr, mid + 1, right);
    ll start_1 = left;
    ll start_2 = mid + 1;
    Vec merged;

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

ll num_inversions(Vec vec) { return merge_sort(vec, 0, vec.size() - 1); }

class QueryTree {
   public:
    Vec array;
    Vec inp_arr;
    ll identity = 0;
    ll func(ll a, ll b) { return a ^ b; }
    QueryTree(Vec inp_arr) {
        this->inp_arr = inp_arr;
        array = Vec(inp_arr.size() * 4, identity);
        this->build(1, 0, inp_arr.size() - 1);
    }

    ll build(ll node, ll n_l, ll n_r) {
        if (n_l == n_r) {
            this->array[node] = this->inp_arr[n_l];
        } else {
            ll m = (n_l + n_r) / 2;
            this->build(node * 2, n_l, m);
            this->build(node * 2 + 1, m + 1, n_r);
            this->array[node] =
                this->func(this->array[2 * node], this->array[2 * node + 1]);
        }
        return 0;
    }

    ll query(ll a, ll b) {
        return this->query_rec(1, 0, this->inp_arr.size() - 1, a, b);
    }

    ll update(ll a, ll b, ll val) {
        this->update_rec(1, 0, this->inp_arr.size() - 1, a, val);
        return 0;
    }

    ll query_rec(ll node, ll l, ll r, ll n_l, ll n_r) {
        if (l == n_l && r == n_r) {
            return this->array[node];
        } else if (n_l > r || n_r < l) {
            return this->identity;
        } else {
            ll m = (l + r) / 2;
            return this->func(
                this->query_rec(node * 2, l, m, n_l, min(m, n_r)),
                this->query_rec(node * 2 + 1, m + 1, r, max(m + 1, n_l), n_r));
        }
    }

    ll update_rec(ll node, ll n_l, ll n_r, ll i, ll x) {
        if (n_l == n_r) {
            this->array[node] = x;
            return 0;
        }
        ll m = (n_l + n_r) / 2;
        if (i <= m) {
            this->update_rec(node * 2, n_l, m, i, x);
        } else {
            this->update_rec(node * 2 + 1, m + 1, n_r, i, x);
        }
        this->array[node] =
            this->func(this->array[node * 2], this->array[node * 2 + 1]);
        return 0;
    }
};

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, q;
    cin >> n >> q;

    Vec inp_arr;
    ArrInp(inp_arr, n);

    QueryTree tree = QueryTree(inp_arr);

    ll choice, a, b;

    for (int i = 0; i < q; i++) {
        cin >> a >> b;

        cout << tree.query(a - 1, b - 1) << endl;
    }
}
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

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    tc {
        ll n;
        cin >> n;

        vll inp;
        arrinp(inp, n);

        ll invs = num_inversions(inp);
        ll min_invs = invs;

        vll inv_counts;
        inv_counts.push_back(invs);

        ll max_shift = 0;

        for (int i = 0; i < n - 1; i++) {
            invs += n - inp[i] - 1 - (inp[i]);
            inv_counts.push_back(invs);
            if (invs < min_invs) {
                min_invs = invs;
                max_shift = i + 1;
            }
        }
        // break;
        ll max_cost = 0;

        max_shift -= 1;
        if (max_shift < 0) {
            max_shift = n - 1;
        }
        for (int i = 0; i < 3; i++) {
            ll cost = n;

            vll new_arr;
            new_arr.push_back(inp[max_shift]);
            for (int i = (max_shift + 1) % n; i != max_shift; i = (i + 1) % n) {
                new_arr.push_back(inp[i]);
            }

            ll mx = n;

            for (int i = n - 1; i > 0; i--) {
                if (new_arr[i] < mx) {
                    mx = new_arr[i];
                }
                cost += mx;
            }
            if (cost > max_cost) {
                max_cost = cost;
            }

            max_shift = (max_shift + 1) % n;
        }

        cout << max_cost << endl;
    }
}
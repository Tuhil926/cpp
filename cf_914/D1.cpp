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

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    TestCases {
        ll n;
        cin >> n;
        Vec a, b;
        ArrInp(a, n);
        ArrInp(b, n);

        Vec groups;
        Vec curr_max;

        ll curr = -1;
        for (int i = 0; i < b.size(); i++) {
            if (curr != b[i]) {
                curr = b[i];
                groups.push_back(i);
            }
        }
        groups.push_back(n);

        ll possible = 1;

        for (int i = 0; i < groups.size() - 1; i++) {
            ll group_start = groups[i];
            ll group_end = groups[i + 1];
            ll curr_max_group = 0;
            for (int j = group_start; j < group_end; j++) {
                if (a[j] > curr_max_group) {
                    curr_max_group = a[j];
                }
            }
            curr_max.push_back(curr_max_group);

            if (curr_max_group > b[group_start]) {
                possible = 0;
            }
        }
        if (!possible) {
            cout << "NO\n";
            continue;
        }
        for (int i = 0; i < groups.size() - 1; i++) {
            ll group_start = groups[i];
            ll group_end = groups[i + 1];

            ll pos = 0;

            // cout << group_start << " " << group_end << endl;

            if (curr_max[i] < b[group_start]) {
                if (group_start != 0 && b[group_start - 1] > b[group_start]) {
                    ll m = 0;
                    for (int j = group_start - 1; j >= 0; j--) {
                        if (a[j] > m) {
                            m = a[j];
                        }
                        if (m > b[j]) {
                            break;
                        }
                        if (m == b[group_start]) {
                            break;
                        }
                    }
                    if (m != b[group_start]) {
                        // cout << "no!!!!! " << m << endl;

                        pos = 0;
                    } else {
                        pos = 1;
                    }
                }
                if (!pos && i != groups.size() - 2 &&
                    b[group_end] > b[group_start]) {
                    ll m = 0;
                    for (int j = group_end; j < n; j++) {
                        if (a[j] > m) {
                            m = a[j];
                        }
                        if (m > b[j]) {
                            break;
                        }
                        if (m == b[group_start]) {
                            break;
                            // cout << "yes!!! " << m << endl;
                        }
                    }
                    if (m != b[group_start]) {
                        pos = 0;
                    } else {
                        pos = 1;
                    }
                }

                if (!pos) {
                    possible = 0;
                    break;
                }
            }
        }

        if (!possible) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}
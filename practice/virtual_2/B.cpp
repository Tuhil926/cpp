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
#define ArrInp(_a, _n)                      \
    long long _buf;                         \
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

int ncr(int n, int r) {
    int res = 1;
    if (2 * r > n) {
        for (int i = n; i > r; i--) {
            res *= i;
        }
        for (int i = 2; i <= n - r; i++) {
            res /= i;
        }
    } else {
        for (int i = n; i > n - r; i--) {
            res *= i;
        }
        for (int i = 2; i <= r; i++) {
            res /= i;
        }
    }
    return res;
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, c, o, d, i;
    cin >> t >> c >> o >> d >> i;

    Vec t_nums(4), c_nums(6), o_nums(8), d_nums(12), i_nums(20);

    for (int S = t; S <= t * 4; S++) {
        int sum = 0;
        for (int T = 0; T <= (S - t) / 4; T++) {
            int part_of_sum = 1;
            if (T % 2 == 1) part_of_sum = -1;
            part_of_sum *= ncr(t, T);
            part_of_sum *= ncr(S - 1 - 4 * T, t - 1);
            sum += part_of_sum;
        }
        t_nums.push_back(sum);
    }

    for (int S = c; S <= c * 6; S++) {
        int sum = 0;
        for (int T = 0; T <= (S - c) / 6; T++) {
            int part_of_sum = 1;
            if (T % 2 == 1) part_of_sum = -1;
            part_of_sum *= ncr(c, T);
            part_of_sum *= ncr(S - 1 - 6 * T, c - 1);
            sum += part_of_sum;
        }
        c_nums.push_back(sum);
    }

    for (int S = o; S <= o * 8; S++) {
        int sum = 0;
        for (int T = 0; T <= (S - o) / 8; T++) {
            int part_of_sum = 1;
            if (T % 2 == 1) part_of_sum = -1;
            part_of_sum *= ncr(o, T);
            part_of_sum *= ncr(S - 1 - 8 * T, o - 1);
            sum += part_of_sum;
        }
        t_nums.push_back(sum);
    }

    vector<pair<ll, ll>> sums;

    for (int S = d; S <= d * 12; S++) {
        int sum = 0;
        for (int T = 0; T <= (S - d) / 12; T++) {
            int part_of_sum = 1;
            if (T % 2 == 1) part_of_sum = -1;
            part_of_sum *= ncr(d, T);
            part_of_sum *= ncr(S - 1 - 12 * T, d - 1);
            sum += part_of_sum;
        }
        t_nums.push_back(sum);
    }

    for (int S = i; S <= i * 20; S++) {
        int sum = 0;
        for (int T = 0; T <= (S - i) / 20; T++) {
            int part_of_sum = 1;
            if (T % 2 == 1) part_of_sum = -1;
            part_of_sum *= ncr(i, T);
            part_of_sum *= ncr(S - 1 - 20 * T, i - 1);
            sum += part_of_sum;
        }
        t_nums.push_back(sum);
    }

    for (int n1 = t; n1 <= 4 * t; n1++) {
        for (int n2 = c; n2 <= 6 * c; n2++) {
            for (int n3 = o; n3 <= 8 * o; n3++) {
                for (int n4 = d; n4 <= 12 * d; n4++) {
                    for (int n5 = i; n5 <= 20 * i; n5++) {
                        sums.push_back(make_pair(t_nums[n1] * c_nums[n2] *
                                                     o_nums[n3] * d_nums[n4] *
                                                     i_nums[n5],
                                                 n1 + n2 + n3 + n4 + n5));
                    }
                }
            }
        }
    }

    sort(t_nums.begin(), t_nums.end());
}
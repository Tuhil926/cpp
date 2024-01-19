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
#define mod (int)1e9 + 7

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

int fact_dp[(int)2e6];
int done_dp[(int)2e6];

int fact(int n) {
    if (done_dp[n]) return fact_dp[n];
    done_dp[n] = 1;
    int res = (fact(n - 1) * n) % mod;
    fact_dp[n] = res;
    return res;
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < (int)2e6; i++) {
        done_dp[i] = 0;
    }

    int n, h;
    cin >> n >> h;
    Vec k;
    ArrInp(k, h);
    Vec sum_k;
    int sum = k[0];
    sum_k.push_back(sum);

    for (int i = 1; i < h; i++) {
        sum += k[i];
        sum_k.push_back(sum);
    }

    int tot = fact(n);

    for (int i = 0; i < h; i++) {
        int to_sub = fact(n - sum_k[i]);
        for (int j = 0; j <= i; j++) {
                }
    }
}
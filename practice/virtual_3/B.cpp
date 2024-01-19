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

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int rj, rt;
    double sjf, stf;
    cin >> rt >> rj;
    cin >> stf >> sjf;

    int sj, st;
    sj = (int)((sjf * 100.0) + 0.5);
    st = (int)((stf * 100.0) + 0.5);

    if ((rj - 1) * st < (rt - 1) * sj) {
        cout << "JAKARTA" << endl;
    } else if ((rj - 1) * st > (rt - 1) * sj) {
        cout << "TAOYUAN" << endl;
    } else {
        cout << "SAME" << endl;
    }
}
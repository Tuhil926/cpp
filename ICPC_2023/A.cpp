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
#define INF 1e17

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

ll DijkstraAlgo(Vec x, Vec s, ll n)  // adjacency matrix
{
    Vec distance;  // // array to calculate the minimum distance for each node

    set<ll> not_done;

    for (ll k = 0; k <= n; k++) {
        distance.push_back(INF);
    }

    priority_queue<pair<ll, ll>> min_heap;
    min_heap.push(pair<ll, ll>(0, n));

    distance[n] = 0;  // Source vertex distance is set 0

    while (min_heap.size()) {
        ll m = min_heap.top().second;
        min_heap.pop();
        // for (ll k = 0; k < 6; k++) {
        //     // updating the distance of neighbouring vertex
        //     if (!Tset[k] && distance[m] != INF &&
        //         distance[m] + abs((x[m] - x[k]) * s[k]) < distance[k])
        //         distance[k] = distance[m] + abs((x[m] - x[k]) * s[k]);
        // }
        for (int i = 1; i <= n; i++) {
            if (distance[i] > distance[m] + abs((x[m] - x[i]) * s[i])) {
                distance[i] = distance[m] + abs((x[m] - x[i]) * s[i]);
                min_heap.push(pair<ll, ll>(distance[i], i));
            }
        }
    }
    // cout << "Vertex\t\tDistance from source vertex" << endl;
    // for (ll k = 0; k < 6; k++) {
    //     char str = 65 + k;
    //     cout << str << "\t\t\t" << distance[k] << endl;
    // }
    return distance[1];
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    TestCases {
        ll n, k;
        cin >> n >> k;
        Vec x, s;
        ArrInp(x, n);
        ArrInp(s, n);

        cout << DijkstraAlgo(x, s, n) << endl;
    }
}
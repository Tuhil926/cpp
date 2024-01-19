#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define TestCases \
    ll _t;        \
    cin >> _t;    \
    for (ll _i = 0; _i < _t; _i++)
typedef long long ll;

ll _mergeSort(ll arr[], ll temp[], ll left, ll right);
ll merge(ll arr[], ll temp[], ll left, ll mid, ll right);

ll mergeSort(ll arr[], ll array_size) {
    ll temp[array_size];
    return _mergeSort(arr, temp, 0, array_size - 1);
}

ll _mergeSort(ll arr[], ll temp[], ll left, ll right) {
    ll mid, inv_count = 0;
    if (right > left) {
        mid = (right + left) / 2;

        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);

        // Merge the two parts
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

ll merge(ll arr[], ll temp[], ll left, ll mid, ll right) {
    ll i, j, k;
    ll inv_count = 0;

    // i is index for left subarray
    i = left;

    // j is index for right subarray
    j = mid;

    // k is index for resultant merged
    // subarray
    k = left;

    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];

            /* This is tricky -- see above
            explanation/diagram for merge()*/
            inv_count = inv_count + (mid - i);
        }
    }

    /* Copy the remaining elements of left
    subarray (if there are any) to temp*/
    while (i <= mid - 1) temp[k++] = arr[i++];

    /* Copy the remaining elements of right
    subarray (if there are any) to temp*/
    while (j <= right) temp[k++] = arr[j++];

    /* Copy back the merged elements to
    original array*/
    for (i = left; i <= right; i++) arr[i] = temp[i];

    return inv_count;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    ll p[3000000];

    for (ll i = 0; i < n; i++) {
        ll num;
        cin >> num;
        p[i] = num;
    }

    cout << mergeSort(p, n) << endl;
}
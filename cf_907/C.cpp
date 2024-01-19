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

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    TestCases {
        ll n;
        cin >> n;
        Vec a;
        ll buf;
        for (int i = 0; i < n; i++) {
            cin >> buf;
            a.push_back(buf);
        }
        sort(a.begin(), a.end());
        ll start = 0;
        ll end = n - 1;
        ll ans = 0;
        ll x = 0;
        while (a[end]) {
            if (x < a[end]) {
                if (a[start] && (a[start] + x <= a[end]) && start != end) {
                    x += a[start];
                    ans += a[start];
                    a[start] = 0;
                    start++;
                } else if (a[start] && start != end) {
                    ll amt = a[end] - x;
                    x += amt;
                    ans += amt;
                    a[start] -= amt;
                } else if (a[start] && start == end) {
                    ll amt = (a[end] - x) / 2;
                    x += amt;
                    a[end] -= amt;
                    ans += amt;

                    a[end] -= x;
                    x = 0;
                    ans++;
                    if (a[end] == 1) {
                        ans++;
                    }
                    break;
                } else {
                    start++;
                }
            } else {
                a[end] = 0;
                x = 0;
                end--;
                ans++;
            }
        }
        cout << ans << endl;
    }
}
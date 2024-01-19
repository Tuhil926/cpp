#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define TestCases \
    int _t;       \
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
        Repeat(n) {
            ll num;
            cin >> num;
            a.push_back(num);
        }
        ll m_2 = 1;
        ll yes = 1;
        ll start = 0;
        while (start < n) {
            for (; start < m_2 - 1 && start < n - 1; start++) {
                if (a[start] > a[start + 1]) {
                    yes = 0;
                    break;
                }
            }
            start++;
            m_2 *= 2;
        }
        if (yes) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
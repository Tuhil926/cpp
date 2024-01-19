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

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    tc {
        ll n;
        cin >> n;

        string s;
        cin >> s;

        char max_global = 'a';
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] >= max_global) {
                max_global = s[i];
            }
        }
        char max_curr = 'a';

        char prev = 'z' + 1;

        ll num = 0;

        ll pos = 1;

        vll in_subs(n, 0);

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] >= max_curr) {
                max_curr = s[i];
                in_subs[i] = 1;
                if (max_curr != max_global) num++;
            } else {
                if (s[i] > prev) {
                    pos = 0;
                    break;
                }
                prev = s[i];
            }
        }

        ll start = 0, end = n - 1;

        while (!in_subs[start] && start < n) {
            start++;
        }
        while (!in_subs[end] && end >= 0) {
            end--;
        }

        while (start < n && end >= 0) {
            if (start > 0 && !in_subs[start - 1]) {
                if (s[start - 1] > s[end]) {
                    pos = 0;
                    break;
                }
            }
            if (start < n - 1 && !in_subs[start + 1]) {
                if (s[start + 1] < s[end]) {
                    pos = 0;
                    break;
                }
            }
            start++;
            end--;
            while (!in_subs[start] && start < n) {
                start++;
            }
            while (!in_subs[end] && end >= 0) {
                end--;
            }
        }

        if (pos) {
            cout << num << endl;
        } else {
            cout << "-1\n";
        }
    }
}
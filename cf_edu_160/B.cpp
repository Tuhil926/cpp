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
        string s;
        cin >> s;
        ll ze = 0, on = 0, fin_ze, fin_on;

        for (auto c : s) {
            if (c == '0')
                ze++;
            else
                on++;
        }
        fin_ze = on;
        fin_on = ze;

        ll cost = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            if (ze == fin_ze && on == fin_on) break;
            if (fin_ze > ze) {
                fin_ze--;
            } else {
                fin_on--;
            }
            if (s[i] == '0') {
                ze--;
            } else {
                on--;
            }
            cost++;
        }

        cout << cost << endl;
    }
}
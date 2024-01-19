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

    ll N;

    cin >> N;

    vector<string> s;
    s.push_back("3");
    ll num = 0;
    while (num < N) {
        ll sz = s.size();
        vector<string> new_vec;
        for (int i = 0; i < sz; i++) {
            num++;
            if (num == N) {
                cout << s[i] << endl;
            }
        }

        for (int i = 0; i < sz; i++) {
            string new_str = s[i];
            new_vec.push_back("1" + new_str);
        }
        for (int i = 0; i < sz; i++) {
            string new_str = s[i];
            if (new_str[0] == '2' || new_str[0] == '3') {
                new_vec.push_back("2" + new_str);
            }
        }
        for (int i = 0; i < sz; i++) {
            string new_str = s[i];
            if (new_str[0] == '3') {
                new_vec.push_back("3" + new_str);
            }
        }
        s = new_vec;
    }
}

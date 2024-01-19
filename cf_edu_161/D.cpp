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
#define arrinp(_a, _n)                      \
    _a.resize(_n);                          \
    for (long long _l = 0; _l < _n; _l++) { \
        cin >> _a[_l];                      \
    }

#define debug(x) cerr << (#x) << " " << (x) << endl

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    tc {
        ll n;
        cin >> n;
        vll a, d;
        arrinp(a, n);
        arrinp(d, n);

        map<ll, pll> s;

        for (int i = 0; i < n; i++) {
            s.insert({i, make_pair(a[i], d[i])});
        }
        set<ll> to_del;
        set<ll> to_check_prev;
        set<ll> to_check;
        for (int i = 0; i < n; i++) {
            to_check_prev.insert(i);
        }
        loop(n) {
            to_del.clear();
            to_check.clear();
            for (ll k : to_check_prev) {
                auto i = s.lower_bound(k);
                ll dam = 0;
                auto next = s.upper_bound(i->first);
                auto prev = s.lower_bound(i->first);
                // cout << prev->first << endl;
                ll prev_check = 0, next_check = 0;
                if (next != s.end()) {
                    next_check = 1;
                    dam += next->second.first;
                }
                if (prev != s.begin()) {
                    prev_check = 1;
                    prev = std::prev(prev, 1);
                    dam += prev->second.first;
                }

                if (dam > i->second.second) {
                    to_del.insert(i->first);
                    if (next_check) to_check.insert(next->first);
                    if (prev_check) to_check.insert(prev->first);
                }
            }
            to_check_prev.clear();
            to_check_prev = to_check;
            for (ll q : to_del) {
                s.erase(q);
            }
            cout << to_del.size() << " ";
        }
        cout << endl;
    }
}
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

    vector<pll> inps;

    vll pots(N + 1, 0);
    vll tot_pot_count(N + 1, 0);
    ll pos = 1;

    for (int i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;
        if (a == 1) {
            pots[b]++;
            tot_pot_count[b]++;
        } else {
            if (pots[b]) {
                pots[b]--;
            } else {
                pos = 0;
            }
        }
        inps.push_back(make_pair(a, b));
    }

    if (!pos) {
        cout << "-1\n";
        return 0;
    }

    string output;
    vll new_pots(N + 1, 0);
    ll tot_pots = 0;
    ll max_tot_pots = 0;
    for (int i = 0; i < inps.size(); i++) {
        ll a = inps[i].first, b = inps[i].second;

        if (a == 1) {
            if (new_pots[b] < tot_pot_count[b] - pots[b]) {
                output += "1 ";
                tot_pots++;
                if (tot_pots > max_tot_pots) {
                    max_tot_pots = tot_pots;
                }
                new_pots[b]++;
            } else {
                output += "0 ";
            }
        } else {
            tot_pots--;
        }
    }

    cout << max_tot_pots << endl;
    cout << output << endl;
}
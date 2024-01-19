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
        ll N;
        cin >> N;
        string inp;
        cin >> inp;
        string output;

        ll left = N / 2 + 1;

        for (int i = 0; N - i > left && i < N; i++) {
            output.push_back('P');
            if (inp[i] == 'R') left--;
        }
        for (int i = N - left; i < N; i++) {
            if (inp[i] == 'P') output.push_back('S');
            if (inp[i] == 'R') output.push_back('P');
            if (inp[i] == 'S') output.push_back('R');
        }
        cout << output << endl;
    }
}
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
        vll A;
        cin >> N;
        arrinp(A, N);

        ll sum = 0;
        for (int i = 0; i < N; i++) {
            sum += A[i];
        }
        if (N == 1) {
            if (A[0] > 1) {
                cout << "Alice\n";
            } else {
                cout << "Bob\n";
            }
        } else if (sum % 2 == 1) {
            cout << "Bob\n";
        } else {
            if (N % 2 == 0) {
                if ((sum / 2) % 2) {
                    cout << "Alice\n";
                } else {
                    cout << "Bob\n";
                }
            } else {
                if ((sum / 2) % 2 == 0) {
                    cout << "Alice\n";
                } else {
                    cout << "Bob\n";
                }
            }
        }
    }
}
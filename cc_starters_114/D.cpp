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
        if (N % 2) {
            ll even = 2;
            ll odd = 1;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (i == 0 && j == 0) {
                        cout << odd << " ";
                        odd += 2;
                    } else if (i == 0) {
                        if (j % 2) {
                            cout << even << " ";
                            even += 2;
                        } else {
                            cout << odd << " ";
                            odd += 2;
                        }
                    } else if (j == 0) {
                        if (i % 2) {
                            cout << even << " ";
                            even += 2;
                        } else {
                            cout << odd << " ";
                            odd += 2;
                        }
                    } else {
                        if ((i + j) % 2) {
                            cout << odd << " ";
                            odd += 2;
                        } else {
                            cout << even << " ";
                            even += 2;
                        }
                    }
                }
                cout << endl;
            }
        } else if (N == 2) {
            cout << "-1" << endl;
        } else {
            vector<vector<bool>> mat;
            for (int i = 0; i < N; i++) {
                vector<bool> v(N, false);
                mat.push_back(v);
            }

            mat[0][0] = 1;
            mat[0][1] = 1;
            mat[1][1] = 1;
            mat[2][0] = 1;
            ll num = 4;

            for (int i = N - 1; i >= 2 && num < (N * N) / 2; i--) {
                for (int j = 1; j < i; j++) {
                    if (num < (N * N) / 2) {
                        mat[i][j] = 1;
                        mat[j][i] = 1;
                        num += 2;
                    } else {
                        break;
                    }
                }
            }
            ll odd = 1;
            ll even = 2;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (mat[i][j]) {
                        cout << odd << " ";
                        odd += 2;
                    } else {
                        cout << even << " ";
                        even += 2;
                    }
                }
                cout << endl;
            }
        }
    }
}
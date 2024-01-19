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

double min_cal(vector<double> x, double p, ll start) {
    double min_ = (double)start;
    double curr = (double)start;
    for (int i = 0; i < x.size(); i++) {
        curr += x[i];
        curr -= p;
        if (curr < min_) {
            min_ = curr;
        }
    }

    return min_;
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);

    tc {
        ll M, K, C, N, L;
        cin >> M >> K >> C >> N >> L;

        vector<double> x;

        ll xi;
        for (int i = 0; i < M; i++) {
            cin >> xi;
            x.push_back((double)(xi - N));
        }

        // cout << min_cal(x, 0.0, L) << endl << endl;

        double lower = 0.0;
        double upper = 1e8;
        double p = (lower + upper) / 2.0;

        while (1) {
            double res = min_cal(x, p, L);

            if (upper - lower < 1e-6) {
                break;
            }

            if (res < (double)C) {
                upper = p;
            } else if (res > (double)C) {
                lower = p;
            } else {
                break;
            }
            p = (lower + upper) / 2.0;
        }

        double final_wt = L;
        for (int i = 0; i < x.size(); i++) {
            final_wt += x[i];
            final_wt -= p;
        }

        if (final_wt <= (double)K) {
            cout << p << endl;
        } else {
            cout << "-1\n";
        }

        // printf("%lf\n", p);
    }
}
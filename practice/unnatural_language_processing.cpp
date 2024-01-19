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

bool is_vowel(char c) {
    if (c == 'a' || c == 'e')
        return true;
    else
        return false;
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

        for (int i = 0; i < n;) {
            if (i < n - 3) {
                if (is_vowel(s[i + 3])) {
                    cout << s[i] << s[i + 1] << ".";
                    i += 2;
                } else {
                    cout << s[i] << s[i + 1] << s[i + 2] << ".";
                    i += 3;
                }
            } else {
                cout << s[i];
                i++;
            }
        }
        cout << endl;
    }
}
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

        // map<string, vll> nums;

        // for (int i = 1; i < 1000000; i++) {
        //     string num = to_string(i * i);
        //     sort(num.begin(), num.end());
        //     if (num.length() == n) {
        //         if (nums.count(num)) {
        //             nums[num].push_back(i * i);
        //         } else {
        //             vll new_vec = {i * i};
        //             nums.insert({num, new_vec});
        //         }
        //     }
        // }

        // for (auto &stuff : nums) {
        //     if (stuff.second.size() < n) {
        //         continue;
        //     }
        //     for (auto num : stuff.second) {
        //         cout << num << endl;
        //     }
        //     cout << endl;
        // }

        if (n == 1) {
            cout << "4\n";
            continue;
        }

        vector<string> out;

        string num_c = "196";
        ll times = n - num_c.length();
        for (int j = 0; j < times; j++) {
            num_c.push_back('0');
        }
        out.push_back(num_c);

        for (int i = 0; i < n / 2; i++) {
            string num = "1";
            string num2 = "9";
            for (int j = 0; j < i; j++) {
                num.push_back('0');
                num2.push_back('0');
            }
            num2.push_back('6');
            num.push_back('6');
            for (int j = 0; j < i; j++) {
                num2.push_back('0');
                num.push_back('0');
            }
            num.push_back('9');
            num2.push_back('1');

            ll times = n - num.length();

            for (int j = 0; j < times; j++) {
                num2.push_back('0');
                num.push_back('0');
            }
            out.push_back(num);
            out.push_back(num2);
        }

        for (auto i : out) {
            cout << i << endl;
        }
    }
}
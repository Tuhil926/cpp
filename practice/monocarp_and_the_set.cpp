#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
#define mod 998244353

ll fact_dp[3 * (ll)1e5 + 1];
ll done_dp[3 * (ll)1e5 + 1] = {0};

ll fact(ll n) {
    if (done_dp[n]) {
        return fact_dp[n];
    } else if (n == 0) {
        return 1;
    } else {
        ll res = (fact(n - 1) * n) % mod;
        done_dp[n] = 1;
        fact_dp[n] = res;
        return res;
    }
}

ll solve(ll n, vector<ll> num_ques, ll num_less, ll num_great, ll first_less,
         ll first_great) {
    if (first_less == 1) {
        return ((num_ques[n - 1] - num_ques[first_great]) *
                    (num_ques[n - 1] - 2) * fact(num_ques[n - 1] - 2) +
                fact(num_ques[n - 1] - 1)) %
               mod;
    } else if (first_great == 1) {
        return ((num_ques[n - 1] - num_ques[first_less]) *
                    (num_ques[n - 1] - 2) * fact(num_ques[n - 1] - 2) +
                fact(num_ques[n - 1] - 1)) %
               mod;
    } else {
        return 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m;
    cin >> n >> m;

    ll num_less = 0;
    ll num_great = 0;
    ll num_ques = 0;

    ll first_less = n;
    ll first_great = n;

    string s;
    cin >> s;
    s = "?" + s;

    cout << s << endl;

    vector<ll> num_ques_arr;

    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            num_ques++;
        } else if (s[i] == '<') {
            if (first_less == n) first_less = i;
            num_less++;
        } else {
            if (first_great == n) first_great = i;
            num_great++;
        }
        num_ques_arr.push_back(num_ques);
    }

    cout << n << endl;
    cout << num_ques_arr[2] << endl;
    cout << num_less << endl;
    cout << num_great << endl;
    cout << first_less << endl;
    cout << first_great << endl << endl;

    cout << solve(n, num_ques_arr, num_less, num_great, first_less, first_great)
         << endl;

    // cout << fact(2) << endl;

    // cout << ((fact(num_ques - 1) * (num_ques - 1)) % mod) * (s[1] != '?')
    //      << endl;

    for (ll i = 0; i < m; i++) {
        ll ind;
        char c;
        cin >> ind >> c;
        if (c == '?') {
            // if (s[ind] == '<') {
            //     if (first_less == ind) {
            //         do {
            //             first_less++;
            //         } while (s[first_less] != '<' && first_less < n);
            //     }
            //     num_less--;
            //     num_ques_arr[n - 1]++;
            // } else if (s[ind] == '>') {
            //     if (first_great == ind) {
            //         do {
            //             first_great++;
            //         } while (s[first_great] != '>' && first_great < n);
            //     }
            //     num_great--;

            //     num_ques_arr[n - 1]++;
            // }
            if (s[ind] != '?') {
                s[ind] = '?';
                num_ques++;
            };
        } else if (c == '<') {
            if (s[ind] == '?') {  // && first_less > ind) {
                // first_less = ind;
                num_ques--;
            }
            // } else if (s[ind] == '>') {
            //     if (first_less > ind) {
            //         first_less = ind;
            //     }
            //     if (first_great == ind) {
            //         do {
            //             first_great++;
            //         } while (s[first_great] != '>' && first_great < n);
            //     }
            // }
            s[ind] = '<';
        } else if (c == '>') {
            if (s[ind] == '?') {  //&& first_great > ind) {
                // first_great = ind;
                num_ques--;
            }
            // } else if (s[ind] == '<') {
            //     if (first_great > ind) {
            //         first_great = ind;
            //     }
            //     if (first_less == ind) {
            //         do {
            //             first_less++;
            //         } while (s[first_less] != '<' && first_less < n);
            //     }
            // }
            s[ind] = '>';
        }
        // cout << n << endl;
        // cout << num_ques_arr[n - 1] << endl;
        // cout << num_less << endl;
        // cout << num_great << endl;
        // cout << first_less << endl;
        // cout << first_great << endl << endl;
        // cout << solve(n, num_ques_arr, num_less, num_great, first_less,
        //               first_great)
        //      << endl
        //      << endl;
        cout << ((fact(num_ques - 1) * (num_ques - 1)) % mod) * (s[1] != '?')
             << endl;
    }
}
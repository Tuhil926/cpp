#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    int n, a;
    cin >> n;

    int col_1, col_2, col_3;

    int progress1 = 0, progress2 = 1;

    int done = 0;

    for (int i = 0; i < n * n; i++) {
        cin >> a;
        if (i == 0) {
            if (a != 1) {
                col_1 = 1;
                col_2 = 2;
            } else {
                col_1 = 2;
                col_2 = 1;
            }
            col_3 = 3;
        }
        if (!done) {
            if (a != col_1) {
                cout << col_1 << " " << progress1 / n + 1 << " "
                     << progress1 % n + 1 << endl;
                progress1 += 2;
                if (n % 2 == 0)
                    progress1 +=
                        ((progress1) / n) % 2 - ((progress1 - 2) / n) % 2;
            } else {
                cout << col_2 << " " << progress2 / n + 1 << " "
                     << progress2 % n + 1 << endl;
                progress2 += 2;
                if (n % 2 == 0)
                    progress2 +=
                        ((progress2 - 2) / n) % 2 - ((progress2) / n) % 2;
            }
            cout.flush();

            if (progress1 > n * n - 1) {
                done = col_2;
            } else if (progress2 > n * n - 1) {
                done = col_1;
            }
        } else {
            if (done == col_2) {
                if (a == done) {
                    cout << col_3 << " " << progress2 / n + 1 << " "
                         << progress2 % n + 1 << endl;

                } else {
                    cout << done << " " << progress2 / n + 1 << " "
                         << progress2 % n + 1 << endl;
                }
                progress2 += 2;
                if (n % 2 == 0)
                    progress2 +=
                        ((progress2 - 2) / n) % 2 - ((progress2) / n) % 2;
            } else {
                if (a == done) {
                    cout << col_3 << " " << progress1 / n + 1 << " "
                         << progress1 % n + 1 << endl;

                } else {
                    cout << done << " " << progress1 / n + 1 << " "
                         << progress1 % n + 1 << endl;
                }
                progress1 += 2;
                if (n % 2 == 0)
                    progress1 +=
                        ((progress1) / n) % 2 - ((progress1 - 2) / n) % 2;
            }
            cout.flush();
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;

#define n 15

// bitset<n> column;
// bitset<2 * n - 1> diag1;
// bitset<2 * n - 1> diag2;
char column[n];
char diag1[2 * n - 1];
char diag2[2 * n - 1];

ll count_combination;

void search(int y) {
    if (y == n) {
        count_combination++;
        return;
    }
    for (int x = 0; x < n; ++x) {
        short ind = n - 1 + y - x;
        if (column[x] | diag1[x + y] | diag2[ind]) continue;
        column[x] = 1;
        diag1[x + y] = 1;
        diag2[ind] = 1;
        search(y + 1);
        column[x] = 0;
        diag1[x + y] = 0;
        diag2[ind] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    search(0);
    cout << count_combination << endl;
}

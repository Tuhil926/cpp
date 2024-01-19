#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n, m, ans;
    vector<string> rows;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n >> m;
        ans = 0;
        rows.clear();

        vector<vector<int>> row_pre;
        vector<vector<int>> col_pre;

        for (int j = 0; j < n; j++) {
            string row;
            cin >> row;
            rows.push_back(row);
        }

        for (int j = 0; j < n; j++) {
            vector<int> row;
            int sum = 0;
            row.push_back(sum);
            for (int k = 0; k < m; k++) {
                sum += rows[j][k] == '1';
                row.push_back(sum);
            }
            row_pre.push_back(row);
        }

        for (int j = 0; j < m; j++) {
            vector<int> row;
            int sum = 0;
            row.push_back(sum);
            for (int k = 0; k < n; k++) {
                sum += rows[k][j] == '1';
                row.push_back(sum);
            }
            row_pre.push_back(row);
        }

        cout << ans << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
// typedef int ll;

#define n 7

ll search_paths(ll grid[n][n], ll dir) {
    // if (n % 2 == 0) {
    //     return 0;
    // }
    static ll curr[2] = {1, 0};
    static ll num_done = 1;
    // static ll num_available_paths;
    // static ll can_go_forward;

    if (curr[0] == n - 1 && curr[1] == n - 1) {
        if (num_done == n * n - 1)
            return 1;
        else
            return 0;
    }

    grid[curr[0]][curr[1]] = 1;
    num_done++;

    ll tot = 0;

    ll num_available_paths = 0;
    ll can_go_forward = 0;

    if (curr[0] > 0 && grid[curr[0] - 1][curr[1]] == 0) {
        num_available_paths++;
        if (dir == 0) can_go_forward = 1;
    }
    if (curr[0] < n - 1 && grid[curr[0] + 1][curr[1]] == 0) {
        num_available_paths++;
        if (dir == 1) can_go_forward = 1;
    }
    if (curr[1] > 0 && grid[curr[0]][curr[1] - 1] == 0) {
        num_available_paths++;
        if (dir == 2) can_go_forward = 1;
    }
    if (curr[1] < n - 1 && grid[curr[0]][curr[1] + 1] == 0) {
        num_available_paths++;
        if (dir == 3) can_go_forward = 1;
    }

    if (!can_go_forward && num_available_paths >= 2) {
        grid[curr[0]][curr[1]] = 0;
        num_done--;
        return 0;
    }

    if (curr[0] > 0 && grid[curr[0] - 1][curr[1]] == 0) {
        curr[0]--;
        tot += search_paths(grid, 0);
        curr[0]++;
    }
    if (curr[0] < n - 1 && grid[curr[0] + 1][curr[1]] == 0) {
        curr[0]++;
        tot += search_paths(grid, 1);
        curr[0]--;
    }
    if (curr[1] > 0 && grid[curr[0]][curr[1] - 1] == 0) {
        curr[1]--;
        tot += search_paths(grid, 2);
        curr[1]++;
    }
    if (curr[1] < n - 1 && grid[curr[0]][curr[1] + 1] == 0) {
        curr[1]++;
        tot += search_paths(grid, 3);
        curr[1]--;
    }
    grid[curr[0]][curr[1]] = 0;
    num_done--;
    return tot;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll grid[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = 0;
        }
    }
    grid[0][0] = 1;

    ll res = search_paths(grid, 1) * 2;

    cout << res << endl;
}
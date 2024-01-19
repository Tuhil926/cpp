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

#define AdjListDist vector<vector<pll>>
#define INF 1e17

int dijkstra(AdjListDist &adj_list, ll s, vll &distances, vll &prev,
             vll &slowness) {
    for (int i = 1; i < adj_list.size(); i++) {
        distances[i] = INF;
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, less<pair<ll, ll>>> Q;
    distances[s] = 0;

    Q.push(make_pair(0, s));

    vll done(adj_list.size(), 0);

    while (Q.size()) {
        pair<ll, ll> u = Q.top();
        Q.pop();

        for (int i = 0; i < adj_list[u.second].size(); i++) {
            ll new_dist =
                u.first + adj_list[u.second][i].first * (slowness[u.second]);

            if (distances[adj_list[u.second][i].second] > new_dist) {
                prev[adj_list[u.second][i].second] = u.second;
                distances[adj_list[u.second][i].second] = new_dist;
                slowness[adj_list[u.second][i].second] = min(
                    slowness[adj_list[u.second][i].second], slowness[u.second]);
                Q.push(make_pair(new_dist, adj_list[u.second][i].second));
            }
        }
    }
    return 0;
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    tc {
        ll n, m;
        cin >> n >> m;

        vll slowness;
        AdjListDist adj_list(n);

        for (int i = 0; i < m; i++) {
            ll u, v, w;
            cin >> u >> v >> w;
            adj_list[u - 1].push_back(make_pair(w, v - 1));
            adj_list[v - 1].push_back(make_pair(w, u - 1));
        }

        arrinp(slowness, n);

        vll distances(n);
        vll prev(n, 0);

        dijkstra(adj_list, 0, distances, prev, slowness);

        cout << distances[n - 1] << endl;
    }
}
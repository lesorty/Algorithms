#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

#define pb push_back
#define eb emplace_back


int main() {
    ll n, m, q; cin >> n >> m >> q;
    vector<vector<pair<ll,ll>>> adj(n+1);
    ll d[n+1][n+1];

    for (ll i = 0; i < n+1; i++) {
        for (ll j = 0; j < n+1; j++) {
            d[i][j] = LONG_LONG_MAX;
        }
    }
    for (ll i = 0; i < n+1; i++) {
        d[i][i] = 0;
    }

    for (ll i = 0; i < m; i++) {
        ll x, y, z; cin >> x >> y >> z;
            d[x][y] = min(d[x][y], z);
            d[y][x] = min(d[y][x], z);
    }

    for (int k = 1; k < n+1; ++k) {
        for (int i = 1; i < n+1; ++i) {
            for (int j = 1; j < n+1; ++j) {
                  if (d[i][k] < LONG_LONG_MAX && d[k][j] < LONG_LONG_MAX)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
            }
        }
    }

    for (ll i = 0; i < q; i++) {
        ll a, b; cin >> a >> b;
        ll ans = d[a][b] == LONG_LONG_MAX || d[a][b] < 0 ? -1 : d[a][b];
        cout << ans << endl;
    }

    return 0;
}
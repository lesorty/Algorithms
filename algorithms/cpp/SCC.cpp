#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define pb push_back
#define endl "\n"
#define rep(i, a, b) for(ll i = (a); i < (b); i++)
#define sorta(arr) sort((arr).begin(), (arr).end())
#define sz(x) x.size()
#define all(x) (x).begin(), (x).end()
ll const mod = 1e9 + 7;

vector<vector<ll>> adj, adj_rev;
vector<bool> used;
vector<ll> order, component;

void dfs1(ll v) {
    used[v] = true;

    for (auto u : adj[v])
        if (!used[u])
            dfs1(u);

    order.push_back(v);
}

void dfs2(ll v) {
    used[v] = true;
    component.push_back(v);

    for (auto u : adj_rev[v])
        if (!used[u])
            dfs2(u);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);     
    cout.tie(0);
    ll n, m; cin >> n >> m;
    adj.assign(n+1, {});
    adj_rev.assign(n+1,{});

    rep(i,0,m) {
        ll a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }

    used.assign(n+1, false);

    for (ll i = 1; i <= n; i++)
        if (!used[i])
            dfs1(i);

    used.assign(n+1, false);
    reverse(order.begin(), order.end());
    vector<ll> roots(n+1, 0);
    vector<ll> root_nodes;
    vector<vector<ll>> adj_scc(n+1);

    for (auto v : order)
        if (!used[v]) {
            dfs2(v);

            ll root = component.front();
            for (auto u : component) roots[u] = root;
            root_nodes.push_back(root);

            component.clear();
        }


    for (ll v = 1; v <= n; v++)
        for (auto u : adj[v]) {
            ll root_v = roots[v],
                root_u = roots[u];

            if (root_u != root_v)
                adj_scc[root_v].push_back(root_u);
        }

    return 0;
}
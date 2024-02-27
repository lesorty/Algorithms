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

ll n;
ll m;
ll count;
vector<vector<ll>> adj;
set<pair<ll,ll>> ans;
vector<bool> visited;
vector<ll> tin, low;
bool flag;
ll timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if(ans.find({v,to}) == ans.end() && ans.find({to,v}) == ans.end())
            ans.insert({v,to});

        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                flag = true;
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n+1, false);
    tin.assign(n+1, -1);
    low.assign(n+1, -1);

    dfs(1);

}
int main() { 
    ios::sync_with_stdio(0);
    cin.tie(0);     

    n, m; cin >> n >> m;
    flag = false;
    adj.assign(n+1,{});



    rep(i,0,m){
        ll a,b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    find_bridges();
    if(flag || accumulate(all(visited), 0) != n) cout << "IMPOSSIBLE" << endl;
    else {
        for(auto c : ans){
            cout << c.first << " " << c.second << endl;
        }
    }

    return 0;
}

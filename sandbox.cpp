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

ll n,m;
vector<vector<ll>> adj, adj_t;
vector<bool> used;
vector<ll> order, comp;
vector<bool> assignment;

void dfs1(ll v) {
    used[v] = true;
    for (ll u : adj[v]) {
        if (!used[u])
            dfs1(u);
    }
    order.push_back(v);
}

void dfs2(ll v, ll cl) {
    comp[v] = cl;
    for (ll u : adj_t[v]) {
        if (comp[u] == -1)
            dfs2(u, cl);
    }
}

bool solve_2SAT() {
    order.clear();
    used.assign(n, false);
    for (ll i = 0; i < n; ++i) {
        if (!used[i])
            dfs1(i);
    }

    comp.assign(n, -1);
    for (ll i = 0, j = 0; i < n; ++i) {
        ll v = order[n - i - 1];
        if (comp[v] == -1)
            dfs2(v, j++);
    }

    assignment.assign(n / 2, false);
    for (ll i = 0; i < n; i += 2) {
        if (comp[i] == comp[i + 1])
            return false;
        assignment[i / 2] = comp[i] > comp[i + 1];
    }
    return true;
}

void add_disjunction(ll a, bool na, ll b, bool nb) {
    // na and nb signify whether a and b are to be negated 
    a = 2*a ^ na;
    b = 2*b ^ nb;
    ll neg_a = a ^ 1;
    ll neg_b = b ^ 1;
    adj[neg_a].push_back(b);
    adj[neg_b].push_back(a);
    adj_t[b].push_back(neg_a);
    adj_t[a].push_back(neg_b);
}


void solve(){
    cin >> n >> m;
    adj.assign(n+1,{});
    adj_t.assign(n+1,{});

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);     
    cout.tie(0);

    ll t; cin >> t;
    while(t--) solve();
    return 0;
}
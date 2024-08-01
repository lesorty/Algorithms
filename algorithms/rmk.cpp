#include <bits/stdc++.h>
#define endl '\n'
#define rep(i, begin, end) for (int i = begin; i < end; i++)
typedef long long ll;
using namespace std;
#define pb push_back
#define sz(x) x.size()
#define all(x) (x).begin(), (x).end()
#define print(x) cout << x << endl
#define sz(x) x.size()
#define input(x) cin >> x

const int MOD = 1009;
const int MAX = 2e5 + 7;


struct lca_struct {
    vector<vector<int>> adj, anc;
    vector<int> dep, in, out;
    int n, lg, t;
    lca_struct(int n) : n(n), adj(n + 1), dep(n + 1), in(n + 1), out(n + 1) {
        lg = 32 - __builtin_clz(n);
        anc = vector<vector<int>>(n + 1, vector<int>(lg));
    }
    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void dfs(int v, int p = -1, int d = 1) {
        dep[v] = d;
        in[v] = t++;
        rep(i, 1, lg) anc[v][i] = anc[anc[v][i - 1]][i - 1];
        for (int ch : adj[v]) if (ch != p) {
            anc[ch][0] = v;
            dfs(ch, v, d + 1);
        }
        out[v] = t++;
    }
    bool is_anc(int a, int b){
        return (in[a] <= in[b]) && (out[a] >= out[b]);
    }
    int get_lca(int a, int b) {
        if(dep[a] < dep[b]) swap(a,b);

        for(ll i = lg -1; i >= 0; i--){
            if((dep[a] - dep[b]) & (1LL << i)) a = anc[a][i];
        }
        if(a == b) return a;

        for (int i = lg - 1; i >= 0; i--) {
            if (anc[a][i] != anc[b][i]){
                a = anc[a][i];
                b = anc[b][i];
            }
        }
        return anc[a][0];
    }
};

void solve(ll ntc){
    ll n; cin >> n;
    lca_struct lca(n);
    
    rep(i,1,n+1){
        ll m; cin >> m;
        rep(j,0,m){
            ll x; cin >> x;
            lca.add_edge(i,x);
        }
    }
    lca.dfs(1);
    ll q; cin >> q;

    cout << "Case " << ntc << ":" << endl;
    rep(i,0,q){
        ll a,b; cin >> a >> b;
        cout << lca.get_lca(a,b) << endl;
    }

}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);

    ll t; cin >> t;
    ll ntc = 1;
    while(t--) {solve(ntc); ntc++;}
    
    return 0;
}
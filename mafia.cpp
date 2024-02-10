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

vector<vector<ll>> adj;
vector<bool> vis;
vector<pair<ll,ll>> dist;
vector<ll> grau;

ll dfs(ll node) {
    vis[node] = true;
    if(grau[node] == 1){dist[node] = {0,node}; return 0;}

    for(auto nd: adj[node]){
        if(!vis[nd]){
            dfs(nd);
            if(dist[node].first < 1 + dist[nd].first){
                dist[node] = {1+dist[nd].first, node};
            }
        }  
    }
}


vector<bool> del;
bool flag;

void use(ll node){
    del[node] = true;
    ll nxt = 0;
    for(auto n: adj[node]){
        if(!del[node]){
            if(dist[nxt].first < dist[n].first){
                nxt = n;
            }
        }
    }
    if(nxt != 0) use(nxt);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);     

    ll n, k; cin >> n >> k;
    adj.assign(n+1,{});
    vis.assign(n+1,false);
    dist.assign(n+1,{LONG_LONG_MIN,-1});
    grau.assign(n+1,0);
    del.assign(n+1,false);
    flag = false;
    
    rep(i,2,n+1){
        ll x; cin >> x;
        adj[x].pb(i);
        adj[i].pb(x);
        grau[x]++;
        grau[i]++;
    }

    dfs(1);

    ll out = 0;
    sort(all(dist));

    rep(i,0,k){
        flag = false;
        if(sz(dist) == 0) break;
        for(ll j = (sz(dist) - 1); j > 0; j--){
            if(del[dist[j].second] == true) del.pop_back();
            else{
                out += dist[j].first;
                use(dist[j].second);
                break;
            }
        }    
    }

    cout << out << endl;

    return 0;
}

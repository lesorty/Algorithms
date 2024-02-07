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

vector<ll> path;
vector<vector<ll>> adj;
vector<bool> vis;
bool flag;

void dfs(ll n, ll p){
    vis[n] = true;

    for(auto nd : adj[n]){ 
        if(!vis[nd]) dfs(nd, n);    

        else if(nd != p && !flag){
            flag = true;
            path.pb(nd);
            path.pb(n);
            return;
        }
        if(flag){
            path.pb(n);
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n,m; cin >> n >> m;
    adj.assign(n+1, {});
    vis.assign(n+1, false);

    rep(i,0,m){
        ll x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    
    rep(i,1,n+1){
        if(!vis[i]){
            flag = false;
            dfs(i,0);
            if(flag) break;
        }
    }


    if(flag){
        vector<vector<ll>> freq(n+1);
        ll l = 0 ;
        ll r = 0;
        rep(i,0,path.size()){
            freq[path[i]].pb(i);
            if(freq[path[i]].size() > 1){
                l = freq[path[i]][0];
                r = freq[path[i]][1];
            }
        }

        cout << r - l + 1 << endl;
        for(ll i = r; i >= l; i--) cout << path[i] << " ";

    }
    else cout << "IMPOSSIBLE" << endl;

    return 0;
}

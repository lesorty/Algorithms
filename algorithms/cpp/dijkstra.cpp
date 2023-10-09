#include <bits/stdc++.h>
using namespace std;

/* clang-format off */

/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

/* FUNCTIONS */
#define pb push_back
#define eb emplace_back

int main() {
    ll n, m; cin >> n >> m;
    vector<vector<pair<ll,ll>>> adj(n+1);
    vector<ll> distance(n+1, LONG_LONG_MAX);
    set<pair<ll,ll>> fila;
    vector<ll> pais(n+1,0);
    fila.insert({0,1});
    distance[1] = 0;

    for (ll i = 0; i < m; i++) {
        ll x, y, z; cin >> x >> y >> z;
         adj[x].pb({z,y});
        adj[y].pb({z,x});
    }

    while(!fila.empty()){
        pair<ll,ll> topo = *fila.begin();
        fila.erase(topo);
        ll node = topo.second;
        ll dnode = topo.first;
        for(auto c : adj[node]){
            ll newnode = c.second;
            ll dnewnode = c.first;
            if(distance[newnode] > distance[node] + dnewnode){
                distance[newnode] = distance[node] + dnewnode;
                pais[newnode] = node;
                fila.insert(c);
            }   
        }
    }

    if(pais[n] == 0){
        cout << -1 << endl;
    }

    else{
        ll atual = n;
        vector<ll> ans;
        ans.pb(n);
        while(atual != 1){
            atual = pais[atual];
            ans.pb(atual);
        }
        for (ll i = ans.size()-1; i >= 0; i--) {
            cout << ans[i] << " ";
        }
    }
}
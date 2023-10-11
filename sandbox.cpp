#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>
#define mll map<long, long>
#define pb push_back
#define endl "\n"


void dijkstra(ll node, vector<vector<pair<ll,ll>>> adj, vector<ll> &dist){
    set<pair<ll,ll>> fila;
    fila.insert({0,node});
    dist[node] = 0;

    while(!fila.empty()){
        pair<ll,ll> topo = *fila.begin();
        fila.erase(topo);
        ll node = topo.second;
        ll dnode = topo.first;

        if(dist[node] != dnode) continue;

        for(auto c : adj[node]){
            ll newdist = dnode + c.first;
            ll adjnode = c.second;
            if(newdist < dist[adjnode]){
                dist[adjnode] = newdist;
                fila.insert({newdist, adjnode});
            }   
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n,m; cin >> n >> m;
    vector<vector<pair<ll,ll>>> adj(n+1);
    vector<vector<pair<ll,ll>>> adjinvert(n+1);
    vector<ll> dinit(n+1, LONG_LONG_MAX);
    vector<ll> df(n+1, LONG_LONG_MAX);
    vector<vector<ll>> arestas;
    
    for (ll i = 0; i < m; i++) {
        ll x, y,z; cin >> x >> y >> z;
        arestas.pb({z,x,y});
        adj[x].pb({z,y});
        adjinvert[y].pb({z,x});
    }   

    dijkstra(1,adj,dinit);
    dijkstra(n, adjinvert, df);

    ll soma = LONG_LONG_MAX;
    for(auto aresta : arestas){
        ll daresta = aresta[0];
        ll iaresta = aresta[1];
        ll faresta = aresta[2];
        if(dinit[iaresta] != LONG_LONG_MAX && df[faresta] != LONG_LONG_MAX){
            ll costaresta = dinit[iaresta] + df[faresta] + (daresta/2) ;
            soma = min(soma , costaresta);
        }
    }

    cout << soma << endl;

    return 0;
}
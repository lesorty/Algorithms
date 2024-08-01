#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define pb push_back
#define endl "\n"
#define rep(i, a, b) for(ll i = (a); i < (b); i++)
#define sorta(arr) sort((arr).begin(), (arr).end())
#define sz(x) x.size()

vector<ll> vis;
vector<vector<ll>> adj;

bool dfs (ll node, ll parent){
    vis[node] = true;
    for(ll vizinho : adj[node]){
        if(vis[vizinho] && vizinho != parent) return true;
        if(!vis[vizinho]){
            if(dfs(vizinho, node)) return true;
        }
    }
    return false;
}
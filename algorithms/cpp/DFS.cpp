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

vector<vector<ll>> adj;
vector<ll> vis;
vector<ll> out;
ll n,m;

void dfs (ll node){
    vis[node] = true;
    for(ll vizinho : adj[node]){
        if(!vis[vizinho]){
            dfs(vizinho);
        }
    }
}

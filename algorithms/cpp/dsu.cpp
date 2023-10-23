#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

#define pb push_back
#define eb emplace_back


vector<ll> pai;
vector<ll> tamanho;

ll findset(ll i){
    if(pai[i] == i) return i;
    return pai[i] = findset(pai[i]);
}

void unionsets(ll a, ll b){
    a = findset(a);
    b = findset(b);
    if(a == b) return;
    if(tamanho[a] > tamanho[b]) swap(a,b);
    pai[a] = b;
    tamanho[b] += tamanho[a];
}

int main() {

    ll n, m; cin >> n >> m;
    vector<vector<ll>> arestas;
    pai.assign(n+1,0);
    tamanho.assign(n+1,1);
    ll qualification[n+1];
    bool conectados[n+1];

    for (ll i = 0; i < n+1; i++) pai[i] = i;
    for (ll i = 1; i < n+1; i++) cin >> qualification[i];

    for (ll i = 0; i < m; i++) {
        ll x, y, z; cin >> x >> y >> z;
        arestas.pb({z,x,y});
    }

    sort(arestas.begin(), arestas.end());

    ll out = 0;
    for (ll i = 0; i < m; i++) {
        vector<ll> ar = arestas[i];
        ll peso = ar[0];
        ll a = ar[1];
        ll b = ar[2];

        if(findset(a) != findset(b)){
            out += peso;
            conectados[b] = true;
            unionsets(a,b);
        }
    }   


}
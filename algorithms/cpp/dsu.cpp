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
vector<ll> size;

ll findset(ll i){
    if(pai[i] == i) return i;
    return pai[i] = findset(pai[i]);
}

void unionsets(ll a, ll b){
    a = findset(a);
    b = findset(b);
    if(a == b) return;
    if(size[a] > size[b]) swap(a,b);
    pai[a] = b;
    size[b] += size[a];
}

int main() {

    while(true){
        ll n, m; cin >> n >> m;
        if(n==0 && m==0) break;

        set<vector<ll>> arestas;
        pai.assign(n+1,0);
        size.assign(n+1,1);
        ll soma = 0;

        for (ll i = 0; i < n+1; i++) {
            pai[i] = i;
        }

        for (ll i = 0; i < m; i++) {
            ll x, y, z; cin >> x >> y >> z;
            arestas.insert(vector<ll>{z,x,y});
            soma += z;
        }

        while(!arestas.empty()){
            vector<ll> ar = *arestas.begin();
            ll peso = ar[0];
            ll a = ar[1];
            ll b = ar[2];
            arestas.erase(ar);

            if(findset(a) != findset(b)){
                soma -= peso;
                unionsets(a,b);
            }
        }
        cout << soma << endl;

    }


}
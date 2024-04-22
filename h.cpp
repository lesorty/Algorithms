#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define pb push_back
#define endl "\n"
#define rep(i, a, b) for(ll i = (a); i < (b); i++)
#define sorta(arr) sort((arr).begin(), (arr).end())
#define fastio ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define all(x) (x).begin(), (x).end() 
ll const mod = 1e9 + 7;
ll const MAX = 2e5+7;


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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);

    ll n,q,d; cin >> n >> q >> d;

    pai.assign(n+1,0);
    tamanho.assign(n+1,1);
    for (ll i = 0; i < n+1; i++) pai[i] = i;

    map<pair<ll,ll>, ll> mp;
    vector<pair<ll,ll>> pos;

    rep(i,0,n){
        ll x,y;cin >> x >> y;
        mp[{x,y}] = i+1;
        pos.pb({x,y});
    }    

    rep(i,0,n){
        ll curx = pos[i].first;
        ll cury = pos[i].second;

        rep(dx,-6,6) rep(dy,-6,6){
            if(dx*dx + dy*dy > d*d) continue;
            ll xx = curx + dx;
            ll yy = cury + dy;
            if(!mp.count({xx,yy})) continue;
            
            unionsets(i+1, mp[{xx,yy}]);
        }
    }

    rep(i,0,q){
        ll a,b; cin >> a >> b;
        if(findset(a) == findset(b)) cout << "S\n";
        else cout << "N\n";
    }
    return 0;
}
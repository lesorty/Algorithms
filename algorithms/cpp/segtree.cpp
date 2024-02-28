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
ll const maxn = 1e5;

ll seg[4*maxn];

void build(ll arr[], ll id, ll l , ll r){
    if(l == r) {seg[id] = arr[l]; return;}

    ll mid = (l + r) / 2;

    build(arr, 2*id, l, mid);
    build(arr, 2*id+1, mid+1, r);
    seg[id] = seg[2*id] + seg[2*id+1];
}

void update(ll id, ll l, ll r, ll pos, ll nwv){
    if(l == r){seg[id] = nwv; return;}

    ll mid = (l + r) / 2;
    if(pos <= mid) update(2*id, l, mid, pos, nwv);
    else update(2*id+1, mid+1, r, pos, nwv);

    seg[id] = seg[2*id] + seg[2*id+1];
}

ll sum(ll id, ll lt, ll rt, ll l, ll r){
    if(lt > r || rt < l) return 0;
    if(rt <= r && lt >= l) return seg[id];

    ll mid = (lt+rt) / 2;
    return sum(2*id, lt, mid, l,r) + sum(2*id+1, mid+1, rt, l, r);
}

int main () {
    ll n,m; cin >> n >> m;

    ll arr[n];
    rep(i,0,n) cin >> arr[i];
    build(arr,1,0,n-1);     

    rep(i,0,m){
        ll typ; cin >> typ;
        if(typ == 1){
            ll idx, v; cin >> idx >> v;
            update(1, 0, n-1, idx, v);
        }

        else if(typ ==2){
            ll l,r; cin >> l >> r;
            cout << sum(1, 0, n-1, l, r-1) << endl;
        }
    }

    return 0;
}